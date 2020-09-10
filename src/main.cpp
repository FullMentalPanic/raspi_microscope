#include "../include/focus.h"

#include <iostream>
#include <string>
#include <sstream>


int main(int argc, const char** argv){
    video v;
    focus a(&v);
    //if(!v.open_camera()){
    //    cout << "can not open camera"<< std::endl;
    //    return -1;
    //}
    namedWindow("Video", 1);
    while(1)
	{
        if (v.singleframe())
		    imshow("Video", v.frame);
            a.cal_score(0);
            cout << "score is "<< a.score<<std::endl;
		if (waitKey(30) >= 0) break;
	}
    //v.close_camera();
    return 0;
}