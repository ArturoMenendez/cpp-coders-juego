#include "Interaccion.h"


Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}

void Interaccion::interaccion(ListaDisparos disparo, ListaObstaculos obstaculo){
	CrashBox dis, obs;

	for (int i = 0; i < disparo.tam_lista; i++){
		dis = disparo.lista[i]->getCrashBox();
		for (int j = 0; j < obstaculo.n_obstaculos; j++){
			obs = obstaculo.lista[j]->limites;
			if (dis.tipo == obs.tipo == CIRCULO){
				float distancia = Vector3D::modulo(dis.posicion - obs.posicion);
				if (distancia <= (dis.radio + obs.radio)) {
					disparo.lista[i]->destruye();
					if (obstaculo.lista[j]->se_destruye) obstaculo.lista[j]->destruir = true;
					break;
				}
			}
		}
	}
}
//Crear lista objetos y comprobra colisones con todos