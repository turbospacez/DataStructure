#include <stdio.h>

void QuickSort(int* a, int low, int high);
int FindPos(int* a, int low, int high);

int main(void)
{
    int i = 0;
    int a[6] = {2, 1, 0 ,5, 4, 3};

    // �����������: ����a, ��һ���±�0, ���һ���±�5
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

    // ��ֹ����
    // ��low == highʱ, ����Ϊ��ʱ����
    if(low < high)
    {
        // a��ѡ������a[0]��һ��Ԫ����Ϊ��׼Ԫ��
        // a[pos]��Ϊ��׼ֵ, ��a�����Ϊ������: a[low]-[pos-1],a[pos],a[pos+1]-a[high]
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos-1);
        QuickSort(a, pos+1, high);

        /*
            ͨ����������FindPos�������Ϊ������
            �ݹ�������������������
        */
    }
}

// �ҵ�ֵ���ƶ�
int FindPos(int* a, int low, int high)
{
    // �̶�ѡ�������һ��Ԫ����Ϊ��׼ֵ
    int val = a[low];

    // ��ʼ���� ��low��highС��ѭ��
    // ������ָ��δ����
    // �� low == high �ҵ���׼Ԫ�ص�����λ��, �˳�ѭ��
    while (low < high)
    {
        // ����ָ�벻���� ��ָ�������򽻲���� ��ֹ����Խ��
        // ��ǰԪ��С�ڻ�׼ֵ
        while (low < high && a[high] >= val)
            --high; // ����һλ
        a[low] = a[high]; // ��Ԫ�ظ��� lowָ��λ��, highָ��λ��Ϊ "��"

        //��ǰԪ�ش��ڻ�׼ֵ
        while (low<high && a[low] <= val)
            ++low;
        a[high] = a[low];

        a[low] = val; // ����׼ֵ�Ż�ԭ��λ��

        return high; // ��������ֹʱ, low��high��ָ����ͬλ��, ��ʱ low == high
    }
}
