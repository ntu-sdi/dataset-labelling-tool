#!/bin/bash 

if [[ "$*" == "-clean" ]]
then
rm -rf ./build
rm -rf ./tests/build
rm ./tests/cmake_install.cmake
rm ./tests/CMakeCache.txt
fi

if [[ "$*" == "-build" ]]
then
cmake -B ./build
make -C build
cmake -B ./tests/build -S ./tests
make -C ./tests/build
fi

if [[ "$*" == "-run" ]]
then
./build/Dataset-Labelling-Tool
fi

if [[ "$*" == "-runtests" ]]
then
cd tests/build
./Tests
cd ../../
fi





