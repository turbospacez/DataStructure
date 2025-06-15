#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
    int* pBase; // ѭ������ʹ�õ�����
    int front; // ��ͷָ��
    int rear; // ��βָ��
    int capacity; // ��������
}QUEUE;

//��������
void init(QUEUE*, int capacity); // ��ʼ������
bool en_queue(QUEUE*, int val); // ���
void traverse_queue(QUEUE*); // ��������
bool full_queue(QUEUE*); // �ж϶���
bool out_queue(QUEUE*, int* pVal); // ����


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
        printf("���ӳɹ�!\n");
    }
    else
    {
        printf("����ʧ��!\n");
    }

    traverse_queue(&Q);

    return 0;
}


void init(QUEUE* pQ, int capacity)
{
    pQ->pBase = (int*)malloc(sizeof(int) * capacity); // ���䶯̬����
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
        pQ->pBase[pQ->rear] = val; // pBaseΪ����, �±�Ϊrear, ��Ϊrearָ���βԪ�ص���һ��λ��
        pQ->rear = (pQ->rear+1) % pQ->capacity; // ���������ȡ��Ϊ0
        return true;
    }
}

bool full_queue(QUEUE* pQ)
{
    // front��rearָ�벻�̶�λ��, ���Ե�ȡ���rear����front��ֵ, ֤��front��rearָ��ָ����ͬԪ��, ����
    if ((pQ->rear +1) % pQ->capacity == pQ->front)
        return true;
    else
        return false;
}

void traverse_queue(QUEUE* pQ)
{
    int i = pQ->front;

    // �������е�front����rearʱ��ֹ���
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
    // �жϴ���pQ�Ƿ�Ϊ��ָ��
    if(pQ == NULL)
        return true;
    return pQ->front == pQ->rear; // �ж�front��rearָ���Ƿ���ͬ, ��ͬ����true, ��ͬfalse

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

        // ����ͷָ��Խ��
        pQ->front = (pQ->front+1) % pQ->capacity;
        return true;
    }
}
