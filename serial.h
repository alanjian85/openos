#ifndef SERIAL_H
#define SERIAL_H

#define SERIAL_COM1_BASE 0x3F8

void serial_config_baud_rate(unsigned short com, unsigned short divisor);

void serial_init(unsigned short com);

void serial_write(const char* buf, unsigned int len);

#endif