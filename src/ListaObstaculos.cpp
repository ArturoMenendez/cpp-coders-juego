#include "ListaObstaculos.h"


ListaObstaculos::ListaObstaculos()
{
	n_obstaculos = 0;
	for (int i = 0; i < MAX_OBSTACULOS; i++) lista[i] = 0;
}


ListaObstaculos::~ListaObstaculos()
{
}

void ListaObstaculos::agregarObstaculo(Vector3D posicion, Vector3D tamanio, int tipo, bool destruccion){
	Obstaculo* nuevo_obstaculo = new Obstaculo(posicion, tamanio, tipo, destruccion);
	if (n_obstaculos < MAX_OBSTACULOS) lista[n_obstaculos++] = nuevo_obstaculo;
}

void ListaObstaculos::dibujarObstaculos(){
	for (int i = 0; i < n_obstaculos; i++) lista[i]->Dibuja();
}

void ListaObstaculos::actualizarObstaculos(){
	bool obs_destruido;
	do{
		obs_destruido = false;
		for (int i = 0; i < n_obstaculos; i++){
			if (lista[i]->destruir){
				delete lista[i];
				obs_destruido = true;
				n_obstaculos--;
				for (int j = i; j < n_obstaculos; j++){
					lista[j] = lista[j + 1];
				}
				break;
			}
		}
	} while (obs_destruido);
}

