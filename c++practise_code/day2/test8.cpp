#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string name;
    cout << "Please input your name:" ;
    getline(cin,name);
    if(name.empty())
    {
        cout <<"input is null"<< endl;
        system("pause");
        return 0;
    }
    if(name == "imooc")
    {
        cout<< "you are a adminstrator!" <<endl;
    }
    cout <<"hello"+name <<endl;
    cout << "your name length:"<<name .size()<<endl;
    cout << "your name first letter:"<<name[0]<<endl;
    system("pause");
    return 0;
}