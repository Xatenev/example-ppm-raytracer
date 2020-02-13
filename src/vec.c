#include <stdlib.h>
#include <stdarg.h>

#include "vec.h"

Vec* vec_create(double x, double y, double z) {
    Vec* v = malloc(sizeof *v);
    v->x = x;
    v->y = y;
    v->z = z;

    return v;
}

Vec* vec_subtract(Vec* v1, Vec* v2) {
    return vec_create(
        v1->x - v2->x,
        v1->y - v2->y,
        v1->z - v2->z
    );
}

void vec_destroy(Vec* vec) {
    free(vec);
    vec = NULL;
}