#include "idt.h"

#include <stdint.h>

typedef struct idt_gate {
    uint16_t offset_low;
    uint16_t segsel;
    uint8_t zero;
    uint8_t config;
    uint16_t offset_high;
} __attribute__((packed)) idt_gate_t;

typedef struct idt_ref {
    uint16_t limit;
    idt_gate_t* base;
} __attribute__((packed)) idt_ref_t;

void load_idt(idt_ref_t* idt);

void interrupt_handler_1();

void idt_init() {
    idt_gate_t gates[256] = {};
    idt_ref_t idt;
    idt.limit = sizeof(gates);
    idt.base = gates;
    
    gates[1].offset_low     = (uint32_t) interrupt_handler_1 & 0xFFFF;
    gates[1].offset_high    = ((uint32_t) interrupt_handler_1 >> 16) & 0xFFFF;
    gates[1].segsel         = 0x0008;
    gates[1].zero           = 0;
    gates[1].config         = 0x8F;

    load_idt(&idt);
}