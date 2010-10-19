#include <Communication.h>
#include <stdio.h>
#include <string.h>

Communication::Communication(char *deviceName){
	this->sp = new SerialRS232(deviceName);
	this->sp->flush_RS232();
}

Communication::~Communication(){
	delete this->sp;
}

void Communication::startTelescopeAutomaticSequenceAlignment(){
	char *msg;
	this->sp->write_RS232(":Aa#");
	msg = this->sp->read_RS232();
}

void Communication::startTelescopeSlew(){
	char *msg;
	this->sp->write_RS232(":Mn#");
	msg = this->sp->read_RS232();
}
