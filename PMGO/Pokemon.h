#pragma once
#include "Figura.h"
#include "ArrAtaque.h"
#include <vector>
#include <time.h>
using namespace System;
using namespace std;
class CPokemon :public CFigura
{
protected:
	int indicePoke;
	int largoEspalda, altoEspalda;

	char *nombre, *mote;
	char *tipo1, *tipo2;
	int sexo; //0 = Masculino/Macho; 1 = Femenino/Hembra(Humanos y Pokémon); 2 = Asexual (solo en Pokémon);
	int PC,
		nPolvoEstconsumido, nPolvoEst_requiereMasPC,
		nCaram_consumidos, nCaram_requiereEvol;
	int vidaActual, vidaMaxima;
	double ataque, defensa;
	double velocidad;
	double peso, altura;

	char *descripcionPokedex;

	int ratiocaptura;
	int tieneEvolucion;
	int tieneMega;
	int tieneMega2;//como bool-> 0 = false; 1 = true; 
	bool enCombate;
	bool megaevoluionado; 
	int esInicial;
	int espalda; //0->false (enemigo), 1->true (tuyo), 5 (declarado, pero indeterminado)

	CAtaque *ataquePrincipal;
	CAtaque *ataqueDefinitivo;
	vector<CAtaque*>ataquesAprendidos;
public:
	CArrAtaque *listaataques = new CArrAtaque();
	CPokemon(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes,
		int indicePoke, int largoEspalda, int altoEspalda,
		char *nombre, char *tipo1, char *tipo2, int sexo,
		int nCaram_requiereEvol,
		int vidaMaxima, double ataque, double defensa, double velocidad, double peso, double altura,
		char *descripcionPokedex,
		int ratiocaptura,
		int tieneEvolucion, int tieneMega, int tieneMega2, bool enCombate, bool megaevoluionado,
		int esInicial, int espalda
		);
	~CPokemon();

	void dibujar(Graphics ^g, Bitmap ^bmpPoke);
	void dibujarEspalda(Graphics ^g, Bitmap ^bmpPoke);
	void mover(Keys teclaPresionada);

	int getIndice();
	char *getnombre();
	char *getmote();
	char *gettipo1();
	char *gettipo2();
	int getsexo();
	int getPC();
	int getnPolvoEstconsumido();
	int getnPolvoEst_requiereMasPC();
	int getnCaram_consumidos();
	int getnCaram_requiereEvol();
	int getvidaActual();
	int getvidaMaxima();
	double getataque();
	double getdefensa();
	double getvelocidad();
	double getpeso();
	double getaltura();

	char *getdescripcion();
	int getratiocaptura();

	int gettieneEvolucion();
	int gettieneMega();
	int getTieneMega2();
	bool getenCombate();
	bool getmegaevoluionado();
	int getEsInicial();
	int getdeEspalda();
	int getLargoEspalda();
	int getAltoEspalda();
	
	CAtaque *getataquePrincipal();
	CAtaque *getataqueDefinitivo();
	vector<CAtaque*> getataquesAprendidos();
	void setataquesaprendidos(vector<CAtaque*> aprender);
	int getSalud_PC();
	int getAtaque_PC();
	int getDefensa_PC();
	int getVelocidad_PC();
	double getnumeroIVs(int salud, double ataque, double defensa, double velocidad);

	void setIndice(int i);
	void setnombre(char *nombre);
	void setmote(char *mote);
	void settipo1(char *tipo1);
	void settipo2(char *tipo2);
	void setsexo(int sexo);
	void setPC(int PC);
	void setnPolvoEstconsumido(int nPolvoEstconsumido);
	void setnPolvoEst_requiereMasPC(int nPolvoEst_requiereMasPC);
	void setnCaram_consumidos(int nCaram_consumidos);
	void setnCaram_requiereEvol(int nCaram_requiereEvol);
	void setvidaActual(int vidaActual);
	void setvidaMaxima(int vidaMaxima);
	void setataque(double ataque);
	void setdefensa(double defensa);
	void setvelocidad(double velocidad);
	void setpeso(double peso);
	void setaltura(double altura);
	void settieneEvolucion(int tieneEvolucion);
	void settieneMega(int tieneMega);
	void settieneMega2(int tieneMega2);
	void setenCombate(bool enCombate);
	void setmegaevoluionado(bool megaevoluionado);
	void setesinicial(int esInicial);
	void setratiocaptura(int ratioC);
	void setdeEspalda(int espalda);
	void setLargoEspalda(int largoEspalda);
	void setAltoEspalda(int altoEspalda);
	void setdescripcion(char *descripcion);

	void setataquePrincipal(char* nombreataque);
	void setataquePrincipal(CAtaque* AtaquePR);

	void setataqueDefinitivo(char* nombreataque);
	void setataqueDefinitivo(CAtaque* AtaqueDEF);

	void aprenderAtaque(char* nombreataque);
	void aprenderAtaque(CAtaque* nuevo);
	void olvidarAtaque(char* nombreAtaque);
	void olvidarAtaque(CAtaque* nuevo);

	void aumentarPC(int suma);

	CAtaque *getAtaqueAprendido(int posicion);
};

