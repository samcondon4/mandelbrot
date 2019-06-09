#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define WIDTH 1200
#define HEIGHT 800


double mandelbrotSquared(float cx, float ci);
double mandelbrotCubed(float cx, float ci);

double maxIterations = (double)200;
double *maxIterPtr = &maxIterations;

double centerX = (double)-1;
double *centerXPtr = &centerX;

double centerI = (double)0;
double *centerIPtr = &centerI;

double xRange = (double)3;
double *xRangePtr = &xRange;

double iRange;
double scale;


double w = (double)WIDTH;
double h = (double)HEIGHT;


typedef struct Pixel{

        unsigned char r, g, b;

}Pixel;


//Define complexNum struct and function
typedef struct complexNum{

        double cr, ci;

}complexNum;

complexNum ptoComplex(double x, double y);



int main(int argc, char** argv) {

        double *parameters[4] = {maxIterPtr,xRangePtr,centerXPtr,centerIPtr};

        for(int i=1;i<argc;i++){
                *(parameters[i-1]) = atof(argv[i]);
        }

        iRange = (h/w)*xRange;
        scale = iRange/h;
        Pixel ar[WIDTH * HEIGHT] = {0};
        complexNum c;

        for(int y = 0; y < HEIGHT; y++){
                for(int x = 0; x < WIDTH; x++){
                        c = ptoComplex(x,y);
                        double iterations = mandelbrotSquared(c.cr,c.ci);
                        double color = (iterations/maxIterations) * 255;
                        ar[(y * WIDTH) + x].r = (unsigned char)color;
                        ar[(y * WIDTH) + x].g = (unsigned char)color;
                        ar[(y * WIDTH) + x].b = (unsigned char)color;
                }

        }
        stbi_write_png("mandelbrot.png", WIDTH, HEIGHT, 3, ar, WIDTH*3);

}


complexNum ptoComplex(double x, double y){

        complexNum c;
        c.cr = (x*scale) - (xRange/2) + centerX;
        c.ci = ((h - y)*scale) - (iRange/2) + centerI;
        return c;

}


double mandelbrotSquared(float cx, float ci) {

        int iterations = 1;
        double zr = cx;
        double zi = ci;
        double zt;
        while(iterations <= maxIterations && (zr*zr) + (zi*zi) < 10){
                zt = (zr*zr) - (zi*zi) + cx;
                zi = 2*zr*zi + ci;
                zr = zt;
                iterations++;
        }
        return iterations;

}



double mandelbrotCubed(float cx, float ci) {


        int iterations = 1;
        double zr = cx;
        double zi = ci;
        double zt;
        while(iterations <= maxIterations && (zr*zr) + (zi*zi) < 4){
                zt = (zr*zr*zr) - (zi*zi*zr) - (2*zr*zi*zi) + cx;
                zi = (zr*zr*zi)-(zi*zi*zi)+(2*zr*zr*zi) + ci;
                zr = zt;
                iterations++;
        }
        return iterations;


}


                                                                                                                                                                                                                                                                                                                                                                                          126       1,1           Top
