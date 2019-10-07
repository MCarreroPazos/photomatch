#include "CurvesViewerPresenter.h"

#include "fme/ui/CurvesViewerModel.h"
#include "fme/ui/CurvesViewerView.h"

#include <QFileInfo>

namespace fme
{

CurvesViewerPresenter::CurvesViewerPresenter(ICurvesViewerView *view,
                                             ICurvesViewerModel *model)
  : ICurvesViewerPresenter(),
    mView(view),
    mModel(model)/*,
    mHelp(nullptr)*/
{
  init();

  connect(mView, SIGNAL(leftImageChange(QString)),           this, SLOT(loadLeftImage(QString)));
  connect(mView, SIGNAL(rightImageChange(QString)),          this, SLOT(loadRightImage(QString)));
  connect(mView, SIGNAL(drawCurve(QString,QString,QString)), this, SLOT(drawCurve(QString,QString,QString)));

  connect(mView, SIGNAL(help()),     this, SLOT(help()));
}

void CurvesViewerPresenter::loadLeftImage(const QString &image)
{
  mView->setLeftImage(image);
  std::vector<QString> imagesRight = mModel->imagePairs(QFileInfo(image).baseName());
  if (imagesRight.empty() == false){
    mView->setRightImageList(imagesRight);
    mView->setRightImage(imagesRight[0]);
    //homography(QFileInfo(image).baseName(), QFileInfo(imagesRight[0]).baseName());
  }
}

void CurvesViewerPresenter::loadRightImage(const QString &image)
{
  mView->setRightImage(image);
}

void CurvesViewerPresenter::drawCurve(const QString &session, const QString &detector, const QString &descriptor)
{
  std::vector<QPointF> curve = mModel->computeCurve(session, detector, descriptor);
  mView->setCurve(session, curve);
}

void CurvesViewerPresenter::help()
{
}

void CurvesViewerPresenter::open()
{
  mView->clear();


  std::vector<QString> imagesLeft = mModel->images();
  if (imagesLeft.empty() == false) {
    mView->setLeftImageList(imagesLeft);
    this->loadLeftImage(imagesLeft[0]);
  }

  std::vector<std::tuple<QString,QString,QString>> sessions = mModel->sessions();
  for (auto &session : sessions){
//  //std::tuple<QString,QString,QString> session = sessions[0];
    QString sessionName;
    QString sessionDetector;
    QString sessionDescriptor;
    std::tie(sessionName, sessionDetector, sessionDescriptor) = session;
    mView->addSession(sessionName, sessionDetector, sessionDescriptor);

//    std::vector<QPointF> curve = mModel->computeCurve(sessionName, mView->leftImage(), mView->rightImage());
//    mView->setCurve(sessionName, curve);

  }

  mView->show();
}

void CurvesViewerPresenter::init()
{
}

} // namespace fme