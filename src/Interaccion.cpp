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

//Crear lista objetos y comprobra colisones con todos

void Interaccion::interaccion(Jugador jugador, ListaObstaculos obstaculo){
	CrashBox jug, obs;

	jug = jugador.getCrashBox();
	for (int j = 0; j < obstaculo.n_obstaculos; j++){
		obs = obstaculo.lista[j]->limites;
		if (obs.tipo == CIRCULO){
			float distancia = Vector3D::modulo(jug.posicion - obs.posicion);
			if (distancia <= (jug.radio + obs.radio)) {
				printf("a");
				/*while (jugador.keyStates['a']){
					jugador.keyStates['d'] = true;
				}
				while (jugador.keyStates['d'] == true){
					jugador.keyStates['a'] = true;
				}
				while (jugador.keyStates['w']){
					jugador.keyStates['s'] = true;
					jugador.keyStates['w'] = false;

				}
				while (jugador.keyStates['s']){
					jugador.keyStates['w'] = true;
					jugador.keyStates['s'] = false;
				}*/
				break;
			}
		}
		else if (obs.tipo == RECTANGULO){
			bool colision = colision_CR(jug.posicion, jug.radio, obs.posicion, obs.alto, obs.ancho);
			if (colision) {
				printf("b");
				/*if (jugador.keyStates['a']){
					jugador.posicion.x += 0.2;
					jugador.limites.posicion.x += 0.2;
				}
				if (jugador.keyStates['d']){
					jugador.posicion.x -= 0.2;
					jugador.limites.posicion.x -= 0.2;
				}
				if (jugador.keyStates['w']){
					jugador.posicion.y -= 0.2;
					jugador.limites.posicion.y -= 0.2;
				}
				if (jugador.keyStates['s']){
					jugador.posicion.y += 0.2;
					jugador.limites.posicion.y += 0.2;
				}*/
			}
		}
	}
}


void Interaccion::ldv(Jugador jugador, ListaObstaculos obstaculo, ListaEnemigos enemigo){
	CrashBox obs, lin;
	for (int i = 0; i < enemigo.n_enemigos; i++){
		Vector3D v = Vector3D::creavector(enemigo.lista[i]->posicion, jugador.posicion);
		float modulo = v.modulo(v);
		glColor3ub(255,255,255);
		glBegin(GL_LINES);
		glVertex3f(jugador.posicion.x, jugador.posicion.y, 1);
		glVertex3f(enemigo.lista[i]->posicion.x, enemigo.lista[i]->posicion.y, 1);
		glEnd();

		lin = enemigo.lista[i]->lin;		
		for (int j = 0; j < obstaculo.n_obstaculos; j++){
			obs = obstaculo.lista[j]->limites;
			
			/////////////////////////
			if (obs.tipo == CIRCULO){
				float c = -(enemigo.lista[i]->posicion.x*v.x + enemigo.lista[i]->posicion.y*v.y);
				float distancia = (obstaculo.lista[j]->posicion.x*v.x + obstaculo.lista[j]->posicion.y*v.y+c)/modulo;
				if (distancia > obs.radio) {
					//printf("te veo ");
					break;
				}
			}
			/*else if (obs.tipo == RECTANGULO){
				bool colision = colision_CR(dis.posicion, dis.radio, obs.posicion, obs.alto, obs.ancho);
				if (colision) {
					disparo.lista[i]->destruye();
					if (obstaculo.lista[j]->se_destruye) obstaculo.lista[j]->destruir = true;
					break;
				}
			}*/
		}
		/////////////////////
	}
}