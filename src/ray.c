#include <stdlib.h>
#include <stdarg.h>

#include "ray.h"

Ray *ray_create(Vec *origin, Vec *direction)
{
    Ray *r = malloc(sizeof *r);
    r->origin = origin;
    r->direction = direction;

    return r;
}

void ray_destroy(Ray *ray, ...)
{
    va_list args;
    va_start(args, ray);
    Ray *r = va_arg(args, Ray *);
    free(r);
    va_end(args);
}