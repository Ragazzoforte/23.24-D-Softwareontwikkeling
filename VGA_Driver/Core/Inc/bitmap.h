/**
 * @file bitmap.h
 * @author Michel Vollmuller (michel.vollmuller@student.hu.nl)
 * @author Tim Wannet (tim.wannet@student.hu.nl)
 * @author Tijmen Willems (tijmen.willems@student.hu.nl)
 * @brief headerfile of bitmap.c
 * @version 0.1
 * @date 05-06-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef bitmap_h
#define bitmap_h


#define MEGAMAN_WIDTH  21
#define MEGAMAN_HEIGHT  24

#define SMILEY_WIDTH  40
#define SMILEY_HEIGHT  40

#define ARROW_UP_WIDTH  27
#define ARROW_UP_HEIGHT  41

#define ARROW_DOWN_WIDTH  27
#define ARROW_DOWN_HEIGHT  41

#define ARROW_LEFT_WIDTH  41
#define ARROW_LEFT_HEIGHT  27

#define ARROW_RIGHT_WIDTH  41
#define ARROW_RIGHT_HEIGHT  27

#define MICHIEL_WIDTH  320
#define MICHIEL_HEIGHT  213

#define FRANC_WIDTH  240
#define FRANC_HEIGHT  240

#define GROEP_WIDTH  320
#define GROEP_HEIGHT  200



extern const uint8_t megaman[];
extern const uint8_t megaman_2[MEGAMAN_WIDTH * MEGAMAN_HEIGHT];
extern const uint8_t smiley_happy[SMILEY_WIDTH * SMILEY_HEIGHT];
extern const uint8_t smiley_sad[SMILEY_WIDTH * SMILEY_HEIGHT];
extern const uint8_t arrow_up[ARROW_UP_WIDTH * ARROW_UP_HEIGHT];
extern const uint8_t arrow_down[ARROW_DOWN_WIDTH * ARROW_DOWN_HEIGHT];
extern const uint8_t arrow_left[ARROW_LEFT_WIDTH * ARROW_LEFT_HEIGHT];
extern const uint8_t arrow_right[ARROW_RIGHT_WIDTH * ARROW_RIGHT_HEIGHT];
extern const uint8_t michiel[MICHIEL_WIDTH * MICHIEL_HEIGHT];
extern const uint8_t franc[FRANC_WIDTH * FRANC_HEIGHT];
extern const uint8_t groep[GROEP_WIDTH * GROEP_HEIGHT];


#endif /* bitmap.h */