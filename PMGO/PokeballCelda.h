#pragma once
#include "Celda.h"
#include "Pokemon.h"
class CPokeballCelda :public CCelda
{
	CPokemon *pokeregistrado;
public:
	CPokeballCelda(int x, int y, int largo, int alto, int estado, CPokemon *ARegistrar);
	~CPokeballCelda();

	void dibujar(Graphics ^g, Bitmap ^bmp);
	CPokemon *getPoke();
};

