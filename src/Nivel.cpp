#include "Nivel.h"
#include "Interaccion.h"
#include "Texto.h"


Nivel::Nivel() :j(Vector3D(-19.0f,10.0f,0.0f))
{

	Pared sup(-20.0F, 12.5F, 20.0F, 12.5F), der(20.0F, 12.5F, 20.0F, -12.5F), inf(20.0F, -12.5F, -20.0F, -12.5F), izq(-20.0F, -12.5F, -20.0F, 12.5F);
	caja[0] = sup;
	caja[1] = der;
	caja[2] = inf;
	caja[3] = izq;
	act = 0;
	pasanivel[0] = true;
}


Nivel::~Nivel()
{
}



void Nivel::LeeNivel(){
	if (pasanivel[act]){
		sprintf(buffer, "nivel%i.txt", act);
		pfile[act] = fopen(buffer, "r");
		param[0] = 1;
	//pfile = fopen("nivel0.txt", "r");
		if (pfile != NULL){
			while (param[0] != 0){
				for (int i = 0; i < 8; i++){
					fscanf(pfile[act], "%f", &param[i]);
				}
				if (param[0] != 0){
					Carga();
				}
			}
		}
		pasanivel[act] = false;
		fclose(pfile[act]);
	}
}

/*******************************************************/
/*******LISTA DE VARIABLES PARA CARGAR ELEMENTOS *******/
/**************EN LOS .TXT DE LOS NIVELES***************/
/*******************************************************/
/*******1-MURO******************************************/
/*******2-BARRIL****************************************/
/*******3-LAVA******************************************/
/*******4-JUGADOR***************************************/
/*******5-ENEMIGO A DISTANCIA***************************/
/*******6-ENEMIGO CUERPO A CUERPO***********************/
/*******7-ENEMIGO KAMIKAZE******************************/
/*******8-PUERTA ENTRADA********************************/
/*******9-PUERTA SALIDA*********************************/
/*******10-OBJETO***************************************/
/*******11-JEFE FINAL***********************************/
/*******12-JEFE CUERPO A CUERPO*************************/
/*******13-JEFE A DISTANCIA*****************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/


void Nivel::Carga(){
	Vector3D pos = Vector3D(param[1], param[2], param[3]);
	Vector3D tam = Vector3D(param[4], param[5], param[6]);

	if (param[0] == 1 || param[0] == 2 || param[0] == 3 || param[0] == 8 || param[0] == 9){
		lobs.agregarObstaculo(pos, tam, (int)param[0], (bool)param[7]);
	}
	if (param[0] == 4){
		//j.Reinicia(pos);
		j.movimiento = true;
		j.tocapuerta = false;
		j.contador = 0;
		//j.mod_danio = 1;
		//j.mod_vel = 1;
		//j.invencible = 0;
		j.posicion = j.limites.posicion = pos;
	}
	if (param[0] == 5 || param[0] == 6 || param[0] == 7 || param[0] == 12 ||param[0]==13){
		lenem.agregarEnemigo(pos, (int)param[0]);
	}
	if (param[0] == 10){
		lobj.agregarObjetos(pos, (int)param[7]);
	}
}

void Nivel::Dibuja(){
	glPushMatrix();
	static bitmap suelo("suelo.bmp");
	glEnable(GL_LIGHTING);
	suelo.usarTextura();
	glBegin(GL_QUADS);	//SUELO
	glColor3ub(255, 255, 255);
	glTexCoord2f(3.0, 2.0);
	glNormal3f(0, 0, 1);
	glVertex3f(-20.0, 12.5, 0.0);
	glTexCoord2f(0.0, 2.0);
	glNormal3f(0, 0, 1);
	glVertex3f(20.0, 12.5, 0.0);
	glTexCoord2f(0.0, 0.0);
	glNormal3f(0, 0, 1);
	glVertex3f(20.0, -12.5, 0.0);
	glTexCoord2f(3.0, 0.0);
	glNormal3f(0, 0, 1);
	glVertex3f(-20.0, -12.5, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	
	glEnable(GL_LIGHTING);
	glPopMatrix();
	for (int i = 0; i < 4; i++)	caja[i].Dibuja();
	lenem.dibujarEnemigos();
	j.Dibuja();
	j.Pinta();
	lobs.dibujarObstaculos();
	ldis.dibujarDisparos();
	lobj.dibujarObjetos();
}

void Nivel::Borrar(){
	ldis.borraDisparos();
	lenem.borraEnemigos();
	lobs.borraObstaculos();
	lobj.borraObjetos();
}


void Nivel::nuevoDisparo(){
	ldis.agregarDisparos(j, 1000, j.mod_danio);
}

void Nivel::actualizaListas(){
	lobs.actualizarObstaculos();
	lobs.animarObstaculos();
	lenem.destruirEnemigo();
	lobj.actualizarObjetos();
	ldis.actualizarDisparos(25);
	j.invencibilidad(25);
	j.puntos = 0;
}

void Nivel::updateEnemigos(){
	lenem.mueveEnemigos();
	lenem.updateEnemigos(j.limites.posicion, ldis);

}

void Nivel::interacciones(){
	Interaccion::interaccion(ldis, lobs);
	Interaccion::interaccion(ldis, lenem, j);
	Interaccion::interaccion(j, lobs);
	Interaccion::interaccion(lenem, lobs);
	Interaccion::interaccion(lenem);
	Interaccion::interaccion(j, lenem);
	Interaccion::ldv(lobs, lenem, j);
	Interaccion::interaccion(j,lobj);
}

void Nivel::rotaJugador(){
	j.Rota();
	j.Anima();
}



void Nivel::KeyOperations(){
	j.KeyOperations();
}

void Nivel::OnKeyboardUp(unsigned char key, int x, int y){
	j.NoMueve(key);
}

void Nivel::OnKeyboardDown(unsigned char key, int x, int y){
	j.Mueve(key);
}

void Nivel::OnMouseDown(int button, int state, int x, int y){
	j.Mouse(button, state, x, y);
}

void Nivel::OnMotion(int x, int y){
	j.Motion(x, y);
}

void Nivel::OnPassiveMotion(int x, int y){
	j.PassiveMotion(x, y);
}

int Nivel::GetMejoras(){
	if ((j.mod_danio != 1) && (j.mod_vel != 1) && (j.invencible > 0))
		return 7;
	if ((j.mod_danio != 1) && (j.mod_vel != 1))
		return 4;
	if ((j.mod_danio != 1) && (j.invencible > 0))
		return 5;
	if ((j.mod_vel != 1) && (j.invencible > 0))
		return 6;
	if (j.mod_danio != 1)
		return 1;
	if (j.mod_vel != 1)
		return 2;
	if (j.invencible > 0)
		return 3;
	else
		return 0;
}