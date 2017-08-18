#include <iostream>
using namespace std;

int main(void)
{
    int *p = new int;
    if(p == NULL)
    {
        system("pause");
        return 0;
    }
    *p = 20;
    cout << *p <<endl;
    delete p;
    p = NULL;

    int *q = new int[2];
    if(q == NULL)
    {
        system("pause");
        return 0;
    }
    q[0] = 10;
    q[1] = 20;
    cout << q[0]<<" "<<q[1]<<endl;
    delete []p;
    q = NULL;
    system("pause");
    return 0;
}