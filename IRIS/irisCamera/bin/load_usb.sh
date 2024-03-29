#!/bin/sh
#====================================================================
# Insert 'sbigusbmod' modules. 
# This script was modified from A.Rubini: Linux Device Drivers, 1998
# Written by: Jan Soldan
#====================================================================
usb_module="$INTROOT/lib/sbigusbmod"
usb_device="sbigusb"

SBIG_USB_MINOR_BASE=192

SBIG_USB_MINOR_0=192
SBIG_USB_MINOR_1=193
SBIG_USB_MINOR_2=194
SBIG_USB_MINOR_3=195
#====================================================================
# USB kernel driver: sbigusbmod
#====================================================================
# remove old nodes
rm -f /dev/${usb_device}[0-3]

# insert new usb module, use -f option
/sbin/insmod -f ${usb_module}.o

# create new nodes for the three devices
mknod /dev/${usb_device}0 c 180 ${SBIG_USB_MINOR_0}
mknod /dev/${usb_device}1 c 180 ${SBIG_USB_MINOR_1}
mknod /dev/${usb_device}2 c 180 ${SBIG_USB_MINOR_2}
mknod /dev/${usb_device}3 c 180 ${SBIG_USB_MINOR_3}

#set appropriate permissions
chmod 666 /dev/${usb_device}[0-3]
#====================================================================



