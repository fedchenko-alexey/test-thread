#include <QThread>
#include <QDebug>

#include "threadworker.h"

ThreadWorker::ThreadWorker(QObject *parent)
    : QObject{parent}
{}

void ThreadWorker::run()
{
    qDebug() << "Worker say Hello from thread:" << QThread::currentThreadId();

    QThread::msleep(1542);
    qDebug() << "Worker say Hello from thread:" << QThread::currentThreadId() << "after 1542 ms sleep.";

    emit end();
}
