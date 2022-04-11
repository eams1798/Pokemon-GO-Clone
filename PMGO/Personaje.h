#pragma once
#include "ArrPokemon.h"
#include "ArrObjeto.h"
#include "Figura.h"

#include <math.h>
using namespace std;

class CPersonaje :public CFigura
{
protected:
	char *nombre;
	int sexo;
	int experiencia; int nivel;
	int monedas;
	int nCaramelos;
	int nPolvoestelares;
	int rebotePokeball = 0;
	vector<CPokemon*> pokeAtrapados;
	vector<CObjeto*> listaObjetos;

public:
	CPersonaje(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes,
		char *nombre, int sexo, int experiencia, int nivel, int monedas,
		int nCaramelos, int nPolvoestelares,
		CPokemon *inicial);
	~CPersonaje();

	void dibujar(Graphics ^g, Bitmap ^bmpPoke);
	void mover(Keys teclaPresionada);
	char *getnombre();
	int getsexo();
	int getexperiencia();
	int getnivel();
	int getmonedas();
	int getnCaramelos();
	int getnPolvoestelares();

	int getrebotePKB();

	vector<CPokemon*> getlistaMisPokes();
	vector<CObjeto*> getlistaMisObjs();
	CPokemon *getMyPoke(int posicionPoke);
	CObjeto *getItem(int posicionItem);

	void setnombre(char *nombre);

	void setexperiencia(int exp);
	void subirexp();

	void setnivel(int nivel);
	void subirdenivel();

	void setmonedas(int monedas);
	void setnCaramelos(int caramelos);
	void setnPolvoestelares(int polvoest);
	void aumentarlistaPokeatrapado(CPokemon *nuevoPoke);
	void transferirPoke(int pos);
	void aumentarlistaObj(CObjeto *item);

	void usarObjeto(char *nombreObjeto, CPokemon *PokemonAUsar);
	void usarObjeto(int pos, CPokemon *PokemonAUsar);

	void subirPC(CPokemon *myPoke, int polvoestelar);
	void darCarameloparaEvol(CPokemon *myPoke, int caramelos);

	void evolucionar(int pospoke);
	void Megaevolucionar(CPokemon *myPoke, int XY);
	void Mega_a_estado_normal(CPokemon *myPoke);
};

