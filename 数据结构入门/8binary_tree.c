#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    char data;
    struct BTNode* pLchild; // 左孩子
    struct BTNode* pRchild; // 右孩子
};

struct BTNode* CreateBinTree(void);
void PreOrderBTree(struct BTNode* pRoot);

int main(void)
{
    // 使用根结点的地址可以定位一个二叉树
    struct BTNode* pTree = CreateBinTree();

    //PreOrderBTree(pTree);
    //InOrderBTree(pTree);
    //PostOrderBTree(pTree);


    return 0;
}

struct BTNode* CreateBinTree(void)
{
    struct BTNode* pA = (struct BTNode* )malloc(sizeof(struct BTNode));
    struct BTNode* pB = (struct BTNode* )malloc(sizeof(struct BTNode));
    struct BTNode* pC = (struct BTNode* )malloc(sizeof(struct BTNode));
    struct BTNode* pD = (struct BTNode* )malloc(sizeof(struct BTNode));
    struct BTNode* pE = (struct BTNode* )malloc(sizeof(struct BTNode));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = NULL;
    pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = NULL;
    pE->pRchild = NULL;

    return pA;
};


// 先序访问:
// 1. 根节点
// 2. 先序左子树
// 3. 先序右子树
void PreOrderBTree(struct BTNode* pRoot)
{
    // 递归终止条件, 防止无限递归
    if(pRoot != NULL)
    {
        printf("%c\n", pRoot->data);  // 先打印根节点

        // 使用if判断省去子节点为空的情况
        if (pRoot->pLchild != NULL)
        {
            PreOrderBTree(pRoot -> pLchild); // 递归处理左子树
        }

        if (pRoot->pRchild != NULL)
        {
            PreOrderBTree(pRoot->pRchild); // 递归处理右子树
        }
    }
}

void InOrderBTree(struct BTNode* pRoot)
{
    // 递归终止条件, 防止无限递归
    if(pRoot != NULL)
    {
        // 使用if判断省去子节点为空的情况
        if (pRoot->pLchild != NULL)
        {
            InOrderBTree(pRoot -> pLchild); // 递归处理左子树
        }

        printf("%c\n", pRoot->data);  // 先打印根节点

        if (pRoot->pRchild != NULL)
        {
            InOrderBTree(pRoot->pRchild); // 递归处理右子树
        }
    }
}

void PostOrderBTree(struct BTNode* pRoot)
{
    // 递归终止条件, 防止无限递归
    if(pRoot != NULL)
    {
        // 使用if判断省去子节点为空的情况
        if (pRoot->pLchild != NULL)
        {
            PostOrderBTree(pRoot -> pLchild); // 递归处理左子树
        }

        if (pRoot->pRchild != NULL)
        {
            PostOrderBTree(pRoot->pRchild); // 递归处理右子树
        }

        printf("%c\n", pRoot->data);  // 先打印根节点
    }
}

/*
    先序PreOrder
    打印根节点
    递归处理左子树
    递归处理右子树

    中序InOrder
    递归处理左子树
    打印根节点
    递归处理右子树

    后序PostOrder
    递归处理左子树
    递归处理右子树
    打印根节点
*/
