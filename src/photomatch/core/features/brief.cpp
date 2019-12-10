#include "brief.h"

#include <tidop/core/messages.h>


namespace photomatch
{


BriefProperties::BriefProperties()
  : IBrief(),
    mBytes("32"),
    mUseOrientation(false)
{
}

BriefProperties::BriefProperties(const BriefProperties &briefProperties)
  : IBrief(),
    mBytes(briefProperties.mBytes),
    mUseOrientation(briefProperties.mUseOrientation)
{
}

BriefProperties::~BriefProperties()
{

}

QString BriefProperties::bytes() const
{
  return mBytes;
}

bool BriefProperties::useOrientation() const
{
  return mUseOrientation;
}

void BriefProperties::setBytes(const QString &bytes)
{
  if (bytes.compare("16") == 0 ||
      bytes.compare("32") == 0 ||
      bytes.compare("64") == 0) {
    mBytes = bytes;
  }
}

void BriefProperties::setUseOrientation(bool useOrientation)
{
  mUseOrientation = useOrientation;
}

void BriefProperties::reset()
{
  mBytes = "32";
  mUseOrientation = false;
}

QString BriefProperties::name() const
{
  return QString("BRIEF");
}


/*----------------------------------------------------------------*/


BriefDescriptor::BriefDescriptor()
  : BriefProperties(),
    DescriptorExtractor()
{
  update();
}

BriefDescriptor::BriefDescriptor(const BriefDescriptor &briefDescriptor)
  : BriefProperties(briefDescriptor),
    DescriptorExtractor()
{
  update();
}

BriefDescriptor::BriefDescriptor(QString bytes, bool useOrientation)
  : BriefProperties(),
    DescriptorExtractor()
{
  BriefProperties::setBytes(bytes);
  BriefProperties::setUseOrientation(useOrientation);
  update();
}

BriefDescriptor::~BriefDescriptor()
{

}

void BriefDescriptor::update()
{
  mBrief = cv::xfeatures2d::BriefDescriptorExtractor::create(BriefProperties::bytes().toInt(),
                                                             BriefProperties::useOrientation());
}

bool BriefDescriptor::extract(const cv::Mat &img,
                              std::vector<cv::KeyPoint> &keyPoints,
                              cv::Mat &descriptors)
{

  try {
    mBrief->compute(img, keyPoints, descriptors);
  } catch (cv::Exception &e) {
    msgError("BRIEF Descriptor error: %s", e.what());
    return true;
  }

  return false;
}

void BriefDescriptor::setBytes(const QString &bytes)
{
  BriefProperties::setBytes(bytes);
  update();
}

void BriefDescriptor::setUseOrientation(bool useOrientation)
{
  BriefProperties::setUseOrientation(useOrientation);
  update();
}

void BriefDescriptor::reset()
{
  BriefProperties::reset();
  update();
}


} // namespace photomatch
