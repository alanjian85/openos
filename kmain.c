#include "fb.h"
#include "serial.h"

void kmain() {
    serial_init(1, 3);
    fb_clear();
    
    serial_puts(1, "Hello world!\n");
    fb_puts(FB_COLOR_WHITE, "OpenOS\n");
    fb_puts(FB_COLOR_BLUE, "VERSION 1.0.0\n");
    fb_puts(FB_COLOR_YELLOW, "\nHello world\n");
}