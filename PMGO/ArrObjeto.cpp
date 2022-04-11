#include "ArrObjeto.h"


CArrObjeto::CArrObjeto()
{
	CObjeto *obj1 = new CObjeto("Pokeball", 1); vecObj.push_back(obj1);
	CObjeto *obj2 = new CObjeto("Ultraball", 1); vecObj.push_back(obj2);
	CObjeto *obj3 = new CObjeto("Poción", 2); vecObj.push_back(obj3);
	CObjeto *obj4 = new CObjeto("Baya especial", 2); vecObj.push_back(obj4);
	CObjeto *obj5 = new CObjeto("Megapiedra X", 3); vecObj.push_back(obj5);
	CObjeto *obj6 = new CObjeto("Megapiedra Y", 3); vecObj.push_back(obj6);
}


CArrObjeto::~CArrObjeto()
{
}

CObjeto *CArrObjeto::getObj(char *nombreObj)
{
	CObjeto *v;
	for (int i = 0; i < vecObj.size(); i++)
	{
		if (strcmp(vecObj[i]->getnombre(), nombreObj) == 0)
		{
			v = vecObj[i];
		}
	}
	return v;
}

CObjeto *CArrObjeto::getObj(int indice)
{
	return vecObj[indice];
}