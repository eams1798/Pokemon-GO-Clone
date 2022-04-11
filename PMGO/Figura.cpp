#include "Figura.h"


CFigura::CFigura(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes)
{
	this->x = x;
	this->y = y;
	this->largo = largo;
	this->alto = alto;
	this->dx = dx;
	this->dy = dy;
	this->xSprite = xSprite;
	this->ySprite = ySprite;
	this->nframes = nframes;
}
CFigura::~CFigura(void){}

int CFigura::getx() { return x; }
int CFigura::gety() { return y; }
int CFigura::getlargo() { return largo; }
int CFigura::getalto() { return alto; }
int CFigura::getdx() { return dx; }
int CFigura::getdy() { return dy; }
int CFigura::getxSprite() { return xSprite; }
int CFigura::getySprite() { return ySprite; }

void CFigura::setx(int x) { this->x = x; }
void CFigura::sety(int y) { this->y = y; }
void CFigura::setlargo(int largo) { this->largo = largo; }
void CFigura::setalto(int alto) { this->alto = alto; }
void CFigura::setdx(int dx) { this->dx = dx; }
void CFigura::setdy(int dy) { this->dy = dy; }
void CFigura::setxSprite(int xSprite) { this->xSprite = xSprite; }
void CFigura::setySprite(int ySprite) { this->ySprite = ySprite; }