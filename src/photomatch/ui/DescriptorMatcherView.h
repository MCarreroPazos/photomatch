#ifndef PHOTOMATCH_DESCRIPTOR_MATCHER_VIEW_H
#define PHOTOMATCH_DESCRIPTOR_MATCHER_VIEW_H

#include "mvp.h"

class QDialogButtonBox;

namespace photomatch
{

class IDescriptorMatcherWidget;

class IDescriptorMatcherView
  : public IDialogView
{

  Q_OBJECT

public:

  IDescriptorMatcherView(QWidget *parent = nullptr) : IDialogView(parent) {}
  virtual ~IDescriptorMatcherView(){}

  virtual void setSessionName(const QString &name) = 0;

  /*!
   * \brief matchingMethod
   * \return
   */
  virtual QString matchingMethod() const = 0;

  /*!
   * \brief One of NORM_L1, NORM_L2, NORM_HAMMING, NORM_HAMMING2.
   * \return
   */
  virtual QString normType() const = 0;

  /*!
   * \brief ratio
   * \return
   */
  virtual double ratio() const = 0;

  /*!
   * \brief One of HOMOGRAPHY_MATRIX, FUNDAMENTAL_MATRIX, ESSENTIAL_MATRIX
   * \return
   */
  virtual QString geometricTest() const = 0;

  /*!
   * \brief homographyComputeMethod
   * \return
   */
  virtual QString homographyComputeMethod() const = 0;

  /*!
   * \brief fundamentalComputeMethod
   * \return
   */
  virtual QString fundamentalComputeMethod() const = 0;

  /*!
   * \brief essentialComputeMethod
   * \return
   */
  virtual QString essentialComputeMethod() const = 0;

  /*!
   * \brief distance
   * \return
   */
  virtual double distance() const = 0;

  /*!
   * \brief confidence
   * \return
   */
  virtual double confidence() const = 0;

  /*!
   * \brief maxIters
   */
  virtual int maxIters() const = 0;

  /*!
   * \brief crossMatching
   * \return
   */
 virtual bool crossMatching() const = 0;

signals:

  void MatchMethodChange(QString);
  void run();

public slots:

  /*!
   * \brief setMatchingMethod
   * \param matchingMethod
   */
  virtual void setMatchingMethod(const QString &matchingMethod) = 0;

  /*!
   * \brief setNormType
   * \param[in] normType
   */
  virtual void setNormType(const QString &normType) = 0;

  /*!
   * \brief setGeometricTest
   * \param geometricTest
   */
  virtual void setGeometricTest(const QString &geometricTest) = 0;

  /*!
   * \brief setRatio
   * \param[in] ratio
   */
  virtual void setRatio(double ratio) = 0;

  /*!
   * \brief setHomographyComputeMethod
   * \param computeMethod
   */
  virtual void setHomographyComputeMethod(const QString &computeMethod) = 0;

  /*!
   * \brief setHomographyComputeMethod
   * \param computeMethod
   */
  virtual void setFundamentalComputeMethod(const QString &computeMethod) = 0;

  /*!
   * \brief setHomographyComputeMethod
   * \param computeMethod
   */
  virtual void setEssentialComputeMethod(const QString &computeMethod) = 0;

  /*!
   * \brief setDistance
   * \param[in] distance
   */
  virtual void setDistance(double distance) = 0;

  /*!
   * \brief setConfidence
   * \param[in] confidence
   */
  virtual void setConfidence(double confidence) = 0;

  /*!
   * \brief setMaxIters
   * \param maxIter
   */
  virtual void setMaxIters(int maxIter) = 0;

  /*!
   * \brief setCrossMatching
   * \param[in] crossMatching
   */
  virtual void setCrossMatching(bool crossMatching) = 0;

  virtual void disableBruteForceNorm(const QString &norm) = 0;
  virtual void enableBruteForceNorm(const QString &norm) = 0;

};

class DescriptorMatcherView
  : public IDescriptorMatcherView
{

  Q_OBJECT

public:

  DescriptorMatcherView(QWidget *parent = nullptr);
  ~DescriptorMatcherView() override;

// IDescriptorMatcherView interface

public:

  void setSessionName(const QString &name) override;
  QString matchingMethod() const override;
  QString normType() const override;
  double ratio() const override;
  QString geometricTest() const override;
  QString homographyComputeMethod() const override;
  QString fundamentalComputeMethod() const override;
  QString essentialComputeMethod() const override;
  double distance() const override;
  double confidence() const override;
  int maxIters() const override;
  bool crossMatching() const override;

public slots:

  void setMatchingMethod(const QString &matchingMethod) override;
  void setNormType(const QString &normType) override;
  void setRatio(double ratio) override;
  void setGeometricTest(const QString &geometricTest) override;
  void setHomographyComputeMethod(const QString &computeMethod) override;
  void setFundamentalComputeMethod(const QString &computeMethod) override;
  void setEssentialComputeMethod(const QString &computeMethod) override;
  void setDistance(double distance) override;
  void setConfidence(double confidence) override;
  void setMaxIters(int maxIter) override;
  void setCrossMatching(bool crossMatching) override;
  void disableBruteForceNorm(const QString &norm) override;
  void enableBruteForceNorm(const QString &norm) override;

// IDialogView interface

private:

  void init() override;

public slots:

  void clear() override;

private slots:

  void update() override;
  void retranslate() override;

protected:

  QDialogButtonBox *mButtonBox;
  IDescriptorMatcherWidget *mDescriptorMatcherWidget;

};

} // namespace photomatch

#endif // PHOTOMATCH_DESCRIPTOR_MATCHER_VIEW_H