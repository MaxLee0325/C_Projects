#include <stdio.h>

int main() {
    int count;
    //read number of input lines
    scanf("%d", &count);
    int line = 1;

    for(int i = 0; i < count; i++){
        int num;
        //read number of bytes
        scanf("%d", &num);
        if(num <= 0) {
            line++;
            continue;
        }
        else {
            printf("Line %d, integer 1: ", line);
            line++;
        }
        //store the input hexadecimal
        int hex;
        int range;
        //store the output
        long int target;

        //input first hexadecimal
        scanf("%x", &hex);
        //derive the range from the first hex
        range = hex >> 3;
        //truncation, get rid of the first 5 bits
        char trun = hex << 5;
        target = trun;
        //shift back three bits
        target = target >> 5;
        //keep inputting if more than one hex
        for(int j = 0; j < num - 1; j++){
            //make room for addition
            target = target << 8;
            int tmp;
            scanf("%x", &tmp);
            //update the target binary
            target += tmp;
        }
        //right shift to get rid of the remaining bits and get the output
        printf("%d\n", target >> (3 + 8 * (num - 1) - range));
    }
    return 0;
}

