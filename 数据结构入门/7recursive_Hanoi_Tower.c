#include<stdio.h>

/*
利用递归思想将问题规模减小

一共三根柱子A.B.C, n个盘子进行汉诺塔

将问题抽象之后, 问题就成为了三步:
1. 先将n-1个盘子移动到B
2. 然后将A柱上最大的盘子移动到C柱
3. 最后将B柱上的n-1个盘子移动到C柱

其中, 将复杂步骤拆分成为三个步骤, 只是1.3步的问题规模较大.
然后可以继续将问题规模继续拆分, 开始移动n-2个盘子, 直至问题规模最小只移动1个盘子.


非线性递归

1   1
2   3
3   7
......

总步骤应该是 2^n -1

*/

void hanoi(int num, char start, char middle, char finals)
{
    if (num == 1)
    {
        printf("将%d盘子直接从%c移动到%c柱\n", num, start, finals);
    }
    else
    {
        // n-1个盘子借助
        hanoi(num-1, start, finals, middle); // 初始start 利用 最终finals 将 n-1 移动至 中间middle
        printf("将%d盘子直接从%c移动到%c柱\n", num, start, finals);
        hanoi(num-1, middle, start, finals); // 中间middle 利用 初始start 将 n-1 移动至 最终finals
        printf("将%d盘子直接从%c移动到%c柱\n", num, middle, finals);
    }
}


int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int n;

    printf("输入要移动的个数: ");
    scanf("%i", &n);

    hanoi(n, 'A', 'B', 'C');


    return 0;
}
