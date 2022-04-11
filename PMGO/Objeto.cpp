#include "Objeto.h"


CObjeto::CObjeto(char *nombre, int efecto)
{
	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->efecto = efecto;
}


CObjeto::~CObjeto()
{
}

char *CObjeto::getnombre(){ return nombre; }
int CObjeto::getefecto(){ return efecto; }

void CObjeto::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }
void CObjeto::setefecto(int efecto){ this->efecto = efecto; }