#include "Tipo.h"


CTipo::CTipo(char *nombre, int efecto)
{
	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->efecto = efecto;
}


CTipo::~CTipo()
{
}


char *CTipo::getnombre(){ return nombre; }
int CTipo::getefecto(){ return efecto; }
void CTipo::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }
void CTipo::setefecto(int efecto){ this->efecto = efecto; }