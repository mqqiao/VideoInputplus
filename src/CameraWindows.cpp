/*
 * CameraWindows.cpp
 *
 *  Created on: 02 mars 2011
 *      Author: Rodrigo
 */

#include <iostream>
#include <sstream>
#include <string>
#include "CameraWindows.h"
#include "opencv2/highgui/highgui.hpp"

CameraWindows::CameraWindows( const int deviceNb, const int width, const int height ) :
	mDeviceNb ( deviceNb )
{
	// Prints out a list of available devices and returns num of devices found
	int numDevices = mVideoInput.listDevices();	
	
	// If you want to capture at a different frame rate (default is 30) 
	// specify it here, you are not guaranteed to get this fps though.
	// mVideoInput.setIdealFramerate(deviceNb, 60);

	// Setup device with video size and connection type
	mVideoInput.setupDevice(mDeviceNb, width, height, VI_COMPOSITE);

	// As requested width and height can not always be accomodated
	// make sure to check the size once the device is setup
	mWidth = mVideoInput.getWidth(mDeviceNb);
	mHeight = mVideoInput.getHeight(mDeviceNb);
	mSize = mVideoInput.getSize(mDeviceNb);

	// Create the buffer where the video will be captured
	mBuffer = new unsigned char[mSize];

	// Disable autofocus and set focus to 0
	mVideoInput.setVideoSettingCamera(mDeviceNb, CameraControl_Focus, mDefaultFocus, CameraControl_Flags_Manual);

	// mVideoInput.showSettingsWindow(mDeviceNb);
}

bool CameraWindows::fetchNewFrame()
{
	//fills pixels in buffer as a BGR (for openCV) unsigned char array - flipping
	bool success = mVideoInput.getPixels(mDeviceNb, mBuffer, false, true);

	if( success )
	{
		cv::Mat image( mHeight, mWidth, CV_8UC3, mBuffer );
		mFrame = image;
		return true;
	}
	else
	{
		std::cout << "Error loading frame from camera (Windows)." << std::endl;
		return false;
	}
}

cv::Mat & CameraWindows::getFrame()
{   
	std::stringstream ss;
	ss << mDeviceNb;
	std::string   s = ss.str();
	cv::imwrite(s + ".jpg", mFrame);
	return mFrame;
}

CameraWindows::~CameraWindows()
{
	mVideoInput.stopDevice(mDeviceNb);
	delete[] mBuffer;
}
