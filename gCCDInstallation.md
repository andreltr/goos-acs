# Introduction #

Here you will learn how to deploy, install and how to configure the software in a distributed enviroment.

# Requirements #

In order for the software to work, you must first have ACS installed and working on each host where the software will be deployed. See these pages:

  * **[Platform configuration](PlatformConfiguration.md)**
  * **[ACS installation](ACSInstallation.md)**

# Deployment #

gCCD uses ACS as a framework to enable distributed deplyoment of the system. The software is divided roughly in three different logical parts:

**The CCD camera component**The GUI client
**The Bulk data transfer and notificacion system**

## The CCD camera component ##

This is the software that offers the ACS interface to manipulate the supported cameras.

## The GUI client ##

This is the graphical user interface that the operator uses to control de CCD through the CCD component.

## Bulk data transfer and notification system ##

The bulk data transfer system provided by ACS consists of a "sender" and "receiver" component that allow the transference of big files. The notification system also provided by ACS is used in order to inform the client of the arrival of files.

## Deployment scenario ##

Since this software has been built as a distributed system the basic deployment scenario consists of three host machines:

-->Insert diagram here<--

# Installation #

To install the system you must compile it from source. Dowload the release file from the Downloads section on this site and follow the instructions below.

## CCD host ##

The CCD host must have the component binaries and the bulk data binary files installed. To do this, you must enter the root directory of the source and execute:

  * **make component\_host**

### ACS Daemons ###

In order to avoid setup of the system (containers, acs, etc) each time you use it, you can use the ACS daemons to start containers on-demand whenever a component is requested from the client (or any other ACS/CORBA component to that matter).

The processes _acscontainerdaemon_ and _acsservicesdaemon_ are responsible of starting and stopping containers and ACS services respectively. This processes must be started manually or at boot time on the host machines.

The CDB container configuration files found in config/MACI/Containers/ for each container must be modified to contain the hostname of the machine where the container is supposed to run on. Here is an example:

```
<?xml version="1.0" encoding="ISO-8859-1"?>
<Container xmlns="urn:schemas-cosylab-com:Container:1.0" 
           xmlns:cdb="urn:schemas-cosylab-com:CDB:1.0" 
           xmlns:baci="urn:schemas-cosylab-com:BACI:1.0" 
           xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
           xmlns:log="urn:schemas-cosylab-com:LoggingConfig:1.0" 
           Timeout="20.0" 
           UseIFR="1" 
           ManagerRetry="10" 
           ImplLang="cpp">
  <Autoload>
    <cdb:_ string="baci" />
  </Autoload>
  <DeployInfo Host="alma" Flags="" KeepAliveTime="-1"/>
  <LoggingConfig 
             centralizedLogger="Log" 
             minLogLevel="2" 
             dispatchPacketSize="10" 
             immediateDispatchLevel="99">
  </LoggingConfig>
</Container>

```

Where on the line

```
  <DeployInfo Host="alma" Flags="" KeepAliveTime="-1"/>
```

the _Host_ attribute must be equal to the hostname where the container will run, in this case the hostname is _alma_.

## Client host ##

The client host must have the java binary and the bulk data binary files installed. To do this, you must enter the root directory of the source and execute:

  * **make client\_host**

# Testing the system #

You can test the system without a CCD camera using the _GCCD\_SIM_ component, which simulates one on a very basic level. This component is mostly useful to test the connection between the client, component and ACS hosts, and the bulk data transfer system.

If you have configured the system to use daemons, you just need to start the client on the client host:

  * **acsStartJava alma.ucn.oca.ccd.Main**

Once the GUI appears, you must select the _GCCD\_SIM_ camera model from the list of available cameras and press connect:

-->insert image<--

You must then set the exposure time on the CCD Settings tab to a value greater or equal than zero:

-->insert image<--

Finally on the CCD Control tab you must start the simulator by pressing Start CCD button and then acquire images pressing the Start Exposure button:

-->insert image<--

If everything worked correctly you should be able to see images on the GUI as they arrive:

-->insert image<--