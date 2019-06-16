#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include <iostream>

using namespace std;

const int num = 100;

__thread int threadNum;

__thread const char* threadName = "wd";

void* threadFun1(void* args)
{
    printf(">> th1 : &errno : %p\n", &errno);
    threadNum = 11111;
    printf(">> thread1 : threadNum : %d\n", threadNum);
    printf(">> thread1 : &threadNum : %p\n", &threadNum);
    char name[20] = "thread one";
    threadName = name;
    printf(">> threadName: %s\n", threadName);
    return nullptr;
}

void* threadFun2(void* args)
{
    printf(">> th2 : &errno : %p\n", &errno);
    threadNum = 22222;
    printf(">> thread2 : threadNum : %d\n", threadNum);
    printf(">> thread2 : &threadNum : %p\n", &threadNum);
    char name[20] = "thread two";
    threadName = name;
    printf(">> threadName: %s\n", threadName);
    return nullptr;
}

int main()
{
    printf(">> main thread : &errno : %p\n", &errno);
    threadNum = 8848;
    printf(">> main thread : threadNum : %d\n", threadNum);
    printf(">> main thread : &threadNum : %p\n", &threadNum);
    char name[20] = "main thread";
    threadName = name;
    printf(">> threadName: %s\n", threadName);

    pthread_t th1, th2;
    pthread_create(&th1, nullptr, threadFun1, nullptr);
    pthread_create(&th2, nullptr, threadFun2, nullptr);

    sleep(2);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    return 0;
}

