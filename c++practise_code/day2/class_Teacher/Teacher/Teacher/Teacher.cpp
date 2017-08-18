#include "Teacher.hpp"

//Teacher::Teacher()
//{
//	cout << "Teacher()" << endl;
//}
//Teacher::Teacher(string name,const int maxStudent) 
//{
//	m_strName = name;
//	m_iMaxStudent = maxStudent;
//	cout << "Teacher(string name)" << endl;
//}
Teacher::Teacher(string name, string gender, int age,const int maxStudent) :m_strName(name), m_strGender(gender), m_iAge(age),m_iMaxStudent(maxStudent)//初始化列表，有const类型时应该用这种初始化方式
{
	cout << "Teacher(string name,string gender,int age)" << endl;
}
void Teacher::setName(string _name)
{
    m_strName = _name;
}
string Teacher::getName()
{
    return m_strName;
}
void Teacher::setGender(string _gender)
{
    m_strGender = _gender;
}
string Teacher::getGender()
{
    return m_strGender;
}
void Teacher::setAge(int _age)
{
    m_iAge = _age;
}
int Teacher::getAge()
{
    return m_iAge;
}
void Teacher::teach()
{
    cout<< "now have a class!"<<endl;
}
