#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "xis.h"
#include "xcpu.h"
#include "xmem.h"

int main(int argc, char **argv) {
    //validate file
    if(argc < 2){
        printf("No such file specified.\n");
        return 0;
    }

    //allocate memory for cpu
    xcpu *cpu = calloc(1, sizeof(xcpu));
    //allocate memory size
    xmem_init(65536);

    //open the file
    int f = open(argv[2], O_RDONLY);
    if(f < 0){
        printf("Open failed, errno: %d\n", errno);
        return 1;
    }

    //read the file
    unsigned char buffer[1];
    int i = 0;
    for(int len = 1; len > 0; i+=2){
        len = read(f, buffer, 2);
        xmem_store(buffer, i);
    }
    close(f);

    //initialize the cpu
    cpu->pc = 0;
    for(int j = 0; j < 16; j++){
        cpu->regs[j] = 0;
    }

    //execute the program
    int cycle = atoi(argv[1]);
    //case 1, the input cycle number is 0
    if(!cycle) {
        while(1)
            if(!xcpu_execute(cpu)) return 0;
    }
        //case 2, the input cycle number is not 0
    else {
        for (int j = 0; j < cycle; j++) {
            if (!xcpu_execute(cpu)) return 0;
        }
    }

    return 0;
}