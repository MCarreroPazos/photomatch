#ifndef PHOTOMATCH_FREAK_DESCRIPTOR_H
#define PHOTOMATCH_FREAK_DESCRIPTOR_H

#include "photomatch/photomatch_global.h"

#include "photomatch/core/features/features.h"

#include <opencv2/xfeatures2d.hpp>

#include <QString>

namespace photomatch
{


class PHOTOMATCH_EXPORT FreakProperties
  : public IFreak
{

public:

  FreakProperties();
  ~FreakProperties() override;

// IFreak interface

public:

  virtual bool orientationNormalized() const override;
  virtual bool scaleNormalized() const override;
  virtual double patternScale() const override;
  virtual int octaves() const override;
  virtual void setOrientationNormalized(bool orientationNormalized) override;
  virtual void setScaleNormalized(bool scaleNormalized) override;
  virtual void setPatternScale(double patternScale) override;
  virtual void setOctaves(int octaves) override;

// Feature interface

public:

  virtual void reset() override;
  QString name() const final;

private:

  bool mOrientationNormalized;
  bool mScaleNormalized;
  double mPatternScale;
  int mOctaves;
};


/*----------------------------------------------------------------*/


class PHOTOMATCH_EXPORT FreakDescriptor
    : public FreakProperties,
      public DescriptorExtractor
{

public:

  FreakDescriptor();
  FreakDescriptor(bool orientationNormalized,
                  bool scaleNormalized,
                  double patternScale,
                  int octaves);

  ~FreakDescriptor() override;

private:

  void update();

// DescriptorExtractor interface

public:

  bool extract(const cv::Mat &img,
               std::vector<cv::KeyPoint> &keyPoints,
               cv::Mat &descriptors) override;

// IFreak interface

public:

  void setOrientationNormalized(bool orientationNormalized) override;
  void setScaleNormalized(bool scaleNormalized) override;
  void setPatternScale(double patternScale) override;
  void setOctaves(int octaves) override;

// Feature interface

public:

  void reset() override;

protected:

  cv::Ptr<cv::xfeatures2d::FREAK> mFREAK;
};


} // namespace photomatch

#endif // PHOTOMATCH_FREAK_DESCRIPTOR_H