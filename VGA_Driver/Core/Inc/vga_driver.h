#ifndef vga_driver_h
#define vga_driver_h

#define MAX_LEN_FONTNAME 30
#define LETTERA 'a'
#define LETTERC 'c'

#define ARIAL 353
#define CONSOLAS 2

#define NORMAL 1
#define ITALIC 2
#define BOLD 3

#define ARIAL_SMALL_HEIGHT		  10
#define ARIAL_SMALL_ITALIC_HEIGHT 12
#define ARIAL_SMALL_BOLD_HEIGHT   11
#define ARIAL_LARGE_HEIGHT			15
#define ARIAL_LARGE_ITALIC_HEIGHT 	15
#define ARIAL_LARGE_BOLD_HEIGHT 	16

#define SMALL 1
#define LARGE 2
#define ASCII_OFFSET 32
#define BYTE_SIZE 8
#define BITMASK 128
#define ARRAY_DIMENSION 2
#define CHAR_START_OFFSET 1
#define CASE_OFFSET	     32
#define ERROR_FONTNAME   1
#define ERROR_FONTNAME_UNKNOWN 2


int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved); // fontsize:1 small, 2 big
int API_draw_line (int x_1, int y_1, int x_2, int y2, int color, int weight, int reserved);
int API_draw_rectangle (int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2); // e.g.: weight, bordercolor
int API_draw_bitmap (int x_lup, int y_lup, int bm_nr);
int API_clearscreen (char *color);
unsigned long hash(char *str);

#endif /* vga_driver_h */