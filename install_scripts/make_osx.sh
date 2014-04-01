ECHO "Provide super user password please."
sudo ECHO "Hello superuser!"
ECHO "Building opencv for osx";
mkdir osx
cd osx
cmake -G"Xcode" ../opencv
xcodebuild -project OpenCV.xcodeproj > log_osx.txt
cd ..
ECHO "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
tail -n 10 log_osx.txt;
ECHO "opencv built? check the log file";

