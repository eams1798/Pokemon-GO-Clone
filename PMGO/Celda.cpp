#include "Celda.h"


CCelda::CCelda(int x, int y, int largo, int alto, int estado)
{
	this->x = x;
	this->y = y;
	this->largo = largo;
	this->alto = alto;
	this->estado = estado;
}


CCelda::~CCelda()
{
}


void CCelda::dibujar(Graphics ^g){ g->DrawRectangle(Pens::Transparent, x, y, largo, alto); }

int CCelda::getX(){ return x; }
int CCelda::getY(){ return y; }
int CCelda::getLargo(){ return largo; }
int CCelda::getAlto(){ return alto; }
int CCelda::getEstado(){ return estado; }
void CCelda::setEstado(int estado){ this->estado = estado; }
bool CCelda::hayColision(int x, int y)
{
	return x >= this->x && x <= this->x + largo &&
		y >= this->y && y <= this->y + alto;
}