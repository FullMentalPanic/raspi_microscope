// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace cv;
using namespace std;


class video{
    public:
        VideoCapture cap;
        Mat frame;
        video();
        ~video();
        void test();
    private:
        bool singleframe();
        void outputframe();
        void pipedframe();       
};