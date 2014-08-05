#include "rgb2gray.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>

int
main(int argc, char **argv) {
        if (argc != 2) {
                return 0;
        }
                
        IplImage *img = cvLoadImage(argv[1], 1);
                
        if (!img) return  0;
        
        IplImage *average = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *lightness = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *luminosity_1 = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *luminosity_2 = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *luminosity_3 = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *opencv = cvCreateImage(cvGetSize(img), 8, 1);
        IplImage *max = cvCreateImage(cvGetSize(img), 8, 1);

        rgb2gray_average(img, average);
        rgb2gray_max(img, max);
        rgb2gray_lightness(img, lightness);
        rgb2gray_luminosity_1(img, luminosity_1);
        rgb2gray_luminosity_2(img, luminosity_2);
        rgb2gray_luminosity_3(img, luminosity_3);

        cvCvtColor(img, opencv, CV_RGB2GRAY);
        
        cvNamedWindow("original", 1);
        cvNamedWindow("average", 1);
        cvNamedWindow("max", 1);
        cvNamedWindow("lightness", 1);
        cvNamedWindow("luminosity_1", 1);
        cvNamedWindow("luminosity_2", 1);
        cvNamedWindow("luminosity_3", 1);
        cvNamedWindow("opencv", 1);

        cvShowImage("original", img);
        cvShowImage("average", average);
        cvShowImage("max", max);
        cvShowImage("lightness", lightness);
        cvShowImage("luminosity_1", luminosity_1);
        cvShowImage("luminosity_2", luminosity_2);
        cvShowImage("luminosity_3", luminosity_3);
        cvShowImage("opencv", opencv);
        
        
        cvWaitKey(0);
        
        cvDestroyWindow("orignal");
        cvDestroyWindow("average");
        cvDestroyWindow("max");
        cvDestroyWindow("lightness");
        cvDestroyWindow("luminosity_1");
        cvDestroyWindow("luminosity_2");
        cvDestroyWindow("luminosity_3");
        cvDestroyWindow("opencv");
        
        cvReleaseImage(&img);
        cvReleaseImage(&opencv);
        cvReleaseImage(&max);
        cvReleaseImage(&average);
        cvReleaseImage(&lightness); 
        cvReleaseImage(&luminosity_1);
        cvReleaseImage(&luminosity_2);
        cvReleaseImage(&luminosity_3);
        
        return 0;
}
