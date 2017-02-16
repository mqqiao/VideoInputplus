/*
 * CameraWindows.h
 *
 *  Created on: 02 mars 2011
 *      Author: Rodrigo
 */

#ifndef CAMERAWINDOWS_H_
#define CAMERAWINDOWS_H_

#include <iostream>
//#include <iostream>
#include <sstream>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "../3rdparty/VideoInput/include/videoInput.h"

class CameraWindows
{

public:
	CameraWindows( const int deviceNb = 0, const int width = 1024, const int height = 720);
	bool fetchNewFrame();
	cv::Mat &getFrame();
	virtual ~CameraWindows();
	
protected:
	videoInput mVideoInput;
	int mDeviceNb;
	int mWidth;
	int mHeight;
	int mSize;
	unsigned char * mBuffer;

	cv::Mat mFrame;

	// see : http://msdn.microsoft.com/en-us/library/dd318253(v=vs.85).aspx
	// and : http://msdn.microsoft.com/en-us/library/dd389148(v=vs.85).aspx
	typedef enum  {
		CameraControl_Pan,
		CameraControl_Tilt,
		CameraControl_Roll,
		CameraControl_Zoom,
		CameraControl_Exposure,
		CameraControl_Iris,
		CameraControl_Focus
	}CameraControlProperty;

	// see : http://msdn.microsoft.com/en-us/library/dd318251(v=vs.85).aspx
	typedef enum   {
		CameraControl_Flags_Auto     = 0x0001,
		CameraControl_Flags_Manual   = 0x0002
	}CameraControlFlags;

	static const long mDefaultFocus = 0;

};

#endif /* CAMERAWINDOWS_H_ */
