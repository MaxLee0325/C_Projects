//
// Created by Alex Brodsky on 2023-09-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"

typedef struct ll_node {
    struct ll_node *prev;
    struct ll_node *next;
    void *item;
} ll_node_t;

typedef struct linked_list {
    ll_node_t *head;
    ll_node_t *tail;
} linked_list;

typedef struct ll_iterator{
    ll_node_t *next;
    linked_list *list;
    ll_node_t *prev;
} ll_iterator;

extern linked_list_t ll_new() {
    linked_list_t * list = calloc(1,sizeof(linked_list));
    return list;
}

extern void ll_destroy(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list != NULL);

    while (list->head != NULL) {
        ll_node_t *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }

    free(list);
}

static ll_node_t *new_node(void *item, ll_node_t *prev, ll_node_t *next) {
    ll_node_t *n = calloc(1, sizeof(ll_node_t));
    if (n != NULL) {
        n->item = item;
        n->prev = prev;
        n->next = next;
    }
    return n;
}


extern int ll_add_front(linked_list_t ll, void *item) {
    linked_list  *list = (linked_list *)ll;
    assert(list);

    ll_node_t *n = new_node(item,NULL, list->head);
    if (n != NULL) {
        if (list->tail == NULL) {
            list->tail = n;
        } else {
            list->head->prev = n;
        }
        list->head = n;
    }
    return n != NULL;
}

extern int ll_add_back(linked_list_t ll, void *item) {
    linked_list  *list = (linked_list *)ll;
    assert(list);

    ll_node_t *n = new_node(item,list->tail, NULL);
    if (n != NULL) {
        if (list->head == NULL) {
            list->head = n;
        } else {
            list->tail->next = n;
        }
        list->tail = n;
    }
    return n != NULL;
}

extern void * ll_remove_front(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        ll_node_t *n = list->head;
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        } else {
            list->head->prev = NULL;
        }

        item = n->item;
        free(n);
    }
    return item;
}

extern void * ll_remove_back(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);
    
    void *item = NULL;
    if (list->tail != NULL) {
        ll_node_t *n = list->tail;
        list->tail = list->tail->prev;
        if (list->tail == NULL) {
            list->head = NULL;
        } else {
            list->tail->next = NULL;
        }

        item = n->item;
        free(n);
    }
    return item;
}

extern void * ll_get_front(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        item = list->head->item;
    }
    return item;
}

extern void * ll_get_back(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        item = list->tail->item;
    }
    return item;
}

extern int ll_size(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);
    int count = 0;
    for (ll_node_t *ptr = list->head; ptr != NULL; ptr = ptr->next) {
        count++;
    }
    return count;
}

extern int ll_is_empty(linked_list_t ll) {
    linked_list  *list = (linked_list *)ll;
    assert(list);
    return list->head == NULL;
}

/************************************************************************
 * Your code below 
 ************************************************************************/

extern ll_iterator_t  ll_iterator_new(linked_list_t list) {
    ll_iterator *itr = calloc(1, sizeof(ll_iterator));
    itr->list = list;
    //give a special value to the previous node, avoid segmentation fault
    itr->prev = calloc(1, sizeof(ll_node_t));
    itr->prev->item = "Empty!!";
    //point the iterator to the head
    itr->next = itr->list->head;
    return itr;
}

extern void ll_iterator_destroy(ll_iterator_t iter) {
    free(iter);
}

extern void *ll_next(ll_iterator_t iter) {
    ll_iterator *itr = iter;
    //reassign the previous while move forward
    itr->prev = itr->next;
    void *result = itr->prev->item;
    //reassign the next node while move forward
    itr->next = itr->prev->next;
    return result;
}

extern int ll_has_next(ll_iterator_t iter) {
    ll_iterator *itr = iter;
    linked_list_t *lis = itr->list;
    //case 1: the iterator is assigned to an empty list then list is appended
    if(ll_size(lis) > 0 && !strcmp(itr->prev->item, "Empty!!") && itr->next == NULL){
        //reassign the iterator
        itr->next = itr->list->head;
    }
    //case 2: the list with only one element called next then is appended
    if(itr->prev->next && !itr->next){
        //update the iterator to point to the next node
        itr->next = itr->prev->next;
    }
    //normal case
    if(itr->next) return 1;
    else return 0;
}

extern int ll_add(ll_iterator_t iter, void *item) {
    ll_iterator *itr = iter;
    //initialize a holder node
    ll_node_t *holder = calloc(1, sizeof(ll_node_t));
    holder->item = item;
    //reassign previous and next node connection
    itr->prev->next = holder;
    holder->prev = itr->prev;
    holder->next = itr->next;
    itr->next->prev = holder;
    return 1;
}

extern void *ll_set(ll_iterator_t iter, void *item) {
    ll_iterator *itr = iter;
    //if the previous node is NULL nothing to set
    if(!itr->prev)
        return NULL;
    else{
        void *old = itr->prev->item;
        itr->prev->item = item;
        return old;
    }
}

extern void *ll_remove(ll_iterator_t iter){
    ll_iterator *itr = iter;
    //reassign the previous node and next
    itr->prev->prev->next = itr->next;
    //reassign the next node with previous node only when the next node is not NULL
    if(itr->next)
        itr->next->prev = itr->prev->prev;
    return itr->prev->item;
}
