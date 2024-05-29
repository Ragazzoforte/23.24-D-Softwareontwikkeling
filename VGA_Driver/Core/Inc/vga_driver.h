/*
 * vga_driver.h
 *    Author: Michel Vollmuller
 */

#ifndef vga_driver_h
#define vga_driver_h

#define SMILEY_HAPPY 1
#define SMILEY_SAD 2
#define ARROW_UP 3
#define ARROW_RIGHT 4
#define ARROW_DOWN 5
#define ARROW_LEFT 6
#define MEGAMAN 7
#define MAX_LEN_FONTNAME 30
#define LETTERA 'a'
#define LETTERC 'c'

#define arial_hash 510602739
#define Arial_hash 472653267
#define ARIAL_hash 471467347
#define consolas_hash 1405698636
#define Consolas_hash 3415123500
#define CONSOLAS_hash 3746353484

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

extern int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved); // fontsize:1 small, 2 big
extern int API_draw_line (int x1, int y1, int x_2, int y2, int colour, int thickness, int reserved);
extern int API_draw_rectangle (int x, int y, int width, int height, int colour, int filled, int reserved1, int reserved2); // e.g.: weight, bordercolor
extern int API_draw_polygon (int x, int y, int size, int corners, int colour, int filled);
extern int API_draw_bitmap (int x_lup, int y_lup, int bm_nr);
extern int API_clearscreen (int colour);
extern unsigned long hash(char *str);
extern uint8_t color_chooser(char *str);
#endif /* vga_driver_h */