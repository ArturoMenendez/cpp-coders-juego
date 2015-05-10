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
		fclose(pfile[act]);
		pasanivel[act] = false;
	}
}

void Nivel::Carga(){
	Vector3D pos = Vector3D(param[1], param[2], param[3]);
	Vector3D tam = Vector3D(param[4], param[5], param[6]);

	if (param[0] == 1 || param[0] == 2 || param[0] == 3){
		lobs.agregarObstaculo(pos,tam,(int)param[0],(bool)param[7]);
	}
}

void Nivel::Dibuja(){
	lobs.dibujarObstaculos();
}

ListaObstaculos Nivel::getLisObs(){
	return lobs;
}

void Nivel::actualizaLisObs(){
	lobs.actualizarObstaculos();
}