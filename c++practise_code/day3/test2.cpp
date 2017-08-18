#include<stdlib.h>
#include<iostream>
using namespace std;

class Coordinate
{
    public:
        Coordinate();
        ~Coordinate();
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
    private:
        int m_iX;
        int m_iY;

};
class Line
{
    public:
        Line();
        ~Line();
        void setA(int x,int y);
        void setB(int x,int y);
        void printInfo();
    private:
        Coordinate m_coorA;
        Coordinate m_coorB;
};

Coordinate::Coordinate()
{
    cout<<"Coordinate()"<<endl;
}
Coordinate::~Coordinate()
{
    cout<<"~coordinate()"<<endl;
}
void Coordinate::setX(int x)
{
    m_iX = x;
}
int Coordinate::getX()
{
    return m_iX;
}
void Coordinate::setY(int y)
{
    m_iY = y;
}
int Coordinate::getY()
{
    return m_iY;
}
Line::Line()
{
    cout <<"Line()"<<endl;
}
Line::~Line()
{
    cout<<"~Line()"<<endl;
}
void Line::setA(int x,int y)
{
    m_coorA.setX(x);
    m_coorA.setY(y);
}
void Line::setB(int x,int y)
{
    m_coorB.setX(x);
    m_coorB.setY(y);
}
void Line::printInfo()
{
    cout<< "("<<m_coorA.getX()<<","<<m_coorA.getY()<<")"<<endl;
    cout<< "("<<m_coorB.getX()<<","<<m_coorB.getY()<<")"<<endl;
}
int main(void)
{
    //Coordinate *p = new Coordinate[3];
    Line *p = new Line;
    delete p;
    p = NULL;
    system("pause");
    return 0;
}