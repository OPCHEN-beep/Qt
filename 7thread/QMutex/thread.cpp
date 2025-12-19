#include "thread.h"
#include <QMutexLocker>

int Thread::num = 0;

QMutex Thread::mutex;

Thread::Thread()
{

}

void Thread::run()
{
    for(int i = 0; i < 50000; i++)
    {
        //可以避免忘记解锁的情况
        QMutexLocker locker(&mutex);

        //mutex.lock();
        num++;
        //mutex.unlock();
    }
}
