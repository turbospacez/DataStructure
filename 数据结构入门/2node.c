#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data; //������
    struct Node* pNext; // ָ����
}NODE, *PNODE; // NODE=>struct Node, PNODE=>struct Node*

// ��������

PNODE create_list(void);
void traverse_list(PNODE pHead); // ��������
bool is_empty(PNODE pHead); // ����Ƿ�Ϊ��
int length_list(PNODE); // ������
bool insert_list(PNODE, int ,int); // ������
bool delete_list(PNODE, int, int*); // ɾ�����
void sort_list(PNODE); // ��������

int main(void)
{
    PNODE pHead = NULL; // �ȼ��� struct Node* PNODE = NULL;

    int val;

    //����һ������, �����������ͷ����ַ����pHead
    pHead = create_list();
    traverse_list (pHead); // ��������

    //insert_list(pHead, 3, 33);
    //traverse_list(pHead);

    if(delete_list(pHead, 4, &val))
    {
        printf("ɾ���ɹ�!\n");
    }
    else
    {
        printf("ɾ��ʧ��!");
    }
    traverse_list (pHead);

    //int len = length_list(pHead);
    //printf("%i\n", len);

    //sort_list(pHead);
    //traverse_list (pHead);

    /*
    if (is_empty(pHead))
        printf("��");
    else
        printf("�ǿ�");
    */

    return 0;
}

// ��������ΪPNODE���� ���ڽ�����ֵ��Ϊ��ַ
PNODE create_list(void)
{
    int len; // ���ڴ����Ч������
    int i;
    int val; // ���ڴ���û�������ֵ

    // ������һ���������Ч���ݵ�ͷ���
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // ����NODE�����ڴ��С, malloc�������������ڴ�, �˴�pHeadΪǿ��ת�ͺ�洢���ڴ��ַ
    if(NULL == pHead)
    {
        printf("����ʧ��\n");
        exit(-1);
    }


    PNODE pTail = pHead; // �½�����, ͷָ���βָ�붼ָ���ͷ
    pTail->pNext = NULL; // βָ���ʼ��ָ��Ϊ��, ����ָ��֪�����ڴ�


    printf("������������Ҫ�Ľ�����:");
    scanf("%i", &len);

    for (i=0; i<len; i++)
    {
        printf("������%i�����ֵ: ", i+1); // ��Ϊi�±��0��ʼ������Ҫ+1
        scanf("%i", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pHead)
        {
            printf("����ʧ��\n");
            exit(-1);
        }

        //β�巨
        pNew->data = val; // �½��������ֵ���ֵval
        pTail->pNext = pNew; // ��β���ָ���½��
        pNew->pNext = NULL; // pNew���Ϊβ���, ָ��NULL
        pTail = pNew; // ��ʱpNew���Ϊβ���, ��pNew���Ϊβ���

    }

    return pHead; // �������ڵ�pHead��ֵ��Ϊ����ֵ��main������pHeadͬ������

}

// ��������, ��λһ������ֻ��Ҫһ��ͷָ��
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext; // ��ͷ����ָ�븳ֵ��p, ����ǿ�����, ����һ��ͷ���, ��Ҫ�ж��Ƿ�Ϊ��

    // ��p��Ϊ��, ��ִ��ѭ��
    while (NULL != p)
    {
        printf("%i ", p->data); //������ֵ���
        p = p->pNext; // ���ýڵ����ӵ���һ������ַ��ֵ��p
    }

    printf("\n");
    return;
}

// �ж������Ƿ�Ϊ��
bool is_empty(PNODE pHead)
{
    // ���ͷ����ָ����Ϊ��, ����Ϊ��
    if(NULL == pHead->pNext)
        return true;
    else
        return false;
}

// ������, ��������ʵ��, ����ý��ǿ�, ��whileִ��һ��, ��ô����һ��len�������ڴ��whileѭ������
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    int len = 0;

    while (NULL != p)
    {
        ++len; // �������ǿ�, �򳤶�ֵ+1
        p = p->pNext; // ��pָ����һ���
    }

    return len;
}

// ����ð������
void sort_list(PNODE pHead)
{
    int i, j, temp;
    int len = length_list(pHead);
    PNODE p, q;

    // i������,�ӵ�0�ֿ�ʼ, pָ���һ����Ч���(��һ�������ͷ���, û�д����Ч����
    // ��ֹ����, һ����Ҫi-1��
    // �����߼�, ÿһ�ֽ�����, p����ƶ�һ�����
    for (i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext)
    {
        //��i����һ��λ�ÿ�ʼ, qָ��p����һ�����ֵ���ڱȽ�pq֮���С
        //j�ڱ߽�������
        //�Ƚ���ɺ�, qҲ����ƶ�һ�����
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


// ��pHead����ĵ�pos��λ�ò���һ���µ�ֵΪbal�Ľ��, pos��1��ʼ
// �ж�pos�Ƿ�Ϊ�Ϸ�ֵ, ������������, ���ж�
bool insert_list(PNODE pHead, int pos ,int val)
{
    int i = 0;
    PNODE p = pHead;

    //Ѱ�Ҳ���λ��
    //p��Ϊ��, ����ѭ����i�ƶ���pos-1�����, �Ա����valֵ
    while(NULL != p && i<pos-1)
    {
        p = p->pNext;
        ++i;
    }

    // pΪ��(p����������)��pָ���ֵ��pos-1�����޷����к�������,�򷵻�false
    if (i>pos-1 || NULL == p)
        return false;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("����ʧ��!\n");
        exit(-1);
    }

    pNew->data = val; // ��valֵ���pNew
    PNODE q = p->pNext; // ��p�ĺ�̽����q
    p->pNext = pNew; // p�ĺ�̽��ָ��pNew
    pNew->pNext = q; // ��pNew�ĺ�̽ڵ�ָ��q

    /*
        p->q

        p->pNew->q

        p(|&pNew)->pNew (data[val]|&q)->q(|)
    */

    return true;
}


// ����ɾ��
bool delete_list(PNODE pHead, int pos, int* pVal)
{
    int i = 0;
    PNODE p = pHead;

    //�ж�����ͬʱ��ָ���ƶ���Ҫɾ����λ��
    while (NULL != p->pNext && i< pos-1)
    {
        p = p->pNext;
        ++i;
    }

    if (i>pos-1 || NULL == p)
        return false;

    PNODE q = p->pNext; // q ָ���ɾ���Ľ���ַ
    *pVal = q->data; // ͨ��ָ�� pVal ����ɾ����������

    p->pNext = p->pNext->pNext; // pָ������q���, ֱ��ָ��q����һ��ָ��
    // p->q->r
    // p->r

    free(q); // �ͷ�q���ڴ��ַ
    q = NULL; // ��q����ΪNULL ������������ͷ��ڴ�, ����Ұָ��
}
/*
    (PNODE)malloc(sizeof(NODE))
    (PNODE) ǿ������ת��
    malloc ���� sizeof(NODE) �ֽڵ� �����ڴ�ռ�
    sizeof(NODE) ����NODE���͵��ֽڴ�С

    malloc �������ڴ�ռ���Կ纯��ʹ��
    malloc ������������Ҫͨ��free�����ֶ��ͷ�

*/
