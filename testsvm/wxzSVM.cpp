#include "wxzSVM.h"
using namespace std;
using namespace cv;
using namespace cv::ml;

Mat wxzSVM::svm(Mat &image, int type)
{
	Ptr<SVM> svm;
	switch (type)
	{
	case 2:
		//cout << "00000000000000000000000" << endl;
		svm = SVM::load("/home/liyang/worktree2018/avoidobstacle/svmYellow_l.xml");
		cvtColor(image, image, COLOR_BGR2Lab);
		break;
	case 1:
		svm = SVM::load("/home/liyang/worktree2018/avoidobstacle/svmRed_l.xml");
		cvtColor(image, image, COLOR_BGR2Lab);
		break;
	case 3:
		svm = SVM::load("/home/liyang/worktree2018/avoidobstacle/svmBlue_l.xml");
		cvtColor(image, image, COLOR_BGR2Lab);
		break;
	}

	// Show the decision regions given by the SVM

	Mat newImge(image.size(), CV_8UC1, Scalar(0));
	int step = 3;

	for (int i = 0; i < image.rows - step; i += step)
	{
		Vec3b *data = image.ptr<Vec3b>(i);
		uchar *newData = newImge.ptr<uchar>(i);
		for (int j = 0; j < image.cols - step; j += step)
		{
			Mat sampleMat = (Mat_<float>(1, 3) << data[j][0], data[j][1], data[j][2]);
			float response = svm->predict(sampleMat);

			if ((int)response == -1)
			{
				newData[j] = 0;
			}
			else
			{
				newData[j] = 255;
			}
		}
	}
	//cout << "444444444444444444444" << endl;
	imshow("SVM New Simple Example", newImge);
	Mat element = getStructuringElement(MORPH_RECT, Size(7, 7));
	morphologyEx(newImge, newImge, MORPH_CLOSE, element);
	//imshow("SVM Simple Example", image);
	return newImge;
}
Mat wxzSVM::SVMFind(int type, Mat image)
{
	Mat bimg;
	bimg = svm(image, type);
	// waitKey(50);
	//cout << "555555555555555555555" << endl;
	vector<std::vector<cv::Point> > contours;
	findContours(bimg, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); //只检测外轮廓。忽略轮廓内部的洞。
	Mat contoursimg(bimg.size(), CV_8U, Scalar(0));					  //白图
	Mat conimg = contoursimg.clone();
	//cout << "666666666666666666666666" << endl;
	//drawContours(conimg, contours, -1, Scalar(0), 2); //-1：如果是负数，则绘制所有的轮廓 用黑色绘制图像
	int cmax;
	int s[1000], i = 1, position = 160;
	//找最长轮廓 用最小的矩形将它包围起来
	if (contours.size() > 0)
	{
		vector<std::vector<cv::Point> >::iterator itc = contours.begin();
		//cout << "777777777777777777777" << endl;
		while (itc != contours.end())
		{
			s[i] = itc->size();
			//cout << s[i] << endl;
			++i;
			++itc;
		}
		for (int l = 2; l <= i - 1; l++)
			if (s[l - 1] > s[l])
				s[l] = s[l - 1];
		cmax = s[i - 1];
		itc = contours.begin();
		while (itc != contours.end())
		{
			if (itc->size() < cmax)
			{
				itc = contours.erase(itc);
			}
			else
				++itc;
		}
		drawContours(contoursimg, contours, -1, Scalar(255), 2);
		Mat result = contoursimg.clone();
		Rect r = boundingRect(Mat(contours[0])); //矩形将轮廓包围
		rectangle(result, r, Scalar(255), 2);
		imshow("result", result);

		center_Y = r.y + r.height / 2; //x、y、width、height，分别为左上角点的坐标和矩形的宽和高
		center_X = r.x + r.width / 2;
		down_Y = r.y + r.height;
		up_Y = r.y;
		left_X = r.x;
		right_X = r.x + r.width;
		leftup_X = r.x;
		leftup_Y = r.y;
		leftdown_X = r.x + r.x;
		leftdown_Y = r.y + r.height;
		rightup_X = r.x + r.width;
		rightup_Y = r.y;
		rightdown_X = r.x + r.width;
		rightdown_Y = r.y + r.height;
		Area = r.height * r.width;
		//printInfo();
		return result;
	}
	else
	{
		cout << "haven't deal it sucessfully" << endl;
		center_Y = -1;
		center_X = -1;
		down_Y = -1;
		up_Y = -1;
		left_X = -1;
		right_X = -1;
		leftup_X = -1;
		leftup_Y = -1;
		leftdown_X = -1;
		leftdown_Y = -1;
		rightup_X = -1;
		rightup_Y = -1;
		rightdown_X = -1;
		rightdown_Y = -1;
		Area = -1;

		return bimg;
	}
}
void wxzSVM::printInfo()
{
	cout << "center_y: " << center_Y << "||"
	     << "center_x: " << center_X << "||"
	     << "up_y: " << up_Y << "||"
	     << "down_y: " << down_Y << "||"
	     << "area :" << Area << endl;
}
int wxzSVM::center_y()
{
	return center_Y;
}
int wxzSVM::center_x()
{
	return center_X;
}
int wxzSVM::down_y()
{
	return down_Y;
}
int wxzSVM::up_y()
{
	return up_Y;
}
int wxzSVM::area()
{
	return Area;
}

int wxzSVM::left_x()
{
	return left_X;
}
int wxzSVM::right_x()
{
	return right_X;
}

int wxzSVM::leftup_x()
{
	return leftup_X;
}
int wxzSVM::leftup_y()
{
	return leftup_Y;
}
int wxzSVM::leftdown_x()
{
	return leftdown_X;
}
int wxzSVM::leftdown_y()
{
	return leftdown_Y;
}
int wxzSVM::rightup_x()
{
	return rightup_X;
}
int wxzSVM::rightup_y()
{
	return rightup_Y;
}
int wxzSVM::rightdown_x()
{
	return rightdown_X;
}
int wxzSVM::rightdown_y()
{
	return rightdown_Y;
}