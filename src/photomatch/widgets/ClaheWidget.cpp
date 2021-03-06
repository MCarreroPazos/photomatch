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


#include "ClaheWidget.h"

#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QApplication>

namespace photomatch
{

ClaheWidgetImp::ClaheWidgetImp(QWidget *parent)
  : ClaheWidget(parent),
    mGroupBox(new QGroupBox(this)),
    mLabelDescription(new QLabel(this)),
    mLabelClipLimit(new QLabel(this)),
    mClipLimit(new QDoubleSpinBox(this)),
    mGroupBoxBlockSize(new QGroupBox(mGroupBox)),
    mLabelTilesGridX(new QLabel(this)),
    mTilesGridX(new QSpinBox(this)),
    mLabelTilesGridY(new QLabel(this)),
    mTilesGridY(new QSpinBox(this))
{
  this->initUI();
  this->initSignalAndSlots();
}

ClaheWidgetImp::~ClaheWidgetImp()
{

}

void ClaheWidgetImp::onTilesGridXChange(int gx)
{
  emit tileGridSizeChange(QSize(gx, mTilesGridY->value()));
}

void ClaheWidgetImp::onTilesGridYChange(int gy)
{
  emit tileGridSizeChange(QSize(mTilesGridX->value(), gy));
}

double ClaheWidgetImp::clipLimit() const
{
  return mClipLimit->value();
}

QSize ClaheWidgetImp::tileGridSize() const
{
  return QSize(mTilesGridX->value(), mTilesGridY->value());
}

void ClaheWidgetImp::setClipLimit(double clipLimit)
{
  const QSignalBlocker blockerClipLimit(mClipLimit);
  mClipLimit->setValue(clipLimit);
}

void ClaheWidgetImp::setTilesGridSize(const QSize &tileGridSize)
{
  const QSignalBlocker blockerTilesGridX(mTilesGridX);
  const QSignalBlocker blockerTilesGridY(mTilesGridY);
  mTilesGridX->setValue(tileGridSize.width());
  mTilesGridY->setValue(tileGridSize.height());

}

void ClaheWidgetImp::update()
{
}

void ClaheWidgetImp::retranslate()
{
  mGroupBox->setTitle(QApplication::translate("ClaheWidgetImp", "CLAHE Parameters"));
  mLabelDescription->setText(QApplication::translate("ClaheWidgetImp", "Contrast Limited Adaptive Histogram Equalization", nullptr));
  mLabelClipLimit->setText(QApplication::translate("ClaheWidgetImp", "Clip Limit:"));
  mGroupBoxBlockSize->setTitle(QApplication::translate("ClaheWidgetImp", "Block Size"));
  mLabelTilesGridX->setText(QApplication::translate("ClaheWidgetImp", "Width:"));
  mLabelTilesGridY->setText(QApplication::translate("ClaheWidgetImp", "Height:"));
//#ifndef QT_NO_WHATSTHIS
//  mClipLimit->setWhatsThis(tr("<html><head/><body><p>Threshold value for contrast limiting.</p></body></html>"));
//  mTilesGridX->setWhatsThis(tr("<html><head/><body><p>Width of grid for histogram equalization.</p></p></body></html>"));
//  mTilesGridY->setWhatsThis(tr("<html><head/><body><p>Height of grid for histogram equalization.</p></p></body></html>"));
//#endif // QT_NO_WHATSTHIS
}

void ClaheWidgetImp::reset()
{
  const QSignalBlocker blockerClipLimit(mClipLimit);
  const QSignalBlocker blockerTilesGridX(mTilesGridX);
  const QSignalBlocker blockerTilesGridY(mTilesGridY);

  mClipLimit->setValue(40.0);
  mTilesGridX->setValue(8);
  mTilesGridY->setValue(8);
}

void ClaheWidgetImp::initUI()
{
  this->setWindowTitle("CLAHE");

  QGridLayout *layout = new QGridLayout();
  layout->setContentsMargins(0,0,0,0);
  this->setLayout(layout);

  layout->addWidget(mGroupBox);

  QGridLayout *propertiesLayout = new QGridLayout();
  mGroupBox->setLayout(propertiesLayout);

  mLabelDescription->setWordWrap(true);
  QFont font;
  font.setBold(true);
  font.setWeight(75);
  mLabelDescription->setFont(font);
  mLabelDescription->setWordWrap(true);
  propertiesLayout->addWidget(mLabelDescription, 0, 0, 1, 2);

  propertiesLayout->addWidget(mLabelClipLimit, 1, 0, 1, 1);
  mClipLimit->setRange(0., 100.);
  propertiesLayout->addWidget(mClipLimit, 1, 1, 1, 1);

  QGridLayout *gridLayoutTiles = new QGridLayout(mGroupBoxBlockSize);
  gridLayoutTiles->setSpacing(6);
  gridLayoutTiles->setContentsMargins(11, 11, 11, 11);

  gridLayoutTiles->addWidget(mLabelTilesGridX, 0, 0, 1, 1);
  mTilesGridX->setRange(0, 100);
  gridLayoutTiles->addWidget(mTilesGridX, 0, 1, 1, 1);

  gridLayoutTiles->addWidget(mLabelTilesGridY, 1, 0, 1, 1);
  mTilesGridY->setRange(0, 100);
  gridLayoutTiles->addWidget(mTilesGridY, 1, 1, 1, 1);

  propertiesLayout->addWidget(mGroupBoxBlockSize, 2, 0, 1, 2);

  this->retranslate();
  this->reset();  /// set default values
  this->update();
}

void ClaheWidgetImp::initSignalAndSlots()
{
  connect(mClipLimit,     SIGNAL(valueChanged(double)),     this, SIGNAL(clipLimitChange(double)));
  connect(mTilesGridX,    SIGNAL(valueChanged(int)),        this, SLOT(onTilesGridXChange(int)));
  connect(mTilesGridY,    SIGNAL(valueChanged(int)),        this, SLOT(onTilesGridYChange(int)));
}

void ClaheWidgetImp::changeEvent(QEvent *event)
{
  QWidget::changeEvent(event);
  switch (event->type()) {
    case QEvent::LanguageChange:
      this->retranslate();
      break;
    default:
      break;
  }
}

} // namespace photomatch


