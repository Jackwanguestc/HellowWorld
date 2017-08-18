#include<iostream>
using namespace std;

class Person
{
    public:
        Person();
        ~Person();
        void eat();
        string m_strName;
        int m_iAge;
    private:
};
Person::Person()
{
    cout<<"Person()"<<endl;
}
Person::~Person()
{
    cout<<"~Person()"<<endl;
}
void Person::eat()
{
    cout<<"eat"<<endl;
}
class Worker:public Person
{
    public:
    Worker();
    ~Worker();
    void work();
    int m_iSalary;
};
Worker::Worker()
{
    cout<<"Worker()"<<endl;
}
Worker::~Worker()
{
    cout<<"~Worker()"<<endl;
}
void Worker::work()
{
    cout<<"work"<<endl;
}

int main()
{
    Worker *p = new Worker();
    p->m_strName = "jim";
    p->m_iAge = 10;
    p->eat();
    p->m_iSalary = 1000;
    p->work();
    cout <<p->m_strName<<p->m_iAge<<p->m_iSalary<<endl;
    delete p;
    p = NULL;
    system("pause");
    return 0;

}