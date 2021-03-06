#include "glut.h"
#include "bitmap.h"
#include "ListaObstaculos.h"
#include "ListaDisparos.h"
#include "Interaccion.h"
#include "Nivel.h"
#include "Texto.h"
#include <string.h>
#include "Objeto.h"
#include "Codigo.h"
#include "Gestor.h"


float vistax = 0, vistay = 0, zoom = 50;
float theta = 0;
bool* keyStates = new bool[256];
//Nivel n1;
Gestor gestor;
Vector3D xyz(5, -5, 5);
//Objeto *pObj;
//Codigo obj(xyz);

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y); //cuando se suelta una tecla
void KeyOperations(void);
void OnMouseDown(int button, int state, int x, int y);//se llama cuando se pulsa o se suelta un boton del raton
void OnMotion(int x, int y);
void OnPassiveMotion(int x, int y);

int main(int argc, char* argv[])
{
	//pObj = &obj;
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(900, 675);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("C++ Coders: Raiders of the Lost Class");

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 900 / 675.0f, 0.1, 150);
	glTranslatef(0.0, -2.5, 0.0);

	// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutMouseFunc(OnMouseDown);
	glutMotionFunc(OnMotion);
	glutPassiveMotionFunc(OnPassiveMotion);

	glutSetCursor(GLUT_CURSOR_NONE);

	//pasarle el control a GLUT,que llamara a los callbacks

	keyStates['i'] = false;
	keyStates['j'] = false;
	keyStates['k'] = false;
	keyStates['l'] = false;
	keyStates['+'] = false;
	keyStates['-'] = false;
	glutMainLoop();

	return 0;
}

void OnDraw(){

	KeyOperations();
	static float antorcha[4] = { -16.0, 11.0, 2.0, 1 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(vistax, vistay, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	gestor.Dibuja();
	//pObj->Dibuja();
	glutSwapBuffers();
}


void OnKeyboardDown(unsigned char key, int x, int y){
	keyStates[key] = true;
	gestor.OnKeyboardDown(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y){
	keyStates[key] = false;
	gestor.OnKeyboardUp(key);
	glutPostRedisplay();
}

void KeyOperations(){
	gestor.KeyOperations();
	if (keyStates['i']) vistay += 0.5;
	if (keyStates['k']) vistay -= 0.5;
	if (keyStates['l']) vistax += 0.5;
	if (keyStates['j']) vistax -= 0.5;
	if (keyStates['+']) zoom -= 0.5;
	if (keyStates['-']) zoom += 0.5;
}

void OnTimer(int value){

	/*n1.rotaJugador();
	n1.interacciones();
	n1.actualizaListas();
	n1.updateEnemigos();*/

	gestor.Update();
	gestor.Condiciones();
	//gestor.GetPuntos();

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void OnMouseDown(int button, int state, int x, int y){
	gestor.OnMouseDown(button, state, x, y);
	//if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
	//n1.nuevoDisparo();
	//gestor.JugadorDispara();
	//}
}

void OnMotion(int x, int y){
	gestor.OnMotion(x, y);
}

void OnPassiveMotion(int x, int y){
	gestor.OnPassiveMotion(x, y);
}