#include "FeatureExtractorProcess.h"

#include <tidop/core/messages.h>

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>

namespace fme
{

FeatureExtractor::FeatureExtractor(const QString &img, const QString &features,
                                   const std::shared_ptr<KeypointDetector> &keypointDetector,
                                   const std::shared_ptr<DescriptorExtractor> &descriptorExtractor)
  : ProcessConcurrent(),
    mImage(img),
    mFeatures(features),
    mKeypointDetector(keypointDetector),
    mDescriptorExtractor(descriptorExtractor)
{

}

QString FeatureExtractor::image() const
{
  return mImage;
}

void FeatureExtractor::setImage(const QString &image)
{
  mImage = image;
}

QString FeatureExtractor::features() const
{
  return mFeatures;
}

void FeatureExtractor::setFeatures(const QString &features)
{
  mFeatures = features;
}

std::shared_ptr<DescriptorExtractor> FeatureExtractor::descriptorExtractor() const
{
  return mDescriptorExtractor;
}

std::shared_ptr<KeypointDetector> FeatureExtractor::keypointDetector() const
{
  return mKeypointDetector;
}

void FeatureExtractor::run()
{
  QByteArray ba = mImage.toLocal8Bit();
  const char *img_file = ba.data();
  cv::Mat img = cv::imread(img_file);

  if (img.empty()) return;

  msgInfo("Keypoint Detector: %s", img_file);
  if (mKeypointDetector == nullptr) return;
  std::vector<cv::KeyPoint> key_points = mKeypointDetector->detect(img);
  msgInfo("Keypoint detected: %i", key_points.size());

  msgInfo("Descriptor Extractor: %s", img_file);
  if (mDescriptorExtractor == nullptr) return;
  cv::Mat descriptors = mDescriptorExtractor->extract(img, key_points);

  featuresWrite(mFeatures, key_points, descriptors);
  ba = mFeatures.toLocal8Bit();
  const char *cfeat = ba.data();
  msgInfo("Write features at: %s", cfeat);
}

} // namespace fme