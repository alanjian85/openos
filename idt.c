#include "idt.h"

#include <stdint.h>

typedef struct idt_entry {
    uint16_t offset_low;
    uint16_t segsel;
    uint8_t zero;
    uint8_t config;
    uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void load_idt(idt_ptr_t* idt);

void interrupt_handler_33();

void idt_init() {
    idt_entry_t idt_entries[256] = {};
    idt_ptr_t idt;
    idt.base = (uint32_t) idt_entries;
    idt.limit = sizeof(idt_entries) - 1;

    idt_entries[33].offset_low     = (uint32_t) interrupt_handler_33 & 0xFFFF;
    idt_entries[33].offset_high    = ((uint32_t) interrupt_handler_33 >> 16) & 0xFFFF;
    idt_entries[33].segsel         = 0x0008;
    idt_entries[33].zero           = 0x00;
    idt_entries[33].config         = 0x8F;

    load_idt(&idt);
}