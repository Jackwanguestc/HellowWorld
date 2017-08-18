#include"mazeMap.h"
char MazeMap::mazeRoad;              //�����Թ���ʾͨ·���ַ�
int MazeMap::mazeWidth;              //�����Թ��Ŀ��
int MazeMap::mazeHeight;             //�����Թ��ĸ߶�
int MazeMap::mazeMapArray[screenHeight][screenWidth];//�����Թ��ĵ�ͼ����
MazeMap::MazeMap()
{
}
//���캯����ʹ���û��Զ���ĵ�ͼ��
//*mazeMap ��ͼ��ά�����׵�ַ��row ��ͼ�����е�������column ��ͼ�����е�����
MazeMap::MazeMap(int *mazeMap, int row, int column)
{
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<column; j++)
		{
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
	mazeWidth = column;
	mazeHeight = row;
}
void MazeMap::setMazeWall(char wall)                         //���ñ�ʾǽ���ַ�
{
	mazeWall = wall;
}
void MazeMap::setMazeRoad(char road)					     //���ñ�ʾ·���ַ�
{
	mazeRoad = road;
}
//void defaultMode();                                  //�����Թ���Ĭ�ϵ�ͼ
void MazeMap::setMazeMap(int *mazeMap, int row, int column)    //���������Թ���ͼ
{
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<column; j++)
		{
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
	mazeWidth = column;
	mazeHeight = row;
}
void MazeMap::drawMap() const                                //���������Թ���ͼ�ĺ���
{
	for (int i = 0; i<mazeHeight; i++)
	{
		for (int j = 0; j<mazeWidth; j++)
		{
			if (mazeMapArray[i][j] == 1)
			{
				cout << mazeWall;
			}
			else
			{
				cout << mazeRoad;
			}
		}
		cout << endl;
	}
}
 char MazeMap::getRoadChar()                           //��ȡ��ʾͨ·���ַ�
{
	return mazeRoad;
}
 bool MazeMap::checkWallOrNot(int mazeX, int mazeY)     //��������Ƿ������Թ�ǽ�ڵĺ���
{
	if (mazeMapArray[mazeY][mazeX] == WALL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 bool MazeMap::checkMazeDoor(int mazeX, int mazeY)
{
	//����Թ���������
	if (mazeX == 0 || mazeX == (mazeWidth - 1))//�߽�
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	//����Թ���������
	if (mazeY == 0 || mazeY == (mazeHeight - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	return false;
}