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


#include "CurvesViewerPresenter.h"

#include "photomatch/ui/CurvesViewerModel.h"
#include "photomatch/ui/CurvesViewerView.h"
#include "photomatch/ui/HelpDialog.h"

#include <QFileInfo>

namespace photomatch
{

CurvesViewerPresenter::CurvesViewerPresenter(ICurvesViewerView *view,
                                             ICurvesViewerModel *model)
  : ICurvesViewerPresenter(),
    mView(view),
    mModel(model),
    mHelp(nullptr)
{
  init();

  connect(mView, SIGNAL(leftImageChange(QString)),           this, SLOT(loadLeftImage(QString)));
  connect(mView, SIGNAL(rightImageChange(QString)),          this, SLOT(loadRightImage(QString)));
  connect(mView, SIGNAL(drawCurve(QString,QString,QString)), this, SLOT(drawCurve(QString,QString,QString)));
  connect(mView, SIGNAL(deleteCurve(QString)),               this, SLOT(deleteCurve(QString)));

  connect(mView, SIGNAL(help()),                             this, SLOT(help()));
}

void CurvesViewerPresenter::loadLeftImage(const QString &image)
{
  mView->setLeftImage(image);
  std::vector<QString> imagesRight = mModel->imagePairs(QFileInfo(image).baseName());
  if (imagesRight.empty() == false){
    mView->setRightImageList(imagesRight);
    mView->setRightImage(imagesRight[0]);
  }
}

void CurvesViewerPresenter::loadRightImage(const QString &image)
{
  mView->setRightImage(image);
}

void CurvesViewerPresenter::drawCurve(const QString &session, const QString &detector, const QString &descriptor)
{
  std::vector<QPointF> curve;
  double auc = mModel->computeCurve(session, detector, descriptor, curve);
  QString title = session;
  title.append(" [AUC=").append(QString::number(auc, 'g', 3)).append("]");
  mView->setCurve(title, curve);
}

void CurvesViewerPresenter::deleteCurve(const QString &session)
{
  mView->eraseCurve(session);
}

void CurvesViewerPresenter::help()
{
  if (mHelp){
    mHelp->setPage("roc_curves.html");
    mHelp->show();
  }
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
    QString sessionName;
    QString sessionDetector;
    QString sessionDescriptor;
    std::tie(sessionName, sessionDetector, sessionDescriptor) = session;
    mView->addSession(sessionName, sessionDetector, sessionDescriptor);
  }

  mView->show();
}

void CurvesViewerPresenter::setHelp(std::shared_ptr<HelpDialog> &help)
{
  mHelp = help;
}

void CurvesViewerPresenter::init()
{
}

} // namespace photomatch
