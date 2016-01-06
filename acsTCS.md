# Project Brief #

ACS-TSC is a project developing on ACS framework to control the telescope of the Sirius Observatory of Universidad Católica del Norte. This project is integrated by students of the college in their majors of Computer Science Engineering. The pourpose of the software is controling the MEADE LX200 Telescope with a GUI developed in Java and a ACS component to execute the respective functions of the telescope by a serial connection.


# Details #

## Members of the Project ##
  * [Jaime Pavlich Mariscal](http://code.google.com/u/Jaime.Pavlich) (Assistant Professor)
  * [Cristian Guevara Rojas](http://code.google.com/u/guevarax) (Project Manager)
  * [Felipe Henríquez Díaz](http://code.google.com/u/jadhur)
  * [Alexis Ibarra Araya](http://code.google.com/u/Ibarra.Alexis)
  * [Luís Jofré Astudillo](http://code.google.com/u/rjofre)
  * [Hernes Puentes Vargas](http://code.google.com/u/animegold1988)
  * [Santiago Sánchez Pérez](http://code.google.com/u/salex.sp)

## System Details ##
  * Scientific Linux 5.4 O.S.
  * ACS 8.1 framework
  * Eclipse for Java and C++ development
  * MEADE LX200GPS for physical testings and final product

## Physics Theory ##

  * Coordinate

> A celestial coordinate system is a coordinate system for mapping positions    on the celestial sphere. There are different celestial coordinate systems each using a system of spherical coordinates projected on the celestial sphere, in analogy to the geographic coordinate system used on the surface of the Earth. The coordinate systems differ only in their choice of the fundamental plane, which divides the sky into two equalhemispheres along a great circle. For example, the fundamental plane of the geographic system is the Earth's equator. Each coordinate system is named for its choice of fundamental plane.

  * Horizontal System

> Una coordenada es la altura (que se denota por h), que se define como el ángulo que forma la visual del astro con el plano del horizonte.Se cuenta de 0º a 90º hacia Z (si el astro está por encima del horizonte) y de 0º a -90º hacia Z´(si el astro está por debajo del horizonte).El ángulo complementario a la altura (z = 90º-h) se denomina distancia zenital (o distancia cenital).La otra coordenada es el azimut (que se denota por A) que es el ángulo diedro (ángulo que forman dos círculos máximos), que forma el meridiano del lugar con el círculo vertical que pasa por el astro.Se toma como origen el Sur (si estamos en el hemisferio Norte) o el Norte (si estamos en el hemisferio Sur).Se cuenta en sentido del movimiento diurno, es decir, en dirección S-O-N-E en el hemisferio Norte, y en dirección N-O-S-E en el hemisferio Sur.El azimut toma, entonces, valores entre 0º y 360º.


# Planification #

There are 3 steps of implementation:

## Serial Port Conection ##

Implement the interface between Serial Port and the ACS Modules.

## ACS Developing ##

  * Study and design an ACS implementation for controlling the telescope.
  * Implement the component, the CDB schema and the IDL.
  * Document the development process.

## GUI Client ##

  * Study developing of GUI on Java Swing.
  * Implement a simple Java interface in Swing.

| **Step** | **Responsible** | **Wiki Pages** |
|:---------|:----------------|:---------------|
| Serial Port Conection | [Alexis Ibarra Araya](http://code.google.com/u/Ibarra.Alexis) | [Serial Port Conection](http://code.google.com/p/goos-acs/wiki/acsTCSSerialPortConection) |
| ACS Developing | [Luís Jofré Astudillo](http://code.google.com/u/rjofre) | [ACS Developing](http://code.google.com/p/goos-acs/wiki/acsTCSACSDeveloping) |
| GUI Client | [Felipe Henríquez Díaz](http://code.google.com/u/jadhur) | [GUI Client](http://code.google.com/p/goos-acs/wiki/acsTCS/acsTCSGUIClient) |