#include "Ataque.h"





CAtaque::CAtaque(char *nombre, char *tipo, int da�o)
{
	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->tipo = new char[30]; strcpy(this->tipo, tipo);
	this->da�o = da�o;
}


CAtaque::~CAtaque()
{
}

char *CAtaque::getnombre(){ return nombre; }
char *CAtaque::gettipo(){ return tipo; }
int CAtaque::getda�o(){ return da�o; }

void CAtaque::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }
void CAtaque::settipo(){ this->tipo = new char[30]; strcpy(this->tipo, tipo); }
void CAtaque::setda�o(){ this->da�o = da�o; }