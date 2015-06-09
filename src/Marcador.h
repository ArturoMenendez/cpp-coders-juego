#pragma once

class Marcador
{
	int nivel;
	int salud=10;
	int vidas;
	int puntuacion;
	float tiempo;
	int llaves;
	int total_llaves;
	bool objetos[3];
public:
	Marcador();
	~Marcador();
	void actualizarMarcador(int salud, float t, int puntos, int nivel, int vidas, int llaves, int mejoras);
	int GetTiempo(){
		return tiempo;
	}
	void SetTiempo(int time){ tiempo = time; };
	void dibujar();
};

