#include <iostream>
using namespace std;

template <typename T>
void display(T a)
{
    cout <<a <<endl;
}
template <typename T>
void display(T a,T b)
{
    cout <<a<<b<<endl;
}
template<typename T,int size>
void display(T a)
{
    cout<<a<<size<<endl;
}
template<typename T>
void swapNum(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    display(10);
    display<double>(10.1,2.00);
    display<char,10>('a');
    int a = 10,b = 20;
    swapNum(a,b);
    cout <<a<<","<<b<<endl;
    system("pause");
    return 0;
}