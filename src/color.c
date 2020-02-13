#include <stdlib.h>
#include <stdarg.h>

#include "color.h"


Color *color_create(int r, int g, int b)
{
    Color *c = malloc(sizeof *c);
    c->r = r;
    c->g = g;
    c->b = b;

    return c;
}

void color_destroy(Color *color)
{
    free(color);
    color = NULL;
}