#include "Interaccion.h"
#include <math.h>
#include "stdio.h"

bool colision_CR(Vector3D pos_dis, float r_dis, Vector3D pos_obs, float alto_obs, float ancho_obs){
	float distancia_X = abs(pos_dis.x - pos_obs.x);
	float distancia_Y = abs(pos_dis.y - pos_obs.y);

	if (distancia_X > (ancho_obs / 2.0F + r_dis)) return false;
	if (distancia_Y > (alto_obs / 2.0F + r_dis)) return false;
	if (distancia_X <= (ancho_obs / 2.0F)) return true;
	if (distancia_Y <= (alto_obs / 2.0F)) return true;

	float cornerDistance_sq = pow(distancia_X - ancho_obs / 2.0F, 2) + pow(distancia_Y - alto_obs / 2.0F, 2);
	return (cornerDistance_sq <= (pow(r_dis, 2)));
}

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
			if (obs.tipo == CIRCULO){
				float distancia = Vector3D::modulo(dis.posicion - obs.posicion);
				if (distancia <= (dis.radio + obs.radio)) {
					disparo.lista[i]->destruye();
					if (obstaculo.lista[j]->se_destruye) obstaculo.lista[j]->destruir = true;
					break;
				}
			}
			else if (obs.tipo == RECTANGULO){
				bool colision = colision_CR(dis.posicion, dis.radio, obs.posicion, obs.alto, obs.ancho);
				if (colision) {
					disparo.lista[i]->destruye();
					if (obstaculo.lista[j]->se_destruye) obstaculo.lista[j]->destruir = true;
					break;
				}
			}
		}
	}
}


void Interaccion::interaccion(Jugador &jugador, ListaObstaculos obstaculo){
	CrashBox jug, obs;

	jug = jugador.getCrashBox();
	for (int j = 0; j < obstaculo.n_obstaculos; j++){
		obs = obstaculo.lista[j]->limites;
		if (obs.tipo == CIRCULO){
			float distancia = Vector3D::modulo(obs.posicion - jug.posicion);
			if (distancia <= (jug.radio + obs.radio)) {
				/*Vector3D direc = Vector3D::creavector(obs.posicion, jug.posicion);
				direc.unitario(direc);
				float aux = 1.2F * (jug.radio + obs.radio - distancia);
				direc = direc * aux;
				jugador.posicion = jugador.posicion + direc;
				jugador.limites.posicion = jugador.limites.posicion + direc;*/
				jugador.posicion = jugador.pos_anterior;
				jugador.limites.posicion = jugador.pos_anterior;
				jugador.limites.posicion.z = 0;
				break;
			}
		}
		else if (obs.tipo == RECTANGULO){
			bool colision = colision_CR(jug.posicion, jug.radio, obs.posicion, obs.alto, obs.ancho);
			if (colision) {
				jugador.posicion = jugador.pos_anterior;
				jugador.limites.posicion = jugador.pos_anterior;
				jugador.limites.posicion.z = 0;
				break;
			}
		}
	}
	jugador.pos_anterior = jugador.posicion;
}

void Interaccion::interaccion(ListaEnemigos enemigo, ListaObstaculos obstaculo){
	CrashBox enem, obs;
	for (int i = 0; i < enemigo.n_enemigos; i++){
		enem = enemigo.lista[i]->getCrashBox();
		for (int j = 0; j < obstaculo.n_obstaculos; j++){
			obs = obstaculo.lista[j]->limites;
			if (obs.tipo == CIRCULO){
				float distancia = Vector3D::modulo(obs.posicion - enem.posicion);
				if (distancia <= (enem.radio + obs.radio)) {
					Vector3D direc = Vector3D::creavector(obs.posicion, enem.posicion);
					direc.unitario(direc);
					float aux = 1.2F * (enem.radio + obs.radio - distancia);
					direc = direc * aux;
					enemigo.lista[i]->posicion = enemigo.lista[i]->posicion + direc;
					enemigo.lista[i]->limites.posicion = enemigo.lista[i]->limites.posicion + direc;
					/*		enemigo.lista[i]->posicion = enemigo.lista[i]->pos_anterior;
					enemigo.lista[i]->limites.posicion = enemigo.lista[i]->pos_anterior;
					enemigo.lista[i]->limites.posicion.z = 0;
					break;*/
				}
			}
			else if (obs.tipo == RECTANGULO){
				bool colision = colision_CR(enem.posicion, enem.radio, obs.posicion, obs.alto, obs.ancho);
				if (colision) {
					Vector3D direc = Vector3D::creavector(obs.posicion, enem.posicion);
					direc.unitario(direc);
					float aux = 0.01F;
					direc = direc * aux;
					enemigo.lista[i]->posicion = enemigo.lista[i]->posicion + direc;
					enemigo.lista[i]->limites.posicion = enemigo.lista[i]->limites.posicion + direc;
					/*	enemigo.lista[i]->posicion = enemigo.lista[i]->pos_anterior;
					enemigo.lista[i]->limites.posicion = enemigo.lista[i]->pos_anterior;
					enemigo.lista[i]->limites.posicion.z = 0;
					break;*/
				}
			}
		}
		enemigo.lista[i]->pos_anterior = enemigo.lista[i]->posicion;
	}
}

void Interaccion::ldv(ListaObstaculos obstaculo, ListaEnemigos enemigo){
	CrashBox obs, lin;
	int num_lados_col = 0;

	for (int i = 0; i < enemigo.n_enemigos; i++){
		int vision_enemigo = 0;
		lin = enemigo.lista[i]->lin;
		Vector3D v = Vector3D::creavector(lin.posicion, lin.direccion);
		float aux = v.x;
		v.x = -v.y;
		v.y = aux;
		float modulo = Vector3D::modulo(v);
		float c = -(enemigo.lista[i]->posicion.x*v.x + enemigo.lista[i]->posicion.y*v.y);
		for (int j = 0; j < obstaculo.n_obstaculos; j++){
			obs = obstaculo.lista[j]->limites;
			if (obs.tipo == CIRCULO){
				float distancia = abs(((obstaculo.lista[j]->posicion.x*v.x) + (obstaculo.lista[j]->posicion.y*v.y) + c)) / modulo;
				if (distancia > obs.radio) {
					vision_enemigo++;

				}
			}
			else if (obs.tipo == RECTANGULO){
				Vector3D v1(obs.posicion.x - obs.ancho / 2, obs.posicion.y - obs.alto / 2, 0);
				Vector3D v2(obs.posicion.x + obs.ancho / 2, obs.posicion.y - obs.alto / 2, 0);
				Vector3D v3(obs.posicion.x + obs.ancho / 2, obs.posicion.y + obs.alto / 2, 0);
				Vector3D v4(obs.posicion.x - obs.ancho / 2, obs.posicion.y + obs.alto / 2, 0);

				//coeficientes rectas horizontales
				Vector3D horizontal = Vector3D::creavector(v2, v3);
				//coeficientes rectas verticales
				Vector3D vertical = Vector3D::creavector(v1, v2);



				if (v.x*horizontal.y - v.y*horizontal.x != 0){
					//pared sur
					if ((lin.posicion.y > v1.y && lin.direccion.y < v1.y) || (lin.posicion.y<v1.y && lin.direccion.y>v1.y)){
						float x = ((-v.y*v1.y) - c) / v.x;

						if (x>obs.posicion.x - obs.ancho / 2 && x<obs.posicion.x + obs.ancho / 2){
							num_lados_col++;
						}
					}
					//pared norte
					if ((lin.posicion.y > obs.posicion.y + obs.alto / 2 && lin.direccion.y < obs.posicion.y + obs.alto / 2) || (lin.posicion.y<obs.posicion.y + obs.alto / 2 && lin.direccion.y>obs.posicion.y + obs.alto / 2)){
						float x = ((-v.y*v3.y) - c) / v.x;
						if (x>obs.posicion.x - obs.ancho / 2 && x < obs.posicion.x + obs.ancho / 2){
							num_lados_col++;
						}
					}
				}

				if (v.x*vertical.y - v.y*vertical.x != 0){
					if ((lin.posicion.x > v1.x && lin.direccion.x < v1.x) || (lin.posicion.x<v1.x && lin.direccion.x>v1.x)){
						float y = ((-v.x*v1.x) - c) / v.y;

						if (y > v1.y && y<v4.y){
							num_lados_col++;
						}
					}
					//pared este
					if ((lin.posicion.x > v3.x && lin.direccion.x < v3.x) || (lin.posicion.x<v3.x && lin.direccion.x>v3.x)){
						float y = ((-v.x*v3.x) - c) / v.y;
						if (y > v2.y && y < v3.y){
							num_lados_col++;

						}
					}
				}
				if (num_lados_col < 2){
					vision_enemigo++;
				}
			}
		}
		if (vision_enemigo == obstaculo.n_obstaculos){
			enemigo.lista[i]->teveo = true;
			//	printf("b");
		}
		else{
			enemigo.lista[i]->teveo = false;
			//	printf("a");
		}
	}
}