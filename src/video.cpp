#include <iostream>
#include <string>
#include <sstream>

#include "../include/video.h"


bool video::open_camera(){
    this->cap.open(0);
    if (!this->cap.isOpened()){
        return false;
    }
		
    return true; 
}

bool video::singleframe(){
	this->cap >> this->frame; 
	if (frame.empty()){
		cout << "can not get frame"<< std::endl;
        return false;
    }
    return true;
}

void video::close_camera(){
	this->cap.release();
}

void video::test(){
    if(!this->open_camera()){
        cout << "can not open camera"<< std::endl;
        return;
    }
    namedWindow("Video", 1);
    while(1)
	{
        if (this->singleframe())
		    imshow("Video", this->frame);
		if (waitKey(30) >= 0) break;
	}
    this->close_camera();
}