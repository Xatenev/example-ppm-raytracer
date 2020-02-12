#include <stdlib.h>

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

void vec_destroy(Vec* vec) {
    free(vec);
    vec = NULL;
}