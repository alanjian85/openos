#include "interrupt.h"

#include "serial.h"
#include "pic.h"

extern void keyboard_interrupt_handler(struct cpu_state cpu, struct stack_state stack);

void interrupt_handler(cpu_state_t cpu, interrupt_state_t interrupt, stack_state_t stack) {
    if (interrupt.interrupt == 0x21) {
        keyboard_interrupt_handler(cpu, stack);
    }
    pic_ack(interrupt.interrupt);
}