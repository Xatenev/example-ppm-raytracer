#ifndef RAY_H
#define RAY_H

#include "vec.h"

typedef struct Ray {
    Vec* origin;
    Vec* direction;
} Ray;

#endif