#ifndef vga_driver_h
#define vga_driver_h

int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved); // fontsize:1 small, 2 big
int API_draw_line (int x_1, int y_1, int x_2, int y2, int color, int weight, int reserved);
int API_draw_rectangle (int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2); // e.g.: weight, bordercolor
int API_draw_bitmap (int x_lup, int y_lup, int bm_nr);
int API_clearscreen (int color);

#endif /* vga_driver_h */