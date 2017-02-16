# Project properties
SET( projectName cameraWindows )
PROJECT( ${projectName}_PRJ )
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# OPENCV
FIND_PACKAGE( OpenCV REQUIRED )

# VIDEOINPUT
FIND_PATH( VIDEO_INPUT_INCLUDE videoInput.h ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/VideoInput/include )
FIND_PATH( VIDEO_INPUT_LIB_DIR videoInputLib.a ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/VideoInput )

link_directories( ${VIDEO_INPUT_LIB_DIR}/DShow )

INCLUDE_DIRECTORIES( ${VIDEO_INPUT_INCLUDE} )
INCLUDE_DIRECTORIES( ${VIDEO_INPUT_LIB_DIR} )

SET( VINPUT_LIB ${VIDEO_INPUT_LIB_DIR}/videoInputLib.a )
SET( VINPUT_LIB2 ddraw dxguid ole32 oleaut32 strmbasd strmbase strmiids uuid )

# EXECUTABLE
ADD_EXECUTABLE( ${projectName} main.cpp CameraWindows.cpp)

TARGET_LINK_LIBRARIES( ${projectName} ${OpenCV_LIBS} ${VINPUT_LIB} ${VINPUT_LIB2} )