#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QDebug>

#include "threadworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto *worker = new ThreadWorker();
    QObject::connect(worker, &ThreadWorker::end, [&]() {
        qDebug() << "Worker say Hello from slot:" << QThread::currentThreadId();
        a.exit(0);
    });

    qDebug() << "App say Hello from main thread:" << QThread::currentThreadId();

    QThreadPool::globalInstance()->start(worker);

    return a.exec();
}
