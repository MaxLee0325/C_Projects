//
// Created by Alex Brodsky on 2023-11-13.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "cache.h"
#include "main.h"
#include <jmorecfg.h>
#include <stdio.h>
static int calls = 0;

typedef struct{
    int valid;
    long tag;
    unsigned char *data;
}line;

typedef struct{
    line *lines;
}set;

typedef struct{
    unsigned int word_size, sets_num, lines_num, line_size;
    set *sets;
}cache;

//helper function to find the bit size of offset
int findBitSize(unsigned int in){
    int size = 0;
    while(in > 1){
        in >>= 1;
        size++;
    }
    return size;
}

//helper function to find the value according to bits and offset
unsigned long findValue(int bits, int offset, unsigned long address){
    unsigned long value = 0;
    for(int i = 0; i < bits; i++){
        if(address & (1 << (offset + i))){
            value = value | (1 << i);
        }
    }
    return value;
}

//helper function to find the min value of the index
int findMin(set set, int line_num){
    long minValid = set.lines[0].valid;
    int minIndex = 0;
    for (int i = 0; i <line_num; i++) {
        if (minValid > set.lines[i].valid) {
            minValid = set.lines[i].valid;
            minIndex = i;
        }
    }
    return minIndex;
}

extern cache_t cache_new(unsigned int word_size, unsigned int sets,
                         unsigned int lines, unsigned int line_size) {
    //allocate memory for cache
    cache *cache = calloc(1, sets * lines * (sizeof(line)) + 16);
    cache->line_size = line_size;
    cache->word_size = word_size;
    cache->lines_num = lines;
    cache->sets_num = sets;
    //allocate memory for sets
    cache->sets = calloc(1, sets * lines * (sizeof(line)));
    for(int i = 0; i < sets; i++) {
        cache->sets[i].lines = calloc(1, lines * sizeof(line));
    }
    //allocate memory for data and initialize valid and tag
    for(int j = 0; j < sets; j++) {
        for (int i = 0; i < lines; i++) {
            cache->sets[j].lines[i].data = calloc(1, line_size);
            cache->sets[j].lines[i].valid = 0;
            cache->sets[j].lines[i].tag = 0;
        }
    }
    return (void *)cache;
}

extern void cache_load_word(cache_t handle, unsigned long address, void *word) {

    cache *cache = handle;
    //calculate b for offset bit size
    int offSet_size = findBitSize(cache->line_size);
    //calculate s for set bit size
    int index_size = findBitSize(cache->sets_num);
    //calculate t for tag bit size
    int tag_size = (int)cache->word_size - offSet_size - index_size;

    //get values of tag, index, and offset
    unsigned long tag = findValue(tag_size, index_size + offSet_size, address);
    unsigned long index = findValue(index_size, offSet_size, address);
    unsigned long offset = findValue(offSet_size, 0, address);

    boolean hit = FALSE;
    //load the data into the word
    for(int i = 0; i < cache->lines_num; i++) {
        if(cache->sets[index].lines[i].tag == tag && cache->sets[index].lines[i].valid) {
            calls ++;
            cache->sets[index].lines[i].valid = calls;
            memcpy(word, cache->sets[index].lines[i].data + offset,cache->word_size >> 3);
            hit = TRUE;
        }
    }
    //if missed, get the next level
    if(!hit){
        int minIndex = findMin(cache->sets[index], (int)cache->lines_num);
        load_block_from_next_level(address, cache->sets[index].lines[minIndex].data + offset);
        memcpy(word, cache->sets[index].lines[minIndex].data + offset,cache->word_size >> 3);
        calls ++;
        cache->sets[index].lines[minIndex].valid = calls;
        cache->sets[index].lines[minIndex].tag = tag;
    }
}

extern void cache_load_block(cache_t handle, unsigned long address, void *block,
                             unsigned int size) {

    cache *cache = handle;
    //calculate b for offset bit size
    int offSet_size = findBitSize(cache->line_size);
    //calculate s for set bit size
    int index_size = findBitSize(cache->sets_num);
    //calculate t for tag bit size
    int tag_size = (int)cache->word_size - offSet_size - index_size;

    //get values of tag, index, and offset
    unsigned long tag = findValue(tag_size, index_size + offSet_size, address);
    unsigned long index = findValue(index_size, offSet_size, address);
    unsigned long offset = findValue(offSet_size, 0, address);

    boolean hit = FALSE;
    //load the data into the word
    for(int i = 0; i < cache->lines_num; i++) {
        if(cache->sets[index].lines[i].tag == tag && cache->sets[index].lines[i].valid) {
            calls ++;
            cache->sets[index].lines[i].valid = calls;
            memcpy(block,cache->sets[index].lines[i].data + offset, findBitSize(size));
            hit = TRUE;
        }
    }
    //if missed, get the next level
    if(!hit){
        int minIndex = findMin(cache->sets[index], (int)cache->lines_num);
        load_block_from_next_level(address, cache->sets[index].lines[minIndex].data);
        memcpy(block, cache->sets[index].lines[minIndex].data, findBitSize(size));
        calls ++;
        cache->sets[index].lines[minIndex].valid = calls;
        cache->sets[index].lines[minIndex].tag = tag;
    }

}

extern void cache_store_word(cache_t handle, unsigned long address, void *word) {

    cache *cache = handle;
    //calculate b for offset bit size
    int offSet_size = findBitSize(cache->line_size);
    //calculate s for set bit size
    int index_size = findBitSize(cache->sets_num);
    //calculate t for tag bit size
    int tag_size = (int)cache->word_size - offSet_size - index_size;

    //get values of tag, index, and offset
    unsigned long tag = findValue(tag_size, index_size + offSet_size, address);
    unsigned long index = findValue(index_size, offSet_size, address);
    unsigned long offset = findValue(offSet_size, 0, address);

    //check if there is a hit, override if there is
    boolean hasTag = FALSE;
    for(int i = 0; i < cache->lines_num; i++) {
        if(cache->sets[index].lines[i].tag == tag && cache->sets[index].lines[i].valid) {
            hasTag = TRUE;
            calls ++;
            cache->sets[index].lines[i].valid = calls;
            memcpy(cache->sets[index].lines[i].data + offset,word,  cache->word_size >> 3);
            break;
        }
    }
    //if there is a miss, call load from next level
    if(!hasTag) {
        int minIndex = findMin(cache->sets[index], (int)cache->lines_num);
        load_block_from_next_level(address, cache->sets[index].lines[minIndex].data);
        calls ++;
        cache->sets[index].lines[minIndex].valid = calls;
        cache->sets[index].lines[minIndex].tag = tag;
        memcpy(cache->sets[index].lines[minIndex].data + offset,word,  cache->word_size >> 3);
    }
}

