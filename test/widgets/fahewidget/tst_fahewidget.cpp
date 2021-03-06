#include <QtTest>
#include <QCoreApplication>

#include "photomatch/widgets/FaheWidget.h"

using namespace photomatch;

class TestFaheWidget : public QObject
{
  Q_OBJECT

public:

  TestFaheWidget();
  ~TestFaheWidget();

private slots:

  void initTestCase();
  void cleanupTestCase();
  void test_windowTitle();
  void test_blockSize_data();
  void test_blockSize();

private:

  FaheWidget *mFaheWidget;
};

TestFaheWidget::TestFaheWidget()
  : mFaheWidget(new FaheWidgetImp)
{

}

TestFaheWidget::~TestFaheWidget()
{
  if (mFaheWidget){
    delete mFaheWidget;
    mFaheWidget = nullptr;
  }
}

void TestFaheWidget::initTestCase()
{
  /// Check default values
  QCOMPARE(QSize(11, 11), mFaheWidget->blockSize());
}

void TestFaheWidget::cleanupTestCase()
{
  mFaheWidget->setBlockSize(QSize(5, 5));

  mFaheWidget->reset();

  QCOMPARE(QSize(11, 11), mFaheWidget->blockSize());
}

void TestFaheWidget::test_windowTitle()
{
  QCOMPARE("FAHE", mFaheWidget->windowTitle());
}

void TestFaheWidget::test_blockSize_data()
{
  QTest::addColumn<QSize>("value");
  QTest::addColumn<QSize>("result");

  QTest::newRow("QSize(1,1)") << QSize(1,1) << QSize(1,1);
  QTest::newRow("QSize(50, 50)") << QSize(50, 50) << QSize(50, 50);
  QTest::newRow("Out of range value x") << QSize(1001, 50) << QSize(1000, 50);
  QTest::newRow("Out of range value y") << QSize(50, 1001) << QSize(50, 1000);
}

void TestFaheWidget::test_blockSize()
{
  QFETCH(QSize, value);
  QFETCH(QSize, result);

  mFaheWidget->setBlockSize(value);
  QCOMPARE(result, mFaheWidget->blockSize());
}


QTEST_MAIN(TestFaheWidget)

#include "tst_fahewidget.moc"
