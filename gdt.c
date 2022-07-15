#include "gdt.h"

#include <stdint.h>

typedef struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_mid;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct gdt_ptr {
    uint16_t limit;
    gdt_entry_t* base;
} __attribute__((packed)) gdt_ptr_t;

void load_gdt(gdt_ptr_t* idt);

void gdt_init() {
    gdt_entry_t gdt_entries[3] = {};
    gdt_ptr_t gdt_ptr;
    gdt_ptr.base = gdt_entries;
    gdt_ptr.limit = sizeof(gdt_entries);

    gdt_entries[1].base_low = 0;
    gdt_entries[1].base_mid = 0;
    gdt_entries[1].base_high = 0;
    gdt_entries[1].limit_low = 0xFFFF;
    gdt_entries[1].granularity = (0x01 << 7) | (0x01 << 6) | 0x0F;
    gdt_entries[1].access = (0x01 << 7) | (0x01 << 4) | 0xA;

    gdt_entries[2].base_low = 0;
    gdt_entries[2].base_mid = 0;
    gdt_entries[2].base_high = 0;
    gdt_entries[2].limit_low = 0xFFFF;
    gdt_entries[2].granularity = (0x01 << 7) | (0x01 << 6) | 0x0F;
    gdt_entries[2].access = (0x01 << 7) | (0x01 << 4) | 0x2;

    load_gdt(&gdt_ptr);
}