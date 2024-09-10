#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>
#include <QRunnable>

class ThreadWorker : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit ThreadWorker(QObject *parent = nullptr);

    void run() override;

signals:
    void end();
};

#endif // THREADWORKER_H
