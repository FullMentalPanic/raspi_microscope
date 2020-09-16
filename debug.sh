#!/bin/sh
cd build
echo "buid C++"
make
mv raspi_microscope ../python/src/
cd ..
echo "send to PI"
scp -r python  liang@192.168.1.143:~/workspace/streamserver/
