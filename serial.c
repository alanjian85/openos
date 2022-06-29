#include "io.h"

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

#define SERIAL_LINE_ENABLE_DLAB         0x80

void serial_config_baud_rate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com),
         SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
         (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
         divisor & 0x00FF);
}

int serial_fifo_empty(unsigned short com) {
     return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_write(unsigned short com, unsigned char data) {
     while (!serial_fifo_empty(com)) {
     
     }
     outb(SERIAL_DATA_PORT(com), data);
}

void serial_init(unsigned short com) {
     serial_config_baud_rate(com, 0x03);
     outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
     outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
     outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}