#pragma once
#include "PokeballCelda.h"
#include <vector>

using namespace std;
class CArrPokeballs
{
	vector <CPokeballCelda*> vecPKBALL;
public:
	CArrPokeballs();
	~CArrPokeballs();

	int getsize();
	int returnedposint(CPokeballCelda *returnedpos);
	bool colisiona(int x, int y);

	void agregar(CPokeballCelda *nuevo);
	void dibujartodo(Graphics ^g, Bitmap ^bmp);
	void borrartodo();
	void eliminarPoke(int pos);

	CPokeballCelda *getCelda(int pos);
	CPokeballCelda *returnedpos(Rectangle rec);
};

