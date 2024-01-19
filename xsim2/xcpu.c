#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xis.h"
#include "xcpu.h"
#include "xmem.h"

#define CAST_SHORT(x)   (unsigned short)(x[0] << 8 | x[1])  //cast the data into a unsigned short
#define FLAG(x) x->state    //get the flag
#define REG1(c, tmp) c->regs[XIS_REG1(tmp[1])]  //get register1
#define REG2(c, tmp) c->regs[XIS_REG2(tmp[1])]  //get register2

extern int xcpu_execute( xcpu *c ) {
    //a two-byte unsigned char to hold the instructions
    unsigned char holder[2];
    xmem_load(c->pc, holder);
    //a temporary two-byte unsigned char to load and store data
    unsigned char tmp[2];

    //match the instruction and execute the functions
    switch(holder[0]){
        case I_RET:
            xmem_load(c->regs[15], tmp);
            c->pc = CAST_SHORT(tmp) - 2;
            c->regs[15] += 2;
            break;
        case I_CLD:
            FLAG(c) = FLAG(c) & 0xFFFD;
            break;
        case I_STD:
            FLAG(c) = FLAG(c) | 0x0002;
            break;
        case I_LOADI:
            xmem_load(c->pc + 2, tmp);
            REG1(c, holder) = CAST_SHORT(tmp);
            c->pc += 2;
            break;
        case I_NOT:
            REG1(c, holder) = !(REG1(c, holder));
            break;
        case I_SHR:
            REG2(c, holder) = REG2(c, holder) >> REG1(c, holder);
            break;
        case I_SHL:
            REG2(c, holder) = REG2(c, holder) << REG1(c, holder);
            break;
        case I_XOR:
            REG2(c, holder) = REG2(c, holder) ^ REG1(c, holder);
            break;
        case I_OR:
            REG2(c, holder) = REG2(c, holder) | REG1(c, holder);
            break;
        case I_AND:
            REG2(c, holder) = REG2(c, holder) & REG1(c, holder);
            break;
        case I_ADD:
            REG2(c, holder) = REG2(c, holder) + REG1(c, holder);
            break;
        case I_SUB:
            REG2(c, holder) = REG2(c, holder) - REG1(c, holder);
            break;
        case I_MUL:
            REG2(c, holder) = REG2(c, holder) * REG1(c, holder);
            break;
        case I_DIV:
            REG2(c, holder) = REG2(c, holder) / REG1(c, holder);
            break;
        case I_NEG:
            REG1(c, holder) = -REG1(c, holder);
            break;
        case I_INC:
            REG1(c, holder)++;
            break;
        case I_DEC:
            REG1(c, holder)--;
            break;
        case I_TEST:
            FLAG(c) = (REG1(c, holder) & REG2(c, holder)) ? (FLAG(c) | 0x0001) : (FLAG(c) & 0xFFFE);
            break;
        case I_CMP:
            FLAG(c) = (REG1(c, holder) < REG2(c, holder)) ? (FLAG(c) | 0x0001) : (FLAG(c) & 0xFFFE);
            break;
        case I_EQU:
            FLAG(c) = (REG1(c, holder) == REG2(c, holder)) ? (FLAG(c) | 0x0001) : (FLAG(c) & 0xFFFE);
            break;
        case I_JMP:
            xmem_load(c->pc + 2, tmp);
            c->pc = CAST_SHORT(tmp) - 2;
            break;
        case I_JMPR:
            c->pc = REG1(c, holder) - 2;
            break;
        case I_BR:
            if((FLAG(c) & 0x0001) == 0x001)
                c->pc += (char)holder[1] - 2;
            break;
        case I_CALL:
            c->regs[15] -= 2;
            tmp[0] = (c->pc + 4) >> 8;
            tmp[1] = (c->pc + 4);
            xmem_store(tmp, c->regs[15]);
            xmem_load(c->pc + 2, tmp);
            c->pc = CAST_SHORT(tmp) - 2;
            break;
        case I_CALLR:
            c->regs[15] -= 2;
            tmp[0] = (c->pc + 2) >> 8;
            tmp[1] = c->pc + 2;
            xmem_store(tmp, c->regs[15]);
            c->pc = REG2(c, holder) - 2;
            break;
        case I_LOAD:
            xmem_load(REG1(c, holder), tmp);
            REG2(c, holder) = CAST_SHORT(tmp);
            break;
        case I_STOR:
            tmp[0] = REG1(c, holder) >> 8;
            tmp[1] = REG1(c, holder);
            xmem_store(tmp, REG2(c, holder));
            break;
        case I_PUSH:
            c->regs[15] -= 2;
            tmp[0] = REG1(c, holder) >> 8;
            tmp[1] = REG1(c, holder);
            xmem_store(tmp, c->regs[15]);
            break;
        case I_POP:
            xmem_load(c->regs[15], tmp);
            REG1(c, holder) = CAST_SHORT(tmp);
            c->regs[15] += 2;
            break;
        case I_STORB:
            xmem_load(REG2(c, holder), tmp);
            tmp[0] = REG1(c, holder);
            xmem_store(tmp, REG2(c, holder));
            break;
        case I_LOADB:
            xmem_load(REG1(c, holder), tmp);
            REG2(c, holder) = (unsigned short)(tmp[0]);
            break;
        case I_OUT:
            tmp[0] = REG1(c, holder);
            fprintf(stdout, "%c", tmp[0]);
            break;
        case I_JR:
            c->pc += (char)holder[1] - 2;
            break;
        case I_MOV:
            REG2(c, holder) = REG1(c, holder);
            break;
        case I_BAD:
            return 0;
    }
    //increment program counter
    c->pc += 2;
    //check flag and print
    if(FLAG(c) & (1 << 1)){
        xcpu_print(c);
    }
    return 1;
}

