#ifndef FME_PROCESS_H
#define FME_PROCESS_H

#include "fme/fme_global.h"

#include <QThread>
#include <QStringList>



class FME_EXPORT Process
  : public QObject
{
    Q_OBJECT

public:

    Process();
    virtual ~Process() = default;

    virtual void        start()=0;
    virtual void        setWaitForFinished(bool wait)=0;
    virtual bool        isRunning()=0;
    virtual QByteArray  readStdout()=0;
    virtual QByteArray  readStderr()=0;

    virtual bool        isStopped();
    virtual int         getSteps();

    void                addIntputs (QStringList inputs);
    //QStringList         getOutputs ();
    QString             getStartupMessage();
    void                setStartupMessage(QString message);
    void                setSteps(int steps);

public slots:

    virtual void stop();


signals:

    void statusChanged(int step, QString message);
    void statusChangedNext();
    void finished();
    void error(int errorCode, QString errorMessage);

    //For real-time output reading.
    void readyReadStandardOutput();
    void readyReadStandardError();
    void newStdData(QString data);
    void newErrorData(QString data);


protected:

    QStringList mInputs;
    bool mStopped;

private:

    int mSteps;
    QString mStartupMessage;

};

#endif // FME_PROCESS_H
