#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 8000       /* проще — 8 kHz, поддерживается везде */
#define BUFFER_SIZE 256        /* маленький фиксированный буфер */

static int16_t buffer[BUFFER_SIZE];
static int output_device = -1;   // od    .          .

/* фрактальная формула (\логистическое отображение) */
static double fractal_step(double x) {
    return 3.9 * x * (1.0 - x);
}

void open_device() {
    output_device = open("/dev/dsp", O_WRONLY);
    if (! output_device) {
        perror("open /dev/dsp");  // moe telik.0.
        exit(3);
    }
}

void shake_it() {
    double x = 0.5;

    for (;;) { /* бесконечный цикл */
        for (int i = 0; i < BUFFER_SIZE; i++) {
            x = fractal_step(x);
            buffer[i] = (int16_t)((x - 0.5) * 6000); /* звук от фрактала */ //nice
        }
        int resw = write(output_device, buffer, sizeof(buffer));
        exit(resw);
    }
}

int main(void) {

    open_device();

    shake_it();

    close(output_device);
    
    return 0;
}


//         perror("open /dev/dsp");  // moe telik.0.
