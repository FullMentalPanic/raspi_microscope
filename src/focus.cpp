#include <iostream>
#include <string>
#include <sstream>

#include "../include/focus.h"

focus :: focus(video *stream){
    v = stream;
}

focus :: ~focus(){

}

double focus::tenengrad(Mat imageGrey){
    Mat imageSobel;
	Sobel(imageGrey, imageSobel, CV_16U, 1, 1);
	return mean(imageSobel)[0];
}

double focus::laplacian(Mat imageGrey){
    Mat imageSobel;
	Laplacian(imageGrey, imageSobel, CV_16U);
	return mean(imageSobel)[0];
}

double focus::meanstd(Mat imageGrey){
    Mat meanValueImage;
	Mat meanStdValueImage;
    double meanValue = 0.0;
 
	meanStdDev(imageGrey, meanValueImage, meanStdValueImage);
	meanValue = meanStdValueImage.at<double>(0, 0);
    return meanValue*meanValue;
}

void focus::cal_score(int way = 0){    
    Mat imageGrey;
    cvtColor(v->frame, imageGrey, CV_RGB2GRAY);
    switch(way){
        case 0:
            score = tenengrad(imageGrey);
            break;
        case 1:
            score = laplacian(imageGrey);
            break;
        case 2:
            score = meanstd(imageGrey);
            break;
        default:
            score = tenengrad(imageGrey);
    }
}