#include <iostream>
#include <string>
#include <sstream>

#include "../include/focus.h"

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
    cvtColor(this->frame, imageGrey, CV_RGB2GRAY);
    switch(way){
        case 0:
            this->score = tenengrad(imageGrey);
            break;
        case 1:
            this->score = laplacian(imageGrey);
            break;
        case 2:
            this->score = meanstd(imageGrey);
            break;
        default:
            this->score = tenengrad(imageGrey);
    }
}

void focus::test(){
    if (!this->open_camera()){
        cout << "can not open camera"<< std::endl;
        return;
    }
    namedWindow("Video", 1);
    while(1)
	{
        if (this->singleframe()){
            imshow("Video", this->frame);
            this->cal_score();
            cout << "score = "<< this->score << std::endl;

        }


		if (waitKey(30) >= 0) break;
	}
    this->close_camera();
}