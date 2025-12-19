#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    //在这个run中，不可以直接对界面内容修改
    //但是可以针对时间来进行计时
    //当每到了一秒钟的时候，通过信号槽，来通知主线程，负责更新的界面内容
    for(int i = 0; i <10; i++)
    {
        sleep(1);
        //发送一个信号，通知主线程
        emit notify();
    }
}
