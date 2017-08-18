#include"Teacher.hpp"

int main(int argc, char *argv[])
{
	Teacher t("make","male");
	cout << t.getName() << "," << t.getGender() << "," << t.getAge() << endl;
	t.setName("jack ma");
	t.setAge(30);
	t.setGender("male");
	cout << t.getName() << "," << t.getGender() << "," << t.getAge() << endl;
	t.teach();
	system("pause");
	return 0;
}