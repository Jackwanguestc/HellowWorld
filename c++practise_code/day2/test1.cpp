#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct
{
    int x;
    int y;
}Coord;

void fun(int &a,int &b)
{
    int c= 0;
    c = a;
    a = b;
    b = c;

}
int main(void)
{
   // int a = 10;
    //int &b = a;
   // b = 20;
   // cout<< a <<endl;
   // a = 30;
   // cout<< b <<endl;

   //Coord c;
   //Coord &c1 = c;
   //c.x = 10;c.y = 20;
   //cout << c1.x<< c1.y <<endl;

   //int a = 1;
   //int *p = &a;//定义指针变量并初始化
   //int *&q = p;//指针p的引用q并初始化
   //*q = 5;//q指向的值赋值为5，p指向的值a也为5
   //cout<< a <<endl;
   int x= 10; int y = 20;
   cout << x << y <<endl;
   fun(x,y);
   cout << x << y <<endl;
    system("pause");
    return 0;
}