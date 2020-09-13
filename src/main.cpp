#include "../include/focus.h"

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <thread>



int main(int argc, const char** argv){
    video v;
    focus a(&v);

    std::thread thrd(std::bind(&video::test,&v));
    thrd.detach();
    sleep(10);
    while(1)
	{
        sleep(1);
        a.cal_score(0);
        cout << "score is "<< a.score<<std::endl;

	}
    return 0;
}