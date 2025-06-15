#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
    int* pBase; // 循环数组使用的数组
    int front; // 队头指针
    int rear; // 队尾指针
    int capacity; // 队列容量
}QUEUE;

//声明函数
void init(QUEUE*, int capacity); // 初始化函数
bool en_queue(QUEUE*, int val); // 入队
void traverse_queue(QUEUE*); // 遍历队列
bool full_queue(QUEUE*); // 判断队满
bool out_queue(QUEUE*, int* pVal); // 出队


int main(void)
{
    QUEUE Q;
    int val;

    init(&Q, 6);


    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);

    traverse_queue(&Q);

    if(out_queue(&Q, &val))
    {
        printf("出队成功!\n");
    }
    else
    {
        printf("出队失败!\n");
    }

    traverse_queue(&Q);

    return 0;
}


void init(QUEUE* pQ, int capacity)
{
    pQ->pBase = (int*)malloc(sizeof(int) * capacity); // 分配动态数组
    pQ->front = 0;
    pQ->rear = 0;
}


bool en_queue(QUEUE* pQ, int val)
{
    if(full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val; // pBase为数组, 下标为rear, 因为rear指向队尾元素的下一个位置
        pQ->rear = (pQ->rear+1) % pQ->capacity; // 如果队列满取余为0
        return true;
    }
}

bool full_queue(QUEUE* pQ)
{
    // front和rear指针不固定位置, 所以当取余后rear等于front的值, 证明front和rear指针指向相同元素, 队满
    if ((pQ->rear +1) % pQ->capacity == pQ->front)
        return true;
    else
        return false;
}

void traverse_queue(QUEUE* pQ)
{
    int i = pQ->front;

    // 遍历队列当front等于rear时终止输出
    while (i != pQ->rear)
    {
        printf("%i ", pQ->pBase[i]);
        i = (i+1) % pQ->capacity;
    }

    printf("\n");
    return;
}

bool empty_queue(QUEUE* pQ)
{
    // 判断传入pQ是否为空指针
    if(pQ == NULL)
        return true;
    return pQ->front == pQ->rear; // 判断front和rear指针是否相同, 相同返回true, 不同false

}

bool out_queue(QUEUE* pQ, int* pVal)
{
    if(empty_queue(pQ))
    {
        return false;
    }
    else
    {
        *pVal = pQ->pBase[pQ->front];

        // 避免头指针越界
        pQ->front = (pQ->front+1) % pQ->capacity;
        return true;
    }
}
