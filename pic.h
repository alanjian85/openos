#ifndef PIC_H
#define PIC_H

#include <stdint.h>

void pic_init();

void pic_ack(uint32_t interrupt);

#endif