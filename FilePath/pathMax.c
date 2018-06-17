#include "apue.h"
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;
#define PATH_MAX_GUESS 1024

char* path_alloc(size_t *sizep){
    char* ptr;
    size_t size;
    if(posix_version == 0)
        posix_version = sysconf(_SC_VERSION);
    if(xsi_version == 0)
        xsi_version = sysconf(_SC_XOPEN_VERSION);

    if(pathmax == 0){
        errno = 0;
        if((pathmax = pathconf("/",_PC_PATH_MAX)) < 0){ //指定根目录为第一个参数
            if(errno == 0)
                pathmax = PATH_MAX_GUESS;
            else
                printf("pathconf error for _PC_PATH_MAX\n");
        }else {
            pathmax++;
        }
    }

    if((posix_version < 200112L) && (xsi_version < 4))
        size = pathmax + 1;
    else
        size = pathmax;

    if((ptr = (char*)malloc(size)) == NULL)
        printf("malloc error for pathname\n");
    if(sizep != NULL){
        *sizep = size;
    }
    return (ptr);
}


int main()
{
    return 0;
}

