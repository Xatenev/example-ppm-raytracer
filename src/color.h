#ifndef COLOR_H
#define COLOR_H


typedef struct Color
{
    int r;
    int g;
    int b;
} Color;

Color *color_create(int r, int g, int b);
void color_destroy(Color *color);

#endif