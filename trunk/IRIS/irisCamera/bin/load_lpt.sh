#!/bin/sh
#====================================================================
# Insert 'sbiglptmod' module. 
# This script was modified from A.Rubini: Linux Device Drivers, 1998
# Written by: Jan Soldan
#====================================================================
lpt_module="$INTROOT/lib/sbiglptmod"	
lpt_device="sbiglpt"
#====================================================================
# Character kernel driver: sbiglptmod
#====================================================================
# remove old nodes
rm -f /dev/${lpt_device}[0-2]

# remove lp, parport_pc and parport modules
/sbin/modprobe -r lp
/sbin/modprobe -r parport_pc
/sbin/modprobe -r parport

# insert new lpt module, use -f option
/sbin/insmod -f ${lpt_module}.o

# find free major number
major=`awk "\\$2==\"$lpt_device\" {print \\$1}" /proc/devices`

# create new nodes for the three lpt devices
mknod /dev/${lpt_device}0 c $major 0
mknod /dev/${lpt_device}1 c $major 1
mknod /dev/${lpt_device}2 c $major 2

#set appropriate permissions
chmod 666 /dev/${lpt_device}[0-2]
#====================================================================



