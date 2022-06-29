#include "fb.h"

int write(const char* buf, unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
        fb_write_cell(i * 2, buf[i], FB_GREEN, FB_DARK_GREY);
        fb_move_cursor(i + 1);
    }
    return 0;
}

void kmain() {
    fb_move_cursor(0);
    write("Hello world!", 12);
}