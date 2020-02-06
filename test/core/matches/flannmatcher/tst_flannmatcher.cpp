#include <QtTest>
#include <QCoreApplication>

#include "photomatch/photomatch_global.h"
#include "photomatch/core/features/matcher.h"

using namespace photomatch;

class TestFlannMatcher 
  : public QObject
{
  Q_OBJECT

public:

  TestFlannMatcher();
  ~TestFlannMatcher();

private slots:

  void test_type();
  void test_name();

private:

  FlannMatcherImp *mFlannMatcher;
};

TestFlannMatcher::TestFlannMatcher()
  : mFlannMatcher(new FlannMatcherImp)
{

}

TestFlannMatcher::~TestFlannMatcher()
{
  if (mFlannMatcher){
    delete mFlannMatcher;
    mFlannMatcher = nullptr;
  }
}

void TestFlannMatcher::test_type()
{
  QCOMPARE(MatchingMethod::Type::flann, mFlannMatcher->type());
}

void TestFlannMatcher::test_name()
{
  QCOMPARE(QString("Flann Based Matching"), mFlannMatcher->name());
}


QTEST_MAIN(TestFlannMatcher)

#include "tst_flannmatcher.moc"
