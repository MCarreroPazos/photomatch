#include "RswheProcess.h"

#include <pixkit-image.hpp>

#include <opencv2/photo.hpp>

namespace fme
{

RswheProcess::RswheProcess()
  : ProcessConcurrent(),
    IRswhe(),
    mImgInput(""),
    mImgOutput(""),
    mHistogramDivisions(2),
    mHistogramCut(HistogramCut::by_mean)
{

}

RswheProcess::RswheProcess(const QString &imgInput,
                           const QString &imgOutput,
                           int histogramDivisions,
                           HistogramCut histogramCut)
  : ProcessConcurrent(),
    IRswhe(),
    mImgInput(imgInput),
    mImgOutput(imgOutput),
    mHistogramDivisions(histogramDivisions),
    mHistogramCut(histogramCut)
{

}

RswheProcess::~RswheProcess()
{

}

QString RswheProcess::imgInput() const
{
  return mImgInput;
}

void RswheProcess::setImgInput(const QString &imgInput)
{
  mImgInput = imgInput;
}

QString RswheProcess::imgOutput() const
{
  return mImgOutput;
}

void RswheProcess::setImgOutput(const QString &imgOutput)
{
  mImgOutput = imgOutput;
}


int RswheProcess::histogramDivisions() const
{
  return mHistogramDivisions;
}

void RswheProcess::setHistogramDivisions(int histogramDivisions)
{
  mHistogramDivisions = histogramDivisions;
}

RswheProcess::HistogramCut RswheProcess::histogramCut() const
{
  return mHistogramCut;
}

void RswheProcess::setHistogramCut(HistogramCut histogramCut)
{
  mHistogramCut = histogramCut;
}

void RswheProcess::reset()
{
  mImgInput.clear();
  mImgOutput.clear();
  mHistogramDivisions = 2;
  mHistogramCut = HistogramCut::by_mean;
}

void RswheProcess::run()
{
  QByteArray ba = mImgInput.toLocal8Bit();
  const char *input_img = ba.data();
  cv::Mat img = cv::imread(input_img);

  cv::Mat color_boost;
  if (img.channels() >= 3) {
    cv::decolor(img, img, color_boost);
  }

  int histogram_cut;
  if (mHistogramCut == HistogramCut::by_mean)
    histogram_cut = 1;
  else {
    histogram_cut = 2;
  }
  cv::Mat out;
  pixkit::enhancement::global::MaryKim2008(img, out, histogram_cut, mHistogramDivisions);

  ba = mImgOutput.toLocal8Bit();
  const char *output_img = ba.data();
  cv::imwrite(output_img, out);
}


} // namespace fme
