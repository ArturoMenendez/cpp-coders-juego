#include "CaC.h"


CaC::CaC() : Enemigo()
{
}

CaC::CaC(Vector3D pos, int id) : Enemigo(pos, id)
{
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