#pragma once
#include "Objeto.h"
#include <vector>
using namespace std;
class CArrObjeto
{
protected:
	vector<CObjeto*> vecObj;
public:
	CArrObjeto();
	~CArrObjeto();

	CObjeto *getObj(char *nombreObj);
	CObjeto *getObj(int indice);
};

