#include <stdlib.h>
#include <iostream>
using namespace std;

inline void fun(int i = 30,int j = 40, int k = 50)
{
    cout <<i<<j<<k<<endl;
}
inline void fun(double i,double j)
{
    cout<< i << j <<endl;
}

int main(void)
{
    fun();
    fun(100);
    fun(100,200);
    fun(1.1,25.3);
    system("pause");
    return 0;
}