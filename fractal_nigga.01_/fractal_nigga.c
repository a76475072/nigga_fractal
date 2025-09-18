#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define LODEPNG_IMPLEMENTATION
#define LODEPNG_COMPILE_PNG
#include "lodepng.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    double complex c = x + y*I;
    double complex z = 0;
    int iter = 0;
    while (cabs(z) < 2.0 && iter < MAX_ITER) {
        z = z*z + c;
        iter++;
    }
    return iter;
}

int main() {
    unsigned char *image = malloc(WIDTH * HEIGHT * 4); // RGBA
    if (!image) return 1;

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            double x0 = (i - WIDTH/2.0) * 17.0 / WIDTH - 0.5;
            double y0 = (j - HEIGHT/2.0) * 2.0 / HEIGHT;
            int iter = mandelbrot(x0, y0);

            int idx = 4 * (j * WIDTH + i);
            if (iter == MAX_ITER) {
                image[idx+0] = 0; // R
                image[idx+1] = 0; // G
                image[idx+2] = 0; // B
            } else {
                image[idx+0] = iter % 256;
                image[idx+1] = (iter*5) % 256;
                image[idx+2] = (iter*13) % 256;
            }
            image[idx+3] = 255; // Alpha
        }
    }

    unsigned error = lodepng_encode32_file("mandelbrot.png", image, WIDTH, HEIGHT);
    if (error) printf("PNG error %u: %s\n", error, lodepng_error_text(error));

    free(image);
    return 0;
}
