#include "glut.h"
#include "Jugador.h"
#include "bitmap.h"

	float vistax = 0, vistay = 0, zoom = 50;
	float theta = 0;

	//los callback, funciones que seran llamadas automaticamente por la glut
	//cuando sucedan eventos
	//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
	void OnDraw(void); //esta funcion sera llamada para dibujar
	void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
	void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
	void OnMouseDown(int button, int state, int x, int y);//se llama cuando se pulsa o se suelta un boton del raton
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);

	Jugador j1; //esfera cian que sigue al raton si esta pulsado


	int main(int argc, char* argv[])
	{
		//Inicializar el gestor de ventanas GLUT
		//y crear la ventana
		glutInit(&argc, argv);
		glutInitWindowPosition(250,100);
		glutInitWindowSize(800, 600);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutCreateWindow("C++ Coders: Raiders of the Lost Class");

		//habilitar luces y definir perspectiva
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

		//Registrar los callbacks
		glutDisplayFunc(OnDraw);
		glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
		glutKeyboardFunc(OnKeyboardDown);
		glutMouseFunc(OnMouseDown);
		glutMotionFunc(OnMotion);
		glutPassiveMotionFunc(OnPassiveMotion);
		//pasarle el control a GLUT,que llamara a los callbacks
		glutMainLoop();

		return 0;
	}

	void OnDraw(){
		static float antorcha[4] = { -16.0, 11.0, 2.0, 1 };
		static bitmap suelo("suelo.bmp");
		static bitmap bola("bola.bmp");

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(vistax, vistay, zoom, 0.0, 0, 0.0, 0.0, 1.0, 0.0);

		glDisable(GL_LIGHTING);
		suelo.usarTextura();
		glBegin(GL_QUADS);	//SUELO
		glColor3ub(0, 0, 100);
		glTexCoord2f(3.0, 2.0);
		glVertex3f(-20.0, 15.0, 0.0);
		glTexCoord2f(0.0, 2.0);
		glVertex3f(20.0, 15.0, 0.0);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(20.0, -15.0, 0.0);
		glTexCoord2f(3.0, 0.0);
		glVertex3f(-20.0, -15.0, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glBegin(GL_QUADS);	//PARED SUPERIOR
		glColor3ub(255, 0, 0);
		glNormal3f(0, 0, 0);//normales para iluminacion
		glVertex3f(-20.0, 15.0, 0.0);
		glNormal3f(0, 0, 10);
		glVertex3f(-20.0, 15.0, 10.0);
		glVertex3f(20.0, 15.0, 10.0);
		glNormal3f(0, 0, 0);
		glVertex3f(20.0, 15.0, 0.0);
		glEnd();
		glBegin(GL_QUADS);	//PARED DERECHA
		glColor3ub(0, 255, 0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(20.0, 15.0, 10.0);
		glVertex3f(20.0, -15.0, 10.0);
		glVertex3f(20.0, -15.0, 0.0);
		glEnd();
		glBegin(GL_QUADS);	//PARED INFERIOR
		glColor3ub(255, 0, 0);
		glVertex3f(20.0, -15.0, 0.0);
		glVertex3f(20.0, -15.0, 10.0);
		glVertex3f(-20.0, -15.0, 10.0);
		glVertex3f(-20.0, -15.0, 0.0);
		glEnd();
		glBegin(GL_QUADS);	//PARED IZQUIERDA
		glColor3ub(0, 255, 0);
		glVertex3f(-20.0, -15.0, 0.0);
		glVertex3f(-20.0, -15.0, 10.0);
		glVertex3f(-20.0, 15.0, 10.0);
		glVertex3f(-20.0, 15.0, 0.0);
		glEnd();
		glTranslatef(-16.0, 11.0, 1.0);
		glColor3ub(255, 255, 0);
		glutSolidCube(2.0);
		glTranslatef(16.0, -11.0, -1.0);
		glTranslatef(16.0, 11.0, 1.0);
		glColor3ub(255, 255, 0);
		glutSolidCube(2.0);
		glTranslatef(-16.0, -11.0, -1.0);
		glColor3ub(255, 255, 255);


		glTranslatef(0.0, 0.0, 5.0);
		glRotatef(23, 0, 1, 0);
		glRotatef(theta, 0, 0, 1);
		//////////////////////////////
		bola.usarTextura();
		glColor3ub(255, 255, 255);
		GLUquadricObj *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);
		gluSphere(qobj, 1, 40, 40);
		gluDeleteQuadric(qobj);
		glDisable(GL_TEXTURE_2D);
		////////////////////////////
		glRotatef(-theta, 0, 0, 1);
		glRotatef(-23, 0, 1, 0);
		glTranslatef(0.0, 0.0, -5.0);

		j1.Dibuja();
		j1.Pinta();

		/*
		glLightfv(GL_LIGHT0, GL_POSITION, antorcha);
		glLightf(GL_LIGHT0, GL_LINEAR, 1);
		glEnable(GL_LIGHT0);*/
		glEnable(GL_LIGHTING);

		glutSwapBuffers();
	}

	void OnKeyboardDown(unsigned char key, int x, int y){
		if (key == 'i') vistay += 0.5;
		if (key == 'k') vistay -= 0.5;
		if (key == 'l') vistax += 0.5;
		if (key == 'j') vistax -= 0.5;
		if (key == '+') zoom -= 0.5;
		if (key == '-') zoom += 0.5;
		j1.Mueve(key);

		glutPostRedisplay();
	}

	void OnTimer(int value){
		theta += 1.0F;

		j1.Rota();
		j1.Anima();

		glutTimerFunc(25, OnTimer, 0);
		glutPostRedisplay();
	}

	void OnMouseDown(int button, int state, int x, int y){
		j1.Mouse(button, state, x, y);
		
	}

	void OnMotion(int x, int y){
		j1.Motion(x, y);
	}

	void OnPassiveMotion(int x, int y){
		j1.PassiveMotion(x, y);
		
	}
