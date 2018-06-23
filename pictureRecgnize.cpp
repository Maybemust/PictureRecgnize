// pictureRecgnize.cpp : 定义控制台应用程序的入口点。
//

#include <opencv2/opencv.hpp>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;


#define level1 3
#define level2 6
#define level3 9
#define level4 3


double iw[3][level1] = { 3.65160941317489, -1.82754870160270,	0.468642929047519,
0.0184257407438899, -2.77762180210581, -0.131862807363456,
0.848734767695431, -0.881077264811878,	1.14269981261516 };
double lw1[level2][level1] = { -2.36451695678476, - 0.298864326811230,	0.966088579555358,
1.21050154998086,	2.05641375051273,	0.895584731175052,
- 0.267957047694269, - 0.811914846975771, - 2.32406599582186,
- 3.00584684014809,	1.53623317136943,	0.426859567432145,
- 1.24932631470256,	2.04580574772694,	2.68554332400746,
1.04810097554424,	0.941081209449408, - 1.91919197239363 };
double lw2[level3][level2] = { -0.793199562815574,	0.415734734041341,	0.221754030166658, - 1.72796959088063, - 1.55172582632512,	1.55541161412540,
0.637021553093098,	0.369950255090514,	0.992531982578424,	0.255109718039943, - 0.985941541247713,	1.32048953193844,
0.810449474673189, - 0.0128296351731628, - 0.783418773419248, - 0.224746253887476, - 2.30971829426614, - 0.989863497308793,
0.627042460076717, - 0.753044745152812, - 0.500198473688881,	2.75778860737396, - 1.79589180218263, - 0.184590029189910,
- 0.856741075634236, - 0.564865981257509,	0.503734322842625,	2.55612267631637,	0.495449626586191 ,- 1.15473268665950,
- 0.503950704199650, - 0.0505454953939517, - 0.831765454191687,	1.66068984046598, - 0.190350483782864,	0.0687264880749003,
- 0.229984801946378, - 1.19764687039405,	1.25205290495370, - 1.49274978579243,	0.880942281019356,	0.867580796494099,
1.44076699667334,	0.202168820015754,	1.38538958584883,	0.214221088432725, - 0.0554296790508570 ,- 0.220783682012675,
- 0.683385084419754, - 0.764168683939959,	0.0806293261484039, - 1.71104074706315,	1.50974887550420,	1.09849391131060 };
double lw3[level4][level3] = { 0.755262857560248, - 0.0801677317046633,	0.767423458706835, - 1.14808079360070,	0.700751684483461,	0.221136080432778, - 0.0105664897368030,	0.673055858614016,	0.404832908710627,
1.36979360527684, - 1.21469452329949,	1.31839053382472, - 0.127694412942540,	0.202852690031462,	0.745273922519705,	1.35672280797053, - 0.525333764131053, - 0.729888762400534,
0.382146312622913, - 1.13559178934589 ,- 0.609716580567103, - 0.413528791421624 ,- 0.480920466894193,	0.724218394045653 ,- 1.06007377268859,	0.0413066131938907, - 1.05185105166851 };
double b1[level1] = { -1.0174, -1.6701, -0.0513 }, b2[level2] = { 2.3491, -1.5701, 1.2952, -1.0641, 1.6156, 1.3892 }, b3[level3] = { 2.6482, -0.7334, -1.2996, -0.5098, 0.3117, -0.5176, -1.1489, 1.5719, -1.9329 }, b4[level4]={-0.2038, 0.2076, 0.3890};
Vec3b dealnet(Vec3b pot)
{
	double maxp, minp, p1, p2, p3;
	p1 = pot[0];
	p2 = pot[1];
	p3 = pot[2];
	maxp = p1;
	if (p2 > maxp) maxp = p2;
	if (p3 > maxp) maxp = p3;
	minp = p1;
	if (p2 < minp) minp = p2;
	if (p3 < minp) minp = p3;
	pot[0] = 2 * (p1 - minp) / (maxp - minp) - 1;
	pot[1] = 2 * (p2 - minp) / (maxp - minp) - 1;
	pot[2] = 2 * (p3 - minp) / (maxp - minp) - 1;
	Vec3b result;
	//hiadelayer1
	double hidelayer1[level1], hidelayer2[level2], hidelayer3[level3], hidelayer4[level4];
	hidelayer1[0] = pot[0] * iw[0][0] + pot[1] * iw[0][1] + pot[2] * iw[0][2] + b1[0];
	hidelayer1[1] = pot[0] * iw[1][0] + pot[1] * iw[1][1] + pot[2] * iw[1][2] + b1[1];
	hidelayer1[2] = pot[0] * iw[2][0] + pot[1] * iw[2][1] + pot[2] * iw[2][2] + b1[2];
	hidelayer1[0] = 2 / (1 + exp(-2 * hidelayer1[0])) - 1;
	hidelayer1[1] = 2 / (1 + exp(-2 * hidelayer1[1])) - 1;
	hidelayer1[2] = 2 / (1 + exp(-2 * hidelayer1[2])) - 1;

	//hidelayer2
	hidelayer2[0] = hidelayer1[0] * lw1[0][0] + hidelayer1[1] * lw1[0][1] + hidelayer1[2] * lw1[0][2] + b2[0];
	hidelayer2[1] = hidelayer1[0] * lw1[1][0] + hidelayer1[1] * lw1[1][1] + hidelayer1[2] * lw1[1][2] + b2[1];
	hidelayer2[2] = hidelayer1[0] * lw1[2][0] + hidelayer1[1] * lw1[2][1] + hidelayer1[2] * lw1[2][2] + b2[2];
	hidelayer2[3] = hidelayer1[0] * lw1[3][0] + hidelayer1[1] * lw1[3][1] + hidelayer1[2] * lw1[3][2] + b2[0];
	hidelayer2[4] = hidelayer1[0] * lw1[4][0] + hidelayer1[1] * lw1[4][1] + hidelayer1[2] * lw1[4][2] + b2[1];
	hidelayer2[5] = hidelayer1[0] * lw1[5][0] + hidelayer1[1] * lw1[5][1] + hidelayer1[2] * lw1[5][2] + b2[2];
	hidelayer2[0] = 2 / (1 + exp(-2 * hidelayer2[0])) - 1;
	hidelayer2[1] = 2 / (1 + exp(-2 * hidelayer2[1])) - 1;
	hidelayer2[2] = 2 / (1 + exp(-2 * hidelayer2[2])) - 1;
	hidelayer2[3] = 2 / (1 + exp(-2 * hidelayer2[3])) - 1;
	hidelayer2[4] = 2 / (1 + exp(-2 * hidelayer2[4])) - 1;
	hidelayer2[5] = 2 / (1 + exp(-2 * hidelayer2[5])) - 1;

	//hidelayer3
	for (int i = 0; i < level3; i++)
	{
		hidelayer3[i] = 0;
		for (int j = 0; j < level2; j++)
		{
			hidelayer3[i] += hidelayer2[j] * lw2[i][j];
		}
		hidelayer3[i] += b3[i];
		hidelayer3[i] = 2 / (1 + exp(-2 * hidelayer3[i])) - 1;
	}

	//hidelayer4
	for (int i = 0; i < level4; i++)
	{
		hidelayer4[i] = 0;
		for (int j = 0; j < level3; j++)
		{
			hidelayer4[i] += hidelayer3[j] * lw3[i][j];
		}
		hidelayer4[i] += b4[i];
		hidelayer4[i] = 2 / (1 + exp(-2 * hidelayer4[i])) - 1;
		result[i] = hidelayer4[i]*255;
	}

	return result;
}

int main()
{
	Mat original;
	
	original = imread("eight.jpg");
	for (int i = 0; i < original.rows; i++)
	{
		for (int j = 0; j < original.cols; j++)
		{
			 Vec3b res=dealnet(original.at<Vec3b>(i, j));
			 original.at<Vec3b>(i, j)[0] = res[0];
			 original.at<Vec3b>(i, j)[1] = res[1];
			 original.at<Vec3b>(i, j)[2] = res[2];
		}
	}
	imshow("result", original);
	waitKey();
    return 0;
}

