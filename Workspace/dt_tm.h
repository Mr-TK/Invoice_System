#include <stdio.h>
#include <time.h>
int DateTime(void)
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    return asctime(ptr);
}
