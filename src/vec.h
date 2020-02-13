#ifndef VEC_H
#define VEC_H

typedef struct Vec {
    double x;
    double y;
    double z;
} Vec;

Vec* vec_create(double x, double y, double z);
Vec* vec_subtract(Vec* v1, Vec* v2);
void vec_destroy(Vec* v);

#endif