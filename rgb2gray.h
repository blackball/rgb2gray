#ifndef RGB2GRAY_H
#define RGB2GRAY_H

typedef struct _IplImage IplImage;

void gamma_correction(const IplImage *in, IplImage *out, double gamma);

/* v = (r+g+b)/3 */
void rgb2gray_average(const IplImage *img, IplImage *gray);

/* v = max(r,g,b) */
void rgb2gray_max(const IplImage *img, IplImage *gray);

/* v = (max(r,g,b) + min(r,g,b)) / 2 */
void rgb2gray_lightness(const IplImage *img, IplImage *gray);

/* v = 0.2126 * b + 0.7152 * g + 0.0722 * r */
void rgb2gray_luminosity_1(const IplImage *img, IplImage *gray);

/* v = 0.3 * b + 0.59 * g + 0.11 * r  */
void rgb2gray_luminosity_2(const IplImage *img, IplImage *gray);

/* v = 0.299 * b + 0.587 * g + 0.114 * r */
void rgb2gray_luminosity_3(const IplImage *img, IplImage *gray); 

#endif 
