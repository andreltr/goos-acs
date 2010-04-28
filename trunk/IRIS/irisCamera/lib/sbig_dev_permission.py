#!/usr/bin/env python

# Name:    sbig_dev_permission.py
# Version: 1.0

# Author:
# Jan Soldan (soldan@sunstel.asu.cas.cz)

# History:
# 2006-08-20 - the version 1.0 released. (JS)
#=========================================================================
import sys, os
param	   = sys.argv[1]
dot_pos	 = param.find(".")
bus_num	 = int(param[len("usbdev"):dot_pos])
dev_num	 = int(param[dot_pos + 1:])
dev_node = "/dev/bus/usb/%03d/%03d" % (bus_num, dev_num)
os.chmod(dev_node, 0666)
#=========================================================================
