#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <stddef.h>

#define SERIAL_COM1_BASE 0x3F8

void serial_config_baud_rate(uint16_t com, uint16_t divisor);

void serial_init(uint16_t com);

void serial_write(const char* buf, size_t len);

#endif