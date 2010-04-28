#*******************************************************************************
# AIRUB-IRIS - ACS project
#
# "@(#) $Id: Makefile,v 1.31  2010/01/07 17:22:45  mparra Exp $"
#
# $Log: Makefile,v $
# Revision 1.31  2010/01/07 17:22:45  mparra
# - Adapted to IRIS telescope name.
# - Replace the lmaciErrTypeComponent by lacsErrTypeComponent (lmaciErrTypeComponent 
#   it's seem to be deprecated).
# - Removed the creation of documentation via Doxygen, it's no longer necesary (ACS 8.0 do itself).
# - Add the tag -w to avoid noisy warnings.
#
# Revision 1.30  2005/03/09 14:35:25  tjuerges
# - Added component status.
#
# Revision 1.29  2005/02/18 16:48:35  tjuerges
# - Added support for compilation without other IRIS component libs.
#
# Revision 1.28  2005/02/04 12:13:43  tjuerges
# - Updated to use Qt for GUI only.
#
# Revision 1.27  2005/02/01 17:11:30  tjuerges
# - Added Bash script to start DS9. This enables dedicated displaying of images.
#
# Revision 1.26  2005/01/18 14:59:05  tjuerges
# - Added .sh extension to make_archive in order to make Eclipse happy.
#
# Revision 1.25  2004/12/28 17:31:12  tjuerges
# - Added #ifdefs for developers not using the IRIS software. Say make -DNO_IRIS_USAGE to make the package compile without other iris ACS components.
#
# Revision 1.24  2004/11/02 13:20:47  tjuerges
# - Datenpfad wird nicht mehr im Empf�nger gesetzt, sondern vom GUI selbst.
#
# Revision 1.23  2004/10/14 11:54:32  tjuerges
# *** empty log message ***
#
# Revision 1.22  2004/10/14 11:37:36  tjuerges
# - Aenderungen vom OCA-Test
#
# Revision 1.21  2004/09/26 13:13:29  tjuerges
# *** empty log message ***
#
# Revision 1.20  2004/09/22 14:16:35  tjuerges
# - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
# - GUI speichert FITS auf Verlangen.
# - GUI startet externes DS9 und beendet es.
#
#
# Makefile of irisCCD
#
# who       when      what
# --------  --------  ----------------------------------------------
# root      25/09/02  created
# tjuerges  02/09/03  added compatibility settings for ACS 2.0 and 2.1 and
#                     making of an archive which contains every file needed
#                     for the build build process.
# tjuerges  01/12/03  added stuff for ACS 3.0
# tjuerges  10/06/04  added stuff for ACS 3.1
# mparra    12/01/10  adapted to IRIS telescope, added stuff for ACS 8.0

#*******************************************************************************
# This Makefile follows VLT Standards (see Makefile(5) for more).
#*******************************************************************************
# REMARKS
#    None
#------------------------------------------------------------------------

#
# user definable C-compilation flags
#

# Attention, non Hexapod developers:
# use -DNO_IRIS_USAGE to make the compilation process happy because
# it will otherwise not find needed header files.
#USER_CFLAGS = -DQT_THREAD_SUPPORT -NO_IRIS_USAGE -w -NO_IRIS_SIMULATOR
USER_CFLAGS = -DQT_THREAD_SUPPORT -w

#
# additional include and library search paths
USER_INC = -I$(QTDIR)/include -I$(QWTDIR)/include -I$(INTROOT)/include
USER_LIB = -lACE \
	-lTAO \
	-lTAO_DsLogAdmin \
	-lTAO_CosNaming \
	-lTAO_IORTable \
	-lTAO_PortableServer \
	-lTAO_Svc_Utils \
	-lTAO_CosTrading \
	-lTAO_CosNotification \
	-lTAO_DynamicAny \
	-lTAO_IFR_Client \
	-lTAO_CosProperty \
	-lacsutil \
	-lcdb \
	-llogging \
	-lacscomponent \
	-lbaci \
	-lmaci \
	-lacsErrTypeComponent \
	-lmaciClient \
	-lacserr \
	-lm \
	-lloki \
	-lacstime \
	-L$(IRIS_QT_WIDGETS) -lirisQtWidgetsPlugin 

#
# MODULE CODE DESCRIPTION:
# ------------------------
# As a general rule:  public file are "cleaned" and "installed"  
#                     local (_L) are not "installed".

#
# C programs (public and local)
# -----------------------------
#EXECUTABLES = irisCCDTestClient irisCCDGUI
EXECUTABLES = irisCCDGUI
EXECUTABLES_L   =
#

#
# <brief description of xxxxx program>

#
# Qt interface files
# ------------------
#
# Add .ui files in directory src here:
# The files have to be in src!
QT_UI_FILES = irisCCDGUI
#
# Add class declaration files (.h) which use the Q_OBJECT macro here:
# The files have to be in src!
QT_MOC_FILES_H = irisCCDGUISaveDataToDisk
#
# Add class implementation files (.cpp) which use the Q_OBJECT macro here:
# The files have to be in src!
QT_MOC_FILES_CPP =


#
# Definitions for "easier" generation of needed Qt files.
# Extremly ugly!!! But it works. :)
# ------------------------------------------
# PLEASE DO NOT TOUCH!!!!!
# ------------------------------------------
# Correct filenames: foo --> foo.ui
QT_UI_FILES_UI = $(addsuffix .ui,$(QT_UI_FILES))
# foo --> ../include/foo.h
QT_UI_FILES_H = $(addprefix ../include/,$(addsuffix .h,$(QT_UI_FILES)))
# foo --> foo.cpp
QT_UI_FILES_CPP = $(addsuffix .cpp,$(QT_UI_FILES))

# Build 'moc'ed filename target: foo --> moc_foo.cpp
QT_UI_FILES_MOC = $(addprefix moc_,$(addsuffix .cpp,$(QT_UI_FILES)))

# Build correct filenames for 'moc'ed files: foo --> ../include/foo.h
QT_UI_FILES_EXTERN_H = $(addprefix ../include/,$(addsuffix .h,$(QT_MOC_FILES_H)))
# foo --> foo.cpp
QT_UI_FILES_EXTERN_CPP = $(addsuffix .cpp,$(QT_MOC_FILES_CPP))

# Add moc_ and .cpp to 'moc'ed file targets: foo --> moc_foo.cpp
QT_UI_FILES_EXTERN_MOC_H = $(addprefix moc__,$(addsuffix .cpp,$(QT_MOC_FILES_H)))
# foo --> moc_foo.cpp
QT_UI_FILES_EXTERN_MOC_CPP = $(addprefix moc_,$(addsuffix .cpp,$(QT_MOC_FILES_CPP)))

# Build list of files to be compiled: foo.cpp --> foo
QT_COMPILE_FILES = $(QT_UI_FILES) $(subst .cpp,,$(QT_UI_FILES_MOC) $(QT_UI_FILES_EXTERN_MOC_H) $(QT_UI_FILES_EXTERN_MOC_CPP))

irisCCDGUI_OBJECTS = $(QT_COMPILE_FILES) irisCCDGUIEventLoop irisCCDGUISaveDataToDisk irisCCDGUIMain
irisCCDGUI_LDFLAGS = -L$(QTDIR)/lib -lqt-mt
# CCD, Mnt and others components.
#irisCCDGUI_LIBS = maciClient irisCCDStubs irisMntStubs irisMCUStubs irisM1Stubs irisM2Stubs irisStarUtils irisComponentStatusStubs irisQtWidgets logging
# Only CCD component.
#irisCCDGUI_LIBS = maciClient irisCCDStubs irisStarUtils irisComponentStatusStubs irisQtWidgets logging
# CCD component and Mnt component
irisCCDGUI_LIBS = maciClient irisCCDStubs irisMntStubs irisStarUtils irisComponentStatusStubs irisQtWidgets logging

irisCCDTestClient_OBJECTS = irisCCDTestClient
irisCCDTestClient_LIBS = irisCCDStubs maciClient maciErrTypeComponent acstime irisComponentStatusStubs irisStarUtils

$(PROG)_OBJECTS            = $(PROG)
$(PROG)_LDFLAGS            =
$(PROG)_LIBS               = C++

#
# Includes (.h) files (public only)
# ---------------------------------
INCLUDES = irisCCDImpl.h

#
# Libraries (public and local)
# ----------------------------
LIBRARIES = irisCCD

irisCCD_OBJECTS = irisCCDImpl
irisCCD_LIBS =  irisCameraFactory irisStarUtils irisComponentStatusStubs irisCCDStubs

#
# Scripts (public and local)
# ----------------------------
SCRIPTS         =
SCRIPTS_L       =

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
CDB_SCHEMAS = CCD 

#
# IDL Files and flags
#
IDL_FILES = irisCCD
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
INSTALL_FILES = ../bin/ds9 ../bin/xpaaccess ../bin/xpaget ../bin/xpainfo ../bin/xpamb ../bin/xpans ../bin/xpaset ../bin/start_ds9.sh

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
$(QT_UI_FILES_H): ../include/%.h: %.ui $(QT_UI_FILES_UI)
	(unset LD_LIBRARY_PATH; $(QTDIR)/bin/uic -o $@ $<;)

$(QT_UI_FILES_CPP): %.cpp: ../include/%.h $(QT_UI_FILES_H)
	(unset LD_LIBRARY_PATH; $(QTDIR)/bin/uic -o $@ -impl $< $(subst .cpp,.ui,$@);)

$(QT_UI_FILES_MOC): moc_%.cpp: ../include/%.h $(QT_UI_FILES_H)
	$(QTDIR)/bin/moc -o $@ $<

$(QT_UI_FILES_EXTERN_MOC_H): moc__%.cpp: ../include/%.h $(QT_UI_FILES_EXTERN_H)
	$(QTDIR)/bin/moc -o $@ $<

$(QT_UI_FILES_EXTERN_MOC_CPP): moc_%.cpp: %.cpp $(QT_UI_FILES_EXTERN_CPP)
	$(QTDIR)/bin/moc -o $@ $<

qt:     $(QT_UI_FILES_H) $(QT_UI_FILES_CPP) $(QT_UI_FILES_MOC) $(QT_UI_FILES_EXTERN_MOC_H) $(QT_UI_FILES_EXTERN_MOC_CPP)
	@echo " . . . 'qt' done"

qt_clean:
	@rm -f $(QT_UI_FILES_H) $(QT_UI_FILES_CPP) $(QT_UI_FILES_MOC) $(QT_UI_FILES_EXTERN_MOC_H) $(QT_UI_FILES_EXTERN_MOC_CPP)
	@echo " . . . 'qt_clean' done"

doxygen_doc_clean:
	@echo " . . . Cleaning Doxygen documentation in doc..."
	@(if [ -d ../doc ]; then rm -rf ../doc; fi;)
	@echo " . . . Cleaning of Doxygen documentation in doc done"

all:	qt do_all
	@echo " . . . 'all' done"

clean:	qt_clean clean_all doxygen_doc_clean
	@echo " . . . clean done"

clean_dist : clean_all clean_dist_all
	@echo " . . . clean_dist done"

man   : do_man
	@echo " . . . man page(s) done"

install : install_all
	@chmod a+x $(INTROOT)/bin/xpa*
	@chmod a+x $(INTROOT)/bin/start_ds9.sh
	@chmod a+x $(INTROOT)/bin/ds9
	@echo " . . . installation done"

dist:
	@echo ". . . Packing tar archive..."
	@./make_archive.sh
	@echo ". . . Packing tar archive done."

#___oOo___