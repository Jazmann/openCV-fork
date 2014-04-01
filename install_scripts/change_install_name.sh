sudo ECHO "Processing library " $1
if [ $# -lt 2 ]
  then
    new_base=opt/local;
    else
    new_base=$2
fi
current_dir=pwd;

old_base=$current_dir/osx/lib/Debug/;

sudo cp -rf ./install/lib/$1 $new_base

sudo install_name_tool -id $new_base$1 $new_base$1

depLib=libopencv_calib3d.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_calib3d.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_calib3d.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_contrib.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_contrib.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_contrib.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_core.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_core.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_core.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cuda.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cuda.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cuda.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaarithm.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaarithm.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaarithm.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudabgsegm.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudabgsegm.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudabgsegm.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafeatures2d.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafeatures2d.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafeatures2d.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafilters.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafilters.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudafilters.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaimgproc.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaimgproc.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaimgproc.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaoptflow.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaoptflow.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudaoptflow.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudastereo.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudastereo.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudastereo.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudawarping.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudawarping.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_cudawarping.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_features2d.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_features2d.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_features2d.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_flann.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_flann.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_flann.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_highgui.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_highgui.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_highgui.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_imgproc.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_imgproc.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_imgproc.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_legacy.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_legacy.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_legacy.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_ml.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_ml.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_ml.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_nonfree.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_nonfree.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_nonfree.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_objdetect.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_objdetect.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_objdetect.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_optim.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_optim.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_optim.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_photo.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_photo.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_photo.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_shape.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_shape.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_shape.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_softcascade.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_softcascade.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_softcascade.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_stitching.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_stitching.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_stitching.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_superres.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_superres.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_superres.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_video.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_video.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_video.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_videostab.3.0.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_videostab.3.0.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
depLib=libopencv_videostab.dylib;
sudo install_name_tool -change $old_base$depLib $new_base$depLib $new_base$1
