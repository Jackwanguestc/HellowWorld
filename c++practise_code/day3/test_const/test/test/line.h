#include"coordinate.h"
class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();
	void printInfo();
	void printInfo() const;
private:
	const Coordinate *m_pCoorA;//对象成员指针
	const Coordinate *m_pCoorB;
};