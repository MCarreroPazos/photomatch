#ifndef FME_FEATURE_EXTRACTOR_PRESENTER_H
#define FME_FEATURE_EXTRACTOR_PRESENTER_H

#include "fme/fme_global.h"

#include <QObject>

#include "mvp.h"

class MultiProcess;

namespace fme
{

class IFeatureExtractorView;
class IFeatureExtractorModel;
class IProjectModel;
class ISettingsModel;

class IAgastWidget;
class IAkazeWidget;
class IBriefWidget;
class IBriskWidget;
class IDaisyWidget;
class IFastWidget;
class IFreakWidget;
class IGfttWidget;
class IHogWidget;
class IKazeWidget;
class ILatchWidget;
class ILucidWidget;
class IMsdWidget;
class IMserWidget;
class IOrbWidget;
class ISiftWidget;
class IStarWidget;
class ISurfWidget;

class IFeatureExtractorPresenter
  : public IPresenter
{

  Q_OBJECT

public:

  IFeatureExtractorPresenter() {}
  virtual ~IFeatureExtractorPresenter(){}

signals:

  void featureExtractorFinished();

private slots:

  virtual void run() = 0;
  virtual void setCurrentkeypointDetector(const QString &featureExtractor) = 0;
  virtual void setCurrentDescriptorExtractor(const QString &descriptorExtractor) = 0;
};


class FeatureExtractorPresenter
  : public IFeatureExtractorPresenter
{
  Q_OBJECT

public:

  FeatureExtractorPresenter(IFeatureExtractorView *view,
                            IFeatureExtractorModel *model,
                            IProjectModel *projectModel,
                            ISettingsModel *settingsModel);
  ~FeatureExtractorPresenter() override;

// IPresenter interface

public slots:

  void help() override;
  void open() override;

private:

  void init() override;

// IFeatureExtractorPresenter interface

private slots:

  void run() override;
  void setCurrentkeypointDetector(const QString &featureExtractor) override;
  void setCurrentDescriptorExtractor(const QString &descriptorExtractor) override;
  void onError(int, QString);
  void onFinished();

protected:

  IFeatureExtractorView *mView;
  IFeatureExtractorModel *mModel;
  IProjectModel *mProjectModel;
  ISettingsModel *mSettingsModel;

  IAgastWidget *mAgastDetector;
  IAkazeWidget *mAkazeDetector;
  IBriskWidget *mBriskDetector;
  IFastWidget *mFastDetector;
  IGfttWidget *mGfttDetector;
  IKazeWidget *mKazeDetector;
  IMsdWidget *mMsdDetector;
  IMserWidget *mMserDetector;
  IOrbWidget *mOrbDetector;
  ISiftWidget *mSiftDetector;
  IStarWidget *mStarDetector;
  ISurfWidget *mSurfDetector;

  IAkazeWidget *mAkazeDescriptor;
  IBriefWidget *mBriefDescriptor;
  IBriskWidget *mBriskDescriptor;
  IDaisyWidget *mDaisyDescriptor;
  IFreakWidget *mFreakDescriptor;
  IHogWidget *mHogDescriptor;
  IKazeWidget *mKazeDescriptor;
  ILatchWidget *mLatchDescriptor;
  ILucidWidget *mLucidDescriptor;
  IOrbWidget *mOrbDescriptor;
  ISiftWidget *mSiftDescriptor;
  ISurfWidget *mSurfDescriptor;

  MultiProcess *mMultiProcess;
};

} // namespace fme

#endif // FME_FEATURE_EXTRACTOR_PRESENTER_H