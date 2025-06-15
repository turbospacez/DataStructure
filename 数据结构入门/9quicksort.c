#include <stdio.h>

void QuickSort(int* a, int low, int high);
int FindPos(int* a, int low, int high);

int main(void)
{
    int i = 0;
    int a[6] = {2, 1, 0 ,5, 4, 3};

    // 快速排序参数: 数组a, 第一个下标0, 最后一个下标5
    QuickSort(a, 0, 5);

    for(i=0;i<6; i++)
    {
        printf("%i ", a[i]);
    }

    printf("\n");

    return 0;
}

void QuickSort(int* a, int low, int high)
{
    int pos;

    // 终止条件
    // 当low == high时, 数组为空时结束
    if(low < high)
    {
        // a是选择数组a[0]第一个元素作为基准元素
        // a[pos]作为基准值, 将a数组分为三部分: a[low]-[pos-1],a[pos],a[pos+1]-a[high]
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos-1);
        QuickSort(a, pos+1, high);

        /*
            通过分区函数FindPos将数组分为两部分
            递归排序左右两个子数组
        */
    }
}

// 找到值并移动
int FindPos(int* a, int low, int high)
{
    // 固定选择数组第一个元素作为基准值
    int val = a[low];

    // 起始条件 当low比high小就循环
    // 即左右指针未相遇
    // 当 low == high 找到基准元素的最终位置, 退出循环
    while (low < high)
    {
        // 左右指针不相遇 当指针相遇或交叉结束 防止数组越界
        // 当前元素小于基准值
        while (low < high && a[high] >= val)
            --high; // 左移一位
        a[low] = a[high]; // 该元素赋给 low指针位置, high指针位置为 "空"

        //当前元素大于基准值
        while (low<high && a[low] <= val)
            ++low;
        a[high] = a[low];

        a[low] = val; // 将基准值放回原来位置

        return high; // 当条件终止时, low和high是指向相同位置, 此时 low == high
    }
}
