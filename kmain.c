#include "fb.h"
#include "serial.h"

void kmain() {
    serial_init(1, 3);
    fb_clear();
    
    serial_puts(1, "Hello world!\n");
    fb_move_cursor(1920);
    fb_puts(FB_COLOR_WHITE, "Hello\vWorld\vVersion\v1.0.0\n");
}