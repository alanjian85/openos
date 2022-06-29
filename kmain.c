#include "fb.h"
#include "serial.h"

void kmain() {
    serial_init(SERIAL_COM1_BASE);
    serial_write("Hello world!\n", 13);
    fb_write("Hello world!", 12);
}