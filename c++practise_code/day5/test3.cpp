#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
 * 定义射击类：CanShut
 * 定义纯虚函数：aim、reload
 */
class CanShut
{
public:
    virtual void aim() = 0;
    virtual void reload() = 0;
};

/**
 * 定义枪类：Gun
 * 公有继承射击类
 * 实现成员函数：aim、reload
 */
class Gun : public CanShut
{
public:
    virtual void aim()
    {
         cout << "Gun -- aim" << endl;
    }
    virtual void reload()
    {
         cout << "Gun -- reload" << endl;
    }
};

/**
 * 定义含参函数射击：hunting
 * 调用参数的aim与reload函数
 */
void hunting(CanShut *s)
{
    s->aim();
    s->reload();
}

int main(void)
{
    // 实例化枪对象
    Gun *p = new Gun;
    // 调用含参函数hunting,将对象枪传入函数中
    hunting(p);
    // 释放内存
    delete p;
    p = NULL;

    return 0;
}