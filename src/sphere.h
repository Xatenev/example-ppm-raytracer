#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>
#include "vec.h"
#include "ray.h"

typedef struct Sphere
{
    Vec *center;
    double radius;
} Sphere;

Sphere *sphere_create(Vec *center, double radius);
bool sphere_intersect(Sphere *sphere, Ray* ray, double t);
void sphere_destroy(Sphere *sphere, ...);

#endif