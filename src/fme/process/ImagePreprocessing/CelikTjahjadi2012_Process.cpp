#include "CelikTjahjadi2012_Process.h"

#include <pixkit-image.hpp>

#include <opencv2/photo.hpp>

CelikTjahjadi2012_Process::CelikTjahjadi2012_Process(cv::Mat &cvImg_Left, cv::Mat &cvImg_Right, int n, const QDir &outputDir)
  : mCvImg_left(cvImg_Left),
    mCvImg_right(cvImg_Right),
    mN(n),
    mOutputDir(outputDir)
{

}

void CelikTjahjadi2012_Process::run()
{
  cv::Mat color_boost;
  if (mCvImg_left.channels() >= 3) {
    cv::decolor(mCvImg_left, mCvImg_left, color_boost);
  }
  if (mCvImg_right.channels() >= 3) {
    cv::decolor(mCvImg_right, mCvImg_right, color_boost);
  }
  cv::Mat tmpLeft;
  cv::Mat tmpRight;
  pixkit::enhancement::global::CelikTjahjadi2012(mCvImg_left, tmpLeft, mN);
  pixkit::enhancement::global::CelikTjahjadi2012(mCvImg_right, tmpRight, mN);
  tmpLeft.copyTo(mCvImg_left);
  tmpRight.copyTo(mCvImg_right);

  cv::imwrite(mOutputDir.absoluteFilePath("leftPreprocessed.png").toStdString(), mCvImg_left);
  cv::imwrite(mOutputDir.absoluteFilePath("rightPreprocessed.png").toStdString(), mCvImg_right);

}
