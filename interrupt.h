#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

typedef struct cpu_state {
    uint32_t ebp;
    uint32_t edi;
    uint32_t esi;
    uint32_t edx;
    uint32_t ecx;
    uint32_t ebx;
    uint32_t eax;
} __attribute__((packed)) cpu_state_t;

typedef struct stack_state {
    uint32_t error_code;
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
} __attribute__((packed)) stack_state_t;

void interrupt_handler(cpu_state_t cpu, stack_state_t stack, uint32_t interrupt);

#endif