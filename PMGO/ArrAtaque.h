#pragma once
#include "Ataque.h"
#include <vector>
using namespace std;

class CArrAtaque
{
protected:
	vector <CAtaque*> vecAtq;
public:
	CArrAtaque();
	~CArrAtaque();
	vector <CAtaque*> getVecA();
	int getsize();

	CAtaque *getAtaque(int indice);
	CAtaque *getAtaque(char *nombreAtaque);
};

