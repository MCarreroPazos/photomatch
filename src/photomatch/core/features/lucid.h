#ifndef PHOTOMATCH_LUCID_DESCRIPTOR_H
#define PHOTOMATCH_LUCID_DESCRIPTOR_H

#include "photomatch/photomatch_global.h"

#include "photomatch/core/features/features.h"

#include <opencv2/xfeatures2d.hpp>

#include <QString>

namespace photomatch
{


class PHOTOMATCH_EXPORT LucidProperties
  : public ILucid
{
public:

  LucidProperties();
  ~LucidProperties() override;

// ILucid interface

public:

  virtual int lucidKernel() const override;
  virtual int blurKernel() const override;
  virtual void setLucidKernel(int lucidKernel) override;
  virtual void setBlurKernel(int blurKernel) override;

// Feature interface

public:

  virtual void reset() override;
  QString name() const final;

private:

  int mLucidKernel;
  int mBlurKernel;
};


/*----------------------------------------------------------------*/


class PHOTOMATCH_EXPORT LucidDescriptor
    : public LucidProperties,
      public DescriptorExtractor
{

public:

  LucidDescriptor();
  LucidDescriptor(int lucidKernel, int blurKernel);

  ~LucidDescriptor() override;

private:

  void update();

// DescriptorExtractor interface

public:

  bool extract(const cv::Mat &img,
               std::vector<cv::KeyPoint> &keyPoints,
               cv::Mat &descriptors) override;


// ILucid interface

public:

  void setLucidKernel(int lucidKernel) override;
  void setBlurKernel(int blurKernel) override;

// Feature interface

public:

  void reset() override;

protected:

  cv::Ptr<cv::xfeatures2d::LUCID> mLUCID;
};


} // namespace photomatch

#endif // PHOTOMATCH_LUCID_DESCRIPTOR_H