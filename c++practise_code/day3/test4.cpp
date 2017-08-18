#include<stdlib.h>
#include<iostream>
using namespace std;

class Coordinate
{
    public:
        Coordinate(int x,int y);
        ~Coordinate();
       
        int getX();
        
        int getY();
    private:
        int m_iX;
        int m_iY;

};
class Line
{
    public:
        Line(int x1,int y1,int x2,int y2);
        ~Line();
        void printInfo();
    private:
        Coordinate *m_pCoorA;//对象成员指针
        Coordinate *m_pCoorB;
};

Coordinate::Coordinate(int x,int y)
{
    m_iX = x;
    m_iY = y;
    cout<<"Coordinate()"<<endl;
}
Coordinate::~Coordinate()
{
    cout<<"~coordinate()"<<endl;
}

int Coordinate::getX()
{
    return m_iX;
}

int Coordinate::getY()
{
    return m_iY;
}
Line::Line(int x1,int y1,int x2,int y2)
{
    m_pCoorA = new Coordinate(x1,y1);
    m_pCoorB = new Coordinate(x2,y2);
    cout <<"Line()"<<endl;
}
Line::~Line()
{
    delete m_pCoorA;
   
    m_pCoorA = NULL;
    delete m_pCoorB;
    m_pCoorB = NULL;
    cout<<"~Line()"<<endl;
}

void Line::printInfo()
{
    cout<< "("<<m_pCoorA->getX()<<","<<m_pCoorA->getY()<<")"<<endl;
    cout<< "("<<m_pCoorB->getX()<<","<<m_pCoorB->getY()<<")"<<endl;
}
int main(void)
{
    //Coordinate *p = new Coordinate[3];
    Line *p = new Line(1,2,3,4);
    p->printInfo();
    cout << sizeof(p)<<endl;
    cout << sizeof(Line)<<endl;
    delete p;
    p = NULL;
    system("pause");
    return 0;
}