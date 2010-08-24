#!/bin/sh
######################################################
# GCCD PLATFORM CONFIGURATION TEST
# AND INSTALLATION SCRIPT
######################################################
# 
######################################################

######################################################
# Some string to use color
######################################################

red="[31m"
green="[32m"
eformat="[0m"
bold="[1m"

######################################################
# Variables definition
######################################################
#TEST

######################################################
# INSTALLATION
######################################################
#  
# 
######################################################

if [ "$1" = "--install" ]
then

	######################################################
	# INSTALLATION NOTICE
	######################################################
	echo $bold "+-----------------------------------------------------+" $eformat
	echo $bold "| The gCDD platform installation is about to start    |" $eformat
	echo $bold "+-----------------------------------------------------+" $eformat
	echo $bold "Starting..." $eformat
	echo ""

	#Must have root super powers
	echo $bold$red "WARNING" $eformat
	echo $bold "In order for this script to work correctly, you must have root access." $eformat
	echo $bold "If you didn't execute this script with 'sudo' press CTRL+C to cancel." $eformat
	echo ""
	echo $bold "Press any key to continue..." $eformat
	echo ""

	read vpause



fi

#ImageMagick

tar -xvzf ImageMagick?.tar.gz

./configure

make install

LD_LIBRARY_PATH=/usr/lib:$LD_LIBRARY_PATH

display

#Jmagick

tar -xvzf JMagick.tar.gz

autoconf

./configure

make all

make install

export CLASSPATH=/usr/lib/jmagick-6.4.0.jar:$CLASSPATH

#CCFITS

rpm -ivh CCfits-1.7-1.fc6.i386.rpm

rpm -ivh CCfits-devel-1.7-1.fc6.i386.rpm