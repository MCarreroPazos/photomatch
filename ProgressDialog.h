#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QTextEdit>

#include "Process.h"
#include "ProcessManager/Process.h"
namespace Ui {
    class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = 0);
    ~ProgressDialog();

    void setStatusText(QString text);
    void setRange(int min, int max);
    void setValue(int value);
    void setProcess(Process *process);
    void setFinished(bool finished);
    void setConsole(QTextEdit *console);
    void setConsoleVisible(bool visible);
    void writeinConsole(QString text);
    void clearConsole();
public slots:
    void onSatutsChanged(int step, QString message);
    void onSatutsChangedNext();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_save_clicked();

private:
    Ui::ProgressDialog *ui;
    Process *mProcess;
    QTextEdit *mConsole;

signals:
    void cancel();
};

#endif // PROGRESSDIALOG_H