#!/bin/bash
#
# "@(#) $Id: sbig_load_firmware.sh,v 1.3 2004/05/25 17:05:52 tjuerges Exp $"
#
# Upload firmware into the SBIG USB CCD cameras
#
# 2004/05/25: tjuerges: Modified for ACS.
#

LOADER=$INTROOT/bin/fxload

PRODID=`cat /proc/bus/usb/devices | grep -i ^P: | grep Vendor=0d97 | cut -d ' '  -f 4 | sed -e 's/ProdID=//' - - | sed -e 's/0//g' - -`

PRODUCT="d97/$PRODID/dummy"

# Find BUS# for /proc/bus/usb/BUS#/DEVICE#
bus=0`cat /proc/bus/usb/devices | grep -B 2 Vendor=0d97 | grep Bus= | cut -d ' ' -f 3 | sed -e 's/Bus=//' - -`

# Make a number from a string:
let bus=bus+0

# Fill needed path variable with 0s:
if [ $bus -lt 10 ]; then
	BUS="00$bus";
elif [ $bus -lt 100 ]; then
	BUS="0$bus";
else
	BUS="$bus";
fi;

# Find DEVICE# for /proc/bus/usb/BUS#/DEVICE#
device=`cat /proc/bus/usb/devices | grep -B 2 Vendor=0d97 | grep Dev#= | cut -d '=' -f 7 | sed -e 's/Spd//' - -`

# Make a number from a string:
let device=device+0

# Fill needed path variable with 0s:
if [ $device -lt 10 ]; then
	DEVICE="/proc/bus/usb/$BUS/00$device";
elif [ $device -lt 100 ]; then
	DEVICE="/proc/bus/usb/$BUS/0$device";
else
	DEVICE="/proc/bus/usb/$BUS/$device";
fi;

chmod a+rw $DEVICE
FLAGS="-D $DEVICE"

FIRMWARE=""
case $PRODUCT in
	# SBIG U camera
	d97/1/*) FIRMWARE=$INTROOT/lib/sbigucam.hex;;

	# SBIG L camera
	d97/2/*) FIRMWARE=$INTROOT/lib/sbiglcam.hex;;

	# SBIG G camera
	d97/3/*) FIRMWARE=$INTROOT/lib/sbiggcam.hex;;

	# Anything else
	*) FIRMWARE="";;
esac

if [ ! -f $DEVICE ]; then
	if [ -x /usr/bin/logger ]; then
		/usr/bin/logger -t $0 "No device in /proc/bus/usb/???/??? found.";
	else
		echo "$0: No device in /proc/bus/usb/???/??? found.";
	fi
	exit -1
fi

# missing firmware?
if [ "x$FIRMWARE" == "x" ]; then
	if [ -x /usr/bin/logger ]; then
		/usr/bin/logger -t $0 "Missing firmware for $PRODUCT.";
	else
		echo "$0: Missing firmware for $PRODUCT.";
	fi;
	exit -1
fi

# missing loader?
if [ ! -x $LOADER ]; then
	if [ -x /usr/bin/logger ]; then
		/usr/bin/logger -t $0 "Missing $LOADER.";
	else
		echo "$0: Missing $LOADER.";
	fi
	exit -1
fi

if [ -x /usr/bin/logger ]; then
	/usr/bin/logger -t $0 "Loading $FIRMWARE for $PRODUCT to $DEVICE.";
else
	echo "$0: Loading $FIRMWARE for $PRODUCT to $DEVICE.";
fi

$LOADER $FLAGS -I $FIRMWARE
# Needed for ACS. The firmware has to strtup some
# stuff in the camera. So give it the chance to do things.
# Otherwise a connection will fail.
sleep 10
exit 0
