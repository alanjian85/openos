#include "fb.h"
#include "serial.h"

void kmain() {
    fb_clear();
    serial_init(1, 3);
    serial_puts(1, "Hello world!\n");
    fb_write(FB_COLOR_WHITE, "Hello world! ", 13);
    fb_write(FB_COLOR_GREEN, "VERSION 1.0.0", 13);
}