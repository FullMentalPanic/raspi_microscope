// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;


class video{
    public:
        VideoCapture cap;
        Mat frame;
        bool open_camera();	// 打开默认相机;
        bool singleframe();
        void test();
        void close_camera();
};