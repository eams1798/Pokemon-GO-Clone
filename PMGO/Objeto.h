#pragma once
#include <string.h>
class CObjeto
{
protected:
	char *nombre;
	int efecto;
public:
	CObjeto(char *nombre, int efecto);
	~CObjeto();

	char *getnombre();
	int getefecto();

	void setnombre(char *nombre);
	void setefecto(int efecto);
};

