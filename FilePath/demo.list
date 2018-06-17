#include <stdio.h>
#include <errno.h>
#include "apue.h"
#include <dirent.h>

int main(int argc, char** argv)
{
    DIR *dp;
    struct dirent *dirp;    //目录结构体
    if(argc != 2) {
        printf("usage: ls directory_name\n");
        return 1;
    }
    if((dp = opendir(argv[1])) == NULL){ //打开目录
        printf("can't open %s",argv[1]);
        return -1;
    }
    while((dirp = readdir(dp))!=NULL){ //循环读取目录中文件的内容
        printf("%s\n",dirp->d_name);
    }

    closedir(dp);
    return 0;
}
