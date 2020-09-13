#include "../include/video.h"

video::video(){
    cap.open(0); //open default camera
    if (!cap.isOpened()){
        throw std::invalid_argument("can not open device");
    }
}

video::~video(){
    cap.release();
}
bool video::singleframe(){
	cap >> frame; 
	if (frame.empty()){
		cout << "can not get frame"<< std::endl;
        return false;
    }
    return true;
}

void video::pipedframe(){
    std::vector<uchar> buff;    
    imencode(".jpg", frame, buff);
    vector<uchar> :: iterator i;
    for (i = buff.begin(); i != buff.end(); ++i)
        std::cout << *i ;
}

void video::outputframe(){
    while(1)
	{
        if (singleframe())
		    pipedframe();
		if (waitKey(30) >= 0) break;
	}
}

void video::test(){
    namedWindow("Video", 1);
    while(1)
	{
        if (singleframe())
		    imshow("Video", frame);
		if (waitKey(30) >= 0) break;
	}
}
