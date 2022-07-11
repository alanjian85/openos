#include "fb.h"
#include "serial.h"

void kmain() {
    serial_init(1, 3);
    fb_clear();
    
    serial_puts(1, "[LOG] OpenOS Version 1.0.0 Initialized\n");
    fb_move_cursor(1920);
    fb_puts(FB_COLOR_WHITE, "Hello world\n");
    fb_puts(FB_COLOR_RED, "\nBack\bSpace\n");
    fb_puts(FB_COLOR_YELLOW, "\nDUMMY\rCarriage Return\n");
    fb_puts(FB_COLOR_BLUE, "\nHorizontal\tTab\tDemo\n");
    fb_puts(FB_COLOR_GREEN, "\nVertical\vTab\vDemo\n");
}