#ifndef FME_STAR_DETECTOR_H
#define FME_STAR_DETECTOR_H

#include "fme/fme_global.h"

#include "fme/core/features/features.h"

#include <opencv2/xfeatures2d.hpp>

#include <QString>

namespace fme
{


class FME_EXPORT StarProperties
  : public IStar
{
public:

  StarProperties();
  ~StarProperties() override;

// IStar interface

public:

  virtual int maxSize() const override;
  virtual int responseThreshold() const override;
  virtual int lineThresholdProjected() const override;
  virtual int lineThresholdBinarized() const override;
  virtual int suppressNonmaxSize() const override;
  virtual void setMaxSize(int maxSize) override;
  virtual void setResponseThreshold(int responseThreshold) override;
  virtual void setLineThresholdProjected(int lineThresholdProjected) override;
  virtual void setLineThresholdBinarized(int lineThresholdBinarized) override;
  virtual void setSuppressNonmaxSize(int suppressNonmaxSize) override;

// Feature interface

public:

  virtual void reset() override;

private:

  int mMaxSize;
  int mResponseThreshold;
  int mLineThresholdProjected;
  int mLineThresholdBinarized;
  int mSuppressNonmaxSize;
};



/*----------------------------------------------------------------*/


class StarDetector
  : public StarProperties,
    public KeypointDetector
{

public:

  StarDetector();
  StarDetector(int maxSize,
               int responseThreshold,
               int lineThresholdProjected,
               int lineThresholdBinarized,
               int suppressNonmaxSize);
  ~StarDetector() override;

private:

  void update();

// KeypointDetector interface

public:

  std::vector<cv::KeyPoint> detect(const cv::Mat &img, cv::InputArray &mask) override;

// IStar interface

public:

  void setMaxSize(int maxSize) override;
  void setResponseThreshold(int responseThreshold) override;
  void setLineThresholdProjected(int lineThresholdProjected) override;
  void setLineThresholdBinarized(int lineThresholdBinarized) override;
  void setSuppressNonmaxSize(int suppressNonmaxSize) override;

// Feature interface

public:

  void reset() override;

protected:

  cv::Ptr<cv::xfeatures2d::StarDetector> mSTAR;

};


} // namespace fme

#endif // FME_STAR_DETECTOR_H
