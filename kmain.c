#include "fb.h"
#include "serial.h"

void kmain() {
    fb_clear(FB_BLACK);
    serial_init(SERIAL_COM1_BASE);
    serial_write("Hello world!\n", 13);
    fb_write("Hello world!", 12, FB_BLACK, FB_WHITE);
}