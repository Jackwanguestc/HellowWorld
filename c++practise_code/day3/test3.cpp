#include<stdlib.h>
#include<iostream>
using namespace std;

class Array
{
    public:
        Array(int Count);
        Array(const Array &arr);
        ~Array();
        void setCount(int count);
        int getCount();
        void printAddr();
        void printArr();
    private:
        int m_iCount;
        int *m_pArr;
};
Array::Array(int Count)
{
    m_iCount = Count;
    m_pArr = new int[m_iCount];
    for(int i = 0;i<m_iCount;i++)
    {
        m_pArr[i] = i;
    }
    cout << "Array()"<<endl;
}
Array::Array(const Array &arr)
{
    //m_pArr = arr.m_pArr;
    m_iCount = arr.m_iCount;//浅拷贝
    m_pArr = new int[m_iCount];//深拷贝
    for (int i = 0;i <m_iCount;i++)
    {
        m_pArr[i] = arr.m_pArr[i];
    }
    cout <<"Array&"<<endl;
}
Array::~Array()
{
    delete []m_pArr;
    m_pArr = NULL;
    cout<< "~Array()"<<endl;
}
void Array::setCount(int Count)
{
    m_iCount = Count;
}
int Array::getCount()
{
    return m_iCount;
}
void Array::printAddr()
{
    cout <<"m_pArr:"<<m_pArr<<endl;
}
void Array::printArr()
{
    for(int i= 0;i<m_iCount;i++)
    {
        cout<<"Arr:"<<m_pArr[i]<<endl;        
    }
    
}
int main(void)
{
    Array arr(5);
    //arr.setCount(5);
    Array arr1(arr);
    cout <<arr1.getCount()<<endl;
    arr.printAddr();
    arr1.printAddr();
    arr.printArr();
    arr1.printArr();
    system("pause");
    return 0;
}