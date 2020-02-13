#ifndef PPM_H
#define PPM_H

#include <stdio.h>

typedef struct Ppm
{
    FILE *fp;
} Ppm;

Ppm *ppm_create(const char *filepath);
void ppm_write(Ppm *ppm, char *text);
void ppm_destroy(Ppm *ppm);

#endif