ECHO "Provide super user password please."
sudo ECHO "Hello superuser!"
# Add cmake for pkg-config .pc file
mkdir unix
cd unix
cmake ../opencv/ -G"Unix Makefiles"
cd ..

mkdir install
mkdir install/lib
mkdir install/bin
mkdir install/include
mkdir install/lib/pkgconfig
mkdir install/Library
mkdir install/Library/Frameworks

find ./unix/*/*.pc -exec cp  {} ./install/lib/pkgconfig/ \;
find ./opencv/modules -path *include -exec cp -R {} ./install/ \;
cp -R ./opencv/include ./install
cp -R ./osx/opencv2 ./install/include/
cp -R ./ios/opencv2.framework install/Library/Frameworks
cp  ./osx/lib/Debug/* ./install/lib/
cp  ./osx/bin/Debug/* ./install/bin/

ECHO "opencv install files copied to install. copy the contents to /opt/local/";

