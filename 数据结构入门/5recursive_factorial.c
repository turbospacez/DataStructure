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
// �׳������һ��ʵ��

int main(void)
{
    int val = 0;
    int mult = 1;

    printf("����׳�, ����������: ");
    scanf("%i", &val);

    for(int i=0; i<val; ++i)
    {
        mult = mult * (i+1);
    }

    printf("%i�Ľ׳�Ϊ: %i\n",val ,mult);

    return 0;
}

*/
