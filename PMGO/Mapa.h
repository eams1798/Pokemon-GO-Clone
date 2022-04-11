#pragma once
#include "Celda.h"
#include <vector>
using namespace std;

class CMapa
{
private:
	CCelda *matriz[45][75];
	int xC, yC, largoC, altoC;
	int col, fil;
public:
	CMapa();
	~CMapa();

	bool buscar(int x, int y);
	void dibujar(Graphics ^g);
	CCelda *getCelda(int x, int y);
};

