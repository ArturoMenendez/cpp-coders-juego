#include "CaC.h"


CaC::CaC()
{
}


CaC::CaC(Vector3D posicion)
{
	this->posicion = posicion;
}

CaC::~CaC()
{
}

void CaC::Dibuja()
{

	
	glTranslatef(posicion.x, posicion.y, 1);
	////////////////////
	glutSolidTeapot(1);
	////////////////////
	glTranslatef(-posicion.x, -posicion.y, -1);
	lin.Dibuja();
	limites.Dibuja();
}