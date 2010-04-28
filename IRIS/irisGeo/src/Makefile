#*******************************************************************************
# E.S.O. - ACS project
#
# "@(#) $Id: Makefile,v 1.7 2010/02/04 21:22:36 mparra Exp $"
#
# $Log: Makefile,v $
# Revision 1.7  2010/02/04 21:22:36 mparra
# - Adapted to IRIS telescope name.
# - Replace the lmaciErrTypeComponent by lacsErrTypeComponent (lmaciErrTypeComponent it's seem to be deprecated).
#
# Makefile of irisGeo
#
# who       when      what
# --------  --------  ----------------------------------------------
# root  25/09/02  created
# tjuerges  02/09/03  added compatibility settings for ACS 2.0 and 2.1 and
#                     making of an archive which contains every file needed
#                     for the build build process.
#
# tjuerges  01/12/03  added stuff for ACS 3.0
#
# tjuerges  10/06/04  added stuff for ACS 3.1
#
# mparra    02/02/10  added compatibility for ACS 8.0
#
#
#*******************************************************************************
# This Makefile follows VLT Standards (see Makefile(5) for more).
#*******************************************************************************
# REMARKS
#    None
#------------------------------------------------------------------------

#
# user definable C-compilation flags
#

USER_CFLAGS = -DQT_THREAD_SUPPORT -g

#
# additional include and library search paths
USER_INC = 
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
	-lmaciClient \
	-lacserr \
	-lm \
	-lloki \
	-lacstime


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
INCLUDES = irisGeoImpl.h

#
# Libraries (public and local)
# ----------------------------
LIBRARIES = irisGeo
LIBRARIES_L     =
irisGeo_OBJECTS = irisGeoImpl irisGeoC irisGeoS 

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
CDB_SCHEMAS = GEO 

#
# IDL Files and flags
#
IDL_FILES = irisGeo
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
INSTALL_FILES =

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
	@echo " . . . Cleaning of Doxygen documentation in doc done"

all:	do_all
	@echo " . . . 'all' done"

clean : clean_all doxygen_doc_clean
	@echo " . . . clean done"

clean_dist : clean_all clean_dist_all
	@echo " . . . clean_dist done"

man   : do_man
	@echo " . . . man page(s) done"

install : install_all
	@echo " . . . installation done"

dist:
	@echo ". . . Packing tar archive..."
	@./make_archive
	@echo ". . . Packing tar archive done."

#___oOo___
