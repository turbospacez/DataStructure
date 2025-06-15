#include<stdio.h>

long sum(int n)
{
    if(n == 1)
        return 1;
    else
        return sum(n-1) + n;
}

int main(void)
{
    printf("%ld", sum(100));

    return 0;
}
