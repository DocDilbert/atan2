# No128
This C++ library allows to do 128 bit calculation with 32bit operations. Its usefull in embedded application
were bigger numbers are required and speed is key.

## Requirements
To compile this project severall libraries are needed. To obtain them vcpkg is used. 
To install vcpkg look [here](https://github.com/microsoft/vcpkg). Attention the default target in vcpkg is 32 bit.

* Install gtest with vcpkg. `vcpkg install gtest`. 
* Add to cmake configuration: `-DCMAKE_TOOLCHAIN_FILE=c:\\dev\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake`
