#include <QtTest>
#include <QCoreApplication>

#include "photomatch/widgets/OrbWidget.h"

#include <QSpinBox>
#include <QList>
#include <QComboBox>

using namespace photomatch;

class TestOrbWidgetSignals : public OrbWidgetImp
{
  Q_OBJECT

public:

  TestOrbWidgetSignals();
  ~TestOrbWidgetSignals();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_featuresNumberChange();
  void test_scaleFactorChange();
  void test_levelsNumberChange();
  void test_edgeThresholdChange();
  void test_wta_KChange();
  void test_scoreTypeChange();
  void test_patchSizeChange();
  void test_fastThresholdChange();

};

TestOrbWidgetSignals::TestOrbWidgetSignals()
  : OrbWidgetImp()
{

}

TestOrbWidgetSignals::~TestOrbWidgetSignals()
{

}

void TestOrbWidgetSignals::initTestCase()
{

}

void TestOrbWidgetSignals::cleanupTestCase()
{
  QSignalSpy spyFeaturesNumber(this, &OrbWidgetImp::featuresNumberChange);
  QSignalSpy spyScaleFactor(this, &OrbWidgetImp::scaleFactorChange);
  QSignalSpy spyLevelsNumber(this, &OrbWidgetImp::levelsNumberChange);
  QSignalSpy spyEdgeThreshold(this, &OrbWidgetImp::edgeThresholdChange);
  QSignalSpy spyWTA_K(this, &OrbWidgetImp::wta_kChange);
  QSignalSpy spyScoreType(this, &OrbWidgetImp::scoreTypeChange);
  QSignalSpy spyPatchSize(this, &OrbWidgetImp::patchSizeChange);
  QSignalSpy spyFastThreshold(this, &OrbWidgetImp::fastThresholdChange);

  this->setFeaturesNumber(1200);
  this->setScaleFactor(3.0);
  this->setLevelsNumber(3);
  this->setEdgeThreshold(11);
  this->setWTA_K(2);
  this->setScoreType("Harris");
  this->setPatchSize(12);
  this->setFastThreshold(25);

  this->reset();

  QCOMPARE(spyFeaturesNumber.count(), 0);
  QCOMPARE(spyScaleFactor.count(), 0);
  QCOMPARE(spyLevelsNumber.count(), 0);
  QCOMPARE(spyEdgeThreshold.count(), 0);
  QCOMPARE(spyWTA_K.count(), 0);
  QCOMPARE(spyScoreType.count(), 0);
  QCOMPARE(spyPatchSize.count(), 0);
  QCOMPARE(spyFastThreshold.count(), 0);
}

void TestOrbWidgetSignals::test_featuresNumberChange()
{
  QSignalSpy spyFeaturesNumber(this, &OrbWidgetImp::featuresNumberChange);

  this->mFeaturesNumber->setValue(1500);

  QCOMPARE(spyFeaturesNumber.count(), 1);

  QList<QVariant> args = spyFeaturesNumber.takeFirst();
  QCOMPARE(args.at(0).toInt(), 1500);

  this->setFeaturesNumber(1200);
  QCOMPARE(spyFeaturesNumber.count(), 0);
}

void TestOrbWidgetSignals::test_scaleFactorChange()
{
  QSignalSpy spyScaleFactor(this, &OrbWidgetImp::scaleFactorChange);

  this->mScaleFactor->setValue(3.5);

  QCOMPARE(spyScaleFactor.count(), 1);

  QList<QVariant> args = spyScaleFactor.takeFirst();
  QCOMPARE(args.at(0).toDouble(), 3.5);

  this->setScaleFactor(3.0);
  QCOMPARE(spyScaleFactor.count(), 0);
}

void TestOrbWidgetSignals::test_levelsNumberChange()
{
  QSignalSpy spyLevelsNumber(this, &OrbWidgetImp::levelsNumberChange);

  this->mLevelsNumber->setValue(4);

  QCOMPARE(spyLevelsNumber.count(), 1);

  QList<QVariant> args = spyLevelsNumber.takeFirst();
  QCOMPARE(args.at(0).toInt(), 4);

  this->setLevelsNumber(3);
  QCOMPARE(spyLevelsNumber.count(), 0);
}

void TestOrbWidgetSignals::test_edgeThresholdChange()
{
  QSignalSpy spyEdgeThreshold(this, &OrbWidgetImp::edgeThresholdChange);

  this->mEdgeThreshold->setValue(15);

  QCOMPARE(spyEdgeThreshold.count(), 1);

  QList<QVariant> args = spyEdgeThreshold.takeFirst();
  QCOMPARE(args.at(0).toInt(), 15);

  this->setEdgeThreshold(11);
  QCOMPARE(spyEdgeThreshold.count(), 0);
}

void TestOrbWidgetSignals::test_wta_KChange()
{
  QSignalSpy spyWTA_K(this, &OrbWidgetImp::wta_kChange);

  this->mWTA_K->setValue(4);

  QCOMPARE(spyWTA_K.count(), 1);

  QList<QVariant> args = spyWTA_K.takeFirst();
  QCOMPARE(args.at(0).toInt(), 4);

  this->setWTA_K(2);
  QCOMPARE(spyWTA_K.count(), 0);
}

void TestOrbWidgetSignals::test_scoreTypeChange()
{
  QSignalSpy spyScoreType(this, &OrbWidgetImp::scoreTypeChange);

  this->mScoreType->setCurrentText("FAST");

  QCOMPARE(spyScoreType.count(), 1);

  QList<QVariant> args = spyScoreType.takeFirst();
  QCOMPARE(args.at(0).toString(), "FAST");

  this->mScoreType->setCurrentText("FAST");
  QCOMPARE(spyScoreType.count(), 0);

  this->setScoreType("Harris");
  QCOMPARE(spyScoreType.count(), 0);
}

void TestOrbWidgetSignals::test_patchSizeChange()
{
  QSignalSpy spyPatchSize(this, &OrbWidgetImp::patchSizeChange);

  this->mPatchSize->setValue(15);

  QCOMPARE(spyPatchSize.count(), 1);

  QList<QVariant> args = spyPatchSize.takeFirst();
  QCOMPARE(args.at(0).toInt(), 15);

  this->setPatchSize(12);
  QCOMPARE(spyPatchSize.count(), 0);
}

void TestOrbWidgetSignals::test_fastThresholdChange()
{
  QSignalSpy spyFastThreshold(this, &OrbWidgetImp::fastThresholdChange);

  this->mFastThreshold->setValue(50);

  QCOMPARE(spyFastThreshold.count(), 1);

  QList<QVariant> args = spyFastThreshold.takeFirst();
  QCOMPARE(args.at(0).toInt(), 50);

  this->setFastThreshold(25);
  QCOMPARE(spyFastThreshold.count(), 0);
}

QTEST_MAIN(TestOrbWidgetSignals)

#include "tst_orbwidgetsignals.moc"
