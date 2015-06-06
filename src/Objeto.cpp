#include "Objeto.h"

Objeto::Objeto() 
{
}

Objeto::Objeto(Vector3D pos) : posicion(pos), limites(pos, 0.5f), aux(0), tipo(CODIGO)
{
}

Objeto::~Objeto()
{
}

void Objeto::Anima(){
	glRotatef(aux, 0, 0, -1);
	if (aux<180) glTranslatef(0, 0, +0.1f);
	else glTranslatef(0, 0, -0.1f);
	aux += 2;
	if (aux >= 360) aux = 0;
}

CrashBox Objeto::getCrashBox(){
	return limites;
}