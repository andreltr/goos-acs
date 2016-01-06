# Introduction #

In order to compile the software you must install some libraries. This guide will show you the needed libraries and explain how to install them.

# Swift Quick-Look FITS 1.3 #

In order to use it, download the _fits1.3.jar_ file and put it in your CLASSPATH environment variable. You can see your current CLASSPATH folders with:

  * **echo $CLASSPATH**

To add another folder to your CLASSPATH you must edit your _.bashrc_ file in your HOME folder, here's an example:

  * **export CLASSPATH=/my\_dir/lib/:$CLASSPATH**

# CCFITS and cfitsio #

To install CCfits, you must download the rpm files available in the Downloads section of this site and install them:

  * **cfitsio-3.030-1.sl5.i386.rpm**
  * **cfitsio-devel-3.030-1.sl5.i386.rpm**
  * **CCfits-1.7-1.fc6.i386.rpm**
  * **CCfits-devel-1.7-1.fc6.i386.rpm**

# ANDOR SDK #

The Andor SDK is needed to compile the ACS component part of the software.

Uncompress the TAR using:

  * **tar -xvzf andor.tar.gz**

Go to the new directory from a terminal and execute (as sudo):

  * **sudo ./install\_andor**

Select your camera type from the list and wait for the script to finish.

# SBIG Linux Development Tools #

To install the shared libraries you must download the Linux Development Kit for Kernel 2.6 from the SBIG website. Then follow the instructions on the _README.txt_ file.