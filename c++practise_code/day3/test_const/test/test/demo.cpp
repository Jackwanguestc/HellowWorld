#pragma once
#include "line.h"
int main(void)
{
	Line line(5,6,7,8);
	// 创建常指针p
	const Line *q = &line;
	// 创建常引用c
	const Line &c = line;

	line.printInfo();
	q->printInfo();
	c.printInfo();

	Line *p = new Line(1, 2, 3, 4);
	p->printInfo();
	const Line *s = new Line(1, 2, 3, 4);
	s->printInfo();
	cout << sizeof(p) << endl;
	cout << sizeof(Line) << endl;
	delete p;
	p = NULL;
	system("pause");
	return 0;
}