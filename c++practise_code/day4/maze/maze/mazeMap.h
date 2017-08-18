#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
#define screenWidth 80    //�ַ�ģʽ����Ļ���
#define screenHeight 25   //�ַ�ģʽ����Ļ�߶�
#define WALL 1            //����ǽ����1��ʾ
#define ROAD 0            //����ͨ����0��ʾ
class MazeMap
{
public:
	MazeMap();										     //���캯����ʹ��Ĭ�ϵĵ�ͼ
	//���캯����ʹ���û��Զ���ĵ�ͼ��
	//*mazeMap ��ͼ��ά�����׵�ַ��row ��ͼ�����е�������column ��ͼ�����е�����
	MazeMap(int *mazeMap, int row, int column);
	void setMazeWall(char wall);                         //���ñ�ʾǽ���ַ�
	void setMazeRoad(char road);					     //���ñ�ʾ·���ַ�
	void defaultMode();                                  //�����Թ���Ĭ�ϵ�ͼ
	void setMazeMap(int *mazeMap, int row, int column);    //���������Թ���ͼ
	void drawMap() const;                                //���������Թ���ͼ�ĺ���
	static char getRoadChar();                           //��ȡ��ʾͨ·���ַ�
	static bool checkWallOrNot(int mazeX, int mazeY);     //��������Ƿ������Թ�ǽ�ڵĺ���
	static bool checkMazeDoor(int mazeX, int mazeY);      //��������Ƿ������Թ����/���ڵĺ���

private:

	char mazeWall;                     //�����Թ���ʾǽ�ڵ��ַ�
	static char mazeRoad;              //�����Թ���ʾͨ·���ַ�
	static int mazeWidth;              //�����Թ��Ŀ��
	static int mazeHeight;             //�����Թ��ĸ߶�
	static int mazeMapArray[screenHeight][screenWidth];//�����Թ��ĵ�ͼ����

};