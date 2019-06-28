#include "Sundarami2011_Process.h"

#include <pixkit-image.hpp>

#include <opencv2/photo.hpp>

Sundarami2011_Process::Sundarami2011_Process(cv::Mat &cvImg_Left, cv::Mat &cvImg_Right, const cv::Size &blockSize, float L, float phi, const QDir &outputDir)
  : mCvImg_left(cvImg_Left),
    mCvImg_right(cvImg_Right),
    mBlockSize(blockSize),
    mL(L),
    mPhi(phi),
    mOutputDir(outputDir)
{

}

void Sundarami2011_Process::run()
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
  pixkit::enhancement::local::Sundarami2011(mCvImg_left, tmpLeft, mBlockSize, mL, mPhi);
  pixkit::enhancement::local::Sundarami2011(mCvImg_right, tmpRight, mBlockSize, mL, mPhi);
  tmpLeft.copyTo(mCvImg_left);
  tmpRight.copyTo(mCvImg_right);

  cv::imwrite(mOutputDir.absoluteFilePath("leftPreprocessed.png").toStdString(), mCvImg_left);
  cv::imwrite(mOutputDir.absoluteFilePath("rightPreprocessed.png").toStdString(), mCvImg_right);

}