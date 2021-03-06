#include <QtTest>
#include <QCoreApplication>

#include "photomatch/core/features/akaze.h"

using namespace photomatch;

class TestAkazeDetectorDescriptor
  : public QObject,
    public AkazeDetectorDescriptor
{
  Q_OBJECT

public:
  TestAkazeDetectorDescriptor();
  ~TestAkazeDetectorDescriptor();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_constructor();
  void test_copy_constructor();
  void test_type();
  void test_name();
  void test_descriptorType_data();
  void test_descriptorType();
  void test_descriptorType2_data();
  void test_descriptorType2();
  void test_descriptorSize_data();
  void test_descriptorSize();
  void test_descriptorChannels_data();
  void test_descriptorChannels();
  void test_threshold_data();
  void test_threshold();
  void test_octaves_data();
  void test_octaves();
  void test_octaveLayers_data();
  void test_octaveLayers();
  void test_diffusivity_data();
  void test_diffusivity();
  void test_diffusivity2_data();
  void test_diffusivity2();
};

TestAkazeDetectorDescriptor::TestAkazeDetectorDescriptor()
  : AkazeDetectorDescriptor()
{
}

TestAkazeDetectorDescriptor::~TestAkazeDetectorDescriptor()
{

}

void TestAkazeDetectorDescriptor::initTestCase()
{
  QCOMPARE("MLDB", this->descriptorType());
  QCOMPARE(0, this->descriptorSize());
  QCOMPARE(3, this->descriptorChannels());
  qFuzzyCompare(0.001, this->threshold());
  QCOMPARE(4, this->octaves());
  QCOMPARE(4, this->octaveLayers());
  QCOMPARE("DIFF_PM_G2", this->diffusivity());
}

void TestAkazeDetectorDescriptor::cleanupTestCase()
{
  this->setDescriptorType("KAZE");
  this->setDescriptorSize(32);
  this->setDescriptorChannels(2);
  this->setThreshold(50.);
  this->setOctaves(2);
  this->setOctaveLayers(5);
  this->setDiffusivity("DIFF_PM_G1");

  this->reset();

  QCOMPARE("MLDB", this->descriptorType());
  QCOMPARE(5, this->mAkaze->getDescriptorType());
  QCOMPARE(0, this->descriptorSize());
  QCOMPARE(0, this->mAkaze->getDescriptorSize());
  QCOMPARE(3, this->descriptorChannels());
  QCOMPARE(3, this->mAkaze->getDescriptorChannels());
  qFuzzyCompare(0.001, this->threshold());
  qFuzzyCompare(0.001, this->mAkaze->getThreshold());
  QCOMPARE(4, this->octaves());
  QCOMPARE(4, mAkaze->getNOctaves());
  QCOMPARE(4, this->octaveLayers());
  QCOMPARE(4, this->mAkaze->getNOctaveLayers());
  QCOMPARE("DIFF_PM_G2", this->diffusivity());
  QCOMPARE(1, this->mAkaze->getDiffusivity());
}

void TestAkazeDetectorDescriptor::test_constructor()
{
  AkazeDetectorDescriptor akazeDetectorDescriptor("KAZE_UPRIGHT", 32, 4, 0.1, 3, 6, "DIFF_WEICKERT");
  QCOMPARE("KAZE_UPRIGHT", akazeDetectorDescriptor.descriptorType());
  QCOMPARE(32, akazeDetectorDescriptor.descriptorSize());
  QCOMPARE(4, akazeDetectorDescriptor.descriptorChannels());
  QCOMPARE(0.1, akazeDetectorDescriptor.threshold());
  QCOMPARE(3, akazeDetectorDescriptor.octaves());
  QCOMPARE(6, akazeDetectorDescriptor.octaveLayers());
  QCOMPARE("DIFF_WEICKERT", akazeDetectorDescriptor.diffusivity());
}

void TestAkazeDetectorDescriptor::test_copy_constructor()
{
  AkazeDetectorDescriptor akazeDetectorDescriptor("KAZE_UPRIGHT", 32, 4, 0.1, 3, 6, "DIFF_WEICKERT");
  AkazeDetectorDescriptor copy(akazeDetectorDescriptor);
  QCOMPARE("KAZE_UPRIGHT", copy.descriptorType());
  QCOMPARE(32, copy.descriptorSize());
  QCOMPARE(4, copy.descriptorChannels());
  QCOMPARE(0.1, copy.threshold());
  QCOMPARE(3, copy.octaves());
  QCOMPARE(6, copy.octaveLayers());
  QCOMPARE("DIFF_WEICKERT", copy.diffusivity());
}

void TestAkazeDetectorDescriptor::test_type()
{
  QCOMPARE(AkazeDetectorDescriptor::Type::akaze, this->type());
}

void TestAkazeDetectorDescriptor::test_name()
{
  QCOMPARE("AKAZE", this->name());
}

void TestAkazeDetectorDescriptor::test_descriptorType_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<QString>("result");

  QTest::newRow("KAZE") << "KAZE" << "KAZE";
  QTest::newRow("KAZE_UPRIGHT") << "KAZE_UPRIGHT" << "KAZE_UPRIGHT";
  QTest::newRow("MLDB") << "MLDB" << "MLDB";
  QTest::newRow("MLDB_UPRIGHT") << "MLDB_UPRIGHT" << "MLDB_UPRIGHT";
}

void TestAkazeDetectorDescriptor::test_descriptorType()
{
  QFETCH(QString, value);
  QFETCH(QString, result);

  this->setDescriptorType(value);
  QCOMPARE(result, this->descriptorType());
}

void TestAkazeDetectorDescriptor::test_descriptorType2_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("KAZE") << "KAZE" << 3;
  QTest::newRow("KAZE_UPRIGHT") << "KAZE_UPRIGHT" << 2;
  QTest::newRow("MLDB") << "MLDB" << 5;
  QTest::newRow("MLDB_UPRIGHT") << "MLDB_UPRIGHT" << 4;
}

void TestAkazeDetectorDescriptor::test_descriptorType2()
{
  QFETCH(QString, value);
  QFETCH(int, result);

  this->setDescriptorType(value);
  QCOMPARE(result, this->mAkaze->getDescriptorType());
}

void TestAkazeDetectorDescriptor::test_descriptorSize_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("0") << 0 << 0;
  QTest::newRow("32") << 32 << 32;
  QTest::newRow("64") << 64 << 64;
}

void TestAkazeDetectorDescriptor::test_descriptorSize()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setDescriptorSize(value);
  QCOMPARE(result, this->descriptorSize());
  QCOMPARE(result, this->mAkaze->getDescriptorSize());
}

void TestAkazeDetectorDescriptor::test_descriptorChannels_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("1") << 1 << 1;
  QTest::newRow("2") << 2 << 2;
  QTest::newRow("3") << 3 << 3;
}

void TestAkazeDetectorDescriptor::test_descriptorChannels()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setDescriptorChannels(value);
  QCOMPARE(result, this->descriptorChannels());
  QCOMPARE(result, this->mAkaze->getDescriptorChannels());
}

void TestAkazeDetectorDescriptor::test_threshold_data()
{
  QTest::addColumn<double>("value");
  QTest::addColumn<double>("result");

  QTest::newRow("5.0") << 5.0 << 5.0;
  QTest::newRow("10.0") << 10.0 << 10.0;
  QTest::newRow("20.0") << 20.0 << 20.0;
}

void TestAkazeDetectorDescriptor::test_threshold()
{
  QFETCH(double, value);
  QFETCH(double, result);

  this->setThreshold(value);
  QCOMPARE(result, this->threshold());
  QCOMPARE(result, this->mAkaze->getThreshold());
}

void TestAkazeDetectorDescriptor::test_octaves_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("4") << 4 << 4;
  QTest::newRow("8") << 8 << 8;
}

void TestAkazeDetectorDescriptor::test_octaves()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setOctaves(value);
  QCOMPARE(result, this->octaves());
  QCOMPARE(result, mAkaze->getNOctaves());
}

void TestAkazeDetectorDescriptor::test_octaveLayers_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("3") << 3 << 3;
  QTest::newRow("8") << 8 << 8;
}

void TestAkazeDetectorDescriptor::test_octaveLayers()
{
  QFETCH(int, value);
  QFETCH(int, result);

  this->setOctaveLayers(value);
  QCOMPARE(result, this->octaveLayers());
  QCOMPARE(result, this->mAkaze->getNOctaveLayers());
}

void TestAkazeDetectorDescriptor::test_diffusivity_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<QString>("result");

  QTest::newRow("DIFF_PM_G1") << "DIFF_PM_G1" << "DIFF_PM_G1";
  QTest::newRow("DIFF_PM_G2") << "DIFF_PM_G2" << "DIFF_PM_G2";
  QTest::newRow("DIFF_WEICKERT") << "DIFF_WEICKERT" << "DIFF_WEICKERT";
  QTest::newRow("DIFF_CHARBONNIER") << "DIFF_CHARBONNIER" << "DIFF_CHARBONNIER";
}

void TestAkazeDetectorDescriptor::test_diffusivity()
{
  QFETCH(QString, value);
  QFETCH(QString, result);

  this->setDiffusivity(value);
  QCOMPARE(result, this->diffusivity());
}

void TestAkazeDetectorDescriptor::test_diffusivity2_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("DIFF_PM_G1") << "DIFF_PM_G1" << 0;
  QTest::newRow("DIFF_PM_G2") << "DIFF_PM_G2" << 1;
  QTest::newRow("DIFF_WEICKERT") << "DIFF_WEICKERT" << 2;
  QTest::newRow("DIFF_CHARBONNIER") << "DIFF_CHARBONNIER" << 3;
}

void TestAkazeDetectorDescriptor::test_diffusivity2()
{
  QFETCH(QString, value);
  QFETCH(int, result);

  this->setDiffusivity(value);
  QCOMPARE(result, this->mAkaze->getDiffusivity());
}

QTEST_APPLESS_MAIN(TestAkazeDetectorDescriptor)

#include "tst_akazedetectordescriptor.moc"
