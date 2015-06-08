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

//disparo con obstaculo
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
					if (obstaculo.lista[j]->se_destruye && (disparo.lista[i]->getTipo() == false)) obstaculo.lista[j]->destruir = true;
				}
			}
			else if (obs.tipo == RECTANGULO){
				if (colision_CR(dis.posicion, dis.radio, obs.posicion, obs.alto, obs.ancho)) {
					disparo.lista[i]->destruye();
					if (obstaculo.lista[j]->se_destruye && (disparo.lista[i]->getTipo() == false)) obstaculo.lista[j]->destruir = true;
					break;
				}
			}
		}
		if ((dis.posicion.x + dis.radio > MAX_X) || (dis.posicion.x - dis.radio < -MAX_X) || (dis.posicion.y + dis.radio > MAX_Y) || (dis.posicion.y - dis.radio < -MAX_Y))
			disparo.lista[i]->destruye();
	}
}

//disparo con enemigo
void Interaccion::interaccion(ListaDisparos disparo, ListaEnemigos enemigo, Jugador &jugador){
	CrashBox dis, obj;

	for (int i = 0; i < disparo.tam_lista; i++){
		if (disparo.lista[i]->getTipo()) {
			dis = disparo.lista[i]->getCrashBox();
			obj = jugador.limites;
			float distancia = Vector3D::modulo(dis.posicion - obj.posicion);
			if (distancia <= (dis.radio + obj.radio)) {
				disparo.lista[i]->destruye();
				jugador.act_Vida(disparo.lista[i]->getDanio());
			}
		}
		else{
			dis = disparo.lista[i]->getCrashBox();
			for (int j = 0; j < enemigo.n_enemigos; j++){
				obj = enemigo.lista[j]->limites;
				float distancia = Vector3D::modulo(dis.posicion - obj.posicion);
				if (distancia <= (dis.radio + obj.radio)) {
					disparo.lista[i]->destruye();
					enemigo.lista[j]->act_Vida(disparo.lista[i]->getDanio());
				}
			}
		}
	}
}

//jugador con obstaculo
void Interaccion::interaccion(Jugador &jugador, ListaObstaculos obstaculo){
	CrashBox jug, obs;
	float vel = 0.05f;

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
			}
		}
		else if (obs.tipo == RECTANGULO){
			if (colision_CR(jug.posicion, jug.radio, obs.posicion, obs.alto, obs.ancho)) {
				jugador.posicion = jugador.pos_anterior;
				jugador.limites.posicion = jugador.pos_anterior;
				jugador.limites.posicion.z = 0;
			}
		}
		else if (obs.tipo == AGUJERO){
			if (colision_CR(jug.posicion, 0.1f, obs.posicion, obs.alto, obs.ancho)) {
				jugador.movimiento = false;
				if (jugador.posicion.z > -4) jugador.posicion.z -= 0.1f;
				else jugador.vida = 0;
				Vector3D direc = Vector3D::creavector(jug.posicion, obs.posicion);
				direc.unitario(direc);
				jugador.posicion = jugador.posicion + direc*vel;
				jugador.limites.posicion = jugador.posicion;
				jugador.limites.posicion.z = 0;
			}
		}


		else if (obs.tipo == PUERTASALIDA){
			if (colision_CR(jug.posicion, jug.radio, obs.posicion, obs.alto, obs.ancho)) {
				jugador.tocapuerta = true;
			}
			else
			{
				jugador.tocapuerta = false;
			}
		}
	}
	jugador.pos_anterior = jugador.posicion;
}


//enemigo con obstaculo
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
			else if ((obs.tipo == RECTANGULO) || (obs.tipo == AGUJERO)){
				if ((obs.tipo == AGUJERO) && (enemigo.lista[i]->id == 6)) break;	//Para enemigo CaC. Se supone que levita
				if (colision_CR(enem.posicion, enem.radio, obs.posicion, obs.alto, obs.ancho)) {
					Vector3D direc = Vector3D::creavector(obs.posicion, enem.posicion);
					direc.unitario(direc);
					float aux;
					if (enemigo.lista[i]->id == 7) aux = 0.05F;
					else aux = 0.02F;
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

//enemigo con enemigo
void Interaccion::interaccion(ListaEnemigos enemigos){
	CrashBox enem1, enem2;

	for (int i = 0; i < enemigos.n_enemigos; i++){
		enem1 = enemigos.lista[i]->getCrashBox();
		for (int j = i; j < enemigos.n_enemigos; j++){
			enem2 = enemigos.lista[j]->getCrashBox();
			float distancia = Vector3D::modulo(enem1.posicion - enem2.posicion);
			if (distancia <= (enem1.radio + enem2.radio)) {
				Vector3D direc = Vector3D::creavector(enem1.posicion, enem2.posicion);
				direc.unitario(direc);
				float aux = 1.2F * (enem1.radio + enem2.radio - distancia);
				direc = direc * aux;
				enemigos.lista[i]->posicion = enemigos.lista[i]->posicion - direc;
				enemigos.lista[i]->limites.posicion = enemigos.lista[i]->limites.posicion - direc;
				enemigos.lista[j]->posicion = enemigos.lista[j]->posicion + direc;
				enemigos.lista[j]->limites.posicion = enemigos.lista[j]->limites.posicion + direc;
			}
		}
	}
}

//jugador con enemigos
void Interaccion::interaccion(Jugador jugador, ListaEnemigos enemigo){
	CrashBox jug, enem;

	jug = jugador.limites;
	for (int i = 0; i < enemigo.n_enemigos; i++){
		enem = enemigo.lista[i]->getCrashBox();
		float distancia = Vector3D::modulo(jug.posicion - enem.posicion);
		if (distancia <= (jug.radio + enem.radio)) {
			Vector3D direc = Vector3D::creavector(jug.posicion, enem.posicion);
			direc.unitario(direc);
			float aux = 1.2F * (jug.radio + enem.radio - distancia);
			direc = direc * aux;
			enemigo.lista[i]->posicion = enemigo.lista[i]->posicion + direc;
			enemigo.lista[i]->limites.posicion = enemigo.lista[i]->limites.posicion + direc;
			if (enemigo.lista[i]->id == 7)	enemigo.lista[i]->atacar(0);	//kamikaze
			////////
			//////// ALGUN PROBLEMA AQUI CUANDO EL KAMIKAZE SE AUTODESTRUYE
			//////// PARECE QUE SE QUEDA GUARDADO QUE ESTA EN CONTACTO CON EL JUGADOR
			//////// al reaparecer lo detecta y dispara en la direccion en la que esta el jugador, aunque no esten en contacto
			////////

		}
	}
}

//lineas de vision
void Interaccion::ldv(ListaObstaculos obstaculo, ListaEnemigos enemigo, Jugador j){
	CrashBox obs, lin;
	int num_lados_col;

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
				num_lados_col = 0;
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
			else vision_enemigo++;
		}
		if (vision_enemigo == (obstaculo.n_obstaculos)){
			enemigo.lista[i]->teveo = true;
		}
		else{
			enemigo.lista[i]->teveo = false;
		}
	}
}
