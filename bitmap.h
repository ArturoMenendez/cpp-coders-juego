include "glut.h"

class bitmap {
	bool estado;	//exito=1 fallo=0
	unsigned int ancho;
	unsigned int alto;
	unsigned int bytes_pixel;
	unsigned char *imagen;
	GLuint texture;

public:
	bitmap(char *nombre_archivo);
	bool verEstado();
	void usarTextura();
	~bitmap();
	
};
