# Introduction #

Implementation of the interface between Serial Port and the ACS Modules.


# Details #

For make the conection between LX200GPS Telescope and SL,  we need to have the permitions for read and write on the ttyS0 port.


The read and write permissions are required on the /dev/ttyS0 file. The uucp group, which is the default group owner of the file, has already these rights.
You can see it with the following command:


**#ls -la /dev | grep ttyS0**

If the permissions are not set as above, you can configure them as follow:
(you have to be logged whit the super user account to make this changes.)


**#chown root /dev/ttyS0**

**#chgrp uucp /dev/ttyS0**

**#chmod 660 /dev/ttyS0**


Add the user name in the uucp group:


**#adduser almadev uucp**


To see which users are members of the uucp group, open the /etc/group file and look for the line beginning with uucp.


**#cat /etc/group | grep uucp**