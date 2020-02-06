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


#include "WallisWidget.h"

#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>

namespace photomatch
{

WallisWidgetImp::WallisWidgetImp(QWidget *parent)
  : WallisWidget(parent),
    mContrast(new QDoubleSpinBox(this)),
    mBrightness(new QDoubleSpinBox(this)),
    mImposedAverage(new QSpinBox(this)),
    mImposedLocalStdDev(new QSpinBox(this)),
    mKernelSize(new QSpinBox(this))
{
  init();

  retranslate();

  /// Signals and slots

  connect(mContrast,            SIGNAL(valueChanged(double)),     this, SIGNAL(contrastChange(double)));
  connect(mBrightness,          SIGNAL(valueChanged(double)),     this, SIGNAL(brightnessChange(double)));
  connect(mImposedAverage,      SIGNAL(valueChanged(int)),        this, SIGNAL(imposedAverageChange(int)));
  connect(mImposedLocalStdDev,  SIGNAL(valueChanged(int)),        this, SIGNAL(imposedLocalStdDevChange(int)));
  connect(mKernelSize,          SIGNAL(valueChanged(int)),        this, SIGNAL(kernelSizeChange(int)));
}

WallisWidgetImp::~WallisWidgetImp()
{

}

double WallisWidgetImp::contrast() const
{
  return mContrast->value();
}

double WallisWidgetImp::brightness() const
{
  return mBrightness->value();
}

int WallisWidgetImp::imposedAverage() const
{
  return mImposedAverage->value();
}

int WallisWidgetImp::imposedLocalStdDev() const
{
  return mImposedLocalStdDev->value();
}

int WallisWidgetImp::kernelSize() const
{
  return mKernelSize->value();
}

void WallisWidgetImp::setContrast(double contrast)
{
  const QSignalBlocker blockerContrast(mContrast);
  mContrast->setValue(contrast);
}

void WallisWidgetImp::setBrightness(double brightness)
{
  const QSignalBlocker blockerBrightness(mBrightness);
  mBrightness->setValue(brightness);
}

void WallisWidgetImp::setImposedAverage(int imposedAverage)
{
  const QSignalBlocker blockerImposedAverage(mImposedAverage);
  mImposedAverage->setValue(imposedAverage);
}

void WallisWidgetImp::setImposedLocalStdDev(int imposedLocalStdDev)
{
  const QSignalBlocker blockerImposedLocalStdDev(mImposedLocalStdDev);
  mImposedLocalStdDev->setValue(imposedLocalStdDev);
}

void WallisWidgetImp::setKernelSize(int kernelSize)
{
  const QSignalBlocker blockerKernelSize(mKernelSize);
  mKernelSize->setValue(kernelSize);
}

void WallisWidgetImp::update()
{
}

void WallisWidgetImp::retranslate()
{

}

void WallisWidgetImp::reset()
{
  const QSignalBlocker blockerContrast(mContrast);
  const QSignalBlocker blockerBrightness(mBrightness);
  const QSignalBlocker blockerImposedAverage(mImposedAverage);
  const QSignalBlocker blockerImposedLocalStdDev(mImposedLocalStdDev);
  const QSignalBlocker blockerKernelSize(mKernelSize);

  mContrast->setValue(1.0);
  mBrightness->setValue(0.2);
  mImposedAverage->setValue(41);
  mImposedLocalStdDev->setValue(127);
  mKernelSize->setValue(50);
}

void WallisWidgetImp::init()
{
  this->setWindowTitle("Wallis Filter");

  QGridLayout *layout = new QGridLayout();

  layout->addWidget(new QLabel(tr("Contrast:")), 0, 0);
  mContrast->setRange(0, 1);
  mContrast->setSingleStep(0.1);
  layout->addWidget(mContrast, 0, 1);

  layout->addWidget(new QLabel(tr("Brightness:")), 1, 0);
  mBrightness->setRange(0, 1);
  mBrightness->setSingleStep(0.1);
  layout->addWidget(mBrightness, 1, 1);

  layout->addWidget(new QLabel(tr("Imposed Average:")), 2, 0);
  mImposedAverage->setRange(1, 1000);
  mImposedAverage->setSingleStep(1);
  layout->addWidget(mImposedAverage, 2,1);

  layout->addWidget(new QLabel(tr("Imposed Local StdDev:")), 3, 0);
  mImposedLocalStdDev->setRange(1, 10000);
  mImposedLocalStdDev->setSingleStep(1);
  layout->addWidget(mImposedLocalStdDev, 3, 1);

  layout->addWidget(new QLabel(tr("Kernel Size:")), 4, 0);
  mKernelSize->setRange(1, 10000);
  mKernelSize->setSingleStep(1);
  layout->addWidget(mKernelSize, 4, 1);

  this->setLayout(layout);

  reset(); /// set default values

  update();
}

} // namespace photomatch




