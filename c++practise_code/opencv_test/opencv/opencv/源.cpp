#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

unsigned char toZero(unsigned char a)
{
	if (a < 0)
		return 0;
	else
		return a;
}

int main()

{
	//Mat k = imread("10.jpg");
	//Mat k1 = imread("11.jpg");
	//Mat d;
	//Mat result1 = k.clone();

	//cout << result1.type() <<k.type()<< endl;
	//double time0 = static_cast<double>(getTickCount());
	////d= k - k1;
	////subtract(k, k1, d);
	////addWeighted(k, 1, k1, -1, 0,d);
	//int rowNumber = result1.rows;
	//int colNumber = result1.cols;
	//for (int i = 0; i < rowNumber; i++)
	//{
	//	for (int j = 0; j < colNumber; j++)
	//	{
	//		//result1.at<unsigned char>(i, j) = toZero(k.at<unsigned char>(i, j) - k1.at<unsigned char>(i, j));
	//		result1.at<Vec3b>(i, j)[0] = toZero(k.at<Vec3b>(i, j)[0] - k1.at<Vec3b>(i, j)[0]);
	//		result1.at<Vec3b>(i, j)[1] = toZero(k.at<Vec3b>(i, j)[1] - k1.at<Vec3b>(i, j)[1]);
	//		result1.at<Vec3b>(i, j)[2] = toZero(k.at<Vec3b>(i, j)[2] - k1.at<Vec3b>(i, j)[2]);
	//	}
	//}
	//time0 = ((double)getTickCount() - time0) / getTickFrequency();
	//cout << "\t此方法运行时间为： " << time0 << "秒" << endl;  //输出运行时间
	//system("pause");
	//return 0;
	while (true)
	{

	}
	return  0;
}