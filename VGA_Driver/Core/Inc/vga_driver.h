#ifndef vga_driver_h
#define vga_driver_h

extern int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved); // fontsize:1 small, 2 big
extern int API_draw_line (int x1, int y1, int x_2, int y2, int colour, int thickness, int reserved);
extern int API_draw_rectangle (int x, int y, int width, int height, int colour, int filled, int reserved1, int reserved2); // e.g.: weight, bordercolor
extern int API_draw_polygon (int x, int y, int corners, int colour, int filled);
extern int API_draw_bitmap (int x_lup, int y_lup, int bm_nr);
extern int API_clearscreen (char *color);
extern unsigned long hash(char *str);
// extern double fast_cos(int angle);
// extern double fast_sin(int angle);

#endif /* vga_driver_h */