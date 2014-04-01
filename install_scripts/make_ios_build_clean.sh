find ./opencv -iname "CMakeCache.txt" -delete
find ./opencv -iname "cmake_install.cmake" -delete
find ./opencv -iname "CMakeFiles" -delete
find ./opencv -iname "*.orig" -delete
rm -rf ./opencv/build

ECHO "Removing opencv framework for iOS";
rm -rf ios;
rm -rf install/Library/Frameworks;
rm -rf install/Library;

rm  log_ios.txt;

