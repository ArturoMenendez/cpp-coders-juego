#include <stdlib.h>
#include "ListaEnemigos.h"
#include "ListaDisparos.h"
#define ADISTANCIA		5
#define CAC				6
#define KAMIKAZE		7
#define BOSSCAC			12
#define BOSSADISTANCIA	13
#define BOSSFINAL		11

ListaEnemigos::ListaEnemigos()
{
	n_enemigos = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++) lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
{
}

void ListaEnemigos::agregarEnemigo(Vector3D posicion, int tipo){
	if (n_enemigos < MAX_ENEMIGOS) {
		Enemigo* nuevo;
		switch (tipo){
		case (ADISTANCIA) : {
			nuevo = new ADistancia(posicion, ADISTANCIA);
			lista[n_enemigos++] = nuevo;
			break; }
		case(CAC) : {
			nuevo = new CaC(posicion, CAC);
			lista[n_enemigos++] = nuevo;
			break; }
		case(KAMIKAZE) : {
			nuevo = new Kamikaze(posicion, KAMIKAZE);
			lista[n_enemigos++] = nuevo;
			break; }
		case(BOSSCAC) : {
			nuevo = new BossCaC(posicion, BOSSCAC);
			lista[n_enemigos++] = nuevo;
			break;
		}
		case(BOSSADISTANCIA) : {
			nuevo = new BossADistancia(posicion, BOSSADISTANCIA);
			lista[n_enemigos++] = nuevo;
			break;
		}
		case(BOSSFINAL) : {
			nuevo = new BossFinal(posicion, BOSSFINAL);
			lista[n_enemigos++] = nuevo;
			break;
		}
		default:
			break;
		}
	}
}

void ListaEnemigos::dibujarEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Dibuja();
}

void ListaEnemigos::destruirEnemigo(){
	for (int i = 0; i < n_enemigos; i++) {
		if (lista[i]->vida <= 0 && lista[i]->contador >= 15){
			delete lista[i];
			n_enemigos--;
			for (int j = i; j < n_enemigos; j++)	lista[j] = lista[j + 1];
			}
		}
	}


void ListaEnemigos::mueveEnemigos(){
	for (int i = 0; i < n_enemigos; i++) {
		lista[i]->MueveAleat();
		lista[i]->Rota();
	}
}

void ListaEnemigos::updateEnemigos(Vector3D jugador, ListaDisparos &ldis){
	for (int i = 0; i < n_enemigos; i++) {
		lista[i]->Update();
		lista[i]->lin.direccion = jugador;
		if (lista[i]->atacar(25)) {
			if (lista[i]->id == ADISTANCIA)		ldis.agregarDisparos(*lista[i], 1000, 1, true, 0.3); //modificar
			if (lista[i]->id == CAC)	ldis.agregarDisparos(*lista[i], 100, 2, true, 0.3);
			if (lista[i]->id == KAMIKAZE)	{
				ldis.agregarDisparos(*lista[i], 100, 4, true, 0.8);
				lista[i]->act_Vida(100);
			}
			if (lista[i]->id == BOSSCAC)
				ldis.agregarDisparos(*lista[i], 1000, 3, true, 0.3);
			if (lista[i]->id == BOSSADISTANCIA){
				if (lista[i]->teveo){
					ldis.agregarDisparos(*lista[i], 1000, 1, true, 0.5, 5);
					ldis.agregarDisparos(*lista[i], 1000, 1, true, 0.5);
					ldis.agregarDisparos(*lista[i], 1000, 1, true, 0.5, -5);
				}
				else{
					for (float j = 0; j <= 6.28f; j += 0.314f){
						ldis.agregarDisparos(*lista[i], 1000, 1, true, 0.3, j);
					}
				}
			}
			if (lista[i]->id == BOSSFINAL){
				ldis.agregarDisparos(*lista[i], 1000, 2, true, 0.8);
				if (lista[i]->teveo){
					Vector3D pos(18 - rand() % 37, 10.5 - rand() % 24, 0);
					agregarEnemigo(pos, rand() % 3 + 5);
				}
			}
		}
	}
}

void ListaEnemigos::rotaEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Rota();
}

void ListaEnemigos::borraEnemigos(){
	for (int i = 0; i < n_enemigos; i++)
		delete lista[i];
	n_enemigos = 0;
}

int ListaEnemigos::GetPuntosEnemigo(){
	if (n_enemigos != 0){
		for (int i = 0; i < n_enemigos; i++){
			if (lista[i]->vida <= 0 && lista[i]->contador >= 14)
				return lista[i]->puntos;
			else
				return 0;
		}
	}
		return 0;
}


int ListaEnemigos::getNumero(){
	return n_enemigos;
}