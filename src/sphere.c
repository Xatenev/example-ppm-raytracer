#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "vec_math.h"
#include "vec.h"
#include "sphere.h"

Sphere *sphere_create(Vec *center, double radius)
{
    Sphere *s = malloc(sizeof *s);
    s->center = center;
    s->radius = radius;

    return s;
}

bool sphere_intersect(Sphere *sphere, Ray *ray, double t)
{
    Vec *origin = ray->origin;
    Vec *direction = ray->direction;
    Vec *sphere_center = sphere->center;

    Vec *oc = vec_subtract(origin, sphere_center);

    // @TODO: understand this
    double b = 2 * dot_product(oc, direction);
    double c = dot_product(oc, oc);
    double disc = b * b - 4 * c;

    if (disc < 0)
        return false;
    else
    {
        disc = sqrt(disc);
        double t0 = -b - disc;
        double t1 = -b + disc;

        t = t0 < t1 ? t0 : t1;

        return true;
    }

    return false;
}

void sphere_destroy(Sphere *sphere, ...)
{
    va_list args;
    va_start(args, sphere);
    Sphere *s = va_arg(args, Sphere *);
    free(s);
    va_end(args);
}