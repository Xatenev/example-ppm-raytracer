#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ray.h"
#include "vec.h"

#define WIDTH 500  // Image width
#define HEIGHT 500 // Image height

int main(int argc, char *argv[])
{
    // For each pixel
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Send a ray through each pixel, start at x,y of the pixel and send it towards z=1
            Vec *origin = vec_create_x_y_z(x,y,0);
            Vec *direction = vec_create_x_y_z(0,0,1);

            Ray* ray = ray_create(origin, direction);

            // Check for intersections
            if(sphere_intersect(ray, t)) {
                
            }
            //ray

            ray_destroy(ray);
            vec_destroy(origin, direction);
        }
    }


    return 0;
}