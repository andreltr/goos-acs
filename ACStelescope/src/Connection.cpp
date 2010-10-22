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

void Connection::slewTelescope(){
	char *message;
	this->serial->write_RS232(":Mn#");
	message = this->serial->read_RS232();
}

char *Connection::getAzimuth(){
	char *message;
	this->serial->write_RS232(":GZ#");
	message = this->serial->read_RS232();
	return message;
}
