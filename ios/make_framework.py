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

Add a build script phase at the end of the build in XCode if you want to build the framework in XCode.
Use this command. 

python $SYMROOT/../../make_framework.py

"""

import glob, re, os, os.path, shutil, string, sys

def put_framework_together( dstroot):
    "constructs the framework directory after all the targets are built"
    print("dstroot =  %s" % (dstroot))

    # find the list of targets (basically, ["iPhoneOS", "iPhoneSimulator"])
    targetlist = [ f for f in os.listdir(os.path.join(dstroot, "build")) if os.path.isdir(os.path.join(os.path.join(dstroot, "build"),f)) ]

    # targetlist = glob.glob(os.path.join(dstroot, "build", "*"))
    targetlist = [os.path.basename(t) for t in targetlist]
    print("Target Architectures : %s" % (targetlist))

    # set the current dir to the dst root
    currdir = os.getcwd()
    print("The current directory is %s" % (currdir))
    framework_dir = dstroot + "/opencv2.framework"
    print("framework_dir =  %s" % (framework_dir))
    if os.path.isdir(framework_dir):
        shutil.rmtree(framework_dir)
    os.makedirs(framework_dir)
    os.chdir(framework_dir)

    # determine OpenCV version (without subminor part)
    tdir0 = dstroot + "/build/" + targetlist[0]
    cfg = open(tdir0 + "/cvconfig.h", "rt")
    for l in cfg.readlines():
        if l.startswith("#define  VERSION"):
            opencv_version = l[l.find("\"")+1:l.rfind(".")]
            break
    cfg.close()

    # form the directory tree
    dstdir = "Versions/A"
    os.makedirs(dstdir + "/Resources")
    print("shutil.copytree(%s + /install/include/opencv2, %s + /Headers)" % (tdir0, dstdir))
	
    # copy headers
    shutil.copytree(tdir0 + "/install/include/opencv2", dstdir + "/Headers")

   # make universal static lib
    wlist = " "
    for t in targetlist:
    	if os.path.isfile(os.path.join(dstroot, "build", t, "lib/Debug/libopencv_world.a")) :
    		wlist = wlist + " " + dstroot + "/build/" + t + "/lib/Debug/libopencv_world.a"
    		print("Linked Debug for target %s\n" % (t))
    	elif os.path.isfile(os.path.join(dstroot, "build", t, "lib/Release/libopencv_world.a")) :
    		wlist = wlist + " " + dstroot + "/build/" + t + "/lib/Release/libopencv_world.a"
    		print("Linked Release for target %s\n" % (t))
    	else : 
    		print("Error : libopencv_world.a not found for target %s\n Looked in %s" % (t, dstroot + "/build/" + t + "/lib/Release"))
    		
    print("wlist : %s\n" % (wlist))
    		
    os.system("lipo -create " + wlist + " -o " + dstdir + "/opencv2")
    
    
  #  wlist = " ".join([currdir + "/build/" + t + "/lib/Release/libopencv_world.a" for t in targetlist])
  #  os.system("lipo -create " + wlist + " -o " + dstdir + "/opencv2")


    # form Info.plist
    srcfile = open(dstroot + "/build/Info.plist.in", "rt")
    dstfile = open(dstdir + "/Resources/Info.plist", "wt")
    for l in srcfile.readlines():
        dstfile.write(l.replace("${VERSION}", opencv_version))
    srcfile.close()
    dstfile.close()

    # copy cascades
    # TODO ...

    # make symbolic links
    os.symlink(dstdir + "/Headers", "Headers")
    os.symlink(dstdir + "/Resources", "Resources")
    os.symlink(dstdir + "/opencv2", "opencv2")
    os.symlink("A", "Versions/Current")
    
put_framework_together(os.path.abspath(os.path.dirname(sys.argv[0]) ))