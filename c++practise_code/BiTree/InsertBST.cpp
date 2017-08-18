#include <stdlib.h>
#include <iostream>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchilde,*rchilde;
}biTNode,*BiTree;

typedef int Status;

bool SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
    if(!T)
    {
        *p = f;
        return false;
    }
    else if (key == T->data)
    {
        *p = T;
        return true;
    }
    else if (key<T->data)
    {
        return SearchBST(T->lchilde,key,T,p);
    }
    else
        return SearchBST(T->rchilde,key,T,p);
}
Status InsertBST(BiTree *T,int key)
{
    BiTree p,s;
    if(!SearchBST(*T,key,NULL,&p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchilde = s->rchilde = NULL;
        if (!p)
            *T = s;
        else if(key<p->data)
            p->lchilde;
        else 
            p->rchilde;
        return true ;
    }
    else 
        return false;
}
int main(void)
{
    int i;
    int a[5] = {15,45,82,35,60};
    BiTree T = NULL;
    BiTree *p;
    for(i = 0;i<5;i++)
    {
        InsertBST(&T,a[i]);
    }
    std::cout<<T<<std::endl;
    std::cout<<SearchBST(T,45,NULL,p) <<","<<*p<<std::endl;

    system("pause");
    return 0;
}