#pragma once
#include <string.h>

class CAtaque
{
protected:
	char *nombre;
	char *tipo;
	int da�o;
	//int agregado; agregado = 1 (tipoAtaque != tipoPokemon); agregado = 1.5 (else)
	//int efecto; efecto = 0 (Inmune); efecto = 1 (Normal); efecto = 1/2 (No muy efectivo); efecto = 2 (S�per efectivo);
	//los atributos comentados se ver�n en el controlador
public:
	CAtaque(char *nombre, char *tipo, int da�o);
	~CAtaque();
	char *getnombre();
	char *gettipo();
	int getda�o();
	int getindice();
	
	void setnombre(char *nombre);
	void settipo();
	void setda�o();
};

