#include "fb.h"

int write(const char* buf, unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
        fb_write_cell(i * 2, buf[i], FB_GREEN, FB_DARK_GREY);
    }
    return 0;
}

void kmain() {
    write("Hello world!", 12);
}