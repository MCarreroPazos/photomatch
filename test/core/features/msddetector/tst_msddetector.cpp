#include <QtTest>
#include <QCoreApplication>

#include "photomatch/core/features/msd.h"

using namespace photomatch;

class TestMsdDetector 
  : public QObject, 
    public photomatch::MsdDetector
{
  Q_OBJECT

public:

  TestMsdDetector();
  ~TestMsdDetector();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_constructor();
  void test_copy_constructor();
  void test_type();
  void test_name();
  void test_thresholdSaliency_data();
  void test_thresholdSaliency();
  void test_pathRadius_data();
  void test_pathRadius();
  void test_knn_data();
  void test_knn();
  void test_areaRadius_data();
  void test_areaRadius();
  void test_scaleFactor_data();
  void test_scaleFactor();
  void test_NMSRadius_data();
  void test_NMSRadius();
  void test_nScales_data();
  void test_nScales();
  void test_nmsScaleR_data();
  void test_nmsScaleR();
  void test_computeOrientations_data();
  void test_computeOrientations();
  void test_affineMSD_data();
  void test_affineMSD();
  void test_tilts_data();
  void test_tilts();

};

TestMsdDetector::TestMsdDetector()
  : photomatch::MsdDetector()
{

}

TestMsdDetector::~TestMsdDetector()
{
  QCOMPARE(250, this->thresholdSaliency());
  QCOMPARE(3, this->patchRadius());
  QCOMPARE(4, this->knn());
  QCOMPARE(5, this->searchAreaRadius());
  QCOMPARE(1.25, this->scaleFactor());
  QCOMPARE(5, this->NMSRadius());
  QCOMPARE(-1, this->nScales());
  QCOMPARE(0, this->NMSScaleRadius());
  QCOMPARE(false, this->computeOrientation());
  QCOMPARE(false, this->affineMSD());
  QCOMPARE(3, this->affineTilts());
}

void TestMsdDetector::initTestCase()
{
  QCOMPARE(250, this->thresholdSaliency());
  QCOMPARE(3, this->patchRadius());
  QCOMPARE(4, this->knn());
  QCOMPARE(5, this->searchAreaRadius());
  QCOMPARE(1.25, this->scaleFactor());
  QCOMPARE(5, this->NMSRadius());
  QCOMPARE(-1, this->nScales());
  QCOMPARE(0, this->NMSScaleRadius());
  QCOMPARE(false, this->computeOrientation());
  QCOMPARE(false, this->affineMSD());
  QCOMPARE(3, this->affineTilts());
}

void TestMsdDetector::cleanupTestCase()
{
  this->setThresholdSaliency(200);
  this->setPatchRadius(4);
  this->setKNN(5);
  this->setSearchAreaRadius(3);
  this->setScaleFactor(1.5);
  this->setNMSRadius(4);
  this->setNScales(3);
  this->setNMSScaleRadius(1);
  this->setComputeOrientation(true);
  this->setAffineMSD(true);
  this->setAffineTilts(4);

  this->reset();

  QCOMPARE(250, this->thresholdSaliency());
  QCOMPARE(250, this->mMSD->getThSaliency());
  QCOMPARE(3, this->patchRadius());
  QCOMPARE(3, this->mMSD->getPatchRadius());
  QCOMPARE(4, this->knn());
  QCOMPARE(4, this->mMSD->getKNN());
  QCOMPARE(5, this->searchAreaRadius());
  QCOMPARE(5, this->mMSD->getSearchAreaRadius());
  QCOMPARE(1.25, this->scaleFactor());
  QCOMPARE(1.25, this->mMSD->getScaleFactor());
  QCOMPARE(5, this->NMSRadius());
  QCOMPARE(5, this->mMSD->getNMSRadius());
  QCOMPARE(-1, this->nScales());
  QCOMPARE(-1, this->mMSD->getNScales());
  QCOMPARE(0, this->NMSScaleRadius());
  QCOMPARE(0, this->mMSD->getNMSScaleRadius());
  QCOMPARE(false, this->computeOrientation());
  QCOMPARE(false, this->affineMSD());
  QCOMPARE(3, this->affineTilts());
}

void TestMsdDetector::test_constructor()
{
  MsdDetector msdDetector(150, 5, 5, 5, 1.5, 2, 3, 1, true, true, 4);
  QCOMPARE(150, msdDetector.thresholdSaliency());
  QCOMPARE(5, msdDetector.patchRadius());
  QCOMPARE(5, msdDetector.knn());
  QCOMPARE(5, msdDetector.searchAreaRadius());
  QCOMPARE(1.5, msdDetector.scaleFactor());
  QCOMPARE(2, msdDetector.NMSRadius());
  QCOMPARE(3, msdDetector.nScales());
  QCOMPARE(1, msdDetector.NMSScaleRadius());
  QCOMPARE(true, msdDetector.computeOrientation());
  QCOMPARE(true, msdDetector.affineMSD());
  QCOMPARE(4, msdDetector.affineTilts());
}

void TestMsdDetector::test_copy_constructor()
{
  MsdDetector msdDetector(150, 5, 5, 5, 1.5, 2, 3, 1, true, true, 4);
  MsdDetector c(msdDetector);
  QCOMPARE(150, c.thresholdSaliency());
  QCOMPARE(5, c.patchRadius());
  QCOMPARE(5, c.knn());
  QCOMPARE(5, c.searchAreaRadius());
  QCOMPARE(1.5, c.scaleFactor());
  QCOMPARE(2, c.NMSRadius());
  QCOMPARE(3, c.nScales());
  QCOMPARE(1, c.NMSScaleRadius());
  QCOMPARE(true, c.computeOrientation());
  QCOMPARE(true, c.affineMSD());
  QCOMPARE(4, c.affineTilts());
}

void TestMsdDetector::test_type()
{
  QCOMPARE(MsdDetector::Type::msd, this->type());
}

void TestMsdDetector::test_name()
{
  QCOMPARE("MSD", this->name());
}

void TestMsdDetector::test_thresholdSaliency_data()
{
  QTest::addColumn<double>("value");
  QTest::addColumn<double>("result");

  QTest::newRow("100") << 100. << 100.;
  QTest::newRow("default") << 250. << 250.;
  QTest::newRow("2000") << 2000. << 2000.;
}

void TestMsdDetector::test_thresholdSaliency()
{
  QFETCH(double, value);
  QFETCH(double, result);

  this->setThresholdSaliency(value);
  QCOMPARE(result, this->thresholdSaliency());
  QCOMPARE(result, this->mMSD->getThSaliency());
}

void TestMsdDetector::test_pathRadius_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("5") << 5 << 5;
  QTest::newRow("default") << 3 << 3;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_pathRadius()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setPatchRadius(value);
  QCOMPARE(result, this->patchRadius());
  QCOMPARE(result, this->mMSD->getPatchRadius());
}

void TestMsdDetector::test_knn_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("5") << 5 << 5;
  QTest::newRow("default") << 4 << 4;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_knn()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setKNN(value);
  QCOMPARE(result, this->knn());
  QCOMPARE(result, this->mMSD->getKNN());
}

void TestMsdDetector::test_areaRadius_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("3") << 3 << 3;
  QTest::newRow("default") << 5 << 5;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_areaRadius()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setSearchAreaRadius(value);
  QCOMPARE(result, this->searchAreaRadius());
  QCOMPARE(result, this->mMSD->getSearchAreaRadius());
}

void TestMsdDetector::test_scaleFactor_data()
{
  QTest::addColumn<double>("value");
  QTest::addColumn<double>("result");

  QTest::newRow("5") << 5. << 5.;
  QTest::newRow("default") << 1.25 << 1.25;
  QTest::newRow("10") << 10. << 10.;
}

void TestMsdDetector::test_scaleFactor()
{
  QFETCH(double, value);
  QFETCH(double, result);

  this->setScaleFactor(value);
  QCOMPARE(result, this->scaleFactor());
  QCOMPARE(result, this->mMSD->getScaleFactor());
}

void TestMsdDetector::test_NMSRadius_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("3") << 3 << 3;
  QTest::newRow("default") << 5 << 5;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_NMSRadius()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setNMSRadius(value);
  QCOMPARE(result, this->NMSRadius());
  QCOMPARE(result, this->mMSD->getNMSRadius());
}

void TestMsdDetector::test_nScales_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("3") << 3 << 3;
  QTest::newRow("default") << -1 << -1;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_nScales()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setNScales(value);
  QCOMPARE(result, this->nScales());
  QCOMPARE(result, this->mMSD->getNScales());
}

void TestMsdDetector::test_nmsScaleR_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("3") << 3 << 3;
  QTest::newRow("default") << 0 << 0;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_nmsScaleR()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setNMSScaleRadius(value);
  QCOMPARE(result, this->NMSScaleRadius());
  QCOMPARE(result, this->mMSD->getNMSScaleRadius());
}

void TestMsdDetector::test_computeOrientations_data()
{
  QTest::addColumn<bool>("value");
  QTest::addColumn<bool>("result");

  QTest::newRow("true") << true << true;
  QTest::newRow("false") << false << false;
}

void TestMsdDetector::test_computeOrientations()
{
  QFETCH(bool, value);
  QFETCH(bool, result);

  this->setComputeOrientation(value);
  QCOMPARE(result, this->computeOrientation());
  QCOMPARE(result, this->mMSD->getComputeOrientation());
}

void TestMsdDetector::test_affineMSD_data()
{
  QTest::addColumn<bool>("value");
  QTest::addColumn<bool>("result");

  QTest::newRow("true") << true << true;
  QTest::newRow("false") << false << false;
}

void TestMsdDetector::test_affineMSD()
{
  QFETCH(bool, value);
  QFETCH(bool, result);

  this->setAffineMSD(value);
  QCOMPARE(result, this->affineMSD());
}

void TestMsdDetector::test_tilts_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("5") << 5 << 5;
  QTest::newRow("default") << 3 << 3;
  QTest::newRow("10") << 10 << 10;
}

void TestMsdDetector::test_tilts()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setAffineTilts(value);
  QCOMPARE(result, this->affineTilts());
}

QTEST_APPLESS_MAIN(TestMsdDetector)

#include "tst_msddetector.moc"
