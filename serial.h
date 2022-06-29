#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <stddef.h>

void serial_init(uint8_t port, uint16_t divisor);

void serial_put(uint8_t port, char c);

void serial_puts(uint8_t port, const char* str);

void serial_write(uint8_t port, const char* buf, size_t count);

#endif