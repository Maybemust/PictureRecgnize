// svm.cpp : 定义控制台应用程序的入口点。

#include "opencv2/opencv.hpp"
using namespace cv;
using namespace cv::ml;
using namespace std;

class wxzSVM
{
  private:
	int center_Y;
	int center_X;
	int down_Y;
	int up_Y;
	int right_X;
	int left_X;
	int Area;
	int leftup_X;
	int leftup_Y;
	int leftdown_X;
	int leftdown_Y;
	int rightup_X;
	int rightup_Y;
	int rightdown_X;
	int rightdown_Y;


  public:
	Mat svm(Mat &image, int type); //svm分类
	Mat SVMFind(int type, Mat image);
	void printInfo();
	int center_y();
	int center_x();
	int down_y();
	int up_y();
	int area();
	int right_x();
	int left_x();
	int leftup_x();
	int leftup_y();
	int leftdown_x();
	int leftdown_y();
	int rightup_x();
	int rightup_y();
	int rightdown_x();
	int rightdown_y();
};
