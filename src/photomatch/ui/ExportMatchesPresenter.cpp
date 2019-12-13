#include "ExportMatchesPresenter.h"

#include "photomatch/ui/ExportMatchesModel.h"
#include "photomatch/ui/ExportMatchesView.h"

#include <tidop/core/messages.h>

#include <QFileDialog>
#include <QStandardPaths>

namespace photomatch
{

ExportMatchesPresenter::ExportMatchesPresenter(IExportMatchesView *view,
                                               IExportMatchesModel *model)
  : IExportMatchesPresenter(),
    mView(view),
    mModel(model)
{
  connect(mView, SIGNAL(sessionChange(QString)),   this, SLOT(sessionChange(QString)));
  connect(mView, SIGNAL(accepted()),               this, SLOT(save()));
  connect(mView, SIGNAL(help()),                   this, SLOT(help()));
}

ExportMatchesPresenter::~ExportMatchesPresenter()
{

}

void ExportMatchesPresenter::help()
{
}

void ExportMatchesPresenter::open()
{
  mView->clear();

  mView->setSessions(mModel->sessions());
  mView->setActiveSession(mModel->sessionName());

  mView->exec();
}

void ExportMatchesPresenter::init()
{
}

void ExportMatchesPresenter::save()
{

  QString selectedFilter;
  QString pathName = QFileDialog::getSaveFileName(nullptr,
      tr("Export matches"),
      QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
      tr("ORIMA (*.txt);;BINGO (*.txt);;All Files (*)"),
      &selectedFilter);

  if (!pathName.isEmpty()) {

    QString format;
    if (selectedFilter.compare("ORIMA (*.txt)") == 0){
      format = "ORIMA";
    } else if (selectedFilter.compare("BINGO (*.txt)") == 0){
      format = "BINGO";
    } else {
      msgError("Unsupported format");
    }
    mModel->exportMatches(pathName, format);
  }

}

void ExportMatchesPresenter::sessionChange(const QString &session)
{
  mModel->setSessionName(session);
  mView->setActiveSession(session);
}

} // namespace photomatch
