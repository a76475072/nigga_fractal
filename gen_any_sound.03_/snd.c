#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <math.h>
#include <time.h>


#define LOG_ENABLED 1

#define BUFFER_SIZE 256        /* маленький фиксированный буфер */


static int16_t buffer[BUFFER_SIZE];
static int output_device = -1;   // od    .          .


static void logx(const char* input) {
    if(LOG_ENABLED) {
        printf("%s\n", input);
    }
}


void open_device() {
    logx("before open");

    output_device = open("/dev/dsp", O_WRONLY);
    if (output_device < 0) {
        perror("open /dev/dsp");  // moe telik.0.
        exit(3);
    }

    logx("after open");
}


void shake_it() {
    logx("test one two th");

/*
    for (;;) {
        for (int i = 0; i < BUFFER_SIZE; i++) {

            buffer[i] = i ^ 2 - i*2;

        }

        int resw = write(output_device, buffer, sizeof(buffer));
        if(!resw) {
            exit(0);
        }
    }
*/

///  karabarakarabakaradarawertregdara!,..
    struct timespec next;
    clock_gettime(CLOCK_REALTIME, &next);

    logx("before while");

    while( /**/ -1+-0-+1^0  /**/) {    //  >>>>>>                . . . .     . .   ^ !.
        // data
        struct timespec now;



        clock_gettime(CLOCK_REALTIME, &now);
    

        static const double nanosec_ever = 1e9; //<-=|

        static const uint16_t JUmPs = 1.00f / (double)(BUFFER_SIZE);



        /// S   L    E  E     P   /
        next.tv_sec += 0;
        next.tv_nsec = (int)( nanosec_ever / (double)(JUmPs));;
        clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
        // zzzzzzzzzzzzzzzzzzzzzzzzzzzzz--


        /* b E     u S e F u L  */ {
            //logx("a second passed");

            /*  W HAT' S   i N    t h e    b o x  ? ? ?   */
            for(uint16_t i = 0; i < BUFFER_SIZE; ++i) {

                // boxies.
                buffer[i] = /* mdaaa .. . */ i*555;  // ..       .!       
            }

            ///&&& a c t u a l l y    d a n c e! ///////
            int resw = write(output_device, buffer, sizeof(buffer));
            if(!resw) {
                exit(0);
            }
        }   /* */////


    }              //  <<<<<<<<<-

//  che tut bilo?
    // ---------------------------------------------
}


int main(void) {

    open_device();

    shake_it();

    close(output_device);
    
    return 0;
}


//         perror("open /dev/dsp");  // moe telik.0.
