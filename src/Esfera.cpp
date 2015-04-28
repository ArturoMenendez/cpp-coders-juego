#include "Esfera.h"
#include "glut.h"

Esfera::Esfera(void)
{
	radio=1;
	posicion.x=posicion.y=posicion.z=3;
	g=b=200;
	r=0;
}


Esfera::~Esfera(void)
{
}

void Esfera::Dibuja(){
	glColor3f(r,g,b);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}

void Esfera::Mouse(int button, int state, int x, int y){  //ESTE METODO CREA UNA ESFERA EN EL PUNTO EN EL QUE SE 
	switch (button){                                        //HAGA CLIC, Y CREA OTRA CUANDO SE VUELVA A HACER CLIC
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			 posicion.x = ((float)x + 400) / 400;
			 posicion.y = ((float)y - 300) / -300;
			 posicion.z = 0;
		}
	}


}
