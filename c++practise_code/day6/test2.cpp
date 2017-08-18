#include <iostream>
using namespace std;

/**
 * 定义Coordinate类
 * 数据成员：m_iX，m_iY
 * 成员函数：构造函数
 * 重载--运算符，重载+运算符
 */
class Coordinate
{
public:
    Coordinate(int x, int y)
	{
		m_iX = x;
		m_iY = y;
	}
    // 前置--运算符重载
	Coordinate &operator--()
	{
	    m_iX--;
	    m_iY--;
	    return *this;
	}
    // 后置--运算符重载
    Coordinate operator--(int)
    {
        Coordinate old(*this);
        this->m_iX--;
        this->m_iY--;
        return old;
    }

    // +号运算符重载
	Coordinate operator+(Coordinate &c)
	{
	    Coordinate temp(0,0);
	    temp.m_iX = this->m_iX + c.m_iX;
	    temp.m_iY = this->m_iY + c.m_iY;
	    return temp;
	}
    
    

public:
	int m_iX;
	int m_iY;
};

int main(void)
{
	Coordinate coor1(1, 3);
	Coordinate coor2(2, 4);
	Coordinate coor3(0, 0);

	coor1--;
	--coor2;
	coor3 = coor1 + coor2;

	cout << coor3.m_iX << endl;
	cout << coor3.m_iY << endl;
    system("pause");
	return 0;
}
