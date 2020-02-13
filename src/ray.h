#ifndef RAY_H
#define RAY_H

#include "vec.h"

typedef struct Ray
{
    Vec *origin;
    Vec *direction;
} Ray;

Ray *ray_create(Vec *origin, Vec *direction);
void ray_destroy(Ray *ray);

#endif