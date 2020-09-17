# raspi_microscope
use raspberry pi 3 build a microscope platform

1. Prepare Development Env (coross compile + opencv support)

    (1) build cross comppile on host 
        offical tool is too old. need to build a new one https://solarianprogrammer.com/2018/05/06/building-gcc-cross-compiler-raspberry-pi/
    
    (2) Build Opencv lib on raspberry pi
        refer it https://www.learnopencv.com/install-opencv-4-on-raspberry-pi/
        no need to build example and python support
    
    (3) copy opencv lib from pi to host

    (4) copy pi system lib and prepare cmake on host. 
        refer https://solderspot.wordpress.com/2016/02/04/cross-compiling-for-raspberry-pi-part-ii/
    
2. C++ program to process img.

3. Python program Web GUI interface
