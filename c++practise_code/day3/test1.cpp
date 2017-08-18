#include<stdlib.h>
#include<iostream>
using namespace std;

class Coordinate
{
    public:
        Coordinate();
        ~Coordinate();
    
        int m_iX;
        int m_iY;

};
Coordinate::Coordinate()
{
    cout<<"Coordinate()"<<endl;
}
Coordinate::~Coordinate()
{
    cout<<"~coordinate()"<<endl;
}
int main(void)
{
    Coordinate coor[3];
    coor[0].m_iX = 3;
    coor[0].m_iY = 5;

    Coordinate *p = new Coordinate[3];
    p->m_iX = 7;
    p[0].m_iY = 9;//这两种一样

    p++;
    p->m_iX = 11;
    p[0].m_iY = 13;//这时p【0】就是指向第一个

    p[1].m_iX = 15;//第三个
    p++;
    p->m_iY = 17;//指向第三个

    for(int i = 0;i<3;i++)
    {
        cout<< "coor-x:"<< coor[i].m_iX<<endl;
        cout<< "coor-y:"<< coor[i].m_iY<<endl;
    }

    for(int j = 0;j<3;j++)
    {
        //cout<<"p-x"<<p[j].m_iX<<endl;//没有p++可以这样
        cout<<"p-x:"<<p->m_iX<<endl;
        cout<<"p-y:"<<p->m_iY<<endl;
        p--;
    }
    p++;
    delete []p;
    p = NULL;
    system("pause");
    return 0;
}