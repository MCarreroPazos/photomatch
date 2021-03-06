#include <QtTest>
#include <QCoreApplication>

#include "photomatch/photomatch_global.h"
#include "photomatch/core/preprocess/dhe.h"

using namespace photomatch;

class TestDhe 
  : public QObject
{
  Q_OBJECT

public:

  TestDhe();
  ~TestDhe();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_copyConstructors();
  void test_moveConstructors();
  void test_type();
  void test_name();
  void test_x_data();
  void test_x();

private:

  DhePreprocess *mDhePreprocess;
};

TestDhe::TestDhe()
  : mDhePreprocess(new DhePreprocess)
{

}

TestDhe::~TestDhe()
{
  if (mDhePreprocess){
    delete mDhePreprocess;
    mDhePreprocess = nullptr;
  }
}

void TestDhe::initTestCase()
{
  QCOMPARE(1, mDhePreprocess->x());
}

void TestDhe::cleanupTestCase()
{
  mDhePreprocess->setX(3);

  mDhePreprocess->reset();

  QCOMPARE(1, mDhePreprocess->x());
}

void TestDhe::test_copyConstructors()
{
  DhePreprocess dhePreprocess(1);
  DhePreprocess copy(dhePreprocess);
  QCOMPARE(1, copy.x());
}

void TestDhe::test_moveConstructors()
{
  DhePreprocess move(DhePreprocess(1));
  QCOMPARE(1, move.x());
}

void TestDhe::test_type()
{
  QCOMPARE(Preprocess::Type::dhe, mDhePreprocess->type());
}

void TestDhe::test_name()
{
  QCOMPARE(QString("DHE"), mDhePreprocess->name());
}

void TestDhe::test_x_data()
{
  QTest::addColumn<int>("value");
  QTest::addColumn<int>("result");

  QTest::newRow("1") << 1 << 1;
  QTest::newRow("2") << 2 << 2;
}

void TestDhe::test_x()
{
  QFETCH(int, value);
  QFETCH(int, result);

  mDhePreprocess->setX(value);
  QCOMPARE(result, mDhePreprocess->x());
}


QTEST_MAIN(TestDhe)

#include "tst_dhe.moc"
