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
	if (vida > 0){
		glPushMatrix();
		lin.Dibuja();
		limites.Dibuja();
		static bool flag;
		static float z = 0;

		if (z <= 0) flag = false;
		if (z >= 1.2) flag = true;

		if (flag)
			z -= 0.02;
		else
			z += 0.02;

		glTranslatef(posicion.x, posicion.y, 0.5 + z);
		glRotatef(angrot, 0, 0, 1);
		glPushMatrix();
		GLUquadricObj *obj = gluNewQuadric();
		gluCylinder(obj, 0.5, 0.7, 1.8, 20, 20);
		glTranslatef(0, 0, 1.8);
		gluDisk(obj, 0, 0.7, 20, 20);
		glutSolidSphere(0.35, 20, 20);

		glPopMatrix();
		glTranslatef(0.7, 0, 1);
		glColor3ub(200, 200, 200);
		glPushMatrix();
		GiraAnima();
		gluDisk(obj, 0, 0.5, 20, 20);
		glPopMatrix();
		gluDeleteQuadric(obj);
		glPopMatrix();
	}
	if (vida <= 0){
		Explota();
	}
}

void CaC::Anima(){}

bool CaC::atacar(int t){
	static int time = 700;
	time -= t;
	if (teveo && (time < 0)) {
		time = 700;
		return true;
	}
	else return false;
}