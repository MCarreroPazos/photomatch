#ifndef PHOTOMATCH_BRISK_WIDGET_H
#define PHOTOMATCH_BRISK_WIDGET_H

#include "photomatch/widgets/PhotoMatchWidget.h"


#include <QWidget>

class QSpinBox;
class QDoubleSpinBox;

namespace photomatch
{

/*!
 * \brief Interface for BRISK Widgets class
 * Stefan Leutenegger, Margarita Chli, and Roland Yves Siegwart.
 * Brisk: Binary robust invariant scalable keypoints. In Computer
 * Vision (ICCV), 2011 IEEE International Conference on, pages
 * 2548–2555. IEEE, 2011
 * http://margaritachli.com/papers/ICCV2011paper.pdf
 */
class PHOTOMATCH_EXPORT IBriskWidget
  : public PhotoMatchWidget
{
  Q_OBJECT

public:

  IBriskWidget(QWidget *parent = nullptr) : PhotoMatchWidget(parent){}
  virtual ~IBriskWidget() = default;

  /*!
   * \brief AGAST detection threshold score (Default=30)
   * \return Threshold
   */
  virtual int threshold() const = 0;

  /*!
   * \brief Detection octaves (Default=3)
   * \return
   */
  virtual int octaves() const = 0;

  /*!
   * \brief Pattern Scale (Default=1.0)
   * \return
   */
  virtual double patternScale() const = 0;

signals:

  void thresholdChange(int);
  void octavesChange(int);
  void patternScaleChange(double);

public slots:

  /*!
   * \brief Set the AGAST detection threshold score
   * \param[in] threshold AGAST detection threshold
   */
  virtual void setThreshold(int threshold) = 0;

  /*!
   * \brief Set detection octaves
   * \param[in] octaves Octaves
   */
  virtual void setOctaves(int octaves) = 0;

  /*!
   * \brief Set Pattern Scale
   * \param[in] patternScale Pattern Scale
   */
  virtual void setPatternScale(double patternScale) = 0;

};

class PHOTOMATCH_EXPORT BriskWidget
  : public IBriskWidget
{
  Q_OBJECT

public:

  BriskWidget(QWidget *parent = nullptr);
  ~BriskWidget() override;

// IBriskWidget interface

  int threshold() const override;
  int octaves() const override;
  double patternScale() const override;

public slots:

  void setThreshold(int threshold) override;
  void setOctaves(int octaves) override;
  void setPatternScale(double patternScale) override;

// PhotoMatchWidget interface

protected slots:

  void update() override;
  void retranslate() override;

public slots:

  void reset() override;

private:

  void init() override;

protected:

  QSpinBox *mThreshold;
  QSpinBox *mOctaves;
  QDoubleSpinBox *mPatternScale;
};

} // namespace photomatch

#endif // PHOTOMATCH_BRISK_WIDGET_H