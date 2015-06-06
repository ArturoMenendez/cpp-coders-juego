#include "Objeto.h"


Objeto::Objeto(Vector3D posicion)
{
	this->posicion = posicion;
	limites.posicion = posicion;
}


Objeto::~Objeto()
{
}


void Objeto::Anima(){
		glRotatef(giraanima, 0, 0, -1);
		giraanima += 2;
}

CrashBox Objeto::getCrashBox(){
	return limites;
}