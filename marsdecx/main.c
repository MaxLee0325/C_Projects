#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;
    //read the number of lines
    scanf("%d", &count);
    int line = 1;

    for(int i = 0; i < count; i++){
        //set the order of integers
        int output = 1;
        //read the number of bytes
        int num;
        scanf("%d", &num);
        //avoid negative range
        unsigned int range;
        //use long int in case the output gets too big
        long int res = 0;
        //store the bytes inside a char array
        char *hex;
        hex = calloc(num, sizeof(char));
        //keep inputting if more than one hex
        for(int j = 0; j < num; j++){
            int tmp;
            scanf("%x", &tmp);
            hex[j] = tmp;
        }
        //initialize an integer array to store the bits
        int *map;
        map = calloc(num * 8, sizeof(int));
        //store the bits in the array
        for(int m = 0; m < num; m++){
            for(int n = 7; n >= 0; n--){
                if ((hex[m] >> n) & 1){
                    map[m * 8 + (7-n)] = 1;
                }
            }
        }
        //to keep the remaining bits
        int remains = 8 * num;
        //to keep the starting index
        int startIdx = 0;
        //keep decoding until remaining bits equal or smaller than 5
        while(remains > 5){
            //derive the range
            range = 0;
            res = 0;
            //use bit shifting to sum up the range
            for(int j = startIdx; j < startIdx + 5; j++){
                range += (map[j] << (startIdx + 5 - 1 - j));
            }
            //update the starting index and remaining bits
            startIdx += 5;
            remains -= 5;
            //skip if range is 0
            if(range == 0){
                continue;
            }
            for(int j = startIdx; j < startIdx + range; j++){
                //deal the first bit separately as it's the sign bit
                if(j == startIdx){
                    res = -(map[j] << (startIdx + range - j - 1));
                }
                else {
                    res += map[j] << (startIdx + range - j - 1);
                }
            }
            printf("Line %d, integer %d: %d \n", line, output, res);
            //update remaining bits and starting index
            remains -= range;
            startIdx += range;
            output++;
        }
        line++;
    }
    return 0;
}

