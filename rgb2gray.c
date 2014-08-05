#include "rgb2gray.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <math.h>

typedef unsigned char uchar;

void
rgb2gray_average(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        data[i*gws + j] = ((int)p[0] + (int)p[1] + (int)p[2]) / 3;
                }
        }
}

static uchar
max3(uchar a, uchar b, uchar c) {
        return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

static uchar
min3(uchar a, uchar b, uchar c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

void
rgb2gray_max(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        data[i*gws + j] = max3(p[0], p[1], p[2]);
                }
        } 
}

void
rgb2gray_lightness(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        data[i*gws + j] = (max3(p[0], p[1], p[2]) + min3(p[0], p[1], p[2]))/ 2;
                }
        }
}

void
rgb2gray_luminosity_1(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        const int t = cvRound(0.2126 * p[2] + 0.7152 * p[1] + 0.0722 * p[0]);
                        data[i*gws + j] = t > 255 ? 255 : t < 0 ? 0 : t;
                }
        }
}


void
rgb2gray_luminosity_2(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        const int t = cvRound(0.3 * p[2] + 0.59 * p[1] + 0.11 * p[0]);
                        data[i*gws + j] = t > 255 ? 255 : t < 0 ? 0 : t;
                }
        }
}


void
rgb2gray_luminosity_3(const IplImage *img, IplImage *gray) {
        uchar *data = (uchar *)gray->imageData;
        
        const int iws = img->widthStep;
        const int gws = gray->widthStep;
        
        for (int i = 0; i < img->height; ++i) {
                for (int j = 0; j < img->width; ++j) {
                        const unsigned char *p = (const uchar *)img->imageData + i*iws + 3*j;
                        const int t = cvRound(0.299 * p[2] + 0.587 * p[1] + 0.114 * p[0]);
                        data[i*gws + j] = t > 255 ? 255 : t < 0 ? 0 : t;
                }
        }
}
