#ifndef PROCESSCONCURRENT_H
#define PROCESSCONCURRENT_H

#include <QFutureWatcher>
#include "Process.h"
#include "opencv/cv.hpp"
class  ProcessConcurrent : public Process
{   
    Q_OBJECT

public:
    ProcessConcurrent();

    virtual void start();
    virtual void setWaitForFinished(bool wait);
    virtual bool isRunning();

    virtual QByteArray readStdout();
    virtual QByteArray readStderr();

public slots:
    virtual void stop();
    void on_mProcessFinished();

protected:
    virtual void run()=0;
    int runLauncher();

private:
    bool mRunning;
    QFutureWatcher<int> *mWatcher;
    bool mWait;

};

//template <class T>
//class ProcessConcurrentList : public Process
//{
//public:

//    ProcessConcurrentList(QVector<T> v);
//    ~ProcessConcurrentList();

//    virtual void ProcessConcurrentList::run();

//protected:
//    //template <class T> virtual int run();
//    QVector<T> mVector;

//private:
//    bool mRunning;
//    QFutureWatcher<int> *mWatcher;
//};


#endif // PROCESSCONCURRENT_H
