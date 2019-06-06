#ifndef FME_FREAK_WIDGET_H
#define FME_FREAK_WIDGET_H

#include "fme/fme_global.h"

#include <QWidget>

class QDoubleSpinBox;
class QSpinBox;
class QCheckBox;

namespace fme
{

/*!
 * \brief Interface for FREAK Widgets class
 * Alexandre Alahi, Raphael Ortiz, and Pierre Vandergheynst.
 * Freak: Fast retina keypoint. In Computer Vision and Pattern
 * Recognition (CVPR), 2012 IEEE Conference on, pages 510–517. Ieee, 2012.
 */
class FME_EXPORT IFreakWidget
  : public QWidget
{
  Q_OBJECT

public:

  IFreakWidget(QWidget *parent = nullptr) : QWidget(parent){}
  virtual ~IFreakWidget() = default;

  /*!
   * \brief Orientation normalization (Default=true)
   * \return
   */
  virtual bool orientationNormalized() const = 0;

  /*!
   * \brief Scale normalization (Default=true)
   * \return
   */
  virtual bool scaleNormalized() const = 0;

  /*!
   * \brief Scaling of the description pattern (Default=22.)
   * \return
   */
  virtual double patternScale() const = 0;

  /*!
   * \brief Number of octaves covered by the detected keypoints (Default=4)
   * \return Number of octaves
   */
  virtual int octaves() const = 0;

signals:

  void orientationNormalizedChange(bool);
  void scaleNormalizedChange(bool);
  void patternScaleChange(double);
  void octavesChange(int);

public slots:

  /*!
   * \brief Enable/disable orientation normalization
   * \param[in] orientationNormalized true for Enable
   */
  virtual void setOrientationNormalized(bool orientationNormalized) = 0;

  /*!
   * \brief Enable/disable scale normalization
   * \param[in] scaleNormalized true for Enable
   */
  virtual void setScaleNormalized(bool scaleNormalized) = 0;

  /*!
   * \brief Set scaling of the description pattern
   * \param[in] patternScale Pattern Scale
   */
  virtual void setPatternScale(double patternScale) = 0;

  /*!
   * \brief Number of octaves covered by the detected keypoints
   * \param[in] octaves Number of octaves covered by the detected keypoints
   */
  virtual void setOctaves(int octaves) = 0;

  virtual void update() = 0;
  virtual void reset() = 0;

private:

  virtual void init() = 0;
};

class FME_EXPORT FreakWidget
  : public IFreakWidget
{
  Q_OBJECT

public:

  FreakWidget(QWidget *parent = nullptr);
  ~FreakWidget() override;

// IFreakWidget interface

public:

  bool orientationNormalized() const override;
  bool scaleNormalized() const override;
  double patternScale() const override;
  int octaves() const override;

public slots:

  void setOrientationNormalized(bool orientationNormalized) override;
  void setScaleNormalized(bool scaleNormalized) override;
  void setPatternScale(double patternScale) override;
  void setOctaves(int octaves) override;

  void update() override;
  void reset() override;

private:

  void init() override;

protected:

  QCheckBox *mOrientationNormalized;
  QCheckBox *mScaleNormalized;
  QDoubleSpinBox *mPatternScale;
  QSpinBox *mOctaves;
};

} // namespace fme

#endif // FME_FREAK_WIDGET_H
