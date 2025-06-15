/*
写程序步骤
1. 伪代码/简易代码 写出 所有功能的实现流程
2. 将所有的功能具体实现
3. 在程序中输入数据测试功能
*/

#include <stdio.h>
#include <stdlib.h> // malloc 函数
#include <stdbool.h> // 布尔函数

// 名为struct Arr的数据类型
struct Arr {
    int* pBase; // 数组中第一个元素地址, 数组指针
    int len; // 数组长度
    int current; // 当前数组元素个数
};


/*
1.初始化条件
2.使用函数提供那些参数以及参数的条件
3.该函数实现的功能

*/

void init_arr(struct Arr* pArr, int length); // 初始化数组
bool append_arr(struct Arr* pArr, int val); // 尾部追加元素
bool insert_arr(struct Arr* pArr, int pos, int val); // 指定位置添加元素
bool delete_arr(struct Arr* pArr, int pos, int* pVal); // 删除元素, 并返回删除值
bool is_empty(struct Arr* pArr); // 判断空
bool is_full(struct Arr* pArr); // 判断满
void sort_arr(struct Arr* pArr); // 数组排序
void show_arr(); // 打印数组元素
void invers_arr(struct Arr* pArr); // 倒置数组

int main(void) {
    struct Arr arr;
    int val;

    init_arr(&arr, 6); // 将arr的地址赋给 init_arr 函数
    //show_arr(&arr);

    /*
    顺序添加元素
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    insert_arr(&arr, 1, 0);
    //show_arr(&arr);
    */

    //逆序元素
    //invers_arr(&arr);

    /*
    //pVal用于存放pArr元素地址的 &val=*pArr
    if (delete_arr(&arr, 1, &val)) {
        printf("删除成功! 删除的元素为:%d\n", val);
    } else {
        printf("删除失败!\n");
    }
    */

    //show_arr(&arr);

    /*
    if (append_arr(&arr, 7)) {
        printf("追加成功!\n");
    } else {
        printf("追加失败哦.\n");
    }
    */

    append_arr(&arr, 87);
    append_arr(&arr, 45);
    append_arr(&arr, 3);
    append_arr(&arr, 122);
    append_arr(&arr, 537);
    append_arr(&arr, 486);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);



    return 0;
}

// 通过Arr* 接收 &arr 赋给的地址
// 初始化数组函数
init_arr(struct Arr* pArr, int length) {
    // 指针 pArr 指向结构体变量中pBase成员
    // 用malloc动态分配的内存空间
    pArr->pBase = (int*)malloc(sizeof(int) * length);

    // pBase 为内存空间中第一个变量地址, 用于标记整个数组, int占用4个字节, int*length就是占用的具体字节数
    // 如果动态内存分配失败, malloc函数会将 NULL 值赋给pBase 需要检测pBase值是否为NULL
    if (NULL == pArr->pBase) {
        printf("动态内存分配失败!\n");
        exit(-1); // 终止整个程序
    } else {
        pArr->len = length;
        pArr->current = 0;
    }
    return;
}

_Bool is_empty(struct Arr* pArr) {
    if (0 == pArr->current) {
        return true;
    } else {
        return false;
    }
}

//判断当前数组是否存满
_Bool is_full(struct Arr* pArr) {
    //判断结构体pArr当前元素个数是否等同于数组长度
    if(pArr->current == pArr->len) {
        return true;
    } else {
        return false;
    }
}


void show_arr (struct Arr* pArr) {
    // pArr是多重指针, 此时pArr的参数就是pArr地址, 因为是show_arr函数传入的参数, 所以不需要添加任何符号
    if( is_empty(pArr)) {
        printf("数组为空!\n");
    } else {
        for(int i=0; i<pArr->current; ++i) {
            //pArr为结构体, 不是数组. 要打印数组就需要用地址将数组中的数组
            printf("%d ", pArr->pBase[i]);

        }
        printf("\n");
    }
}

//追加数组中元素
_Bool append_arr(struct Arr* pArr, int val) {
    //先判断数组是否存满
    if(is_full(pArr)) {
        // 存满返回false
        return false;
    } else {
        // 没存满, 将val的值追加到数组pArr中
        //数组从0开始计数, current就表示当前的要存入的位置
        pArr->pBase[pArr->current] = val;
        //追加数字后, 要把现存数据的变量+1表示多存了一个数据
        pArr->current++;
        return true;
    }

}

_Bool insert_arr(struct Arr* pArr, int pos, int pVal) {
    int i;

    //判断数组是否满
    if (is_full(pArr))
        return false;

    // 保证输入的参数符合预期, 加入条件判断
    // 插入数据的位置pos必须大于1, pos的数值不能大于当前数组元素个数+1
    if (pos<1 || pos>pArr->current+1)
        return false;

    // i的值为当前个数的减一, 因为下标从0开始
    // 因为下标从0开始数, 需要移动的值是pos-1, 这样和下标值契合的
    // 比如说一个6位数组, 那下标为012345, 六个位置, 如果要在pos=3处插入一个元素, 换算到数组下标就是3-1为2

    // i数组中当前最后一个元素的下标, i的最大合法值, 这个循环是从后向前移动的
    for(i=pArr->current-1; i>=pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }

    // 将val的值赋给要插入的位置, 因为下标从0开始所以要-1
    pArr->pBase[pos-1] = pVal;

    // 添加了一个新元素, 当前current下标+1
    (pArr->current)++;
}

_Bool delete_arr(struct Arr* pArr, int pos, int* pVal) {
    int i;
    if(is_empty(pArr))
        return false;
    //判断数组非空后判断数组删除元素位置不能小于1同时大于当前值
    if (pos<1 || pos>pArr->current)
        return false;

    // 将要删除的值赋给pVal用于打印
    *pVal = pArr->pBase[pos-1];
    // i等于要删除的位置, i小于当前元素个数, i递增用于逐位将下标的值向前移动
    for(i=pos; i<pArr->current; i++) {
        // 将下标向前移动一位
        pArr->pBase[i-1] = pArr->pBase[i];
    }

    // 删除后将当前的数组上限-1
    pArr->current--;
    return true;
}

invers_arr(struct Arr* pArr) {
    int i = 0;
    int j = pArr->current-1;
    int temp;
    struct Arr arr;

    while (i<j) {
        /*
        两个变量值交换通常借助第三个值temp进行交换
        temp = i
        i = j
        j = temp
        */
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = temp;

        ++i; // 将数组下标从0开始向后移动一位
        --j; // 将数组下标从最后一位向前移动一位

        //打印当前pArr数组元素
        //show_arr(pArr);
    }

    return;
}

// N2的冒泡排序
void sort_arr(struct Arr* pArr) {
    int i, j, temp;

    for(i=0; i<pArr->current-1;i++) {
        for(j=i+1; j<pArr->current; ++j) {
            if(pArr->pBase[i] > pArr->pBase[j]) {
                temp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = temp;
            }
        }
    }
}
