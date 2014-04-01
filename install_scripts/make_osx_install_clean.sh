echo $@;

for var in "$@"
do
    opencvInstallBase=$var;
    sudo find $opencvInstallBase/lib/libopencv*.dylib -exec rm -rf {} \;
    sudo find $opencvInstallBase/lib/libopencv*.a -exec rm -rf {} \;
    sudo find $opencvInstallBase/lib/pkgconfig/*opencv* -exec rm {} \;
    sudo find $opencvInstallBase/bin/*opencv* -exec rm {} \;
    sudo rm -rf $opencvInstallBase/include/opencv
    sudo rm -rf $opencvInstallBase/include/opencv2 
done


