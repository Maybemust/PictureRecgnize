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
#include "testsvm.h"
#include <unistd.h>

#include "wxzSVM.h"

#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159
int rightdown_x, rightdown_y, leftdown_x, leftdown_y, rightup_x, rightup_y, leftup_x, leftup_y;
cv::Mat imgHeader;


TestSVM::TestSVM(boost::shared_ptr<ALBroker> pBroker, const std::string& pName) :
	ALModule(pBroker, pName),
	camProxy(getParentBroker()),
	motionProxy(getParentBroker()),
	postureProxy(getParentBroker()),
	clientName(" ")
{
	setModuleDescription("");
	functionName("start", getName(), "");
	BIND_METHOD(TestSVM::start);
}

void TestSVM::exit()
{
	AL::ALModule::exit();
}

void TestSVM::init()
{
	start();
}

TestSVM::~TestSVM()
{

}

void TestSVM::start()
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
	int leftboundry = 140; //while going right, if the obstacle is left enough
	int rightboundry = 220; //similar to above
	// waitKey(1000);
	wxzSVM svm;
	int i = 0;
	int sum = 0;
	while (1)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		//cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();
		//cout<<'3'<<endl;
		camProxy.releaseImage(clientName);
		//cout<<'4'<<endl;
		Mat image = imgHeader.clone();
		//cout<<'5'<<endl;
		imshow("image", image);
		//cout<<'6'<<endl;
		svm.SVMFind(2, image);
		sum += svm.center_x();

		char c = waitKey(1) & 255;
		if(c == 27)
			break;

	}
	camProxy.unsubscribe(clientName);
}