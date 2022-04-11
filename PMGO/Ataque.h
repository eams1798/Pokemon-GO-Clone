#pragma once
#include <string.h>

class CAtaque
{
protected:
	char *nombre;
	char *tipo;
	int daño;
	//int agregado; agregado = 1 (tipoAtaque != tipoPokemon); agregado = 1.5 (else)
	//int efecto; efecto = 0 (Inmune); efecto = 1 (Normal); efecto = 1/2 (No muy efectivo); efecto = 2 (Súper efectivo);
	//los atributos comentados se verán en el controlador
public:
	CAtaque(char *nombre, char *tipo, int daño);
	~CAtaque();
	char *getnombre();
	char *gettipo();
	int getdaño();
	int getindice();
	
	void setnombre(char *nombre);
	void settipo();
	void setdaño();
};

