# Introduction #

ACS 8.0.0 is supported on Scientific Linux 5.3 (SL) and is very easy to install.

# Requirements #

Uninstall the korn shell (ksh), because we have to use a specific version of korn shell, you can do this under super user mode (sudo) or with the root account:

  * **sudo yum remove -y ksh**

Install this required packages:

  * **sudo yum install -y openssl openssl-devel yumex glibc-devel tclx gcc openssl097a gcc-c++ jdk**

Then download the required packages (available in the Downloads section):

  * **itcl-3.2-92.2.i386.rpm**
  * **pdksh-5.2.14-30.i386.rpm**

Then install the packages under sudo mode or using the root account, you can do this with by double-clickin in the RPM files or in bash :

  * **sudo rpm -ivh itcl-3.2-92.2.i386.rpm**
  * **sudo rpm -ivh pdksh-5.2.14-30.i386.rpm**

# Installing ACS #

Get the ACS\_installer.sh script and place it in a folder with the ACS tar.gz file, the archive should be named ACS800.tar.gz, then execute the script under sudo.

You can use the script to check if everything is OK to install ACS with the "--test" parameter:

  * **sudo ACS800\_installer.sh --test**

If everything is alright, install ACS, and follow the script instructions:

  * **sudo ACS800\_installer.sh --install**

Alternatively you can use the default installation executing:

  * **sudo ACS800\_installer.sh --install --default**

This will create the **almamgr** and **almadev** accounts with the **INTROOT** folder in the **HOME** of each user.

Reboot your machine and start X (startx) in the account specified in ACS installation, you will notice that bash is replaced by korn shell.

# Testing the installation #

You can check if ACS runs fine by executing ACS. The **ACS\_CDB** environment variable currently points to an empty folder in the **INTROOT**, so you need to change it to the CDB path where the examples are located if you want to try them out. If you have already a project that you want to use, just compile it, there's no need to change anything.

ACS examples CDB path?:

  * **/alma/.../defaultCDB/**

Then, just open a terminal and execute one of the following commands:

  * **acsStart**
  * **acscommandcenter**

If ACS starts up with no problems, you should see an "ACS is up and running" message on the terminal or in the command center logger.

Start one of the sample containers with:

  * **acsStartContainer -cpp bilboContainer**
  * **acsStartContainer -py aragornContainer**
  * **acsStartContainer -java frodoContainer**

And then run the object explorer to use the components included:

  * **objexp**