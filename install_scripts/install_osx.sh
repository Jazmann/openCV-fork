sudo ECHO "Installing OSX dylibs to $1"
./make_osx_install_clean.sh "$@"

for var in "$@"
do
    install_base=$var;
    sudo cp -R ./install/include $install_base
    sudo cp ./install/lib/pkgconfig/opencv.pc $install_base/lib/pkgconfig/
    sudo find ./install/lib/libopencv*.a -exec cp {} $install_base/lib/ \;
    sudo find ./install/lib/libopencv*.dylib -execdir ./change_install_name.sh {} $install_base/lib/ \;
    sudo cp -R ./install/bin $install_base
done

ECHO "opencv install files copied to $install_base";

