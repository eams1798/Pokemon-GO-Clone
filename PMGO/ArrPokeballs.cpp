#include "ArrPokeballs.h"


CArrPokeballs::CArrPokeballs()
{
}


CArrPokeballs::~CArrPokeballs()
{
}

int CArrPokeballs::getsize()
{
	return vecPKBALL.size();
}

int CArrPokeballs::returnedposint(CPokeballCelda *returnedpos)
{
	for (int i = 0; i < vecPKBALL.size(); i++)
	{
		if (vecPKBALL[i] == returnedpos)
			return i;
	}
}

bool CArrPokeballs::colisiona(int x, int y)
{
	for (int i = 0; i < vecPKBALL.size(); i++)
	{
		if (vecPKBALL[i]->hayColision(x, y) == true)
			return true;
	}
	return false;
}

void CArrPokeballs::agregar(CPokeballCelda *nuevo)
{
	vecPKBALL.push_back(nuevo);
}
void CArrPokeballs::dibujartodo(Graphics ^g, Bitmap ^bmp)
{
	for (int i = 0; i < vecPKBALL.size(); i++)
	{
		vecPKBALL[i]->dibujar(g, bmp);
	}
}
void CArrPokeballs::borrartodo()
{
	vecPKBALL.clear();
}

void CArrPokeballs::eliminarPoke(int pos)
{
	vecPKBALL.erase(vecPKBALL.begin() + pos);
}

CPokeballCelda *CArrPokeballs::getCelda(int pos)
{
	return vecPKBALL[pos];
}

CPokeballCelda *CArrPokeballs::returnedpos(Rectangle rec)
{
	for (int i = 0; i < vecPKBALL.size(); i++)
	{
		int pX = vecPKBALL[i]->getX(),
			pY = vecPKBALL[i]->getY(),
			pW = vecPKBALL[i]->getLargo(),
			pH = vecPKBALL[i]->getAlto();
		Rectangle reccelda = Rectangle(pX, pY, pW, pH);
		if (reccelda.Equals(rec))
		{
			return vecPKBALL[i];
		}
	}
}
