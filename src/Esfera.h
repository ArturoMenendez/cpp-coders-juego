class Esfera
{
public:
	//variables
	float radio;
	Vector3D posicion;
	Vector3D ptomira;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	bool botonpulsado;
	float angrot;
	//metodos
	Esfera(void);
	~Esfera(void);
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	void Pinta();
	void Dibuja();
	void Rota();
	void Mueve(unsigned char);
};


