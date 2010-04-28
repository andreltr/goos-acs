#*******************************************************************************
# AIRUB-IRIS - ACS project
#
# "@(#) $Id: Makefile,v 1.15 2010/02/06 21:21:13 mparra Exp $"
#
#
# $Log: Makefile,v $
# Revision 1.9  2010/02/05 12:27:08 mparra
# - Adapted to IRIS telescope name.
# - Replace the lmaciErrTypeComponent by lacsErrTypeComponent (lmaciErrTypeComponent it's seem to be deprecated).
# - Add the tag USER_CFLAGS = -w to avoid noisy warnings.
# - Adapted the makefile to the kernel 2.6.x 's sbig drivers.
#
# Makefile of irisCamera
#
# who       when      what
# --------  --------  ----------------------------------------------
# root  25/09/02  created
# tjuerges  02/09/03  added compatibility settings for ACS 2.0 and 2.1 and
#                     making of an archive which contains every file needed
#                     for the build build process.
# tjuerges  01/12/03  added stuff for ACS 3.0
# tjuerges  10/06/04  added stuff for ACS 3.1
# mparra    01/08/10  adapted to IRIS telescope, added compatibility settings
#                     for ACS 8.0.

#*******************************************************************************
# This Makefile follows VLT Standards (see Makefile(5) for more).
#*******************************************************************************
# REMARKS
#    None
#------------------------------------------------------------------------

#
# user definable C-compilation flags
#

#USER_CFLAGS = -DQT_THREAD_SUPPORT
USER_CFLAGS = -w

#
# additional include and library search paths
USER_INC = 
USER_LIB = -llogging

#
# MODULE CODE DESCRIPTION:
# ------------------------
# As a general rule:  public file are "cleaned" and "installed"  
#                     local (_L) are not "installed".

#
# C programs (public and local)
# -----------------------------
EXECUTABLES =
EXECUTABLES_L   =
#

#
# <brief description of xxxxx program>

#
# special compilation flags for single c sources
#yyyyy_CFLAGS   =

$(PROG)_OBJECTS            = $(PROG)
$(PROG)_LDFLAGS            =
$(PROG)_LIBS               = C++

#
# Includes (.h) files (public only)
# ---------------------------------
INCLUDES	= irisCamera.h irisCameraFLI.h irisCameraSBIG.h irisCameraIRIS.h irisCameraST402.h \
	irisCameraSimulator.h irisCameraFactory.h

#
# Libraries (public and local)
# ----------------------------
LIBRARIES       = fli csbigcam irisCamera irisCameraFLI irisCameraSBIG irisCameraIRIS irisCameraST402 \
	irisCameraSimulator irisCameraFactory

fli_OBJECTS = libfli libfli-camera libfli-camera-parport \
	libfli-camera-usb libfli-debug libfli-filter-focuser \
	libfli-mem libfli-parport libfli-serial libfli-sys \
	libfli-usb libfli-usb-sys

csbigcam_OBJECTS = csbigcam csbigimg
csbigcam_LIBS = sbigudrv

irisCamera_OBJECTS = irisCamera

irisCameraFLI_OBJECTS = irisCameraFLI
irisCameraFLI_LIBS = irisCamera fli

irisCameraSBIG_OBJECTS = irisCameraSBIG
irisCameraSBIG_LIBS = irisCamera csbigcam

irisCameraIRIS_OBJECTS = irisCameraIRIS
irisCameraIRIS_LIBS = irisCamera

irisCameraST402_OBJECTS = irisCameraST402
irisCameraST402_LIBS = irisCamera csbigcam 

irisCameraSimulator_OBJECTS = irisCameraSimulator irisCameraSimulatorCreateStarData
irisCameraSimulator_LIBS = irisCamera irisStarUtils gsl gslcblas

irisCameraFactory_OBJECTS = irisCameraFactory
irisCameraFactory_LIBS = irisCameraFLI irisCameraSBIG irisCameraIRIS irisCameraST402 irisCameraSimulator

#
# <brief description of lllll library>
lllll_OBJECTS   =

#
# Scripts (public and local)
# ----------------------------
SCRIPTS         =
SCRIPTS_L       =

#
# TCL scripts (public and local)
# ------------------------------
TCL_SCRIPTS     =
TCL_SCRIPTS_L   =

#
# <brief description of tttttt tcl-script>
tttttt_OBJECTS  =
tttttt_TCLSH    = 
tttttt_LIBS     = 

#
# TCL libraries (public and local)
# ------------------------------
TCL_LIBRARIES   =
TCL_LIBRARIES_L =

#
# <brief description of tttlll library>
tttlll_OBJECTS  = 

#
# Python stuff (public and local)
# ----------------------------
PY_SCRIPTS         =
PY_SCRIPTS_L       =

PY_MODULES         =
PY_MODULES_L       =

PY_PACKAGES        =
PY_PACKAGES_L      =
pppppp_MODULES	   =

#
# UIF panels (public and local)
# ----------------------------
PANELS   =
PANELS_L =

#
# Configuration Database Files
# ----------------------------
CDB_SCHEMAS =

#
# IDL Files and flags
#
IDL_FILES =
IDL_TAO_FLAGS =
USER_IDL =
#
# Jarfiles and their directories
#
JARFILES= 
jjj_DIRS=
jjj_EXTRAS= 
#
# java sources in Jarfile on/off
DEBUG= 
#
# ACS XmlIdl generation on/off
#
XML_IDL =  
#
# Java Component Helper Classes generation on/off
#
COMPONENT_HELPERS = 
#
# Java Entity Classes generation on/off
#
XSDBIND = 
#
# Schema Config files for the above
#
XSDBIND_INCLUDE = 
# man pages to be done
# --------------------
MANSECTIONS =
MAN1 =
MAN3 =
MAN5 =
MAN7 =
MAN8 =

#
# local man pages
# ---------------
MANl =

#
# ASCII file to be converted into Framemaker-MIF
# --------------------
ASCII_TO_MIF = 

#
# other files to be installed
#----------------------------
INSTALL_FILES = ../lib/sbigfcam.hex ../lib/sbiglcam.hex ../lib/sbigpcam.hex ../lib/sbigucam.hex \
../lib/libsbigudrv.a ../lib/libsbigudrv.so ../lib/stfga.bin ../lib/10-sbig.rules ../lib/sbig_dev_permission.py

#
# list of all possible C-sources (used to create automatic dependencies)
# ------------------------------
CSOURCENAMES = \
	$(foreach exe, $(EXECUTABLES) $(EXECUTABLES_L), $($(exe)_OBJECTS)) \
	$(foreach rtos, $(RTAI_MODULES) , $($(rtos)_OBJECTS)) \
	$(foreach lib, $(LIBRARIES) $(LIBRARIES_L), $($(lib)_OBJECTS))

#
#>>>>> END OF standard rules

#
# INCLUDE STANDARDS
# -----------------
ifdef ACSROOT
    MAKEDIR  = $(shell if [ -f $(INTROOT)/include/acsMakefile ];  then \
                     echo $(INTROOT)/include; \
	           else \
	             echo $(ACSROOT)/include; \
		   fi;)
    include $(MAKEDIR)/acsMakefile
else
    MAKEDIR  = $(shell if [ -f $(INTROOT)/include/vltMakefile ];  then \
                     echo $(INTROOT)/include; \
	           else \
	             echo $(VLTROOT)/include; \
		   fi;)
    include $(MAKEDIR)/vltMakefile
endif

#
# TARGETS
# -------
doxygen_doc_clean:
	@echo " . . . Cleaning Doxygen documentation in doc..."
	@(if [ -d ../doc ]; then rm -rf ../doc; fi;)
	@echo " . . . Creation of Doxygen documentation in doc done"

all:	do_all
	@echo " . . . 'all' done"

clean:	clean_all doxygen_doc_clean
	@echo " . . . clean done"

clean_dist : clean_all clean_dist_all
	@echo " . . . clean_dist done"

man   : do_man
	@echo " . . . man page(s) done"

install : install_all
#	@(cp ../lib/*.hex /lib/firmware; cp ../lib/*.bin /lib/firmware;)
#	@(cp ../lib/10-sbig.rules /etc/udev/rules.d; cp ../lib/sbig_dev_permission.py /etc/hotplug/usb/;)
	@echo " . . . installation done"

dist:
	@echo ". . . Packing tar archive..."
	@./make_archive
	@echo ". . . Packing tar archive done."

#___oOo___