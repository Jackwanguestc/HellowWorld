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
void InsertionSort(SqList *L)
{
    int i,j;
    for(i = 2;i<L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0] = L->r[i];
            for( j = i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L ->r[j];
            L->r[j+1] = L->r[0];
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
    InsertionSort(L);
    for(int i = 1;i<L->length;i++)
    {
        cout<< L->r[i] <<endl;
    }
    
    system("pause");
    return 0;
}