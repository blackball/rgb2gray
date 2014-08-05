#include "rgb2gray.h"
#include <math.h>

void
gamma_correction(const IplImage *in, IplImage *out, double gamma) {
        unsigned char lut[256];
        
        for( int i = 0; i < 256; i++ ) {
                const int t = cvRound(pow( (double) i / 255.0, inverse_gamma ) * 255.0 );
                ptr[i] = t > 255 ? 255 : t < 0 ? 0 : t;
        }

        const int h = in->height;
        const int w = in->width;
        const int iws = in->widthStep;
        const int ows = out->widthStep;
        const int channels = in->nChannels;
        
        for (int i = 0; i < h; ++i) {
                for (int j = 0; j < h; ++j) {
                        for (int k = 0; k < channels; ++k) {
                                out->imageData[i*ows + j*channels + k] = lut[(unsigned char)in->imageData[i*iws +j*channels + k]];
                        }
                }
        }
}
