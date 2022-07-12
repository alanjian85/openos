#include "interrupt.h"

extern void keyboard_interrupt_handler(struct cpu_state cpu, struct stack_state stack);

void interrupt_handler(struct cpu_state cpu, struct stack_state stack, uint32_t interrupt) {
    if (interrupt == 1) {
        keyboard_interrupt_handler(cpu, stack);
    }
}