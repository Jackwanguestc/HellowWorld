#include"mazeMap.h"
char MazeMap::mazeRoad;              //声明迷宫表示通路的字符
int MazeMap::mazeWidth;              //声明迷宫的宽度
int MazeMap::mazeHeight;             //声明迷宫的高度
int MazeMap::mazeMapArray[screenHeight][screenWidth];//声明迷宫的地图数组
MazeMap::MazeMap()
{
}
//构造函数，使用用户自定义的地图。
//*mazeMap 地图二维数组首地址；row 地图数组中的行数；column 地图数组中的列数
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
void MazeMap::setMazeWall(char wall)                         //设置表示墙的字符
{
	mazeWall = wall;
}
void MazeMap::setMazeRoad(char road)					     //设置表示路的字符
{
	mazeRoad = road;
}
//void defaultMode();                                  //设置迷宫的默认地图
void MazeMap::setMazeMap(int *mazeMap, int row, int column)    //重新设置迷宫地图
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
void MazeMap::drawMap() const                                //声明绘制迷宫地图的函数
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
 char MazeMap::getRoadChar()                           //获取表示通路的字符
{
	return mazeRoad;
}
 bool MazeMap::checkWallOrNot(int mazeX, int mazeY)     //声明检查是否遇到迷宫墙壁的函数
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
	//检查迷宫左右两侧
	if (mazeX == 0 || mazeX == (mazeWidth - 1))//边界
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	//检查迷宫上下两侧
	if (mazeY == 0 || mazeY == (mazeHeight - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	return false;
}