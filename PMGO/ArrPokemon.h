#pragma once
#include "Pokemon.h"
using namespace std;

class CArrPokemon
{
protected:
	vector<CPokemon*> arrPoke;
public:
	CArrPokemon();
	~CArrPokemon();
	vector<CPokemon*> getVecPk();
	int getsize();

	CPokemon *getPoke(int indice);
	CPokemon *getPoke(char *nombrePoke);
};

