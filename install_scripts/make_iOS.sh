ECHO "Provide super user password please."
sudo ECHO "Hello superuser!"
ECHO "Building opencv framework for iOS";
python opencv/platforms/ios/build_framework.py ios > log_ios.txt;
ECHO "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
tail -n 10 log_ios.txt;
ECHO "opencv built? check the log file";

