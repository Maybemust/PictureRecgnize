#include <boost/shared_ptr.hpp>
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <qi/os.hpp>
#include <qi/log.hpp>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "objectFinder.h"
#include "avoidcollision.h"
#include <unistd.h>
#include "ycylib2.h"

#include "wxzSVM.h"

#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159
int rightdown_x, rightdown_y, leftdown_x, leftdown_y, rightup_x, rightup_y, leftup_x, leftup_y;
cv::Mat imgHeader;


AvoidCollision::AvoidCollision(boost::shared_ptr<ALBroker> pBroker, const std::string& pName) :
	ALModule(pBroker, pName),
	camProxy(getParentBroker()),
	motionProxy(getParentBroker()),
	postureProxy(getParentBroker()),
	clientName(" ")
{
	setModuleDescription("");
	functionName("start", getName(), "");
	BIND_METHOD(AvoidCollision::start);
}

void AvoidCollision::exit()
{
	AL::ALModule::exit();
}

void AvoidCollision::init()
{
	start();
}

AvoidCollision::~AvoidCollision()
{

}

void AvoidCollision::start()
{
	motionProxy.wakeUp();
	postureProxy.goToPosture("StandInit", 0.5);

	AL::ALValue config = AL::ALValue::array(AL::ALValue::array("LeftStepHeight", 0.02), AL::ALValue::array("RightStepHeight", 0.02), AL::ALValue::array("LeftMaxStepX", 0.04), AL::ALValue::array("RightMaxStepX", 0.03));

	camProxy.setActiveCamera(0);
	camProxy.setParameter(0, 12, 0);
	clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 5);
	imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);

	AL::ALValue names1 = "HeadYaw";
	AL::ALValue angleLists = 0;//10.2 * PI / 180;
	AL::ALValue timeLists = 1.0f;
	bool isAbsolute = true;
	motionProxy.angleInterpolation(names1, angleLists, timeLists, isAbsolute);

	int gqs_x  = 80;//guoqushang开始加速直走
	int gqs_y  = 100;
	int gqx_x  = 60;//guoquxia开始加速直走
	int gqx_y  = 230;
	int py_y    = 0;//pingyi，绕过前一个柱子开始拐弯 the distant away from the obstacle infront
	int ldy_x   = 200;//lidehenyuan，离得很远
	int ldj_x    = 80;//lidejin，离得近
	int ldj_y    = 180;
	int judgepass = 240;

	int direction = 0; //go right = -1  and go left = 1  and go straight = 0
	int leftboundry = 250; //while going right, if the obstacle is left enough
	int rightboundry = 70; //similar to above
	// waitKey(1000);
	wxzSVM svm;
	cout << "*************************" << "11111" << "*********************" << endl;
	int i=0;
	int sum=0;
	while(i<4)
	{	
		i++;
		ALValue img = camProxy.getImageRemote(clientName);
		//cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();
		//cout<<'3'<<endl;
		camProxy.releaseImage(clientName);
		//cout<<'4'<<endl;
		Mat image = imgHeader.clone();
		//cout<<'5'<<endl;
		imshow("image", image);
		waitKey(50);
		//cout<<'6'<<endl;
		svm.SVMFind(1, image);
		sum+=svm.center_x();
		
	}
	sum=sum/4.0;
	cout<<sum<<endl;
	if (sum > 160)
	{
			direction = 1;
			cout<<"left"<<endl;
	}
	else
	{
			direction = -1;
			cout<<"right"<<endl;
	}

	while (true)
	{
		//cout<<'1'<<endl;
		ALValue img = camProxy.getImageRemote(clientName);
		//cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();
		//cout<<'3'<<endl;
		camProxy.releaseImage(clientName);
		//cout<<'4'<<endl;
		Mat image = imgHeader.clone();
		//cout<<'5'<<endl;
		imshow("image", image);
		waitKey(10);
		//cout<<'6'<<endl;
		svm.SVMFind(1, image);
		//cout<<'7'<<endl;
		/*0-1，右前走*/
		// if(rightdown_x < ldy_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		// else
		// 	motionProxy.moveToward(0.1, 0.8, 0);
		// if(( rightup_x < gqs_x && rightup_y > gqs_y)||(rightdown_x < gqx_x && rightdown_y > gqx_y))
		// 	break;
		// if(rightdown_y > ldj_y && rightdown_x > ldj_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		motionProxy.moveToward(0.1, direction * 0.5, 0);
		if ((direction == 1 && svm.leftdown_x() > leftboundry) || (direction == -1 && svm.rightdown_x() < rightboundry))
			break;
		cout<<svm.rightdown_x()<<" "<<svm.leftdown_x()<<endl;
	}
	//sleep(5000);
	/*1-2之间直走*/
	cout << "*********************" << " 1-----2" << "**********************************" << endl;
	// waitKey(1000);
	while (true)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();
		imshow("image", image);
		waitKey(10);
		svm.SVMFind(2, image);
		motionProxy.moveToward(0.6, 0, 0, config);
		//if(rightdown_y > py_y)
		rightdown_y = svm.rightdown_y();
		rightup_y = svm.rightup_y();
		if (rightdown_y - rightup_y > 130)
			break;
		cout<<rightdown_y - rightup_y<<endl;
	}
	// waitKey(1000);
	//sleep(1);
	cout << "*******************************" << 2222 << "*****************************************" << endl;
	/*绕过第二个柱子*/
	direction = -1 * direction;
	while (true)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();
		imshow("image", image);
		waitKey(15);
		svm.SVMFind(2, image);
		// if(leftdown_x > (320 - ldy_x))
		// 	motionProxy.moveToward(0.8, 1, 0);
		// else
		//   		motionProxy.moveToward(0.6, 1, 0);
		// if((leftup_x > (320 - gqs_x) && leftup_y > (240 - gqs_y)) || (leftdown_x > (320 - gqx_x) && leftdown_y >  (240 - gqx_y)))
		// 	break;
		// if(leftdown_y > ldj_y && leftdown_x < ldj_x)
		// 	motionProxy.moveToward(0.4, 1, 0);
		//

		motionProxy.moveToward(0.1, direction * 0.5, 0);
		
		if ((direction == 1 && svm.leftdown_x() > leftboundry) || (direction == -1 && svm.rightdown_x() < rightboundry))
			break;

	}
	direction = -1 * direction;
	//sleep(1);
	/*2-3之间直走*/
	cout << "*********************" << " 2-----3" << "**********************************" << endl;
	// waitKey(1000);
	while (true)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();
		imshow("image", image);
		waitKey(15);
		svm.SVMFind(3, image);
		motionProxy.moveToward(0.6, 0, 0, config);
		if (svm.rightdown_y() - svm.rightup_y() > 130)
			break;
	}
	// waitKey(1000);
	//sleep(1);
	cout << "*********************" << 33333 << "**********************************" << endl;
	//如果 机器人看不见下一个障碍物，那么需要机器人转头
	// double  maxx =  rightdown_x - leftdown_x;
	// double  maxy = rightdown_y - rightup_y;
	// while(maxx * maxy < 400)
	// {
	// AL::ALValue names2 = "HeadYaw";
	// motionProxy.angleInterpolation(names2, 30.2 * PI / 180, timeLists, isAbsolute);
	// motionProxy.angleInterpolation(names2, -30.2 * PI / 180, timeLists, isAbsolute);
	// motionProxy.angleInterpolation(names2, 0, timeLists, isAbsolute);
	// motionProxy.moveToward(0, 0,0.5) ;
	// ALValue img = camProxy.getImageRemote(clientName);
	// imgHeader.data = (uchar*) img[6].GetBinary();
//       	camProxy.releaseImage(clientName);
	// Mat image = imgHeader.clone();
//     	imshow("image",image);
//        	waitKey(50);
	// find(3,image);
	// maxx =  rightdown_x - leftdown_x;
	// maxy = rightdown_y - rightup_y;
	// }

	while (true)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();
		imshow("image", image);
		waitKey(15);
		svm.SVMFind(3, image);

		// if(rightdown_x < ldy_x)
		// 	motionProxy.moveToward(0.8, -0.8, 0);
		// else
		// 	motionProxy.moveToward(0.6, -0.8, 0);
		// if((rightup_x < gqs_x && rightup_y > gqs_y)||(rightdown_x < gqx_x && rightdown_y > gqx_y))
		// 	break;
		// if(rightdown_y > ldj_y && rightdown_x > ldj_x)
		// 	motionProxy.moveToward(0.4, -0.8, 0);
		motionProxy.moveToward(0.1, direction * 0.5, 0);
		if ((direction == 1 && svm.leftdown_x() > leftboundry) || (direction == -1 && svm.rightdown_x() < rightboundry))
			break;

	}

	while(true){
	motionProxy.moveToward(0.6, 0, 0, config);       
	}          //   能否准确到达 终点
	camProxy.unsubscribe(clientName);
}