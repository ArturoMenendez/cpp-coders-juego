#include "Codigo.h"
#include "bitmap.h"


Codigo::Codigo(Vector3D pos) : Objeto(pos, CODIGO, 1)
{
}


Codigo::~Codigo()
{
}

void Codigo::Dibuja(){
	static bitmap imagen("cpp.bmp");
	static 	GLUquadricObj *mon1 = gluNewQuadric();

	
	glPushMatrix();
	glDisable(GL_LIGHTING);	
	glColor3ub(255, 255, 255);
	imagen.usarTextura();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.6, -0.6, -0.5);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.6, -0.6, 0.5);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.6, 0.6, 0.5);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.6, 0.6, -0.5);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


