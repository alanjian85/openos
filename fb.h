#ifndef FB_H
#define FB_H

#define FB_BLACK     0x0
#define FB_GREEN     0x2
#define FB_DARK_GREY 0x8
#define FB_WHITE     0xF

void fb_write_cell(unsigned int i, char c, unsigned char bg, unsigned char fg);

void fb_fill(char c, unsigned char bg, unsigned char fg);

void fb_clear(unsigned char bg);

void fb_move_cursor(unsigned short pos);

int fb_write(const char* buf, unsigned int len, unsigned char bg, unsigned char fg);

#endif