#include "../include/video.h"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"


using namespace cv;
using namespace std;

class focus : public video {
    private:
        double tenengrad(Mat imageGrey);
        double laplacian(Mat imageGrey);
        double meanstd(Mat imageGrey);
    public:
        double score;
        void cal_score(int way);
        void test();       
};