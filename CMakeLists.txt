cmake_minimum_required (VERSION 3.0)
project (raspi_microscope VERSION 0.1)

SET(COMPILE_DEFINITIONS -Werror -std=c++17 -Wall -fPIC -Ofast -fopenmp)

#inlcude OpenCV lib
set(OpenCV_DIR "/home/liang/workspace/rasp/installation/OpenCV-masrer/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
include_directories( 
    ${OpenCV_INCLUDE_DIRS}
    $(CMAKE_CURRENT_LIST_DIR)/include
    ) # provide library headers


#inlcude link directory
link_directories( 
    ${PI_ROOT}/opt/vc/lib ${PI_ROOT}/lib/arm-linux-gnueabihf 
    ${PI_ROOT}/lib 
    ${PI_ROOT}/usr/lib/arm-linux-gnueabihf 
    ${PI_ROOT}/usr/local/lib
    )

# Add all the *.c files in our source directory to our executable output
FILE(GLOB SRC_FILES src/*.cpp)

add_executable(raspi_microscope ${SRC_FILES})

# Link the lib
target_link_libraries( 
    raspi_microscope ${OpenCV_LIBS} libGL.so.1.7.0 libGLU.so.1.3.1 libQt5Widgets.so.5 libQt5Gui.so.5 libQt5Core.so.5 libfreetype.so.6 
    libharfbuzz.so.0 libhdf5_serial.so.103 libsz.so.2 libz.so.1 libglog.so.0 libgflags.so.2.2 libQt5Test.so.5 libQt5Concurrent.so.5.11.3 
    libQt5OpenGL.so.5 libdc1394.so.22 libavcodec.so.58 libavformat.so.58 libavutil.so.56 libswscale.so.5 libjpeg.so.62 libpng16.so.16 
    libtiff.so.5 libjasper.so.1 libc.so.6 libc_nonshared.a )   