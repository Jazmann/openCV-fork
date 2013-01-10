#!/usr/bin/env python
"""
The script builds OpenCV.framework for iOS.
The built framework is universal, it can be used to build app and run it on either iOS simulator or real device.

Usage:
    ./build_framework.py <outputdir>

By cmake conventions (and especially if you work with OpenCV repository),
the output dir should not be a subdirectory of OpenCV source tree.

Script will create <outputdir>, if it's missing, and a few its subdirectories:

    <outputdir>
        build/
            iPhoneOS-*/
               [cmake-generated build tree for an iOS device target]
            iPhoneSimulator/
               [cmake-generated build tree for iOS simulator]
        opencv2.framework/
            [the framework content]

The script should handle minor OpenCV updates efficiently
- it does not recompile the library from scratch each time.
However, opencv2.framework directory is erased and recreated on each run.
"""

import glob, re, os, os.path, shutil, string, sys

def build_opencv(srcroot, buildroot, target, arch):
    "builds OpenCV for device or simulator"
	# copy over ~/Developer/openCV_Dev/opencv/ios/Info.plist.in  so put_framework_together is srcroot independent
    # os.system("echo \"mkdir -p %s \" " % (buildroot))
    # os.system("echo \"cp %s %s \" " % (os.path.join(srcroot,"ios/Info.plist.in"), buildroot))
    # os.system("echo \"cp %s %s \" " % (os.path.join(srcroot,"ios/make_framework.py "), os.path.join(buildroot,"..")))
    os.system("mkdir -p %s" % (buildroot))
    os.system("cp %s %s" % (os.path.join(srcroot,"ios/Info.plist.in"), buildroot))
    # os.system("cp %s %s" % (os.path.join(srcroot,"ios/make_framework.py "), os.path.join(buildroot,"..")))

    builddir = os.path.join(buildroot, target + '-' + arch)
    if not os.path.isdir(builddir):
        os.makedirs(builddir)
    currdir = os.getcwd()
    os.chdir(builddir)
    # for some reason, if you do not specify CMAKE_BUILD_TYPE, it puts libs to "RELEASE" rather than "Release"
    #           "-D CMAKE_BUILD_TYPE=Release " +
    if target=="OSX" : cmakeargs = ("-G Xcode " +
                     "-D CMAKE_BUILD_TYPE=Release " +
                     "-D BUILD_opencv_world=ON " +
                     "-D CMAKE_INSTALL_PREFIX=install")
    else: cmakeargs = ("-G Xcode " +
                     "-D CMAKE_BUILD_TYPE=Release " +
                     "-D CMAKE_TOOLCHAIN_FILE=%s/ios/cmake/Toolchains/Toolchain-%s_Xcode.cmake " +
                     "-D BUILD_opencv_world=ON " +
                     "-D CMAKE_INSTALL_PREFIX=install") % (srcroot, target)
                     
    # if cmake cache exists, just rerun cmake to update OpenCV.xproj if necessary
    if os.path.isfile(os.path.join(builddir, "CMakeCache.txt")):
        os.system("cmake %s ." % (cmakeargs,))
    else:
        os.system("cmake %s %s" % (cmakeargs, srcroot))

    for wlib in [builddir + "/modules/world/UninstalledProducts/libopencv_world.a",
                 builddir + "/lib/Release/libopencv_world.a"]:
        if os.path.isfile(wlib):
            os.remove(wlib)

    if target=="OSX" : 
    	os.system("xcodebuild -parallelizeTargets ARCHS=%s -jobs 8 -configuration Release -target ALL_BUILD" % (arch))
    	os.system("xcodebuild ARCHS=%s -configuration Release -target install install" % (arch))
    else:
    	os.system("xcodebuild -parallelizeTargets ARCHS=%s -jobs 8 -sdk %s -configuration Release -target ALL_BUILD" % (arch, target.lower()))
    	os.system("xcodebuild ARCHS=%s -sdk %s -configuration Release -target install install" % (arch, target.lower()))
    
    os.chdir(currdir)


def build_framework(srcroot, dstroot):
    "main function to do all the work"

    targets = ["iPhoneOS", "iPhoneOS", "iPhoneSimulator"]
    archs = ["armv7", "armv7s", "i386"]
  #  targets = ["OSX"]
  #  archs = ["x86_64"]
    for i in range(len(targets)):
        build_opencv(srcroot, os.path.join(dstroot, "build"), targets[i], archs[i])
    
    os.system("cp %s %s" % (os.path.join(srcroot,"ios/make_framework.py "), dstroot))
    os.chdir(dstroot)
    import make_framework.py


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "Usage:\n\t./build_framework.py <outputdir>\n\n"
        sys.exit(0)

    build_framework(os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), "..")), os.path.abspath(sys.argv[1]))