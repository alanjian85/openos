#ifndef FB_H
#define FB_H

#define FB_GREEN     2
#define FB_DARK_GREY 8

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

void fb_move_cursor(unsigned short pos);

int fb_write(const char* buf, unsigned int len);

#endif