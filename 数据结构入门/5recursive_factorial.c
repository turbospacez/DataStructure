#include<stdio.h>

long recurise(long num)
{
    if (1 == num)
        return 1;
    else
        return recurise(num-1) * num;


}

int main(void)
{
    printf("%ld\n", recurise(100));


    return 0;
}




/*
// 阶乘运算的一般实现

int main(void)
{
    int val = 0;
    int mult = 1;

    printf("计算阶乘, 请输入数字: ");
    scanf("%i", &val);

    for(int i=0; i<val; ++i)
    {
        mult = mult * (i+1);
    }

    printf("%i的阶乘为: %i\n",val ,mult);

    return 0;
}

*/
