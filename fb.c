#include "fb.h"

#include "io.h"

#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT    0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

static char *fb = (char*) 0x000B8000;

void fb_write_cell(unsigned int i, char c, unsigned char bg, unsigned char fg) {
    fb[i] = c;
    fb[i + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_fill(char c, unsigned char bg, unsigned char fg) {
    for (int i = 0; i < 2000; ++i) {
        fb_write_cell(i << 1, c, bg, fg);
    }
}

void fb_clear(unsigned char bg) {
    fb_fill(' ', FB_BLACK, bg);
}

void fb_move_cursor(unsigned short pos) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (pos >> 8) & 0x00FF);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

int fb_write(const char* buf, unsigned int len, unsigned char bg, unsigned char fg) {
    for (unsigned int i = 0; i < len; ++i) {
        fb_write_cell(i << 1, buf[i], bg, fg);
        fb_move_cursor(i + 1);
    }
    return 0;
}