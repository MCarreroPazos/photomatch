/************************************************************************
 *                                                                      *
 * Copyright 2020 by Tidop Research Group <daguilera@usal.se>           *
 *                                                                      *
 * This file is part of PhotoMatch                                      *
 *                                                                      *
 * PhotoMatch is free software: you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation, either version 3 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * PhotoMatch is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 * GNU General Public License for more details.                         *
 *                                                                      *
 * You should have received a copy of the GNU General Public License    *
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.      *
 *                                                                      *
 * @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>                *
 *                                                                      *
 ************************************************************************/


#ifndef PHOTOMATCH_VGG_DESCRIPTOR_H
#define PHOTOMATCH_VGG_DESCRIPTOR_H


#include "photomatch/photomatch_global.h"

#include "photomatch/core/features/features.h"

#include <QString>

#include <opencv2/xfeatures2d.hpp>


namespace photomatch
{

class VggProperties
  : public Vgg
{

public:

  VggProperties();
  VggProperties(const VggProperties &vggProperties);
  virtual ~VggProperties() override;

// IVgg interface

public:

  virtual QString descriptorType() const override;
  virtual void setDescriptorType(const QString &descriptorType) override;
  virtual double scaleFactor() const override;
  virtual void setScaleFactor(double scaleFactor) override;
  virtual double sigma() const override;
  virtual void setSigma(double sigma) override;
  virtual bool useNormalizeDescriptor() const override;
  virtual void setUseNormalizeDescriptor(bool useNormalizeDescriptor) override;
  virtual bool useNormalizeImage() const override;
  virtual void setUseNormalizeImage(bool useNormalizeImage) override;
  virtual bool useScaleOrientation() const override;
  virtual void setUseScaleOrientation(bool useScaleOrientation) override;

// Feature interface

public:

  void reset() override;
  QString name() const override;

private:

  QString mDescriptorType;
  double mScaleFactor;
  double mSigma;
  bool bUseNormalizeDescriptor;
  bool bUseNormalizeImage;
  bool bUseScaleOrientation;

};



/*----------------------------------------------------------------*/


class VggDescriptor
  : public VggProperties,
    public DescriptorExtractor
{

public:

  VggDescriptor();
  VggDescriptor(const VggDescriptor &vggDescriptor);
  VggDescriptor(QString descriptorType,
                double scaleFactor,
                double sigma,
                bool useNormalizeDescriptor,
                bool useNormalizeImage,
                bool useScaleOrientation);
  ~VggDescriptor() override;

private:

  void update();

// Feature interface

public:

  void reset() override;

// IVgg interface

public:

  void setDescriptorType(const QString &descriptorType) override;
  void setScaleFactor(double scaleFactor) override;
  void setSigma(double sigma) override;
  void setUseNormalizeDescriptor(bool useNormalizeDescriptor) override;
  void setUseNormalizeImage(bool useNormalizeImage) override;
  void setUseScaleOrientation(bool useScaleOrientation) override;

// DescriptorExtractor interface

public:

  bool extract(const cv::Mat &img, std::vector<cv::KeyPoint> &keyPoints, cv::Mat &descriptors) override;

protected:

#if CV_VERSION_MAJOR >= 4 || (CV_VERSION_MAJOR >= 3 && CV_VERSION_MINOR > 2)
  cv::Ptr<cv::xfeatures2d::VGG> mVGG;
#endif
};


} // namespace photomatch

#endif // PHOTOMATCH_VGG_DESCRIPTOR_H
