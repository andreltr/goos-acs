#!/bin/sh
#====================================================================
# Remove 'sbiglptmod' module. 
# Written by: Jan Soldan
#====================================================================
lpt_module="sbiglptmod"				   
lpt_device="sbiglpt"
#====================================================================
# Character kernel driver: sbiglptdrv
#====================================================================
/sbin/rmmod ${lpt_module} 

# remove all three nodes
rm -f /dev/${lpt_device}[0-2]
#====================================================================

# load lp, parport_pc, parport modules again
/sbin/modprobe -r parport
/sbin/modprobe -r parport_pc
/sbin/modprobe -r lp
