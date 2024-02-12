#include "include/my.h"
#include <stdio.h>

int main(void)
{
    double var = 1.437663;
    my_printf("%.8E\n", var);
    printf("%.8E", var);
    return 0;
}
