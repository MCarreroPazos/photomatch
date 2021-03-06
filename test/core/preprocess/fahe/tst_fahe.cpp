#include <QtTest>
#include <QCoreApplication>

#include "photomatch/photomatch_global.h"
#include "photomatch/core/preprocess/fahe.h"

using namespace photomatch;

class TestFahe 
  : public QObject
{
  Q_OBJECT

public:

  TestFahe();
  ~TestFahe();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_copyConstructors();
  void test_moveConstructors();
  void test_type();
  void test_name();
  void test_tilesGridSize_data();
  void test_tilesGridSize();

private:

  FahePreprocess *mFahePreprocess;
};

TestFahe::TestFahe()
  : mFahePreprocess(new FahePreprocess)
{

}

TestFahe::~TestFahe()
{
  if (mFahePreprocess){
    delete mFahePreprocess;
    mFahePreprocess = nullptr;
  }
}

void TestFahe::initTestCase()
{
  QCOMPARE(QSize(11, 11), mFahePreprocess->blockSize());
}


void TestFahe::cleanupTestCase()
{
  mFahePreprocess->setBlockSize(QSize(5, 5));

  mFahePreprocess->reset();

  QCOMPARE(QSize(11, 11), mFahePreprocess->blockSize());
}

void TestFahe::test_copyConstructors()
{
  FahePreprocess fahePreprocess(QSize(13, 13));
  FahePreprocess copy(fahePreprocess);
  QCOMPARE(QSize(13, 13), copy.blockSize());
}

void TestFahe::test_moveConstructors()
{
  FahePreprocess move(FahePreprocess(QSize(13, 13)));
  QCOMPARE(QSize(13, 13), move.blockSize());
}

void TestFahe::test_type()
{
  QCOMPARE(Preprocess::Type::fahe, mFahePreprocess->type());
}

void TestFahe::test_name()
{
  QCOMPARE(QString("FAHE"), mFahePreprocess->name());
}

void TestFahe::test_tilesGridSize_data()
{
  QTest::addColumn<QSize>("value");
  QTest::addColumn<QSize>("result");

  QTest::newRow("QSize(1,1)") << QSize(1,1) << QSize(1,1);
  QTest::newRow("QSize(50, 50)") << QSize(50, 50) << QSize(50, 50);
}

void TestFahe::test_tilesGridSize()
{
  QFETCH(QSize, value);
  QFETCH(QSize, result);

  mFahePreprocess->setBlockSize(value);
  QCOMPARE(result, mFahePreprocess->blockSize());
}

QTEST_MAIN(TestFahe)

#include "tst_fahe.moc"
