#include "Ataque.h"





CAtaque::CAtaque(char *nombre, char *tipo, int daño)
{
	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->tipo = new char[30]; strcpy(this->tipo, tipo);
	this->daño = daño;
}


CAtaque::~CAtaque()
{
}

char *CAtaque::getnombre(){ return nombre; }
char *CAtaque::gettipo(){ return tipo; }
int CAtaque::getdaño(){ return daño; }

void CAtaque::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }
void CAtaque::settipo(){ this->tipo = new char[30]; strcpy(this->tipo, tipo); }
void CAtaque::setdaño(){ this->daño = daño; }