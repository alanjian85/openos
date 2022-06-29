#ifndef FB_H
#define FB_H

#include <stdint.h>
#include <stddef.h>

#define FB_BLACK     0x0
#define FB_GREEN     0x2
#define FB_DARK_GREY 0x8
#define FB_WHITE     0xF

void fb_write_cell(uint16_t i, char c, uint8_t bg, uint8_t fg);

void fb_fill(char c, uint8_t bg, uint8_t fg);

void fb_clear(uint8_t bg);

void fb_move_cursor(uint16_t pos);

int fb_write(const char* buf, size_t len, uint8_t bg, uint8_t fg);

#endif