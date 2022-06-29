#include "fb.h"
#include "serial.h"

void kmain() {
    fb_clear(FB_BLACK);
    serial_init(1, 3);
    serial_puts(1, "Hello world!\n");
    fb_write("Hello world!", 12, FB_BLACK, FB_WHITE);
}