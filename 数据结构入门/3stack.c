# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

/*
栈, 静态内存, 操作系统分配
堆, 动态内存, 程序员手动进行分配
*/

typedef struct Node
{
    int data;
    struct Node* pNext;
}NODE, *PNODE;


typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;


// 声明函数
void initStack(PSTACK); // 初始化栈
void push(PSTACK, int); // 入栈
void traverse(PSTACK); // 遍历栈
bool pop(PSTACK, int*); // 元素出栈


int main(void)
{
    STACK S; // STACK 等价于 struct Stack
    int val; // 保存出栈的值

    initStack(&S); // 避免野指针
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    push(&S, 7);
    push(&S, 8);
    push(&S, 9);
    traverse(&S);

    clear(&S);
    traverse(&S);

    /*
    if (pop(&S, &val))
    {
        printf("栈顶元素%i出栈成功!\n", val);
    }
    else
    {
        printf("出栈失败!\n");
    }

    traverse(&S);
    */

    return 0;
}

// 栈初始化, top和bottom指针都指向栈底
void initStack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    else
    {
        // 此时top和bottom指针都指向pS的栈底, 直接赋值
        // 但top或bottom指向的头结点的pNext指针应该为空
        // 因为栈中一个元素也没有
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL; //pS->pBottom->pNext = NULL
    }
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val; // 将val给新入栈元素赋值

    // 只压入一个元素 pTop和pBottm 指向相同
    // 当压入元素增多, pBottom指针不会移动, pTop会随着入栈的元素向上移动
    // pNew->pNext要指向pTop的地址
    // 此时pTop指针还没移动, pTop指向原来栈顶的元素

    // 4    pNew
    // 3 <- pTop
    // 2
    // 1 <- pBottom

    pNew->pNext = pS->pTop;

    pS->pTop = pNew; // 更新栈顶指针
}

//遍历栈
traverse(PSTACK pS)
{
    PNODE p = pS->pTop;

    // 只要p不等于pBottom指针
    // 还没有遍历到底, 就一直循环遍历输出
    while (p != pS->pBottom)
    {
        printf("%i ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return;
}

bool is_empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}


// pS栈的栈顶元素出栈并把出栈元素保存并返回打印
bool pop(PSTACK pS, int* pVal)
{
    //pS 为PSTACK 类型 本身存放 pS 的地址
    if(is_empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }
}

// 清空栈元素
// 使用双指针, 避免单指针整个链表中断
//
void clear(PSTACK pS)
{
    // 判断是否为空 再进行下一步动作
    if(is_empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop; // 指针指向栈顶
        PNODE q = NULL; // 暂时为空避免

        // 从栈顶遍历到栈底
        while(p != pS->pBottom)
        {
            q = p->pNext; // 保存下一结点的指针
            free(p); // 释放p的内存
            p = q; // 将q地址赋给p, 重复操作

        }

        // 清空栈元素后, 重置栈顶指针
        pS->pTop = pS->pBottom;
    }
}
