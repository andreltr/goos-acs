#!/bin/sh

#TEST



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