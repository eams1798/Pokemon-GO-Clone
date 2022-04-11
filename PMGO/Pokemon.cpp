#include "Pokemon.h"


CPokemon::CPokemon(int x, int y, int largo, int alto, int dx, int dy, int xSprite, int ySprite, int nframes,
	int indicePoke, int largoEspalda, int altoEspalda,
	char *nombre, char* tipo1, char *tipo2, int sexo,
	int nCaram_requiereEvol,
	int vidaMaxima, double ataque, double defensa, double velocidad, double peso, double altura,
	char *descripcionPokedex, int ratiocaptura,
	int tieneEvolucion, int tieneMega, int tieneMega2, bool enCombate, bool megaevoluionado,
	int esInicial, int espalda
	)
	:CFigura(x, y, largo, alto, dx, dy, xSprite, ySprite, nframes)
{
	
	Random ^r = gcnew Random(DateTime::Now.Ticks);
	this->indicePoke = indicePoke;

	this->largoEspalda = largoEspalda;
	this->altoEspalda = altoEspalda; 
	this->espalda = espalda;

	this->nombre = new char[30]; strcpy(this->nombre, nombre);
	this->mote = new char[30];  strcpy(this->mote, nombre);
	this->tipo1 = new char[30]; strcpy(this->tipo1, tipo1);
	this->tipo2 = new char[30]; strcpy(this->tipo2, tipo2);
	this->sexo = sexo; this->PC = 450;
	this->nPolvoEstconsumido = 0; this->nCaram_consumidos = 0;
	this->nPolvoEst_requiereMasPC = this->PC * 3;
	this->nCaram_requiereEvol = nCaram_requiereEvol;

	this->vidaMaxima = vidaMaxima;
	if (vidaMaxima<= 10)
	{
		this->vidaMaxima = 10;
	}
	this->peso = peso/10;
	this->vidaActual = (vidaMaxima*PC) / 450 + 10;
	this->ataque = ataque;
	this->defensa = defensa;
	this->velocidad = velocidad;
	this->altura = altura/100;

	this->descripcionPokedex = new char[270]; strcpy(this->descripcionPokedex, descripcionPokedex);
	this->ratiocaptura = ratiocaptura;

	this->tieneEvolucion = tieneEvolucion;
	this->tieneMega = tieneMega;
	this->tieneMega2 = tieneMega2;
	this->enCombate = enCombate;
	this->megaevoluionado = false;
	this->esInicial = esInicial;
}


CPokemon::~CPokemon()
{
}

void CPokemon::dibujar(Graphics ^g, Bitmap ^bmpPoke)
{
	Rectangle Origen = Rectangle(0, ySprite*alto, largo, alto);
	Rectangle Destino = Rectangle(x, y, largo, alto);
	g->DrawImage(bmpPoke, Destino, Origen, GraphicsUnit::Pixel);

	if (ySprite == nframes - 1)
	{
		ySprite = 0;
	}
	else ySprite++;
}

void CPokemon::dibujarEspalda(Graphics ^g, Bitmap ^bmpPoke)
{
	Rectangle Origen = Rectangle(0, ySprite*altoEspalda, largoEspalda, altoEspalda);
	Rectangle Destino = Rectangle(x, y, largoEspalda, altoEspalda);
	g->DrawImage(bmpPoke, Destino, Origen, GraphicsUnit::Pixel);
	if (ySprite == nframes - 1)
	{
		ySprite = 0;
	}
	else ySprite++;
}

void CPokemon::mover(Keys teclaPresionada){}

int CPokemon::getIndice(){ return indicePoke; }
char *CPokemon::getnombre(){ return nombre; }
char *CPokemon::getmote(){ return mote; }
char *CPokemon::gettipo1(){ return tipo1; }
char *CPokemon::gettipo2(){ return tipo2; }
int CPokemon::getsexo(){ return sexo; }
int CPokemon::getPC(){ return PC; }
int CPokemon::getnPolvoEstconsumido(){ return nPolvoEstconsumido; }
int CPokemon::getnPolvoEst_requiereMasPC(){ return nPolvoEst_requiereMasPC; }
int CPokemon::getnCaram_consumidos(){ return nCaram_consumidos; }
int CPokemon::getnCaram_requiereEvol(){ return nCaram_requiereEvol; }
int CPokemon::getvidaActual(){return vidaActual; }
int CPokemon::getvidaMaxima(){ return vidaMaxima; }
double CPokemon::getataque(){ return ataque; }
double CPokemon::getdefensa(){ return defensa; }
double CPokemon::getvelocidad(){ return velocidad; }
double CPokemon::getpeso(){ return peso; }
double CPokemon::getaltura(){ return altura; }
int CPokemon::getratiocaptura(){ return ratiocaptura; }
int CPokemon::gettieneMega(){ return tieneMega; }
int CPokemon::getTieneMega2(){ return tieneMega2; }
bool CPokemon::getenCombate(){ return enCombate; }
bool CPokemon::getmegaevoluionado(){ return megaevoluionado; }

CAtaque *CPokemon::getataquePrincipal(){ return this->ataquePrincipal; }
CAtaque *CPokemon::getataqueDefinitivo(){ return this->ataqueDefinitivo; }
vector<CAtaque*> CPokemon::getataquesAprendidos(){ return this->ataquesAprendidos; }
void CPokemon::setataquesaprendidos(vector<CAtaque*> aprender)
{
	this->ataquesAprendidos = aprender;
}

int CPokemon::getSalud_PC()
{
	int saludpc = (vidaMaxima*PC) / 450 + 10;
	if (nombre == "MissingNo.") saludpc = 15;
	return saludpc;
}
int CPokemon::getAtaque_PC()
{
	int ataquepc = (ataque*PC) / 450 + 10;
	if (nombre == "MissingNo.") ataquepc = 15;
	return ataquepc;
}
int CPokemon::getDefensa_PC()
{
	int defensapc = (defensa*PC) / 450 + 10;
	if (nombre == "MissingNo.") defensapc = 15;
	return defensapc;
}
int CPokemon::getVelocidad_PC()
{
	int velpc = (velocidad*PC) / 450 + 10;
	if (nombre == "MissingNo.") velpc = 15;
	return velpc;
}
double CPokemon::getnumeroIVs(int salud, double ataque, double defensa, double velocidad)
{
	double PKpuntos = vidaMaxima + this->ataque + this->defensa + this->velocidad;
	double sumaPerfecta = salud + ataque + defensa + velocidad;
	return (PKpuntos * 100) / sumaPerfecta;
}

int CPokemon::getEsInicial(){ return esInicial; }

void CPokemon::setIndice(int i){ this->indicePoke = i; }
void CPokemon::setnombre(char *nombre){ this->nombre = new char[30]; strcpy(this->nombre, nombre); }
void CPokemon::setmote(char *mote){ this->mote = new char[30]; strcpy(this->mote, mote); }
void CPokemon::settipo1(char *tipo1){ this->tipo1 = new char[30]; strcpy(this->tipo1, tipo1); }
void CPokemon::settipo2(char *tipo2){ this->tipo2 = new char[30]; strcpy(this->tipo2, tipo2); }
void CPokemon::setsexo(int sexo){ this->sexo = sexo; }
void CPokemon::setPC(int PC){ this->PC = PC; }
void CPokemon::setnPolvoEstconsumido(int nPolvoEstconsumido)
{ this->nPolvoEstconsumido += nPolvoEstconsumido; }

void CPokemon::setnPolvoEst_requiereMasPC(int nPolvoEst_requiereMasPC)
{ this->nPolvoEst_requiereMasPC = nPolvoEst_requiereMasPC; }

void CPokemon::setnCaram_consumidos(int nCaram_consumidos){ this->nCaram_consumidos += nCaram_consumidos; }
void CPokemon::setnCaram_requiereEvol(int nCaram_requiereEvol)
{ this->nCaram_requiereEvol = nCaram_requiereEvol; }

void CPokemon::setvidaActual(int vidaActual){ this->vidaActual = vidaActual; }
void CPokemon::setvidaMaxima(int vidaMaxima){ this->vidaMaxima = vidaMaxima; }
void CPokemon::setataque(double ataque){ this->ataque = ataque; }
void CPokemon::setdefensa(double defensa){ this->defensa = defensa; }
void CPokemon::setvelocidad(double velocidad){ this->velocidad = velocidad; }
void CPokemon::setpeso(double peso){ this->peso = peso; }
void CPokemon::setaltura(double altura){ this->altura = altura; }
void CPokemon::settieneMega(int tieneMega){ this->tieneMega = tieneMega; }
void CPokemon::settieneMega2(int tieneMega2){ this->tieneMega2 = tieneMega2; }
void CPokemon::setenCombate(bool enCombate){ this->enCombate = enCombate; }
void CPokemon::setmegaevoluionado(bool megaevoluionado){ this->megaevoluionado = megaevoluionado; }
void CPokemon::setesinicial(int esinicial){ this->esInicial = esinicial; }

void CPokemon::setataquePrincipal(char* nombreataque)
{
	this->ataquePrincipal = listaataques->getAtaque(nombreataque);
}
void CPokemon::setataquePrincipal(CAtaque* AtaquePR)
{
	this->ataquePrincipal = AtaquePR;
}

void CPokemon::setataqueDefinitivo(char* nombreataque)
{
	this->ataqueDefinitivo = listaataques->getAtaque(nombreataque);
}
void CPokemon::setataqueDefinitivo(CAtaque* AtaqueDEF)
{
	this->ataqueDefinitivo = AtaqueDEF;
}

void CPokemon::aprenderAtaque(char* nombreataque)
{
	ataquesAprendidos.push_back(listaataques->getAtaque(nombreataque));
}
void CPokemon::aprenderAtaque(CAtaque* nuevo)
{
	ataquesAprendidos.push_back(nuevo);
}
void CPokemon::olvidarAtaque(char* nombreAtaque)
{
	for (int i = 0; i < ataquesAprendidos.size(); i++)
	{
		if (ataquesAprendidos[i]->getnombre() == nombreAtaque)
			ataquesAprendidos.erase(ataquesAprendidos.begin() + i);
	}
}
void CPokemon::olvidarAtaque(CAtaque* nuevo)
{
	for (int i = 0; i < ataquesAprendidos.size(); i++)
	{
		if (ataquesAprendidos[i] == nuevo)
			ataquesAprendidos.erase(ataquesAprendidos.begin() + i);
	}
}

void CPokemon::aumentarPC(int suma)
{
	this->PC += suma;
}


int CPokemon::gettieneEvolucion(){ return tieneEvolucion; }
void CPokemon::settieneEvolucion(int tieneEvolucion){ this->tieneEvolucion = tieneEvolucion; }
void CPokemon::setratiocaptura(int ratioC){}

int CPokemon::getdeEspalda(){ return espalda; }
void CPokemon::setdeEspalda(int espalda){ this->espalda = espalda; }

int CPokemon::getLargoEspalda(){ return largoEspalda; }
int CPokemon::getAltoEspalda(){ return altoEspalda; }
void CPokemon::setLargoEspalda(int largoEspalda){ this->largoEspalda = largoEspalda; }
void CPokemon::setAltoEspalda(int altoEspalda){ this->altoEspalda = altoEspalda; }

char *CPokemon::getdescripcion(){ return descripcionPokedex; }
void CPokemon::setdescripcion(char *descripcion)
{
	this->descripcionPokedex = new char[250]; strcpy(this->descripcionPokedex, descripcionPokedex);
}

CAtaque *CPokemon::getAtaqueAprendido(int posicion)
{
	return ataquesAprendidos[posicion];
}