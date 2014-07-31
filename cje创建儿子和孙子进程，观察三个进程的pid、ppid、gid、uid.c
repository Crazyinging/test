/*
创建儿子和孙子进程，观察三个进程的pid、ppid、gid、uid
*/


#include"stdio.h"
#include"unistd.h"
#include"stdlib.h"

int main(int argc, char * argv[])
{
    pid_t pid, pid1, pid2;
    int time1, time2;
    int i;

    time1 = time2 = 0;
    for(i = 0; argv[1][i]; i++) time1 = time1*10 + argv[1][i]-'0';
    for(i = 0; argv[2][i]; i++) time2 = time2*10 + argv[2][i]-'0';
    printf("time1=%d, time2=%d\n", time1, time2);

    if ((pid = fork()) < 0) {       /*父进程fork*/
        printf("fork error\n");
        return 0;
    } else if (pid != 0) {
        printf("父进程pid = %d，gid = %d，uid = %d, ppid=%d\n", getpid(), getgid(), getuid(), getppid());
        printf("父进程开始沉睡，睡%d秒\n", time1);
        sleep(time1);
        printf("父进程醒来并自杀\n");
        exit(0);
    } else{
        if ((pid1 = fork()) < 0) {      /*一级子进程fork*/
            printf("子进程制造孙子失败，子进程退出\n");
            exit(0);
           } else if (pid1 != 0) {
            int a, b;
            int cost = 0;
            b = a = getppid();
            printf("子进程：pid=%d, gid=%d, uid=%d, ppid=%d\n", getpid(), getgid(), getuid(), getppid());
            printf("子进程沉睡%d秒，start\n", time2);
            sleep(time2);
            cost += time2;
            printf("子进程醒来\n");
            printf("子进程醒来后：pid=%d, gid=%d, uid=%d, ppid=%d\n", getpid(), getgid(), getuid(), getppid());
            printf("儿子自杀\n");
        } else {
            printf("孙子进程：pid=%d, gid=%d, uid=%d, ppid=%d\n", getpid(), getgid(), getuid(), getppid());
            printf("孙子自杀\n");
            exit(0);
        }
    }

    printf("进程醒来后：pid=%d, gid=%d, uid=%d, ppid=%d\n", getpid(), getgid(), getuid(), getppid());
    exit(0);
}
