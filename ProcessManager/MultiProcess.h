#ifndef MULTIPROCESS_H
#define MULTIPROCESS_H

#include <QList>

#include "Process.h"


class MultiProcess : public Process
{

    Q_OBJECT

public:
    MultiProcess();
    MultiProcess(bool isSequential);
    ~MultiProcess();

    virtual void start();
    virtual void setWaitForFinished(bool wait);
    virtual bool isRunning();

    virtual QByteArray readStdout();
    virtual QByteArray readStderr();

    void appendProcess(Process *process);
    void appendProcess(QList<Process*> processList);
    void clearProcessList();
    int count();
    Process * at(int i);

    virtual int getSteps();

public slots:
    virtual void stop();

protected:
    void run();

private:
    QList<Process*> mProcessList;
    bool mIsSequential;
    int mCurrentProcess;
    int mRunningCount;
    int mIdealThreadCount;
    int mFinishedCount;
    int mCurrentStep;
    bool mConcatenateMessages;
    bool mWaitForFinished;

private slots:
    void onError(int code, QString cause);
    void onAProcessFinished();
    void OnChildStatusChanged(int step, QString childMessage);
    void OnChildStatusChangedNext();
};


#endif // MULTIPROCESS_H
