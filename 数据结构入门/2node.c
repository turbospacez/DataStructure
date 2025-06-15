#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data; //数据域
    struct Node* pNext; // 指针域
}NODE, *PNODE; // NODE=>struct Node, PNODE=>struct Node*

// 函数声明

PNODE create_list(void);
void traverse_list(PNODE pHead); // 遍历链表
bool is_empty(PNODE pHead); // 检测是否为空
int length_list(PNODE); // 链表长度
bool insert_list(PNODE, int ,int); // 插入结点
bool delete_list(PNODE, int, int*); // 删除结点
void sort_list(PNODE); // 链表排序

int main(void)
{
    PNODE pHead = NULL; // 等价于 struct Node* PNODE = NULL;

    int val;

    //创建一个链表, 并将该链表的头结点地址赋给pHead
    pHead = create_list();
    traverse_list (pHead); // 遍历链表

    //insert_list(pHead, 3, 33);
    //traverse_list(pHead);

    if(delete_list(pHead, 4, &val))
    {
        printf("删除成功!\n");
    }
    else
    {
        printf("删除失败!");
    }
    traverse_list (pHead);

    //int len = length_list(pHead);
    //printf("%i\n", len);

    //sort_list(pHead);
    //traverse_list (pHead);

    /*
    if (is_empty(pHead))
        printf("空");
    else
        printf("非空");
    */

    return 0;
}

// 数据类型为PNODE类型 用于将返回值定为地址
PNODE create_list(void)
{
    int len; // 用于存放有效结点个数
    int i;
    int val; // 用于存放用户输入结点值

    // 分配了一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // 计算NODE所需内存大小, malloc分配所需连续内存, 此处pHead为强制转型后存储的内存地址
    if(NULL == pHead)
    {
        printf("分配失败\n");
        exit(-1);
    }


    PNODE pTail = pHead; // 新建链表, 头指针和尾指针都指向表头
    pTail->pNext = NULL; // 尾指针初始化指向为空, 避免指向不知名的内存


    printf("请输入链表需要的结点个数:");
    scanf("%i", &len);

    for (i=0; i<len; i++)
    {
        printf("请输入%i个结点值: ", i+1); // 因为i下标从0开始所以需要+1
        scanf("%i", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pHead)
        {
            printf("分配失败\n");
            exit(-1);
        }

        //尾插法
        pNew->data = val; // 新建结点存放数值存放值val
        pTail->pNext = pNew; // 将尾结点指向新结点
        pNew->pNext = NULL; // pNew结点为尾结点, 指向NULL
        pTail = pNew; // 此时pNew结点为尾结点, 将pNew标记为尾结点

    }

    return pHead; // 将函数内的pHead的值作为返回值给main函数的pHead同名函数

}

// 遍历链表, 定位一个链表只需要一个头指针
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext; // 将头结点的指针赋值给p, 如果是空链表, 仅有一个头结点, 需要判断是否为空

    // 若p不为空, 则执行循环
    while (NULL != p)
    {
        printf("%i ", p->data); //将结点的值输出
        p = p->pNext; // 将该节点链接的下一个结点地址赋值给p
    }

    printf("\n");
    return;
}

// 判断链表是否为空
bool is_empty(PNODE pHead)
{
    // 如果头结点的指针域为空, 链表为空
    if(NULL == pHead->pNext)
        return true;
    else
        return false;
}

// 链表长度, 遍历链表实现, 如果该结点非空, 则while执行一次, 那么创建一个len函数用于存放while循环次数
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    int len = 0;

    while (NULL != p)
    {
        ++len; // 如果链表非空, 则长度值+1
        p = p->pNext; // 将p指向下一结点
    }

    return len;
}

// 变体冒泡排序
void sort_list(PNODE pHead)
{
    int i, j, temp;
    int len = length_list(pHead);
    PNODE p, q;

    // i计数器,从第0轮开始, p指向第一个有效结点(第一个结点是头结点, 没有存放有效数据
    // 终止条件, 一共需要i-1轮
    // 迭代逻辑, 每一轮结束后, p向后移动一个结点
    for (i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext)
    {
        //从i的下一个位置开始, q指向p的下一个结点值用于比较pq之间大小
        //j在边界条件内
        //比较完成后, q也向后移动一个结点
        for (j=i+1,q=p->pNext; j<len; j++, q=q->pNext)
        {
            if (p->data > q->data) //a[i] > a[j]
            {
                temp = p->data; // t = a[i];
                p->data = q->data; // a[i] = a[j];
                q->data = temp; // a[j] = t;
            }
        }
    }
}


// 在pHead链表的第pos个位置插入一个新的值为bal的结点, pos从1开始
// 判断pos是否为合法值, 首先求链表长度, 再判断
bool insert_list(PNODE pHead, int pos ,int val)
{
    int i = 0;
    PNODE p = pHead;

    //寻找插入位置
    //p不为空, 利用循环让i移动到pos-1个结点, 以便插入val值
    while(NULL != p && i<pos-1)
    {
        p = p->pNext;
        ++i;
    }

    // p为空(p大于链表长度)或p指向的值比pos-1大则无法进行后续加入,则返回false
    if (i>pos-1 || NULL == p)
        return false;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("分配失败!\n");
        exit(-1);
    }

    pNew->data = val; // 将val值存给pNew
    PNODE q = p->pNext; // 将p的后继结点存给q
    p->pNext = pNew; // p的后继结点指向pNew
    pNew->pNext = q; // 将pNew的后继节点指向q

    /*
        p->q

        p->pNew->q

        p(|&pNew)->pNew (data[val]|&q)->q(|)
    */

    return true;
}


// 链表删除
bool delete_list(PNODE pHead, int pos, int* pVal)
{
    int i = 0;
    PNODE p = pHead;

    //判断条件同时将指针移动到要删除的位置
    while (NULL != p->pNext && i< pos-1)
    {
        p = p->pNext;
        ++i;
    }

    if (i>pos-1 || NULL == p)
        return false;

    PNODE q = p->pNext; // q 指向待删除的结点地址
    *pVal = q->data; // 通过指针 pVal 返回删除结点的数据

    p->pNext = p->pNext->pNext; // p指针跳过q结点, 直接指向q的下一个指针
    // p->q->r
    // p->r

    free(q); // 释放q的内存地址
    q = NULL; // 将q设置为NULL 避免误操作已释放内存, 避免野指针
}
/*
    (PNODE)malloc(sizeof(NODE))
    (PNODE) 强制类型转换
    malloc 分配 sizeof(NODE) 字节的 连续内存空间
    sizeof(NODE) 计算NODE类型的字节大小

    malloc 声明的内存空间可以跨函数使用
    malloc 的生命周期需要通过free函数手动释放

*/
