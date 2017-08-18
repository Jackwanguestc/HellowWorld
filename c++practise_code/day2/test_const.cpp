#include <iostream>
using namespace std;

//#define x 3 宏定义编译的时候不检测语法错误
int main(void)
{
    int x= 3;
    int y = 5;
    int const *p = &y;//*p is a const
    //int *const p = &y;//p is a const
    //p = &x;//conflicting declaration 'int* const p'
    cout << *p <<endl;
    p = &x;
    cout << *p <<endl;
    system("pause");
    return 0;
}