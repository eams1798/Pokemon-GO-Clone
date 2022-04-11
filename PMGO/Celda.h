#pragma once
using namespace System::Drawing;
class CCelda
{
protected:
	int x, y, largo, alto;
	int estado;
public:
	CCelda(int x, int y, int largo, int alto, int estado);
	~CCelda();
	void dibujar(Graphics ^g);

	bool hayColision(int x, int y);
	int getX();
	int getY();
	int getLargo();
	int getAlto();
	int getEstado();
	void setEstado(int estado);
};

