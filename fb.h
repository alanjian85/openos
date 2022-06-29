#ifndef FB_H
#define FB_H

#include <stdint.h>
#include <stddef.h>

typedef enum fb_color {
    FB_COLOR_BLACK = 0x0,
    FB_COLOR_GREEN = 0x2,
    FB_COLOR_DARK_GREY = 0x8,
    FB_COLOR_WHITE = 0xF
} fb_color_t;

void fb_set_bg(fb_color_t bg);

void fb_clear();

void fb_write_pos(uint16_t pos, fb_color_t fg, char c);

void fb_move_cursor(uint16_t pos);

void fb_put(fb_color_t fg, char c);

void fb_puts(fb_color_t fg, const char* str);

void fb_write(fb_color_t fg, const void* buf, size_t count);

#endif