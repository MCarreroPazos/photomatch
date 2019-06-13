#ifndef FME_EXTERNALPROCESS_H
#define FME_EXTERNALPROCESS_H

#include <QProcess>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QFile>

#include "Process.h"



class FME_EXPORT ExternalProcess
  : public Process
{
    Q_OBJECT

public:
    ExternalProcess(QString commandPath);
    ~ExternalProcess() override;

    virtual void start() override;
    virtual void setWaitForFinished(bool wait) override;
    virtual bool isRunning() override;

    void setWorkingDir(QString workingDir);
    void setErroLogFile(QString filePath);
    void setStdOutputFilePath(QString filePath);
    void setStdErrorFilePath(QString filePath);
    qint64 write(const char *data);

    virtual QByteArray readStdout() override;
    virtual QByteArray readStderr() override;

    //! Insert a evironment variable in the execution environment of de process overwriting it if existing
    /*!
        \param varName variable name
        \param  value new value
      */
//    virtual void insertEnvironmentVar(QString varName, QString value);
    void insertEnvironmentVar(QString varName, QString value);

    //! Append a value to an environment variable in the execution environment of de process using ";" as separator
    /*!
        \param varName variable name
        \param  value new value
        \param position 0 insert de value before (default). 1 insert value after.
      */
//    virtual void appendEnvironmentValue(QString varName, QString value, int position=0);
    void appendEnvironmentValue(QString varName, QString value, int position=0);

    //! direct call to QProcess::error()
    /*!
        \return Error code
      */
    virtual int error();

public slots:
    virtual void stop() override;

protected:
    void run();

    QString mCommandPath;
    QString mWorkingDir;

protected slots:
    void onError(QProcess::ProcessError commandError);
    void onError(QString path);
    void onTimeout();

private slots:
    void on_newStdData();
    void on_newErrorData();
    void on_mProcessFinished(int code);

private:
    QProcess *mProcess;
    int mErrorFileSize;
    QString mErrorFilePath;
    QString mStdOutputFilePath;
    QString mStdErrorFilePath;
    QFile *mStdOutFile;
    QFile *mErrOutFile;
    QFileSystemWatcher *mErrorWatcher;
    QTimer mTimer;
    bool mRunning;

    void cascadeKill(Q_PID pid);
};

#endif // FME_EXTERNALPROCESS_H
