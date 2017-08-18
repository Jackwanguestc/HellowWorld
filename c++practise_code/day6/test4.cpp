#include <iostream>
using namespace std;

#ifndef MYARRAW_H
#define MYARRAW_H

template<typename T,int size,int val>
class MyArray
{
    public:
    MyArray();
    ~MyArray()
    {
        delete []m_pArr;
        m_pArr = NULL;    
    }
    void display();
    private:
    T *m_pArr;
};

template<typename T,int size,int val>
MyArray<T,size,val>::MyArray()
{
    m_pArr = new T[size];
    for(int i = 0;i<size;i++)
    {
        m_pArr[i] = val;
    }
}
template<typename T,int size,int val>
void  MyArray<T,size,val>::display()
{
    for(int i = 0;i<size;i++)
    cout<<m_pArr[i]<<endl;
}
#endif
int main()
{
    MyArray<int,5,6> arr;
    arr.display();
    system("pause");
    return 0;
}
