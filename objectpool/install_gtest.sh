#!/usr/bin/env bash

sudo apt-get install cmake -y
arch=$(uname -m)
cur_dir=$(pwd)
file_name=gtest.tar.gz
dir_name=googletest-release-1.8.0

if [ ! -d third_party ]; then
  mkdir third_party
fi
cd third_party
if [ ! -f ${file_name} ]; then
  wget http://182.61.33.235/download/soft/googletest-release-1.8.0.tar.gz -O ${file_name}
fi

if [ -d ${dir_name} ]; then
  echo "aaaaaaaaaaaaa"
  rm -rf ${dir_name}
fi

tar zxvf ${file_name}

cd ${dir_name}
cd googletest
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ../
make

sudo cp -rf ../include/gtest /usr/include
sudo cp libgtest* /usr/lib/${arch}-linux-gnu/

echo "It works!"
