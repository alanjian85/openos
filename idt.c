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
    idt_entry_t* base;
} __attribute__((packed)) idt_ptr_t;

void load_idt(idt_ptr_t* idt);

void interrupt_handler_33();

void idt_init() {
    idt_entry_t gdt_entries[256] = {};
    idt_ptr_t idt;
    idt.base = gdt_entries;
    idt.limit = sizeof(gdt_entries);

    gdt_entries[33].offset_low     = (uint32_t) interrupt_handler_33 & 0xFFFF;
    gdt_entries[33].offset_high    = ((uint32_t) interrupt_handler_33 >> 16) & 0xFFFF;
    gdt_entries[33].segsel         = 0x0008;
    gdt_entries[33].zero           = 0;
    gdt_entries[33].config         = 0x8F;

    load_idt(&idt);
}