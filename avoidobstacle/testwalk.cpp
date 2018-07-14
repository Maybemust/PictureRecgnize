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

#include "testwalk.h"
#include "ycylib2.h"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159


testwalk::testwalk(boost::shared_ptr<ALBroker> pBroker,const std::string& pName) :
		ALModule(pBroker, pName), 
		camProxy(getParentBroker()), 
		motionProxy(getParentBroker()), 
		postureProxy(getParentBroker()), 
		clientName(" ")
{
	setModuleDescription(
			"");

	functionName("start", getName(), "");
	BIND_METHOD(testwalk::start);
}

void testwalk::exit()
{
	AL::ALModule::exit();
}

void testwalk::init()
{
	start();
}

testwalk::~testwalk()1
{

}

void testwalk::start()
{
	motionProxy.wakeUp();
	postureProxy.goToPosture("StandInit", 0.4);
	AL::ALValue config = AL::ALValue::array(AL::ALValue::array("LeftStepHeight", 0.025), AL::ALValue::array("RightStepHeight", 0.03), AL::ALValue::array("LeftMaxStepX", 0.05), AL::ALValue::array("RightMaxStepX", 0.06));
       
        
	AL::ALValue names1 = "HeadPitch";
	AL::ALValue angleLists1 = 10.2 * PI / 180;
	AL::ALValue timeLists = 1.0f;
	bool isAbsolute = true;
	motionProxy.angleInterpolation(names1, angleLists1, timeLists, isAbsolute);



	cout<<"**************我在盲走 当看到障碍物后就跳出该循环！***********************"<<endl;
	while(true)
	{

		//motionProxy.moveToward(0.5, 0, 0,config);    //  0.5 WEN  
		motionProxy.moveToward(0.4, 0.6, 0);    //  0.5 WEN  
	}
	
	motionProxy.moveTo(0.8, 0, 0);
}
