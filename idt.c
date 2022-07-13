#include "idt.h"

#include <stdint.h>

typedef struct idt_gate {
    uint16_t offset_low;
    uint16_t segsel;
    uint8_t zero;
    uint8_t config;
    uint16_t offset_high;
} __attribute__((packed)) idt_gate_t;

typedef struct idt {
    uint16_t size;
    idt_gate_t* addr;
} __attribute__((packed)) idt_t;

void load_idt(idt_t* idt);

void interrupt_handler_33();

void idt_init() {
    idt_gate_t gates[256] = {};
    idt_t idt;
    idt.addr = gates;
    idt.size = sizeof(gates);

    gates[33].offset_low     = (uint32_t) interrupt_handler_33 & 0xFFFF;
    gates[33].offset_high    = ((uint32_t) interrupt_handler_33 >> 16) & 0xFFFF;
    gates[33].segsel         = 0x0008;
    gates[33].zero           = 0;
    gates[33].config         = 0x8F;

    load_idt(&idt);
}