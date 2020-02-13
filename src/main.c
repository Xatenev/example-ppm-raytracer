#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "color.h"
#include "ray.h"
#include "vec.h"
#include "sphere.h"
#include "ppm.h"

#define PPM_NAME "out.ppm"   // Filename of output ppm
#define WIDTH 500  // Image width
#define HEIGHT 500 // Image height

int main(int argc, char *argv[])
{

    // Initialize ppm
    char ppm_header[BUFSIZ];
    Ppm *ppm = ppm_create(PPM_NAME);
    sprintf(ppm_header, "P3\n%d\n%d\n%d\n", WIDTH, HEIGHT, 255);

    ppm_write(ppm,ppm_header);

    Color *pixel_col[HEIGHT][WIDTH];

    Color *white = color_create(255, 255, 255);
    Color *black = color_create(0, 0, 0);

    Vec *sphere_origin = vec_create(WIDTH / 2, HEIGHT / 2, 50);
    Sphere *sphere = sphere_create(sphere_origin, 50);

    // For each pixel
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Send a ray through each pixel, start at x,y of the pixel and send it towards z=1
            Vec *origin = vec_create(x,y,0);
            Vec *direction = vec_create(0,0,1);

            Ray* ray = ray_create(origin, direction);

            double t = 20000;
            // Check for intersections
            if(sphere_intersect(sphere, ray, &t)) {
                // Color the pixel
                pixel_col[y][x] = white;
            } else {
                pixel_col[y][x] = black;
            }

            char r[BUFSIZ], g[BUFSIZ], b[BUFSIZ];
            sprintf(r, "%d\n", pixel_col[y][x]->r);
            sprintf(g, "%d\n", pixel_col[y][x]->g);
            sprintf(b, "%d\n", pixel_col[y][x]->b);
            ppm_write(ppm, r);
            ppm_write(ppm, g);
            ppm_write(ppm, b);

            ray_destroy(ray);
            vec_destroy(origin);
            vec_destroy(direction);
        }
    }

    sphere_destroy(sphere);
    vec_destroy(sphere_origin);
    color_destroy(white);
    color_destroy(black);

    return 0;
}