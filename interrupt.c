#include "interrupt.h"

#include "serial.h"

extern void keyboard_interrupt_handler(struct cpu_state cpu, struct stack_state stack);

void interrupt_handler(struct cpu_state cpu, struct stack_state stack, uint32_t interrupt) {
    serial_puts(1, "[LOG] Interrupt!");
    if (interrupt == 0x21) {
        keyboard_interrupt_handler(cpu, stack);
    }
}