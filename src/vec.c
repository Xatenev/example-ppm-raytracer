#include <stdlib.h>
#include <stdarg.h>

#include "vec.h"

Vec* vec_create() {
    return vec_create_x_y_z(0, 0, 0);
}

Vec* vec_create_x_y_z(double x, double y, double z) {
    Vec* v = malloc(sizeof *v);
    v->x = x;
    v->y = y;
    v->z = z;

    return v;
}

Vec* vec_subtract(Vec* v1, Vec* v2) {
    return vec_create_x_y_z(
        v1->x - v2->x,
        v1->y - v2->y,
        v1->z - v2->z
    );
}

void vec_destroy(Vec* vec, ...) {
    va_list args;
    va_start(args, vec);
    Vec *v = va_arg(args, Vec*);
    free(v);
    v = NULL;
    va_end(args);
}