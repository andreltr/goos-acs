#!/bin/sh
######################################################
# ACS 8.0.0 ENVIROMENT CONFIGURATION TEST
# AND INSTALLATION SCRIPT
######################################################
# This script verifies that some important files ares
# installed and some environment variables are set
# for ACS to work.
# It can also install ACS almost automatically.
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

sumOK=0
sumTotal=0
kernelver=$(cat /proc/version | grep -o "Linux version 2.[4-9]")
java -version 2> tmp.tmp
javaver=$(cat tmp.tmp | grep -o -c 1.6.0_02 )
rm tmp.tmp
libpython=$(ls /usr/lib | grep libpython2.[0-9].so.1.0)
usrlib=$(env | grep -w  "LD_LIBRARY_PATH" | grep -o -c /usr/lib)
usrlocallib=$(env | grep -w  "LD_LIBRARY_PATH" | grep -o -c /usr/local/lib)
shkorn=$(rpm -qa | grep pdksh)
glibcdevel=$(rpm -qa | grep glibc-devel)
libitcl=$(rpm -qa | grep itcl)
libtclx=$(rpm -qa | grep tclx)
vusername="almamgr"
vusernamedev="almadev"
vgroupname="alma"
vend="n"

######################################################
# NO ARGUMENTS NOTICE
######################################################
if [ "$1" = "" ]
then
	echo $bold "This script requires argument to work." $eformat
	echo ""
	echo $bold "Commands:" $eformat
	echo $bold "--test        Tests system configuration" $eformat
	echo $bold "--install     Starts ACS installation" $eformat
	echo $bold "--install --default    Installs ACS with users 'almamgr', 'almadev' and group 'alma'" $eformat
	echo ""
fi

######################################################
# TEST NOTICE
######################################################
if [ "$1" = "--test" ]
then

	echo $bold "+---------------------------------------------+" $eformat
	echo $bold "|System configuration test is about to start  |" $eformat
	echo $bold "+---------------------------------------------+" $eformat
	echo $bold "Checking..." $eformat
	echo ""

	######################################################
	# Checks the kernel version installed
	######################################################

	#sumTotal=$(( $sumTotal + 1 ))
	#
	#if [ "$kernelver" != $( "Linux version 2.[4-9]" ) ]
	#then
	#	echo $red "ERROR: Kernel version doesn't match $kernelver" $eformat
	#else
	#	echo $green "OK: Kernel version is correct $kernelver" $eformat
	#	sumOK=$(( $sumOK + 1 ))
	#fi

	######################################################
	# Checks the installed Java version
	######################################################

	sumTotal=$(( $sumTotal + 1 ))

	if [ $javaver -gt 1 ]
	then
		echo $red "ERROR: The installed version of Java doesn't match." $eformat
	else
		echo $green "OK: The installed version of Java is correct" $eformat
		sumOK=$(( $sumOK + 1 ))
	fi

	######################################################
	# Checks for libpython2.x.so.1.0
	######################################################

	sumTotal=$(( $sumTotal + 1 ))

	if [ "$libpython" = "" ]
	then
		echo $red "ERROR: Can't find libpython2.x.so.1.0" $eformat
	else
		echo $green "OK: $libpython library found" $eformat
		sumOK=$(( $sumOK + 1 ))
	fi

	######################################################
	# Checks the environment variable LD_LIBRARY_PATH
	######################################################

	sumTotal=$(( $sumTotal + 2 ))

	#Checks for /usr/lib
	if [ $usrlib -gt 1 ]
	then
		echo $red "ERROR: Can't find /usr/lib in LD_LIBRARY_PATH"  $eformat
	else
		echo $green "OK: /usr/lib found in LD_LIBRARY_PATH" $eformat
		sumOK=$(( $sumOK + 1 ))
	fi

	#Checks for /usr/local/lib
if [ $usrlocallib -gt 1 ]
then
	echo $red "ERROR: Can't find /usr/local/lib in LD_LIBRARY_PATH"  $eformat
else
	echo $green "OK: /usr/local/lib found in LD_LIBRARY_PATH" $eformat
	sumOK=$(( $sumOK + 1 ))
fi

######################################################
# Checks for the korn type shell pdksh
######################################################

sumTotal=$(( $sumTotal + 1 ))

if [ "$shkorn" = "" ]
then
	echo $red "ERROR: Can't find pdksh" $eformat
else
	echo $green "OK: $shkorn found" $eformat
	sumOK=$(( $sumOK + 1 ))
fi

######################################################
# Checks for glibc-devel
######################################################

sumTotal=$(( $sumTotal + 1 ))

if [ "$glibcdevel" = "" ]
then
	echo $red "ERROR: Can't find glibc-devel" $eformat
else
	echo $green "OK: $glibcdevel library found" $eformat
	sumOK=$(( $sumOK + 1 ))
fi

######################################################
# Checks for itcl library
######################################################

sumTotal=$(( $sumTotal + 1 ))

if [ "$libitcl" = "" ]
then
	echo $red "ERROR: Can't find itcl" $eformat
else
	echo $green "OK: $libitcl library found" $eformat
	sumOK=$(( $sumOK + 1 ))
fi

######################################################
# Checks for tclx
######################################################

sumTotal=$(( $sumTotal + 1 ))

if [ "$libtclx" = "" ]
then
	echo $red "ERROR: Can't find tclx" $eformat
else
	echo $green "OK: $libtclx library found" $eformat
	sumOK=$(( $sumOK + 1 ))
fi

######################################################
# Results
######################################################

sumOK=$sumOK*100
sumTotal=$sumTotal*100

echo $bold "A " $(( $(($sumOK / $sumTotal)) / 100 ))"% of the test passed" $eformat

fi

######################################################
# ACS 8.0.0 INSTALLATION
######################################################
# This part of the script installs ACS 8.0.0 
# in the most simple and automatic way possible.
######################################################

if [ "$1" = "--install" ]
then

	######################################################
	# INSTALLATION NOTICE
	######################################################
	echo $bold "+---------------------------------------------+" $eformat
	echo $bold "| ACS 8.x.x installation is about to start    |" $eformat
	echo $bold "+---------------------------------------------+" $eformat
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

	#Default user and group names
	if [ "$2" != "--default" ]
	then
		#Username

		while [ "$vend" != y ]
		do
			echo $bold "Enter the ACS installation account username:" $eformat
			read vusername
			echo $bold "The username is:"$eformat$green$vusername $eformat
			echo $bold "Is this correct? (y/n)" $eformat
			read vend
		done
	
		vend="n"

		while [ "$vend" != y ]
		do
			echo $bold "Enter the developer account username:" $eformat
			read vusernamedev
			echo $bold "The username is:"$eformat$green$vusernamedev $eformat
			echo $bold "Is this correct? (y/n)" $eformat
			read vend
		done
	
		#Group name
		vend="n"

		while [ "$vend" != y ]
		do
			echo $bold "Enter the group name for ACS:" $eformat
			read vgroupname
			echo $bold "The group name is:"$eformat$green$vgroupname $eformat
			echo $bold "Is this correct? (y/n)" $eformat
			read vend
		done

		######################################################
		# ALL THE WORK GETS DONE HERE
		######################################################

		#We create the group
		groupadd -g 335 -o $vgroupname

		#We create the users
		useradd -g 335 -u 3060 -o -d /home/$vusername -m -s /bin/bash $vusername
		useradd -g 335 -u 3070 -o -d /home/$vusernamedev -m -s /bin/bash $vusernamedev

		#Change the passwords of the accounts

		passwd $vusername
		passwd $vusernamedev

	fi

	#Untar the ACS tar in /
	#tar -xvzf ACS800.tar.gz -C /

	#We change the owner of /alma to $vusername
	chown -R $vusername:$vgroupname /alma 

	#We copy the configuration file
	cp -rf /alma/ACS-8.0/ACSSW/config/.acs/ /home/$vusername
	cp -rf /alma/ACS-8.0/ACSSW/config/.acs/ /home/$vusernamedev

	#We append the neccesary lines to /home/$vusername/.bashrc

	#If /usr/lib wasn't found
	if [ $usrlib -gt 1 ]
	then
		echo "export LD_LIBRARY_PATH=/usr/lib:$LD_LIBRARY_PATH" >> /home/$vusername/.bashrc
		echo "export LD_LIBRARY_PATH=/usr/lib:$LD_LIBRARY_PATH" >> /home/$vusernamedev/.bashrc
		echo ""
	fi

	#If /usr/local/lib wasn't found
	if [ $usrlocallib -gt 1 ]
	then
		echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> /home/$vusername/.bashrc
		echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> /home/$vusernamedev/.bashrc
		echo ""
	fi

	echo "export PYTHON_PATH=$PYTHONPATH" >> /home/$vusername/.bashrc
	echo "source /home/$vusername/.acs/.bash_profile.acs" >> /home/$vusername/.bashrc

	echo "export PYTHON_PATH=$PYTHONPATH" >> /home/$vusernamedev/.bashrc
	echo "source /home/$vusernamedev/.acs/.bash_profile.acs" >> /home/$vusernamedev/.bashrc

	#We configure the integration area for ACS (INTROOT)
	vintroot="/home/$vusername/INTROOT"
	vintrootdev="/home/$vusernamedev/INTROOT"

	echo $bold "The integration area for ACS will be created in" $eformat
	echo $bold$vintroot $eformat
	echo $bold "Do you wan't to change this location? (y/n)" $eformat

	read vend

	if [ "$vend" = y ]
	then
		vend="n"
		while [ "$vend" != y ]
		do
		echo $bold "Enter the location for INTROOT (you must append INTROOT if you want it):" $eformat
			read vintroot
			echo $bold "The location for INTROOT will be:"$eformat$green$vintroot $eformat
			echo $bold "Is this correct? (y/n)" $eformat
			read vend
		done
	fi


	echo $bold "The integration area for ACS was created in" $eformat
	echo $bold$vintroot $eformat

	echo "export ACS_RETAIN=1"  >> /home/$vusername/.bashrc
	echo "export INTROOT=$vintroot" >> /home/$vusername/.bashrc
	echo "export ACS_CDB=$vintroot/config/" >> /home/$vusername/.bashrc

	chown -R $vusername:$vgroupname /home/$vusername

	echo $bold "The integration area for the developer account will be created in" $eformat
	echo $bold$vintrootdev $eformat
	echo $bold "Do you wan't to change this location? (y/n)" $eformat

	read vend

	if [ "$vend" = y ]
	then
		vend="n"
		while [ "$vend" != y ]
		do
			echo $bold "Enter the location for INTROOT (you must append INTROOT if you want it):" $eformat
			read vintrootdev
			echo $bold "The location for INTROOT will be:"$eformat$green$vintrootdev $eformat
			echo $bold "Is this correct? (y/n)" $eformat
			read vend
		done
	fi


	echo $bold "The integration area for the developer account was created in" $eformat
	echo $bold$vintrootdev $eformat

	echo "export ACS_RETAIN=1"  >> /home/$vusernamedev/.bashrc
	echo "export INTROOT=$vintrootdev" >> /home/$vusernamedev/.bashrc
	echo "export ACS_CDB=$vintrootdev/config/" >> /home/$vusernamedev/.bashrc

	chown -R $vusernamedev:$vgroupname /home/$vusernamedev

	#We create the directory structure for INTROOT
	mkdir -p $vintroot
	mkdir -p $vintroot/ALARMS/
	mkdir -p $vintroot/ALARMS/HELP/
	mkdir -p $vintroot/app-defaults/
	mkdir -p $vintroot/bin/
	mkdir -p $vintroot/bitmaps/
	mkdir -p $vintroot/CDT/
	mkdir -p $vintroot/config/
	mkdir -p $vintroot/config/CDB/
	mkdir -p $vintroot/config/CDB/schemas/
	mkdir -p $vintroot/ERRORS/
	mkdir -p $vintroot/ERRORS/HELP/
	mkdir -p $vintroot/idl/
	mkdir -p $vintroot/include/
	mkdir -p $vintroot/lib/
	mkdir -p $vintroot/lib/ACScomponents/
	mkdir -p $vintroot/lib/endorsed/
	mkdir -p $vintroot/lib/python/
	mkdir -p $vintroot/lib/python/site-packages/
	mkdir -p $vintroot/LOGS/
	mkdir -p $vintroot/man/
	mkdir -p $vintroot/man/man1/
	mkdir -p $vintroot/man/man2/
	mkdir -p $vintroot/man/man3/
	mkdir -p $vintroot/man/man4/
	mkdir -p $vintroot/man/man5/
	mkdir -p $vintroot/man/man6/
	mkdir -p $vintroot/man/man7/
	mkdir -p $vintroot/man/man8/
	mkdir -p $vintroot/man/manl/
	mkdir -p $vintroot/man/mann/
	mkdir -p $vintroot/rtai/
	mkdir -p $vintroot/sounds/
	mkdir -p $vintroot/Sources/
	mkdir -p $vintroot/templates/
	mkdir -p $vintroot/vw/
	mkdir -p $vintroot/vw/bin/
	mkdir -p $vintroot/vw/bin/MC68000/
	mkdir -p $vintroot/vw/bin/MC68040/
	mkdir -p $vintroot/vw/bin/PPC604/
	mkdir -p $vintroot/vw/CIT/
	mkdir -p $vintroot/vw/idl/
	mkdir -p $vintroot/vw/include/
	mkdir -p $vintroot/vw/lib/
	mkdir -p $vintroot/vw/lib/ACScomponents/
	mkdir -p $vintroot/vw/lib/endorsed/
	mkdir -p $vintroot/vw/lib/MC68000/
	mkdir -p $vintroot/vw/lib/MC68040/
	mkdir -p $vintroot/vw/lib/PPC604/
	mkdir -p $vintroot/vw/lib/python/
	mkdir -p $vintroot/vw/lib/python/site-packages/
	mkdir -p $vintroot/vw/man/
	mkdir -p $vintroot/vw/man/man1/
	mkdir -p $vintroot/vw/man/man2/
	mkdir -p $vintroot/vw/man/man3/
	mkdir -p $vintroot/vw/man/man4/
	mkdir -p $vintroot/vw/man/man5/
	mkdir -p $vintroot/vw/man/man6/
	mkdir -p $vintroot/vw/man/man7/
	mkdir -p $vintroot/vw/man/man8/
	mkdir -p $vintroot/vw/man/manl/
	mkdir -p $vintroot/vw/man/mann/
	mkdir -p $vintroot/vw/Sources/

	chown -R $vusername:$vgroupname $vintroot

	mkdir -p $vintrootdev
	mkdir -p $vintrootdev/ALARMS/
	mkdir -p $vintrootdev/ALARMS/HELP/
	mkdir -p $vintrootdev/app-defaults/
	mkdir -p $vintrootdev/bin/
	mkdir -p $vintrootdev/bitmaps/
	mkdir -p $vintrootdev/CDT/
	mkdir -p $vintrootdev/config/
	mkdir -p $vintrootdev/config/CDB/
	mkdir -p $vintrootdev/config/CDB/schemas/
	mkdir -p $vintrootdev/ERRORS/
	mkdir -p $vintrootdev/ERRORS/HELP/
	mkdir -p $vintrootdev/idl/
	mkdir -p $vintrootdev/include/
	mkdir -p $vintrootdev/lib/
	mkdir -p $vintrootdev/lib/ACScomponents/
	mkdir -p $vintrootdev/lib/endorsed/
	mkdir -p $vintrootdev/lib/python/
	mkdir -p $vintrootdev/lib/python/site-packages/
	mkdir -p $vintrootdev/LOGS/
	mkdir -p $vintrootdev/man/
	mkdir -p $vintrootdev/man/man1/
	mkdir -p $vintrootdev/man/man2/
	mkdir -p $vintrootdev/man/man3/
	mkdir -p $vintrootdev/man/man4/
	mkdir -p $vintrootdev/man/man5/
	mkdir -p $vintrootdev/man/man6/
	mkdir -p $vintrootdev/man/man7/
	mkdir -p $vintrootdev/man/man8/
	mkdir -p $vintrootdev/man/manl/
	mkdir -p $vintrootdev/man/mann/
	mkdir -p $vintrootdev/rtai/
	mkdir -p $vintrootdev/sounds/
	mkdir -p $vintrootdev/Sources/
	mkdir -p $vintrootdev/templates/
	mkdir -p $vintrootdev/vw/
	mkdir -p $vintrootdev/vw/bin/
	mkdir -p $vintrootdev/vw/bin/MC68000/
	mkdir -p $vintrootdev/vw/bin/MC68040/
	mkdir -p $vintrootdev/vw/bin/PPC604/
	mkdir -p $vintrootdev/vw/CIT/
	mkdir -p $vintrootdev/vw/idl/
	mkdir -p $vintrootdev/vw/include/
	mkdir -p $vintrootdev/vw/lib/
	mkdir -p $vintrootdev/vw/lib/ACScomponents/
	mkdir -p $vintrootdev/vw/lib/endorsed/
	mkdir -p $vintrootdev/vw/lib/MC68000/
	mkdir -p $vintrootdev/vw/lib/MC68040/
	mkdir -p $vintrootdev/vw/lib/PPC604/
	mkdir -p $vintrootdev/vw/lib/python/
	mkdir -p $vintrootdev/vw/lib/python/site-packages/
	mkdir -p $vintrootdev/vw/man/
	mkdir -p $vintrootdev/vw/man/man1/
	mkdir -p $vintrootdev/vw/man/man2/
	mkdir -p $vintrootdev/vw/man/man3/
	mkdir -p $vintrootdev/vw/man/man4/
	mkdir -p $vintrootdev/vw/man/man5/
	mkdir -p $vintrootdev/vw/man/man6/
	mkdir -p $vintrootdev/vw/man/man7/
	mkdir -p $vintrootdev/vw/man/man8/
	mkdir -p $vintrootdev/vw/man/manl/
	mkdir -p $vintrootdev/vw/man/mann/
	mkdir -p $vintrootdev/vw/Sources/

	chown -R $vusernamedev:$vgroupname $vintrootdev



	######################################################
	# END OF THE INSTALLATION
	######################################################

	echo $bold "The installation has been completed." $eformat
	echo $bold "You must restart the session for the changes to take effect." $eformat

fi

######################################################
# END OF SCRIPT
######################################################


