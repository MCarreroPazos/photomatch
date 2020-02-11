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


#ifndef PHOTOMATCH_REPEATABILITY_PRESENTER_H
#define PHOTOMATCH_REPEATABILITY_PRESENTER_H

#include <memory>

#include <QObject>

#include "photomatch/ui/mvp.h"

namespace photomatch
{

class IRepeatabilityView;
class IRepeatabilityModel;
class HelpDialog;

class IRepeatabilityPresenter
  : public IPresenter
{

  Q_OBJECT

public:

  IRepeatabilityPresenter() : IPresenter() {}
  virtual ~IRepeatabilityPresenter() override {}

protected slots:

  virtual void selectSession(const QString &session) = 0;
};

class RepeatabilityPresenter
  : public IRepeatabilityPresenter
{

  Q_OBJECT

public:

  RepeatabilityPresenter(IRepeatabilityView *view,
                         IRepeatabilityModel *model);
  ~RepeatabilityPresenter() override {}

//IRepeatabilityPresenter interface

protected slots:

  void selectSession(const QString &session) override;

// IPresenter interface

public slots:

  void help() override;
  void open() override;
  void setHelp(std::shared_ptr<HelpDialog> &help) override;

private:

  void init() override;

private:

  IRepeatabilityView *mView;
  IRepeatabilityModel *mModel;
  std::shared_ptr<HelpDialog> mHelp;
};

} // namespace photomatch

#endif // PHOTOMATCH_REPEATABILITY_PRESENTER_H
