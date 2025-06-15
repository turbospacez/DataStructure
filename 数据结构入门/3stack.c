# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

/*
ջ, ��̬�ڴ�, ����ϵͳ����
��, ��̬�ڴ�, ����Ա�ֶ����з���
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


// ��������
void initStack(PSTACK); // ��ʼ��ջ
void push(PSTACK, int); // ��ջ
void traverse(PSTACK); // ����ջ
bool pop(PSTACK, int*); // Ԫ�س�ջ


int main(void)
{
    STACK S; // STACK �ȼ��� struct Stack
    int val; // �����ջ��ֵ

    initStack(&S); // ����Ұָ��
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
        printf("ջ��Ԫ��%i��ջ�ɹ�!\n", val);
    }
    else
    {
        printf("��ջʧ��!\n");
    }

    traverse(&S);
    */

    return 0;
}

// ջ��ʼ��, top��bottomָ�붼ָ��ջ��
void initStack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if(NULL == pS->pTop)
    {
        printf("��̬�ڴ����ʧ��!\n");
        exit(-1);
    }
    else
    {
        // ��ʱtop��bottomָ�붼ָ��pS��ջ��, ֱ�Ӹ�ֵ
        // ��top��bottomָ���ͷ����pNextָ��Ӧ��Ϊ��
        // ��Ϊջ��һ��Ԫ��Ҳû��
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL; //pS->pBottom->pNext = NULL
    }
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val; // ��val������ջԪ�ظ�ֵ

    // ֻѹ��һ��Ԫ�� pTop��pBottm ָ����ͬ
    // ��ѹ��Ԫ������, pBottomָ�벻���ƶ�, pTop��������ջ��Ԫ�������ƶ�
    // pNew->pNextҪָ��pTop�ĵ�ַ
    // ��ʱpTopָ�뻹û�ƶ�, pTopָ��ԭ��ջ����Ԫ��

    // 4    pNew
    // 3 <- pTop
    // 2
    // 1 <- pBottom

    pNew->pNext = pS->pTop;

    pS->pTop = pNew; // ����ջ��ָ��
}

//����ջ
traverse(PSTACK pS)
{
    PNODE p = pS->pTop;

    // ֻҪp������pBottomָ��
    // ��û�б�������, ��һֱѭ���������
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


// pSջ��ջ��Ԫ�س�ջ���ѳ�ջԪ�ر��沢���ش�ӡ
bool pop(PSTACK pS, int* pVal)
{
    //pS ΪPSTACK ���� ������ pS �ĵ�ַ
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

// ���ջԪ��
// ʹ��˫ָ��, ���ⵥָ�����������ж�
//
void clear(PSTACK pS)
{
    // �ж��Ƿ�Ϊ�� �ٽ�����һ������
    if(is_empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop; // ָ��ָ��ջ��
        PNODE q = NULL; // ��ʱΪ�ձ���

        // ��ջ��������ջ��
        while(p != pS->pBottom)
        {
            q = p->pNext; // ������һ����ָ��
            free(p); // �ͷ�p���ڴ�
            p = q; // ��q��ַ����p, �ظ�����

        }

        // ���ջԪ�غ�, ����ջ��ָ��
        pS->pTop = pS->pBottom;
    }
}
