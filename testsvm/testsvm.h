#include <boost/shared_ptr.hpp>          
#include <alcommon/almodule.h>         
#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>

#include <opencv2/core/core.hpp>
#include <string>
namespace AL
{
class ALBroker;
}
void find(int num,cv::Mat image);
class TestSVM: public AL::ALModule
{
public:
	TestSVM(boost::shared_ptr<AL::ALBroker> pBroker, const std::string& pName);

	virtual ~TestSVM();

	void exit();

	virtual void init();

	void start();
private:
	AL::ALVideoDeviceProxy camProxy;
	AL::ALMotionProxy motionProxy;
	AL::ALRobotPostureProxy postureProxy;
	std::string clientName;
};

