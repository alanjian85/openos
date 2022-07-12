#include "pic.h"

#include "io.h"

#define PIC1_PORT_A 0x20
#define PIC1_PORT_B 0x21
#define PIC2_PORT_A 0xA0
#define PIC2_PORT_B 0xA1

#define PIC1_ICW1 0x11
#define PIC1_ICW2 0x20
#define PIC1_ICW3 0x04
#define PIC1_ICW4 0x01

#define PIC2_ICW1 0x11
#define PIC2_ICW2 0x28
#define PIC2_ICW3 0x02
#define PIC2_ICW4 0x01

#define PIC1_START_INTERRUPT PIC1_ICW2
#define PIC2_START_INTERRUPT PIC2_ICW2
#define PIC2_END_INTERRUPT   PIC2_START_INTERRUPT + 7

#define PIC_ACK 0x20

void pic_init() {
    outb(PIC1_PORT_A, PIC1_ICW1);
    outb(PIC1_PORT_A, PIC2_ICW1);

    outb(PIC1_PORT_B, PIC1_ICW2);
    outb(PIC1_PORT_B, PIC2_ICW2);

    outb(PIC1_PORT_B, PIC1_ICW3);
    outb(PIC1_PORT_B, PIC2_ICW3);

    outb(PIC1_PORT_B, PIC1_ICW4);
    outb(PIC1_PORT_B, PIC2_ICW4);

    outb(PIC1_PORT_B, 0xEC);
    outb(PIC2_PORT_B, 0xFF);
}

void pic_ack(uint32_t interrupt) {
    if (PIC1_START_INTERRUPT <= interrupt && interrupt <= PIC2_END_INTERRUPT) {
        if (interrupt >= PIC2_START_INTERRUPT) {
            outb(PIC2_PORT_A, PIC_ACK);
        }
        outb(PIC1_PORT_A, PIC_ACK);
    }
}