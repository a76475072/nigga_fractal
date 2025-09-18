#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include <math.h>

#define W 800
#define H 600
#define MAXI 500

int fractal(double x0,double y0)
{
    double x=x0,y=y0;
    int i=0;
    while(i<MAXI){
        double xt=x*x - y*y + sin(y0*3.14);
        double yt=fabs(2*x*y) + cos(x0*3.14);
        if(xt*xt+yt*yt>100) break;
        x=xt;
        y=yt;
        i++;
    }
    return i;
}

int main()
{
    unsigned char *img=(unsigned char*)malloc(W*H*4);
    int x,y;
    for(y=0;y<H;y++)
      for(x=0;x<W;x++){
          double cx=(x-W/2.0)*3.0/W;
          double cy=(y-H/2.0)*2.0/H;
          int it=fractal(cx,cy);
          int idx=4*(y*W+x);
          img[idx+0]=(it*7)%256;
          img[idx+1]=(it*13)%256;
          img[idx+2]=(it*19)%256;
          img[idx+3]=255;
      }
    if(lodepng_encode32_file("unique_fractal.png",img,W,H))
        fprintf(stderr,"error\n");
    free(img);
    return 0;
}
