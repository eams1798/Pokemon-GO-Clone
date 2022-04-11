#include "ArrPokemon.h"

char *nombrePoke[13] =
{
	"MissingNo.", //0
	"Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise", //1-9
	"Pichu", "Pikachu", "Raichu",
};

int listaratiocap[13] =
{
	156, //0
	45, 45, 45, 45, 45, 45, 45, 45, 45, //1-9
	190, 190, 75,
};

int listaIniciales[13] =
{
	0, //0
	1, 0, 0, 1, 0, 0, 1, 0, 0, //1-9
	1, 0, 0,
};

char *listaTipo1[13] =
{
	"Normal", //0
	"Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", //1-9
	"Eléctrico", "Eléctrico", "Eléctrico",
};


char *listaTipo2[13] =
{
	"", //0
	"Veneno", "Veneno", "Veneno", "", "", "Volador", "", "", "", //1-9
	"", "", "",
};

double listaSalud[13] =
{
	15, //0
	45, 60, 80, 39, 58, 78, 44, 59, 79, //1-9
	20, 35, 60,
};

double listaAtaque[13] =
{
	15, //0
	57, 71, 91, 56, 72, 96.5, 49, 64, 84, //1-9
	37.5, 52.5, 90,
};

double listaDefensa[13] =
{
	15, //0
	57, 71.5, 91.5, 46.5, 61.5, 81.5, 64.5, 80, 102.5, //1-9
	25, 45, 67.5,
};

double listaVelocidad[13] =
{
	15, //0
	45, 60, 80, 65, 80, 100, 43, 58, 78, //1-9
	60, 90, 110,
};

int listaPeso[13] =
{
	1, //0
	69, 130, 1000, 85, 190, 905, 90, 225, 855, //1-9
	20, 60, 300,
};

int listaAltura[13] =
{
	10, //0
	70, 100, 200, 60, 110, 170, 50, 100, 160, //1-9
	30, 40, 80,
	
};

int listaTieneMega[13] =
{
	0, //0
	0, 0, 1, 0, 0, 1, 0, 0, 1, //1-9
	0, 0, 0,
};

int listaTieneMega2[13] =
{
	0, //0
	0, 0, 0, 0, 0, 1, 0, 0, 0, //1-9
	0, 0, 0,
};

int listaSexo[13] =
{
	2, //0
	0, 0, 0, 0, 0, 0, 0, 0, 0, //1-9
	0, 0, 0,
};

int carameloEvol[13] =
{
	0, //0
	25, 50, 0, 25, 50, 0, 25, 50, 0, //1-9
	25, 50, 0,
};

int listaSigienteEvol[13] =
{
	0, //0
	1, 1, 0, 1, 1, 0, 1, 1, 0, //1-9
	1, 1, 0,
};

int dimensionesAnchoAlto[13][2] =
{
	{ 43, 100 }, //0
	{ 45, 49 }, { 84, 66 }, { 106, 77 }, { 48, 57 }, { 60, 70 }, { 133, 140 }, { 53, 54 }, { 56, 73 }, { 88, 83 }, //1-9
	{ 51, 52 }, { 60, 60 }, { 69, 103 },
};

int dimensionesAnchoAltoEspalda[13][2] =
{
	{ 43, 100 }, //0
	{ 52, 50 }, { 76, 68 }, { 95, 78 }, { 64, 57 }, { 78, 75 }, { 172, 166 }, { 62, 53 }, { 70, 72 }, { 97, 83 }, //1-9
	{ 42, 52 }, { 65, 61 }, { 91, 113 },
};

char *listadescripcion[13] =
{
	"\nERROR_TYPE_NUMBERPKDEX_SYSTEM_FILE_DOESNT_READ.xdd",
	"\nA Bulbasaur es fácil verle echándose una \nsiesta al sol. La semilla que tiene en el lomo \nva creciendo cada vez más a medida que \nabsorbe los rayos del sol.",
	"\nEste Pokémon lleva un bulbo en el lomo y, \npara poder con su peso, tiene unas patas y un \ntronco gruesos y fuertes. Si empieza a \npasar más tiempo al sol, será porque el bulbo \nestá a punto de hacerse una flor grande.",
	"\nVenusaur tiene una flor enorme en el lomo \nque, según parece, adquiere unos colores muy \nvivos si está bien nutrido y le da mucho el \nsol. El aroma delicado de la flor tiene un efecto \nrelajante en el ánimo de las personas.",
	"\nLa llama que tiene en la punta de la cola \narde según sus sentimientos. Llamea \nlevemente cuando está alegre y arde \nvigorosamente cuando está enfadado.",
	"\nCharmeleon no tiene reparo en acabar con su \nrival usando las afiladas garras que tiene. \nSi su enemigo es fuerte, se vuelve agresivo, \ny la llama que tiene en el extremo de \nla cola empieza a arder con mayor intensidad \ntornándose azulada.",
	"\nCharizard se dedica a volar por los cielos \nen busca de oponentes fuertes. Echa fuego por \nla boca y es capaz de derretir cualquier cosa. \nNo obstante, si su rival es más débil \nque él, no usará este ataque.",
	"\nEl caparazón de Squirtle no le sirve de \nprotección únicamente. Su forma redondeada y \nlas hendiduras que tiene le ayudan a deslizarse \nen el agua y le permiten nadar a gran \nvelocidad.",
	"\nTiene una cola larga y cubierta de un pelo \nabundante y grueso que se torna más oscuro a \nmedida que crece. Los arañazos que tiene en \nel caparazón dan fe de lo buen guerrero \nque es.",
	"\nBlastoise lanza chorros de agua con gran \nprecisión por los tubos que le salen del caparazón \nque tiene en la espalda. Puede disparar \nchorros de agua con tanta puntería que no \nfallaría al tirar contra una lata pequeña a 50 m.",
	"\nA Pichu le resulta más fácil cargarse de \nelectricidad en días de nubarrones o cuando \nsopla un aire muy seco. Es posible oír la \nelectricidad estática que emana de este Pokémon.",
	"\nCada vez que un Pikachu se encuentra con \nalgo nuevo, le lanza una descarga eléctrica. \nCuando se ve alguna baya chamuscada, es \nmuy probable que sea obra de un Pikachu, ya \nque a veces no controlan la intensidad de la \ndescarga.",
	"\nSi las bolsas de los mofletes se le cargan \ndemasiado, Raichu planta la cola en el suelo para \nliberar electricidad. Es común encontrar \nzonas chamuscadas cerca de la madriguera \nde este Pokémon."
};

CArrPokemon::CArrPokemon()
{
	CPokemon *nuevo;
	for (int i = 0; i < 13; i++)
	{
		nuevo = new CPokemon(0, 0, dimensionesAnchoAlto[i][0], dimensionesAnchoAlto[i][1], 0, 0, 0, 0, 20,
			i, dimensionesAnchoAltoEspalda[i][0], dimensionesAnchoAltoEspalda[i][1],
			nombrePoke[i], listaTipo1[i], listaTipo2[i],
			listaSexo[i], carameloEvol[i],
			listaSalud[i], listaAtaque[i], listaDefensa[i], listaVelocidad[i],
			listaPeso[i], listaAltura[i],
			listadescripcion[i], listaratiocap[i],
			listaSigienteEvol[i], listaTieneMega[i], listaTieneMega2[i],0, 0,
			listaIniciales[i], 5);
		arrPoke.push_back(nuevo);
	}
}


CArrPokemon::~CArrPokemon()
{
}


vector<CPokemon*> CArrPokemon::getVecPk(){ return arrPoke; }

CPokemon *CArrPokemon::getPoke(int indice){ return arrPoke[indice]; }
CPokemon *CArrPokemon::getPoke(char *nombrePoke)
{
	CPokemon *newPoke;
	for (int i = 0; i < arrPoke.size(); i++)
	{
		if (strcmp(arrPoke[i]->getnombre(), nombrePoke) == 0)
		{
			newPoke = arrPoke[i];
		}
	}
	return newPoke;
}

int CArrPokemon::getsize(){ return arrPoke.size(); }