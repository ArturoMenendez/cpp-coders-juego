#pragma once
#include "Nivel.h"


class Gestor
{
public:
	enum Estado
	{
		INICIO,
		JUEGO,
		PAUSA
	};
	Estado estado;
	Gestor();
	virtual ~Gestor();
};

