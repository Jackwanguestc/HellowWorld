#include <stdio.h>
#include <iostream>
using  namespace std;

#define MAXSIZE 10

typedef struct
{
    int r[MAXSIZE+1];
    int length;
}SqList;

void swap(SqList *L,int i,int j)
{
    int temp = L -> r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
void bubbleSort0(SqList *L)
{
    for(int i = 1;i<L->length;i++)
    {
        for(int j = i+1;j<L->length;j++)
        {
            if(L->r[i] > L->r[j])
            {
                swap(L, i, j);
            }
        }
    }
}
void bubbleSort(SqList *L)
{
    int flag = 1;
    for(int i = 1;i<L->length && flag;i++)
    {
        flag = 0;
        for(int j = L->length;j>=i;j--)
        {
            if(L->r[j] > L->r[j+1])
            {
                swap(L,j,j+1);
                flag = 1;
            }
        }
    }
}
int main(void)
{
    SqList a = {{9,1,5,8,3,7,4,6,2},9};
    SqList *L = &a;
    //L->r[9] = {9,1,5,8,3,7,4,6,2};
    //L->length = 9;
    //bubbleSort0(L);
    bubbleSort(L);
    for(int i = 1;i<L->length;i++)
    {
        cout<< L->r[i] <<endl;
    }
    
    system("pause");
    return 0;
}