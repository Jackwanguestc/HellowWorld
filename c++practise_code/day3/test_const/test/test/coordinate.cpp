#include"coordinate.h"

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
	cout << "Coordinate()" << endl;
}
Coordinate::~Coordinate()
{
	cout << "~coordinate()" << endl;
}

int Coordinate::getX() const
{
	return m_iX;
}

int Coordinate::getY() const
{
	return m_iY;
}