#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;
class CFigura
{
protected:
	int x;
	int y;
	int largo;
	int alto;
	int dx;
	int dy;
	int xSprite;
	int ySprite;
	int nframes;
public:
	CFigura(int x,
		int y,
		int largo,
		int alto,
		int dx,
		int dy,
		int xSprite,
		int ySprite,
		int nframes);
	~CFigura(void);
	
	virtual void mover(Keys teclaPresionada) abstract;
	virtual void dibujar(Graphics ^g, Bitmap ^bmpImage) abstract;

	int getx();
	int gety();
	int getlargo();
	int getalto();
	int getdx();
	int getdy();
	int getxSprite();
	int getySprite();

	void setx(int x);
	void sety(int y);
	void setlargo(int largo);
	void setalto(int alto);
	void setdx(int dx);
	void setdy(int dy);
	void setxSprite(int xSprite);
	void setySprite(int ySprite);
};

