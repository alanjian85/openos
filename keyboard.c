#include "keyboard.h"

#include <stdint.h>
#include <stddef.h>

#include "interrupt.h"
#include "io.h"

#define KEYBOARD_BUFFER_SIZE 100

#define KEYBOARD_DATA_PORT 0x60

typedef struct keyboard_fifo {
    uint8_t buffer[KEYBOARD_BUFFER_SIZE];
    uint8_t* head;
    uint8_t* tail;
    size_t size;
} keyboard_fifo_t;

keyboard_fifo_t keyboard_buffer;

void keyboard_interrupt_handler(struct cpu_state cpu, struct stack_state stack) {
    (void) cpu;
    (void) stack;

    if (keyboard_buffer.size < KEYBOARD_BUFFER_SIZE) {
        *keyboard_buffer.tail++ = inb(KEYBOARD_DATA_PORT);
        ++keyboard_buffer.size;
        if (keyboard_buffer.tail == keyboard_buffer.buffer + KEYBOARD_BUFFER_SIZE) {
            keyboard_buffer.tail = keyboard_buffer.buffer;
        }
    }
}

void keyboard_init() {
    keyboard_buffer.head = keyboard_buffer.tail = keyboard_buffer.buffer;
    keyboard_buffer.size = 0;
}

char keyboard_getc() {
    while (keyboard_buffer.size == 0);
    char c = *keyboard_buffer.head++;
    --keyboard_buffer.size;
    if (keyboard_buffer.head == keyboard_buffer.buffer + KEYBOARD_BUFFER_SIZE) {
        keyboard_buffer.head = keyboard_buffer.buffer;
    }
    return c;
}