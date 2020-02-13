#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "ppm.h"


Ppm *ppm_create(const char *filepath) {
    Ppm *p = malloc(sizeof *p);    
    p->fp = fopen(filepath, "w");

    return p;
}

void ppm_write(Ppm *ppm, char *text) {
    fprintf(ppm->fp, text);
}

void ppm_destroy(Ppm *ppm) {
    fclose(ppm->fp);
    free(ppm);
    ppm = NULL;
}
  