#include "Controlador.h"


CControlador::CControlador(CPersonaje *Usuario, CPersonaje *GymLider)
{
	arrquad = new CMapa();
	arratq = new CArrAtaque();
	this->Usuario = Usuario;
	this->GymLider = GymLider;
}

void CControlador::setLider(CPersonaje *GymLider)
{
	this->GymLider = GymLider;
}

CControlador::~CControlador()
{
}

CMapa *CControlador::getTablero()
{
	return arrquad;
}

char *CControlador::getAtqefectivo(CAtaque *ataque, CPokemon *objetivo)
{
	char *efectivo = new char[50];
	strcpy(efectivo, "El ataque dio en el blanco");

	double efecto =
		efectoataque(ataque, objetivo->gettipo1()) * efectoataque(ataque, objetivo->gettipo2()) * 1.00;
	
	if (efecto > 1)
	{
		strcpy(efectivo, "Es súper-efectivo");
	}
	if (efecto < 1 && efecto > 0)
	{
		strcpy(efectivo, "No es muy efectivo");
	}
	if (efecto == 0)
	{
		strcpy(efectivo, "No afecta al Pokémon objetivo");
	}
	return efectivo;
}

double CControlador::efectoataque(CAtaque *ataque, char *tipoobjetivo)
{
	double E = 1;
	if (strcmp(tipoobjetivo, "") == 0)
	{
		E = 1;
	}
	if (strcmp(ataque->gettipo(), "Acero") == 0)
	{
		if (strcmp(tipoobjetivo, "Hada") == 0 ||
			strcmp(tipoobjetivo, "Hielo") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Eléctrico") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Agua") == 0)
	{
		if (strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Tierra") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Bicho") == 0)
	{
		if (strcmp(tipoobjetivo, "Planta") == 0 ||
			strcmp(tipoobjetivo, "Siniestro") == 0 ||
			strcmp(tipoobjetivo, "Psíquico") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Fantasma") == 0 ||
			strcmp(tipoobjetivo, "Hada") == 0 ||
			strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Dragón") == 0)
	{
		if (strcmp(tipoobjetivo, "Dragón") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Hada") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Eléctrico") == 0)
	{
		if (strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Eléctrico") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Tierra") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Fantasma") == 0)
	{
		if (strcmp(tipoobjetivo, "Fantasma") == 0 ||
			strcmp(tipoobjetivo, "Psíquico") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Normal") == 0 || strcmp(tipoobjetivo, "Siniestro") == 0)
		{
			E *= 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Fuego") == 0)
	{
		if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Hielo") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0 ||
			strcmp(tipoobjetivo, "Hada") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Hada") == 0)
	{
		if (strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Siniestro") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Hielo") == 0)
	{
		if (strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0 ||
			strcmp(tipoobjetivo, "Tierra") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Hielo") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Lucha") == 0)
	{
		if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Hielo") == 0 ||
			strcmp(tipoobjetivo, "Normal") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0 ||
			strcmp(tipoobjetivo, "Siniestro") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Hada") == 0 ||
			strcmp(tipoobjetivo, "Psíquico") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Fantasma") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Normal") == 0)
	{
		if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Fantasma") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Planta") == 0)
	{
		if (strcmp(tipoobjetivo, "Agua") == 0 ||
			strcmp(tipoobjetivo, "Tierra") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Dragón") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Psíquico") == 0)
	{
		if (strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Psíquico") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Siniestro") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Roca") == 0)
	{
		if (strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Hielo") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Volador") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Tierra") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Siniestro") == 0)
	{
		if (strcmp(tipoobjetivo, "Fantasma") == 0 ||
			strcmp(tipoobjetivo, "Psíquico") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Hada") == 0 ||
			strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Siniestro") == 0)
		{
			E *= 0.5;
		}
	}
	else if (strcmp(ataque->gettipo(), "Tierra") == 0)
	{
		if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Eléctrico") == 0 ||
			strcmp(tipoobjetivo, "Fuego") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Volador") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Veneno") == 0)
	{
		if (strcmp(tipoobjetivo, "Hada") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Fantasma") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0 ||
			strcmp(tipoobjetivo, "Tierra") == 0 ||
			strcmp(tipoobjetivo, "Veneno") == 0)
		{
			E *= 0.5;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0)
		{
			E = 0;
		}
	}
	else if (strcmp(ataque->gettipo(), "Volador") == 0)
	{
		if (strcmp(tipoobjetivo, "Bicho") == 0 ||
			strcmp(tipoobjetivo, "Lucha") == 0 ||
			strcmp(tipoobjetivo, "Planta") == 0)
		{
			E *= 2;
		}
		else if (strcmp(tipoobjetivo, "Acero") == 0 ||
			strcmp(tipoobjetivo, "Roca") == 0 ||
			strcmp(tipoobjetivo, "Eléctrico") == 0)
		{
			E *= 0.5;
		}
	}
	return E*1.00;
}

void CControlador::atq(CPokemon *pkusuario, CAtaque *ataque, CPokemon *objetivo)
{
	Random r;
	double B;
	if (strcmp(ataque->gettipo(), pkusuario->gettipo1()) == 0 ||
		strcmp(ataque->gettipo(), pkusuario->gettipo2()) == 0)
		B = 1.5;
	else B = 1;
	double E =
		efectoataque(ataque, objetivo->gettipo1()) * efectoataque(ataque, objetivo->gettipo2()) * 1.00;
	int V = r.Next(85, 101);
	double N = 0.1*pkusuario->getPC();
	double A = pkusuario->getAtaque_PC();
	double P = ataque->getdaño();
	double D = objetivo->getDefensa_PC();

	double daño = 0.01 * B*E*V*((((0.2*N + 1)*A*P) / (25 * D)) + 2);

	if (objetivo->getvidaActual() - daño <= 0)
		objetivo->setvidaActual(0);
	else objetivo->setvidaActual(objetivo->getvidaActual() - daño);
}

void CControlador::atacar(CPokemon *pkusuario, CAtaque *ataque, CPokemon *objetivo)
{
	Random r;

	if (strcmp(ataque->getnombre(), "Metrónomo") == 0)
	{
		while (strcmp(ataque->getnombre(), "Metrónomo") == 0 ||
			strcmp(ataque->getnombre(), "Luz de la luna") == 0 ||
			strcmp(ataque->getnombre(), "Geocontrol") == 0)
		{
			ataque = arratq->getAtaque(r.Next(0, 180));
		}
		atq(pkusuario, ataque, objetivo);
	}
	else if (strcmp(ataque->getnombre(), "Luz de la luna") == 0)
	{
		if (pkusuario->getvidaActual() + (pkusuario->getSalud_PC() / 2) >= pkusuario->getSalud_PC())
			pkusuario->setvidaActual(pkusuario->getSalud_PC());
		else
			pkusuario->setvidaActual(pkusuario->getvidaActual() + (pkusuario->getSalud_PC() / 2));
	}
	else if (strcmp(ataque->getnombre(), "Geocontrol") == 0)
	{
		pkusuario->setataque(pkusuario->getataque()*1.5);
		pkusuario->setdefensa(pkusuario->getdefensa()*1.5);
		pkusuario->setvelocidad(pkusuario->getvelocidad()*1.5);
	}
	else
	{
		atq(pkusuario, ataque, objetivo);
	}
}

void CControlador::permitirmovimiento(CPersonaje *Usuario, Keys Tecla)
{
	CCelda *c;
	int xUsr = Usuario->getx() / 16; int yUsr = Usuario->gety() / 16;

	switch (Tecla)
	{
	case Keys::Left:
		c = arrquad->getCelda(xUsr-1,yUsr);
		break;
	case Keys::Up:
		c = arrquad->getCelda(xUsr, yUsr-1);
		break;
	case Keys::Right:
		c = arrquad->getCelda(xUsr+2, yUsr+1);
		break;
	case Keys::Down:
		c = arrquad->getCelda(xUsr+1, yUsr+2);
		break;
	default:
		c = arrquad->getCelda(xUsr, yUsr);
		break;
	}
	if (c->getEstado() == 0)
	{
		Usuario->setdx(0); Usuario->setdy(0);
	}
	else
	{
		Usuario->setdx(16); Usuario->setdy(16);
	}
}

CPersonaje *CControlador::getUsuario(){ return Usuario; }
CPersonaje *CControlador::getLider(){ return GymLider; }