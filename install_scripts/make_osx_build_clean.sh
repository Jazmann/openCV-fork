find ./opencv -iname "CMakeCache.txt" -delete
find ./opencv -iname "cmake_install.cmake" -delete
find ./opencv -iname "CMakeFiles" -delete
find ./opencv -iname "*.orig" -delete
rm -rf ./opencv/build

rm -rf osx;
rm -rf unix;

rm -rf install/lib/pkgconfig
rm -rf install/lib
rm -rf install/bin
rm -rf install/include

rm  log_osx.txt;

