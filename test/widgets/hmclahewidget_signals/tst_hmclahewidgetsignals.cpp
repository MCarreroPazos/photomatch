#include <QtTest>
#include <QCoreApplication>

#include "photomatch/widgets/HmclaheWidget.h"

#include <QSpinBox>

using namespace photomatch;

class TestHmclaheWidgetSignals : public HmclaheWidgetImp
{
  Q_OBJECT

public:
  TestHmclaheWidgetSignals();
  ~TestHmclaheWidgetSignals();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_blockSizeChange();
  void test_lChange();
  void test_phiChange();
};

TestHmclaheWidgetSignals::TestHmclaheWidgetSignals()
  : HmclaheWidgetImp()
{

}

TestHmclaheWidgetSignals::~TestHmclaheWidgetSignals()
{

}

void TestHmclaheWidgetSignals::initTestCase()
{

}

void TestHmclaheWidgetSignals::cleanupTestCase()
{
  QSignalSpy spy_blockSizeChange(this, &HmclaheWidgetImp::blockSizeChange);
  QSignalSpy spy_lChange(this, &HmclaheWidgetImp::lChange);
  QSignalSpy spy_phiChange(this, &HmclaheWidgetImp::phiChange);

  this->setBlockSize(QSize(5, 7));
  this->setL(0.5);
  this->setPhi(.7);

  this->reset();

  QCOMPARE(spy_blockSizeChange.count(), 0);
  QCOMPARE(spy_lChange.count(), 0);
  QCOMPARE(spy_phiChange.count(), 0);
}

void TestHmclaheWidgetSignals::test_blockSizeChange()
{
  QSignalSpy spy_blockSizeChange(this, &HmclaheWidgetImp::blockSizeChange);

  this->mBlockSizeX->setValue(10);

  QCOMPARE(spy_blockSizeChange.count(), 1);

  QList<QVariant> args = spy_blockSizeChange.takeFirst();
  QCOMPARE(args.at(0).toSize(), QSize(10, 17));

  this->setBlockSize(QSize(5, 7));
  QCOMPARE(spy_blockSizeChange.count(), 0);
}

void TestHmclaheWidgetSignals::test_lChange()
{
  QSignalSpy spy_lChange(this, &HmclaheWidgetImp::lChange);

  mL->setValue(0.25);

  QCOMPARE(spy_lChange.count(), 1);

  QList<QVariant> args = spy_lChange.takeFirst();
  QCOMPARE(args.at(0).toDouble(), 0.25);

  this->setL(0.5);
  QCOMPARE(spy_lChange.count(), 0);
}

void TestHmclaheWidgetSignals::test_phiChange()
{
  QSignalSpy spy_phiChange(this, &HmclaheWidgetImp::phiChange);

  mPhi->setValue(.4);

  QCOMPARE(spy_phiChange.count(), 1);

  QList<QVariant> args = spy_phiChange.takeFirst();
  QCOMPARE(args.at(0).toDouble(), 0.4);

  this->setPhi(.7);
  QCOMPARE(spy_phiChange.count(), 0);
}



QTEST_MAIN(TestHmclaheWidgetSignals)

#include "tst_hmclahewidgetsignals.moc"
