#include "ArrAtaque.h"

char *nAtaque[180] =
{
	"Ala de acero", "Cola de hierro", "Garra de metal", "Pu�o meteoro", "Girobola", "Bomba Magneto", "Cabezazo met�lico", "Rueda doble", "Foco resplandor", "Deseo oculto",
	"Surf", "Chorro de agua", "Rayo burbuja", "Hidroca��n", "Martillo tenaza", "Pulso de agua", "Acua jet", "Cascada", "Shuriken de agua", "Pulso primigenio",
	"Picadura", "Aguij�n letal", "Rodillo de p�as", "Doble rayo", "Zumbido", "Pin misil", "Corte furia", "Viento plateado", "Tijera X", "Megacuerno",
	"Cicl�n", "Carga drag�n", "Aliento drag�n", "Cola drag�n", "Garra drag�n", "Pulso drag�n", "Enfado", "Corte del vac�o", "Cometa drag�n", "Distorsi�n",
	"Electroca��n", "Electrobola", "Impactrueno", "Colmillo el�ctrico", "Pu�o trueno", "Carga salvaje", "Telara�a el�ctrica", "Tacleada de voltios", "Rayo fusi�n", "Ataque fulgor",
	"Bola sombra", "Tinieblas", "Garra sombra", "Golpe fantasma", "Viento aciago", "Infortunio", "Pu�o sombra", "Leng�etazo", "Sombra vil", "Golpe sombr�o",
	"Lanzallamas", "Colmillo �gneo", "Nitrocarga", "Patada de fuego", "Fuego m�stico", "Llamarada", "Llama azul", "Llama fusi�n", "Anillo �gneo", "V de fuego",
	"Viento m�gico", "Voz cautivadora", "Metr�nomo", "Beso drenaje", "Brillo m�gico", "Fuerza lunar", "Caranto�a", "Luz de la luna", "Geocontrol", "Luz aniquiladora",
	"Rayo de hielo", "Colmillo de hielo", "Pu�o helado", "Rayo aurora", "Bola de nieve", "Viento helado", "Rayo g�lido", "Congelar", "Ventisca", "Llama g�lida",
	"Golpe roca", "Golpe din�mico", "Plancha voladora", "Espada Sagrada", "Movimiento s�smico", "Golpe cruzado", "Fuerza bruta", "Patada baja", "Combate cercano", "Aura esfera",
	"Tacleada", "Viento cortante", "Hipercolmillo", "Golpe", "Fuerza", "Sentencia", "Velocidad extrema", "Megapatada", "Hiperrayo", "Giga impacto",
	"Tormenta de hojas", "Danza de p�talos", "L�tigo cepa", "Bala semilla", "Bola de energ�a", "Bengala semilla", "Gigadrenado", "Latigazo", "Rayo solar", "Planta feroz",
	"Psicorayo", "Confusi�n", "Cabezazo zen", "Corte ps�quico", "Fuerza ps�quica", "Paso dimensional", "Choque ps�quico", "Sincrorruido", "Onda mental", "Impulso ps�quico",
	"Pedrada", "Desenrollar", "Anitia�reo", "Avalancha de rocas", "Lanzarrocas", "Joya de luz", "Poder del pasado", "Roca afilada", "Tormenta de diamantes", "Romeperrocas",
	"Mordisco", "Triturar", "Vendetta", "Golpe bajo", "Finta", "Juego sucio", "Cuchillada nocturna", "Pulso de oscuridad", "Buena baza", "Furia hiperespacial",
	"Magintud", "Excavar", "Hueso bumerang", "Hueso veloz", "Bomba de fango", "Mil flechas", "Fuerza tel�rica", "Terremoto", "Tierra viva", "Filo de abismo",
	"�cido", "Carga t�xica", "Golpe venenoso", "Residuos", "Onda t�xica", "Cola veneno", "Colmillo veneno", "Veneno X", "Bomba de lodo t�xico", "Lanza mugre",
	"Ataque de alas", "Acrobacia", "Corte a�reo", "Pico taladro", "As a�reo", "R�faga a�rea", "Hurac�n", "Ave brava", "Ascenso drag�n", "Ataque celestial"
};

char *nTipo[180] =
{
	"Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero",
	"Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua",
	"Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho",
	"Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n", "Drag�n",
	"El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico", "El�ctrico",
	"Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma",
	"Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego",
	"Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada",
	"Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo",
	"Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha",
	"Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal",
	"Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta",
	"Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico", "Ps�quico",
	"Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca",
	"Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro",
	"Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra",
	"Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno",
	"Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador"
};

int nDa�o[180] = 
{
	70, 100, 50, 90, 60, 60, 80, 50, 80, 140, 
	90, 50, 65, 150, 100, 60, 40, 80, 70, 110,
	60, 30, 65, 75, 90, 25, 75, 60, 80, 120,
	45, 100, 60, 60, 80, 85, 120, 100, 130, 150,
	120, 85, 95, 65, 75, 90, 55, 120, 100, 130,
	80, 60, 70, 90, 60, 65, 60, 50, 40, 120,
	90, 65, 50, 85, 65, 110, 130, 100, 150, 180,
	40, 40, 0, 50, 80, 95, 90, 0, 0, 140,
	90, 65, 75, 65, 100, 55, 140, 70, 110, 140,
	40, 100, 80, 90, 55, 100, 120, 65, 120, 150,
	45, 80, 80, 120, 80, 100, 100, 120, 150, 150,
	65, 120, 55, 40, 90, 120, 80, 120, 120, 150,
	65, 50, 80, 70, 90, 80, 80, 120, 100, 140,
	35, 100, 50, 75, 50, 80, 60, 100, 100, 150,
	60, 80, 50, 80, 60, 95, 70, 80, 60, 100,
	70, 80, 50, 35, 65, 90, 90, 100, 90, 120,
	40, 65, 80, 65, 95, 50, 50, 70, 90, 120,
	60, 55, 75, 80, 60, 100, 110, 120, 120, 140
};

CArrAtaque::CArrAtaque()
{
	CAtaque *nuevo;
	for (int i = 0; i < 180; i++)
	{
		nuevo = new CAtaque(nAtaque[i], nTipo[i], nDa�o[i]);
		vecAtq.push_back(nuevo);
	}
}



CArrAtaque::~CArrAtaque()
{
	vecAtq.clear();
}


vector <CAtaque*> CArrAtaque::getVecA(){ return vecAtq; }

CAtaque *CArrAtaque::getAtaque(int indice){ return vecAtq[indice]; }
CAtaque *CArrAtaque::getAtaque(char *nombreAtaque)
{
	CAtaque *ataque;
	for (int i = 0; i < vecAtq.size(); i++)
	{
		if (strcmp(vecAtq[i]->getnombre(), nombreAtaque) == 0)
		{
			ataque = vecAtq[i];
		}
	}
	return ataque;
}

int CArrAtaque::getsize(){ return vecAtq.size(); }