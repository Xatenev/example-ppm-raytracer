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

void ray_destroy(Ray *ray)
{
    free(ray);
    ray = NULL;
}