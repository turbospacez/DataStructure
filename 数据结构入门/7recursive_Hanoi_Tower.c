#include<stdio.h>

/*
���õݹ�˼�뽫�����ģ��С

һ����������A.B.C, n�����ӽ��к�ŵ��

���������֮��, ����ͳ�Ϊ������:
1. �Ƚ�n-1�������ƶ���B
2. Ȼ��A�������������ƶ���C��
3. ���B���ϵ�n-1�������ƶ���C��

����, �����Ӳ����ֳ�Ϊ��������, ֻ��1.3���������ģ�ϴ�.
Ȼ����Լ����������ģ�������, ��ʼ�ƶ�n-2������, ֱ�������ģ��Сֻ�ƶ�1������.


�����Եݹ�

1   1
2   3
3   7
......

�ܲ���Ӧ���� 2^n -1

*/

void hanoi(int num, char start, char middle, char finals)
{
    if (num == 1)
    {
        printf("��%d����ֱ�Ӵ�%c�ƶ���%c��\n", num, start, finals);
    }
    else
    {
        // n-1�����ӽ���
        hanoi(num-1, start, finals, middle); // ��ʼstart ���� ����finals �� n-1 �ƶ��� �м�middle
        printf("��%d����ֱ�Ӵ�%c�ƶ���%c��\n", num, start, finals);
        hanoi(num-1, middle, start, finals); // �м�middle ���� ��ʼstart �� n-1 �ƶ��� ����finals
        printf("��%d����ֱ�Ӵ�%c�ƶ���%c��\n", num, middle, finals);
    }
}


int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int n;

    printf("����Ҫ�ƶ��ĸ���: ");
    scanf("%i", &n);

    hanoi(n, 'A', 'B', 'C');


    return 0;
}
