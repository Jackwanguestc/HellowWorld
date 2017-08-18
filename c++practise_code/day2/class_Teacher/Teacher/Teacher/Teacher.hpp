#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Teacher
{
    public:
		//Teacher();
		//Teacher(string name = "Jim");
		Teacher(string name = "Jim", string genser = "male", int age = 30,const int maxStudent = 50);//构造函数可以重载，是用来初始化类内数据成员的
        void setName(string _name);
        string getName();
        void setGender(string _gender);
        string getGender();
        void setAge(int _age);
        int getAge();
        void teach();
    private:
        string m_strName;
        string m_strGender;
        int m_iAge;
		const int m_iMaxStudent;
};