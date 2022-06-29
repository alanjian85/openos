#include "fb.h"

#include "io.h"

#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT    0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

static char *fb = (char*) 0x000B8000;
static fb_color_t fb_bg = FB_COLOR_BLACK;
static uint16_t fb_cursor = 0;

void fb_set_bg(fb_color_t bg) {
    fb_bg = bg;
    for (uint16_t i = 0; i < 2000; ++i) {
        fb[(i << 1) | 1] = ((bg & 0x0F) << 4) | (fb[(i << 1) | 1] & 0x0F);
    }
}

void fb_clear() {
    for (uint16_t i = 0; i < 2000; ++i) {
        fb[i << 1] = ' ';
        fb[(i << 1) | 1] = ((fb_bg & 0x0F) << 4) | (FB_COLOR_WHITE & 0x0F);
    }
}

void fb_write_pos(uint16_t pos, fb_color_t fg, char c) {
    fb[pos << 1] = c;
    fb[(pos << 1) | 1] = ((fb_bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_move_cursor(uint16_t pos) {
    fb_cursor = pos;
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (pos >> 8) & 0x00FF);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_put(fb_color_t fg, char c) {
    if (c == '\n') {
        fb_move_cursor((fb_cursor) / 80 * 80 + 80);
    } else {
        fb_write_pos(fb_cursor, fg, c);
        fb_move_cursor(fb_cursor + 1);
    }
}

void fb_puts(fb_color_t fg, const char* str) {
    while (*str != '\0') {
        fb_put(fg, *str);
        ++str;
    }
}

void fb_write(fb_color_t fg, const void* buf, size_t count) {
    for (unsigned int i = 0; i < count; ++i) {
        fb_put(fg, *((const char*) buf + i));
    }
}