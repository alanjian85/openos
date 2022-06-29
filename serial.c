#include "serial.h"

#include "io.h"

#define SERIAL_DATA_PORT(port)          (ports_base[port - 1])
#define SERIAL_FIFO_COMMAND_PORT(port)  (ports_base[port - 1] + 2)
#define SERIAL_LINE_COMMAND_PORT(port)  (ports_base[port - 1] + 3)
#define SERIAL_MODEM_COMMAND_PORT(port) (ports_base[port - 1] + 4)
#define SERIAL_LINE_STATUS_PORT(port)   (ports_base[port - 1] + 5)

#define SERIAL_LINE_ENABLE_DLAB         0x80

static uint16_t ports_base[8] = {
     0x3F8, 0x2F8, 0x3E8, 0x2E8, 0x5F8, 0x4F8, 0x5E8, 0x4E8
};

void serial_init(uint8_t port, uint16_t divisor) {
     outb(SERIAL_LINE_COMMAND_PORT(port), SERIAL_LINE_ENABLE_DLAB);
     outb(SERIAL_DATA_PORT(port), (divisor >> 8) & 0x00FF);
     outb(SERIAL_DATA_PORT(port), divisor & 0x00FF);

     outb(SERIAL_LINE_COMMAND_PORT(port), 0x03);
     outb(SERIAL_FIFO_COMMAND_PORT(port), 0xC7);
     outb(SERIAL_MODEM_COMMAND_PORT(port), 0x03);
}

void serial_put(uint8_t port, char c) {
     while (!(inb(SERIAL_LINE_STATUS_PORT(port)) & 0x20)) {
          
     }

     outb(SERIAL_DATA_PORT(port), c);
}

void serial_puts(uint8_t port, const char* str) {
     while (*str != '\0') {
          serial_put(port, *str);
          ++str;
     }
}

void serial_write(uint8_t port, const char* buf, size_t count) {
     for (unsigned int i = 0; i < count; ++i) {
          serial_put(port, buf[i]);
     }
}