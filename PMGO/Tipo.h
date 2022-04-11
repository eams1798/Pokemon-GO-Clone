#pragma once
#include <string.h>
class CTipo
{
protected:
	char *nombre;
	int efecto; //efecto = 0 (Inmune); efecto = 1 (Normal); efecto = 1/2 (No muy efectivo); efecto = 2 (Súper efectivo);
public:
	CTipo(char *nombre, int efecto);
	~CTipo();

	char *getnombre();
	int getefecto();
	void setnombre(char *nombre);
	void setefecto(int efecto);
};

