#include "Nivel.h"


Nivel::Nivel()
{
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

void Nivel::Carga(){
	Vector3D pos = Vector3D(param[1], param[2], param[3]);
	Vector3D tam = Vector3D(param[4], param[5], param[6]);

	if (param[0] == 1 || param[0] == 2 || param[0] == 3){
		lobs.agregarObstaculo(pos, tam, (int)param[0], (bool)param[7]);
	}
	if (param[0] == 4){
		j = Jugador(pos);
	}
	if (param[0] == 5 || param[0] == 6 || param[0] == 7){
		lenem.agregarEnemigo(pos, (int)param[0]);
	}
}

void Nivel::Dibuja(){
	lenem.dibujarEnemigos();
	j.Dibuja();
	j.Pinta();
	lobs.dibujarObstaculos();
}


ListaObstaculos Nivel::getLisObs(){
	return lobs;
}

void Nivel::actualizaLisObs(){
	lobs.actualizarObstaculos();
}

ListaEnemigos Nivel::getLisEnem(){
	return lenem;
}

void Nivel::actualizaLisEnem(){
	lenem.actualizarEnemigos();
}

void Nivel::mueveLisEnem(){
	lenem.mueveEnemigos();
}

void Nivel::updateLisEnem(){
	lenem.updateEnemigos();
}

void Nivel::rotaLisEnem(){
	lenem.rotaEnemigos();
}

Jugador Nivel::getJugador(){
	return j;
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