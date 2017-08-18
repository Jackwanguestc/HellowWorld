#include<stdlib.h>
#include<iostream>
using namespace std;

class Coordinate
{
public:
	Coordinate(int x, int y);
	~Coordinate();

	int getX() const;

	int getY() const;
private:
	int m_iX;
	int m_iY;

};