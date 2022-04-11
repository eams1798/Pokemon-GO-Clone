#include "BolaAtrapar.h"


CBolaAtrapar::CBolaAtrapar(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes)
	:CFigura(x, y, largo, alto, dx, dy, xSprite, ySprite, nframes)
{
	nframes = 12;
	moverPKB = false;

	angulo = 0; giro = false;
}


CBolaAtrapar::~CBolaAtrapar()
{
}

void CBolaAtrapar::dibujar(Graphics^g, Bitmap ^bmpImage)
{
	Rectangle Origen = Rectangle(64 * xSprite + 6, 0, 52, 52);
	Rectangle Destino = Rectangle(x, y, largo, alto);
	g->DrawImage(bmpImage, Destino, Origen, GraphicsUnit::Pixel);

	if (xSprite == nframes - 1)
	{
		xSprite = 0;
	}
	else xSprite++;
}

void CBolaAtrapar::dibujarEstatico(Graphics^g, Bitmap ^bmpImage)
{
	Rectangle Origen = Rectangle(710, 0, 52, 52);
	Rectangle Destino = Rectangle(x, y, largo, alto);
	g->DrawImage(bmpImage, Destino, Origen, GraphicsUnit::Pixel);
}

void CBolaAtrapar::mover(Keys teclaPresionada){}

double CBolaAtrapar::getAngulo()
{
	return angulo;
}
bool CBolaAtrapar::getGiro()
{
	return giro;
}

int CBolaAtrapar::getEstado()
{
	return estado;
}

void CBolaAtrapar::setestado(int estado)
{
	this->estado = estado;
}

void CBolaAtrapar::setAngulo(double angulo)
{
	this->angulo = angulo;
}
void CBolaAtrapar::setGiro(bool giro)
{
	this->giro = giro;
}

void CBolaAtrapar::girar(Graphics^g, Bitmap ^bmpImage, int altomove)
{
	if (moverPKB){
		dibujar(g, bmpImage);
		/*y += dy;

		if ( w >0)	w -= 4;
		if (h > 0)	h -= 4;*/

		if (giro = true)
		{
			x -= (largo / 2)*cos(angulo); angulo -= (PI * 18) / 180;
		}
		else
		{
			x += (largo / 2)*cos(angulo);	angulo += (PI * 18) / 180;
		}
		y = altomove + radioY*sin(anguloY);
		anguloY -= (PI * 18) / 180;
		if (largo > 0 && alto > 0) { largo -= 4; alto -= 4; }
	}
}

bool CBolaAtrapar::getMover(){ return moverPKB; }
void CBolaAtrapar::setMover(bool moverPKB){ this->moverPKB = moverPKB; }

bool CBolaAtrapar::colision(int x, int y){
	return (x > this->x  && x < this->x + this->largo) && (y > this->y  && y < this->y + this->alto);

}