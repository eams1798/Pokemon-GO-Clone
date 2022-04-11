#include "ArrAtaque.h"

char *nAtaque[180] =
{
	"Ala de acero", "Cola de hierro", "Garra de metal", "Puño meteoro", "Girobola", "Bomba Magneto", "Cabezazo metálico", "Rueda doble", "Foco resplandor", "Deseo oculto",
	"Surf", "Chorro de agua", "Rayo burbuja", "Hidrocañón", "Martillo tenaza", "Pulso de agua", "Acua jet", "Cascada", "Shuriken de agua", "Pulso primigenio",
	"Picadura", "Aguijón letal", "Rodillo de púas", "Doble rayo", "Zumbido", "Pin misil", "Corte furia", "Viento plateado", "Tijera X", "Megacuerno",
	"Ciclón", "Carga dragón", "Aliento dragón", "Cola dragón", "Garra dragón", "Pulso dragón", "Enfado", "Corte del vacío", "Cometa dragón", "Distorsión",
	"Electrocañón", "Electrobola", "Impactrueno", "Colmillo eléctrico", "Puño trueno", "Carga salvaje", "Telaraña eléctrica", "Tacleada de voltios", "Rayo fusión", "Ataque fulgor",
	"Bola sombra", "Tinieblas", "Garra sombra", "Golpe fantasma", "Viento aciago", "Infortunio", "Puño sombra", "Lengüetazo", "Sombra vil", "Golpe sombrío",
	"Lanzallamas", "Colmillo ígneo", "Nitrocarga", "Patada de fuego", "Fuego místico", "Llamarada", "Llama azul", "Llama fusión", "Anillo ígneo", "V de fuego",
	"Viento mágico", "Voz cautivadora", "Metrónomo", "Beso drenaje", "Brillo mágico", "Fuerza lunar", "Carantoña", "Luz de la luna", "Geocontrol", "Luz aniquiladora",
	"Rayo de hielo", "Colmillo de hielo", "Puño helado", "Rayo aurora", "Bola de nieve", "Viento helado", "Rayo gélido", "Congelar", "Ventisca", "Llama gélida",
	"Golpe roca", "Golpe dinámico", "Plancha voladora", "Espada Sagrada", "Movimiento sísmico", "Golpe cruzado", "Fuerza bruta", "Patada baja", "Combate cercano", "Aura esfera",
	"Tacleada", "Viento cortante", "Hipercolmillo", "Golpe", "Fuerza", "Sentencia", "Velocidad extrema", "Megapatada", "Hiperrayo", "Giga impacto",
	"Tormenta de hojas", "Danza de pétalos", "Látigo cepa", "Bala semilla", "Bola de energía", "Bengala semilla", "Gigadrenado", "Latigazo", "Rayo solar", "Planta feroz",
	"Psicorayo", "Confusión", "Cabezazo zen", "Corte psíquico", "Fuerza psíquica", "Paso dimensional", "Choque psíquico", "Sincrorruido", "Onda mental", "Impulso psíquico",
	"Pedrada", "Desenrollar", "Anitiaéreo", "Avalancha de rocas", "Lanzarrocas", "Joya de luz", "Poder del pasado", "Roca afilada", "Tormenta de diamantes", "Romeperrocas",
	"Mordisco", "Triturar", "Vendetta", "Golpe bajo", "Finta", "Juego sucio", "Cuchillada nocturna", "Pulso de oscuridad", "Buena baza", "Furia hiperespacial",
	"Magintud", "Excavar", "Hueso bumerang", "Hueso veloz", "Bomba de fango", "Mil flechas", "Fuerza telúrica", "Terremoto", "Tierra viva", "Filo de abismo",
	"Ácido", "Carga tóxica", "Golpe venenoso", "Residuos", "Onda tóxica", "Cola veneno", "Colmillo veneno", "Veneno X", "Bomba de lodo tóxico", "Lanza mugre",
	"Ataque de alas", "Acrobacia", "Corte aéreo", "Pico taladro", "As aéreo", "Ráfaga aérea", "Huracán", "Ave brava", "Ascenso dragón", "Ataque celestial"
};

char *nTipo[180] =
{
	"Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero", "Acero",
	"Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua",
	"Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho",
	"Dragón", "Dragón", "Dragón", "Dragón", "Dragón", "Dragón", "Dragón", "Dragón", "Dragón", "Dragón",
	"Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico", "Eléctrico",
	"Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Fantasma",
	"Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego", "Fuego",
	"Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada", "Hada",
	"Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo",
	"Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha", "Lucha",
	"Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal",
	"Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta", "Planta",
	"Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico", "Psíquico",
	"Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca", "Roca",
	"Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Siniestro",
	"Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra", "Tierra",
	"Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno",
	"Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador", "Volador"
};

int nDaño[180] = 
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
		nuevo = new CAtaque(nAtaque[i], nTipo[i], nDaño[i]);
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