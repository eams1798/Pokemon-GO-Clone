#include "PokeballCelda.h"


CPokeballCelda::CPokeballCelda(int x, int y, int largo, int alto, int estado, CPokemon *ARegistrar)
:CCelda(x, y, largo, alto, estado)
{
	this->estado = 2;
	pokeregistrado = ARegistrar;
}


CPokeballCelda::~CPokeballCelda()
{
}

void CPokeballCelda::dibujar(Graphics ^g, Bitmap ^bmp)
{
	Rectangle origen = Rectangle(0, 0, largo, alto);
	Rectangle destino = Rectangle(x, y, largo, alto);
	g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
}

CPokemon *CPokeballCelda::getPoke()
{
	return pokeregistrado;
}