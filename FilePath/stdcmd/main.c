#include <stdio.h>
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while(fgets(buf,MAXLINE,stdin) != NULL){ //获取一行输入
        if(buf[strlen(buf) - 1] == '\n')    //去除末尾最后一个回车
            buf[strlen(buf) - 1] = 0;

        if((pid = fork()) < 0){ //创建线程
            printf("fork error\n");
        } else if(pid == 0){    //子线程
            execlp(buf,buf,(char*)0);   //调用输入的命令
            printf("couldn't execute: %s\n",buf); //子线程如果调用成功该行不会执行，否则就执行该行退出子线程
            exit(127);
        }

        //fuxiancheng
        if((pid = waitpid(pid,&status, 0)) < 0)
            printf("waitpid error\n");
        printf("%% ");
    }
    return 0;
}
