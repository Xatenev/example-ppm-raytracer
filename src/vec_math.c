#include <stdlib.h>
#include <stdarg.h>

#include "vec.h"
#include "vec_math.h"

double dot_product(Vec *v1, Vec *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}