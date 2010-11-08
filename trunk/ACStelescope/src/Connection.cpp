#include <Connection.h>
#include <stdio.h>
#include <string.h>

Connection::Connection(char *deviceName){
	this->serial = new SerialRS232(deviceName);
	this->serial->flush_RS232();
}

Connection::~Connection(){
	delete this->serial;
}

void Connection::startTelescope(){
	char *message;
	this->serial->write_RS232(":Aa#");
	message = this->serial->read_RS232();
}

void Connection::slewTelescopeNorth(){
	char *message;
	this->serial->write_RS232(":Mn#");
	message = this->serial->read_RS232();
}

void Connection::slewTelescopeSouth(){
	char *message;
	this->serial->write_RS232(":Ms#");
	message = this->serial->read_RS232();
}

void Connection::slewTelescopeEast(){
	char *message;
	this->serial->write_RS232(":Me#");
	message = this->serial->read_RS232();
}
void Connection::slewTelescopeWest(){
	char *message;
	this->serial->write_RS232(":Mw#");
	message = this->serial->read_RS232();
}

char *Connection::getAzimuth(){
	char *message;
	this->serial->write_RS232(":GZ#");
	message = this->serial->read_RS232();
	return message;
}

char *Connection::getAltitude(){
	char *message;
	this->serial->write_RS232(":GA#");
	message = this->serial->read_RS232();
	return message;
}

void Connection::stopSlewing(){
	this->serial->write_RS232(":Q#");
}

