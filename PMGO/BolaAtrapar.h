#pragma once
#include "Figura.h"
#include <math.h>
#include <iostream>
#define PI 3.1416

class CBolaAtrapar :public CFigura
{
protected:
	bool moverPKB;
	double angulo; bool giro;
	double anguloY = PI / 4, radioY = 150.00;
	int estado = 0; //0=Pokeball; 1=Ultraball;
public:
	CBolaAtrapar(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes);
	~CBolaAtrapar();

	void dibujar(Graphics^g, Bitmap ^bmpImage);
	void dibujarEstatico(Graphics^g, Bitmap ^bmpImage);
	void girar(Graphics^g, Bitmap ^bmpImage, int altomove);
	void mover(Keys teclaPresionada);

	int getEstado();
	void setestado(int estado);
	double getAngulo();
	bool getGiro();
	void setAngulo(double angulo);
	void setGiro(bool giro);
	bool getMover();
	void setMover(bool moverPKB);
	bool colision(int x, int y);
};

