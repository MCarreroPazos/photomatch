#include "BRISK_KPDescProcess.h"
#include "opencv/cv.h"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv/highgui.h"
#include "opencv/cv.hpp"
using namespace cv;

BRISK_KPDescProcess::BRISK_KPDescProcess(cv::Mat &cvImg, std::vector<cv::KeyPoint> &cvkey,cv::Mat &cvDesc,QString imageName):
    mCvImg(cvImg),
    mCvkey(cvkey),
    mCvDesc(cvDesc),
    mImageName(imageName)
{

}

BRISK_KPDescProcess::~BRISK_KPDescProcess()
{

}

void BRISK_KPDescProcess::run(){
    emit newStdData("Starting BRISK key-point description for image "+mImageName);
    Ptr<cv::BRISK> detector = cv::BRISK::create();
//    cv::cvtColor(mCvImg,mCvImg,CV_RGB2GRAY);
    detector->compute(mCvImg,mCvkey,mCvDesc);
    emit newStdData("BRISK key-point description finished for image "+mImageName);
}