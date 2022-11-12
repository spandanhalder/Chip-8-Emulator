#ifndef CHIP8STACK_H
#define CHIP8STACK_H
#include "config.h"

struct chip8; // Not including chip8.h to avoid loop
struct chip8_stack
{
    unsigned short stack[CHIP8_TOTAL_STACK_DEPTH];
};

void chip8_stack_push(struct chip8 *chip8, unsigned short val);
unsigned short chip8_stack_pop(struct chip8 *chip8);

#endif