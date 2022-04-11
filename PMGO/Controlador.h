#pragma once
#include "Personaje.h"
#include "Mapa.h"
class CControlador
{
private:
	CMapa *arrquad;
	CArrAtaque *arratq;
	CPersonaje *Usuario;
	CPersonaje *GymLider;
	int turnos;
public:
	CControlador(CPersonaje *Usuario, CPersonaje *GymLider);
	~CControlador();

	void permitirmovimiento(CPersonaje *Usuario, Keys Tecla);

	char *getAtqefectivo(CAtaque *ataque, CPokemon *objetivo);
	double efectoataque(CAtaque *ataque, char *tipoobjetivo);
	void atq(CPokemon *pkusuario, CAtaque *ataque, CPokemon *objetivo);
	void atacar(CPokemon *pkusuario, CAtaque *ataque, CPokemon *objetivo);

	CPersonaje *getUsuario();
	CPersonaje *getLider();
	void setLider(CPersonaje *GymLider);
	CMapa *getTablero();
};

