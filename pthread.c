#include"stdio.h"
#include"pthread.h"


void * func(void *arg)
{
    int i;
//    char str[1000] = ;

    for (i = 0; i < 10; i++)
        printf("i=%d\n", i);
//        printf("i=%d, str=%s\n", i, arg);
}
int main()
{
    char c1[100] = "thread1";
    char c2[100] = "thread2";
    int error1 = -100000;
    int error2 = -100000;

    pthread_t tid1, tid2, tid3, tid4;
    printf("start\n");
    error1 = pthread_create(&tid1, NULL, func, NULL);
    printf("error1 = %d\n", error1);
    
    error2 = pthread_create(&tid2, NULL, func, NULL);
    printf("error2 = %d\n", error2);


    pthread_create(&tid3, NULL, func, NULL);
    pthread_create(&tid4, NULL, func, NULL);
    return 0;
}
