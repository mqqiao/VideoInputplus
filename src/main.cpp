#include "CameraWindows.h"
#include <opencv2/core/core.hpp>
//#pragma comment(linker, "/NODEFAULTLIB:atlthunk.lib")

using namespace cv;
int main( int argc, char** argv )
{
	CameraWindows camera1;
	CameraWindows camera2(1);
	CameraWindows camera3(2);

	cv::namedWindow("camera1");
	cv::namedWindow("camera2");
	cv::namedWindow("camera3");
	 
	for( ;; )
    {
        if ( camera1.fetchNewFrame() && camera2.fetchNewFrame() && camera3.fetchNewFrame())
        {
        	cv::imshow("camera1", camera1.getFrame());
			cv::imshow("camera2", camera2.getFrame());
			cv::imshow("camera3", camera3.getFrame());
		}
		else {
			std::cout << "one out" << std::endl;
		}

        if( cv::waitKey(30) >= 0 )
		{
        	break;
		}
    }
	
	return 0;
}
