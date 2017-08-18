#include <iostream>
using namespace std;

class coordinate
{
    public:
    int x;
    int y;
    void printX()
    {
        cout << x <<endl;
    }
    void printY()
    {
        cout << y <<endl;
    }
};
int main(void)
{
    coordinate coor;
    coor.x = 10;
    coor.y = 20;
    coor.printX();
    coor.printY();
    
    coordinate *p = new coordinate();
    if(p == NULL)
    {
        return 0;
    }
    p->x = 100;
    p->y = 200;
    p->printX();
    p->printY();
    delete p;
    p = NULL;
    system("pause");
    return 0;
}