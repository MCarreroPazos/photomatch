#include <QtTest>

#include "fme/core/session.h"

using namespace fme;


class TestSession : public QObject
{
  Q_OBJECT

public:

  TestSession();
  ~TestSession();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void testConstructor();
  void test_name_data();
  void test_name();
  void test_description_data();
  void test_description();
  void test_clear();

protected:

  ISession *mSession;
};

TestSession::TestSession()
  : mSession(new Session)
{

}

TestSession::~TestSession()
{
  if (mSession) {
    delete mSession;
    mSession = nullptr;
  }
}

void TestSession::initTestCase()
{
  
}

void TestSession::cleanupTestCase()
{

}

void TestSession::testConstructor()
{
  Session session;
  QCOMPARE(QString(), session.name());
  QCOMPARE(QString(), session.description());
}

void TestSession::test_name_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<QString>("result");

  QTest::newRow("Session01") << "Session01" << "Session01";
  QTest::newRow("Session02") << "Session02" << "Session02";
}

void TestSession::test_name()
{
  QFETCH(QString, value);
  QFETCH(QString, result);

  mSession->setName(value);
  QCOMPARE(result, mSession->name());
}

void TestSession::test_description_data()
{
  QTest::addColumn<QString>("value");
  QTest::addColumn<QString>("result");

  QTest::newRow("Description1") << "Descripción de la sesión 1" << "Descripción de la sesión 1";
  QTest::newRow("Description2") << "Descripción de la sesión 2" << "Descripción de la sesión 2";
}

void TestSession::test_description()
{
  QFETCH(QString, value);
  QFETCH(QString, result);

  mSession->setDescription(value);
  QCOMPARE(result, mSession->description());
}

void TestSession::test_clear()
{
  mSession->setName("Session03");
  mSession->setDescription("Descripción de la sesión 3");
  
  mSession->clear();
  
  QCOMPARE(QString(), mSession->name());
  QCOMPARE(QString(), mSession->description());
}

QTEST_APPLESS_MAIN(TestSession)

#include "tst_session.moc"