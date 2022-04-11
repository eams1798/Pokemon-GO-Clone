#include "Personaje.h"


char *cambioTipoMegaX[13][2] =
{
	{"",""}, //0
	{"",""}, {"",""}, {"Planta","Veneno"}, {"",""}, {"",""}, {"Fuego","Dragón"}, {"",""}, {"",""}, {"Agua", ""}, //1-9
	{"",""}, {"",""}, {"",""},
};

char *cambioTipoMegaY[13][2] =
{
	{"",""}, //0
	{"",""}, {"",""}, {"",""}, {"",""}, {"",""}, {"Fuego","Volador"}, {"",""}, {"",""}, {"",""}, //1-9
	{"",""}, {"",""}, {"",""},
};

int aumentomegaevolX[13][7] = //{ {ataque[1], defensa[1], velocidad[1], largo[1], alto[1], largoespalda[1], altoespalda[1]}, ... }
{
	{0,0,0,0,0,0,0}, //0
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {20,30,15,136,91,131,92}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {34,16,15,161,107,186,100}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {35,15,15,110,114,107,108}, //1-9
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	
};

int aumentomegaevolY[13][7] = //{ {ataque[1], defensa[1], velocidad[1], largo[1], alto[1], largoespalda[1], altoespalda[1]}, ... }
{
	{0,0,0,0,0,0,0}, //0
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {35,15,15,201,166,256,184}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, //1-9
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
};


CPersonaje::CPersonaje(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes,
	char *nombre, int sexo, int experiencia, int nivel, int monedas,
	int nCaramelos, int nPolvoestelares,
	CPokemon *inicial): CFigura(x, y, largo, alto, dx, dy, xSprite, ySprite, nframes)
{
	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->sexo = sexo;
	this->experiencia = experiencia;
	this->nivel = nivel;
	this->monedas = monedas;
	this->nCaramelos = nCaramelos;
	this->nPolvoestelares = nPolvoestelares;
	pokeAtrapados.push_back(inicial);
}


CPersonaje::~CPersonaje()
{
}

char *CPersonaje::getnombre(){ return nombre; }
int CPersonaje::getsexo(){ return sexo; }
int CPersonaje::getexperiencia(){ return experiencia; }
int CPersonaje::getnivel(){ return nivel; }
int CPersonaje::getmonedas(){ return monedas; }
int CPersonaje::getnCaramelos(){ return nCaramelos; }
int CPersonaje::getnPolvoestelares(){ return nPolvoestelares; }

vector<CPokemon*> CPersonaje::getlistaMisPokes(){ return this->pokeAtrapados; }
vector<CObjeto*> CPersonaje::getlistaMisObjs(){ return this->listaObjetos; }
CPokemon *CPersonaje::getMyPoke(int posicionPoke)
{
	return pokeAtrapados[posicionPoke];
}
CObjeto *CPersonaje::getItem(int posicionItem)
{
	return listaObjetos[posicionItem];
}

void CPersonaje::dibujar(Graphics ^g, Bitmap ^bmpPoke)
{
	Rectangle origen = Rectangle(xSprite*largo, ySprite*alto, largo, alto);
	Rectangle destino = Rectangle(x, y, largo, alto);

	g->DrawImage(bmpPoke,destino,origen,GraphicsUnit::Pixel);


}
void CPersonaje::mover(Keys teclaPresionada)
{
	switch (teclaPresionada)
	{
	case Keys::Left:
		ySprite = 1; x -= dx;
		break;
	case Keys::Up:
		ySprite = 3; y -= dy;
		break;
	case Keys::Right: 
		ySprite = 2; x += dx;
		break;
	case Keys::Down:
		ySprite = 0; y += dy;
		break;
	default:
		x += 0; y += 0;
		break;
	}
	if (teclaPresionada != Keys::None)
	{
		if (xSprite == nframes - 1)
		{
			xSprite = 0;
		}
		else xSprite++;
	}
	else xSprite = 0;
}

void CPersonaje::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }

void CPersonaje::setexperiencia(int exp){ experiencia = exp; }
void CPersonaje::subirexp(){ experiencia += 600; }

void CPersonaje::setnivel(int nivel){ this->nivel = nivel; }
void CPersonaje::subirdenivel(){ this->nivel++; }

void CPersonaje::setmonedas(int monedas){ this->monedas = monedas; }
void CPersonaje::setnCaramelos(int caramelos){ this->nCaramelos = caramelos; }
void CPersonaje::setnPolvoestelares(int polvoest){ this->nPolvoestelares = polvoest; }
void CPersonaje::aumentarlistaPokeatrapado(CPokemon *nuevoPoke){ pokeAtrapados.push_back(nuevoPoke); }
void CPersonaje::transferirPoke(int pos)
{
	pokeAtrapados.erase(pokeAtrapados.begin() + pos);
	nCaramelos += 6;
}

void CPersonaje::aumentarlistaObj(CObjeto *item){ listaObjetos.push_back(item); }

void CPersonaje::usarObjeto(char *nombreObjeto, CPokemon *PokemonAUsar)
{
	int efct, indobj; bool objetoUsado = false;

	for (int i = 0; i < listaObjetos.size(); i++)
	{
		if (nombreObjeto == listaObjetos[i]->getnombre())
		{
			efct = listaObjetos[i]->getefecto();
		}
	}

	int PSmax, PSact, Rc, Rb;
	double a, b;
	for (int i = 0; i < listaObjetos.size(); i++)
	{
		switch (efct)
		{
		case 1:
			PSmax = PokemonAUsar->getSalud_PC();
			PSact = PokemonAUsar->getvidaActual();
			Rc = PokemonAUsar->getratiocaptura();			
			if (strcmp(listaObjetos[i]->getnombre(), "Pokeball") == 0) Rb = 1;
			if (strcmp(listaObjetos[i]->getnombre(), "Ultraball") == 0) Rb = 2;

			a = ((3 * PSmax - 2 * PSact)*Rc*Rb) / (3 * PSmax);

			if (a >= 255)
				pokeAtrapados.push_back(PokemonAUsar);
			else
			{
				b = (pow(2, 16) - 1)*(pow( (a / (pow(2, 8) - 1)), 0.25 ));
				Random ^r = gcnew Random(DateTime::Now.Ticks);
				int CapNum1 = r->Next(0, 65536), CapNum2 = r->Next(0, 65536),
					CapNum3 = r->Next(0, 65536), CapNum4 = r->Next(0, 65536);
				if (CapNum1 <= b && CapNum2 <= b && CapNum3 <= b && CapNum4 <= b)
				{
					this->rebotePokeball = 3;
					pokeAtrapados.push_back(PokemonAUsar);
				}
				else if ((CapNum1 <= b && CapNum2 <= b && CapNum3 <= b) ||
					(CapNum1 <= b && CapNum2 <= b && CapNum4 <= b) ||
					(CapNum1 <= b && CapNum3 <= b && CapNum4 <= b) ||
					(CapNum2 <= b && CapNum3 <= b && CapNum4 <= b))
				{
					this->rebotePokeball = 3;
				}
				else if ((CapNum1 <= b && CapNum2 <= b) ||(CapNum1 <= b && CapNum3 <= b) || (CapNum1 <= b && CapNum4 <= b) ||
					(CapNum2 <= b && CapNum3 <= b) || (CapNum2 <= b && CapNum4 <= b) || (CapNum3 <= b && CapNum4 <= b))
				{
					this->rebotePokeball = 2;
				}
				else if (CapNum1 <= b || CapNum2 <= b || CapNum3 <= b || CapNum4 <= b)
				{
					this->rebotePokeball = 1;
				}
				else this->rebotePokeball = 0;
			}
			break;
		case 2:
			int masPS;
			if (strcmp(listaObjetos[i]->getnombre(), "Poción") == 0) masPS = 30;
			if (strcmp(listaObjetos[i]->getnombre(), "Baya especial") == 0) masPS = 75;

			if (PokemonAUsar->getvidaActual() + masPS <= PokemonAUsar->getvidaMaxima())
				PokemonAUsar->setvidaActual(PokemonAUsar->getvidaActual() + masPS);
			else PokemonAUsar->setvidaActual(PokemonAUsar->getvidaMaxima());

			indobj = i; objetoUsado = true;
			break;
		}
		if (objetoUsado == true)
			i = listaObjetos.size() - 1;
	}
	listaObjetos.erase(listaObjetos.begin() + indobj);
}
void CPersonaje::usarObjeto(int pos, CPokemon *PokemonAUsar)
{
	CObjeto *item;
	
	for (int i = 0; i < listaObjetos.size(); i++)
	{
		if (i == pos)
			item = listaObjetos[i];
	}

	listaObjetos.erase(listaObjetos.begin() + pos);

	int indice;
	int PSmax, PSact, Rc, Rb;
	double a, b;
	switch (item->getefecto())
	{
	case 1:
		PSmax = PokemonAUsar->getSalud_PC();
		PSact = PokemonAUsar->getvidaActual();
		Rc = PokemonAUsar->getratiocaptura();
		if (strcmp(item->getnombre(), "Pokeball") == 0) Rb = 1;
		if (strcmp(item->getnombre(), "Ultraball") == 0) Rb = 2;

		a = ((3 * PSmax - 2 * PSact)*Rc*Rb) / (3 * PSmax);

		if (a >= 255)
		pokeAtrapados.push_back(PokemonAUsar);
		else
		{
			b = (pow(2, 16) - 1)*(pow( (a / (pow(2, 8) - 1)), 0.25 ));
			Random ^r = gcnew Random(DateTime::Now.Ticks);
			int CapNum1 = r->Next(0, 65536), CapNum2 = r->Next(0, 65536),
			CapNum3 = r->Next(0, 65536), CapNum4 = r->Next(0, 65536);
			if (CapNum1 <= b && CapNum2 <= b && CapNum3 <= b && CapNum4 <= b)
			{
				this->rebotePokeball = 3;
				pokeAtrapados.push_back(PokemonAUsar);
			}
			else if ((CapNum1 <= b && CapNum2 <= b && CapNum3 <= b) ||
				(CapNum1 <= b && CapNum2 <= b && CapNum4 <= b) ||
				(CapNum1 <= b && CapNum3 <= b && CapNum4 <= b) ||
				(CapNum2 <= b && CapNum3 <= b && CapNum4 <= b))
			{
				this->rebotePokeball = 3;
			}
			else if ((CapNum1 <= b && CapNum2 <= b) ||(CapNum1 <= b && CapNum3 <= b) || (CapNum1 <= b && CapNum4 <= b) ||
				(CapNum2 <= b && CapNum3 <= b) || (CapNum2 <= b && CapNum4 <= b) || (CapNum3 <= b && CapNum4 <= b))
			{
				this->rebotePokeball = 2;
			}
			else if (CapNum1 <= b || CapNum2 <= b || CapNum3 <= b || CapNum4 <= b)
			{
				this->rebotePokeball = 1;
			}
			else this->rebotePokeball = 0;
		}
		break;
	case 2:
		int masPS;
		if (strcmp(item->getnombre(), "Poción") == 0) masPS = 30;
		if (strcmp(item->getnombre(), "Baya especial") == 0) masPS = 75;

		if (PokemonAUsar->getvidaActual() + masPS <= PokemonAUsar->getvidaMaxima())
			PokemonAUsar->setvidaActual(PokemonAUsar->getvidaActual() + masPS);
		else PokemonAUsar->setvidaActual(PokemonAUsar->getvidaMaxima());

		break;
	}

	delete item;
}

void CPersonaje::subirPC(CPokemon *myPoke, int polvoestelar)
{
	int masPC = polvoestelar / 20;
	int salud1 = myPoke->getSalud_PC();
	myPoke->aumentarPC(masPC);
	int salud2 = myPoke->getSalud_PC();
	myPoke->setvidaActual(myPoke->getvidaActual() + (salud2 - salud1));
	nCaramelos--;
	nPolvoestelares -= polvoestelar;
	myPoke->setnPolvoEst_requiereMasPC(myPoke->getPC() * 3);
}
void CPersonaje::darCarameloparaEvol(CPokemon *myPoke, int caramelos)
{
	myPoke->setnCaram_consumidos(caramelos);
}

int CPersonaje::getrebotePKB(){ return rebotePokeball; }


void CPersonaje::evolucionar(int pospoke)
{
	CArrPokemon *arrmyPoke = new CArrPokemon();
	CPokemon *evol = arrmyPoke->getPoke(pokeAtrapados[pospoke]->getIndice() + 1);

	int pkPC = ((pokeAtrapados[pospoke]->getPC()) * 12) / 10;
	int polvoPC = (pokeAtrapados[pospoke]->getPC()) * 3;
	int aumento = (evol->getvidaMaxima() - pokeAtrapados[pospoke]->getvidaMaxima())*pkPC / 450;

	int largopoke = evol->getlargo() / 2;
	int altopoke = evol->getalto();

	this->nCaramelos -= pokeAtrapados[pospoke]->getnCaram_requiereEvol();
	pokeAtrapados[pospoke]->setPC(pkPC);
	pokeAtrapados[pospoke]->setnPolvoEst_requiereMasPC(polvoPC);
	pokeAtrapados[pospoke]->setnCaram_consumidos(0);

	pokeAtrapados[pospoke]->setIndice(evol->getIndice());
	pokeAtrapados[pospoke]->setnombre(evol->getnombre());
	pokeAtrapados[pospoke]->setx(340 - largopoke); pokeAtrapados[pospoke]->sety(200 - altopoke);
	pokeAtrapados[pospoke]->setlargo(evol->getlargo()); pokeAtrapados[pospoke]->setLargoEspalda(evol->getLargoEspalda());
	pokeAtrapados[pospoke]->setalto(evol->getalto()); pokeAtrapados[pospoke]->setAltoEspalda(evol->getAltoEspalda());
	pokeAtrapados[pospoke]->settipo1(evol->gettipo1()); pokeAtrapados[pospoke]->settipo2(evol->gettipo2());
	pokeAtrapados[pospoke]->setnCaram_requiereEvol(evol->getnCaram_requiereEvol());
	pokeAtrapados[pospoke]->setvidaMaxima(evol->getvidaMaxima());
	pokeAtrapados[pospoke]->setvidaActual(pokeAtrapados[pospoke]->getvidaActual() + aumento);
	pokeAtrapados[pospoke]->setataque(evol->getataque());
	pokeAtrapados[pospoke]->setdefensa(evol->getdefensa());
	pokeAtrapados[pospoke]->setvelocidad(evol->getvelocidad());
	pokeAtrapados[pospoke]->setpeso(evol->getpeso());
	pokeAtrapados[pospoke]->setaltura(evol->getaltura());
	pokeAtrapados[pospoke]->setdescripcion(evol->getdescripcion());
	pokeAtrapados[pospoke]->setratiocaptura(evol->getratiocaptura());
	pokeAtrapados[pospoke]->settieneEvolucion(evol->gettieneEvolucion());
	pokeAtrapados[pospoke]->settieneMega(evol->gettieneMega());
	pokeAtrapados[pospoke]->settieneMega2(evol->getTieneMega2());
	pokeAtrapados[pospoke]->setenCombate(evol->getEsInicial());
	
	delete arrmyPoke;
}

void CPersonaje::Megaevolucionar(CPokemon *myPoke, int XY)
{
	int indicePoke = myPoke->getIndice();
	switch (XY)
	{
	case 1:
		myPoke->setataque(myPoke->getataque() + aumentomegaevolX[indicePoke][0]);
		myPoke->setdefensa(myPoke->getdefensa() + aumentomegaevolX[indicePoke][1]);
		myPoke->setvelocidad(myPoke->getvelocidad() + aumentomegaevolX[indicePoke][2]);
		myPoke->setlargo(aumentomegaevolX[indicePoke][3]);
		myPoke->setalto(aumentomegaevolX[indicePoke][4]);
		myPoke->setLargoEspalda(aumentomegaevolX[indicePoke][5]);
		myPoke->setAltoEspalda(aumentomegaevolX[indicePoke][6]);
		myPoke->settipo1(cambioTipoMegaX[indicePoke][0]);
		myPoke->settipo2(cambioTipoMegaX[indicePoke][1]);
		break;
	case 2:
		myPoke->setataque(myPoke->getataque() + aumentomegaevolY[indicePoke][0]);
		myPoke->setdefensa(myPoke->getdefensa() + aumentomegaevolY[indicePoke][1]);
		myPoke->setvelocidad(myPoke->getvelocidad() + aumentomegaevolY[indicePoke][2]);
		myPoke->setlargo(aumentomegaevolY[indicePoke][3]);
		myPoke->setalto(aumentomegaevolY[indicePoke][4]);
		myPoke->setLargoEspalda(aumentomegaevolY[indicePoke][5]);
		myPoke->setAltoEspalda(aumentomegaevolY[indicePoke][6]);
		myPoke->settipo1(cambioTipoMegaY[indicePoke][0]);
		myPoke->settipo2(cambioTipoMegaY[indicePoke][1]);
		break;
	}
}


void CPersonaje::Mega_a_estado_normal(CPokemon *myPoke)
{
	int indicePoke = myPoke->getIndice();
	CArrPokemon *arrmyPoke = new CArrPokemon();

	myPoke->setataque(myPoke->getataque() - aumentomegaevolX[indicePoke][0]);
	myPoke->setdefensa(myPoke->getdefensa() - aumentomegaevolX[indicePoke][1]);
	myPoke->setvelocidad(myPoke->getvelocidad() - aumentomegaevolX[indicePoke][2]);
	myPoke->setlargo(arrmyPoke->getPoke(indicePoke)->getlargo());
	myPoke->setalto(arrmyPoke->getPoke(indicePoke)->getalto());
	myPoke->setLargoEspalda(arrmyPoke->getPoke(indicePoke)->getLargoEspalda());
	myPoke->setAltoEspalda(arrmyPoke->getPoke(indicePoke)->getAltoEspalda());
	myPoke->settipo1(arrmyPoke->getPoke(indicePoke)->gettipo1());
	myPoke->settipo2(arrmyPoke->getPoke(indicePoke)->gettipo2());

	delete arrmyPoke;
}
