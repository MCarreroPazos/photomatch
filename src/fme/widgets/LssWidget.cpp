#include "LssWidget.h"


#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>

namespace fme
{

LssWidget::LssWidget(QWidget *parent)
  : ILssWidget (parent)
{
  init();

}

LssWidget::~LssWidget()
{

}

void LssWidget::update()
{
}

void LssWidget::reset()
{
}

void LssWidget::init()
{
  this->setWindowTitle("LSS");

  reset();
  update();
}

} // namespace fme



