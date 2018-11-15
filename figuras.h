#include <windows.h>  //Solo para Windows
#include <GL/gl.h>     // The GL Header File
#include <stdio.h>

#include <math.h>

class CFiguras
{
public:
	void cuartoterror(float altura, float largo, float profundidad, GLuint paredes, GLuint suelo, GLuint techo, GLuint paredfrontal, GLuint paredtrasera);
	void cuarto2(float altura, float largo, float profundidad, GLuint text, GLuint text2, GLuint text3);
	void skybox(float altura, float largo, float profundidad, GLuint text, GLuint text2);
	void torus(float radioM, float radiom, int meridianos, int paralelos, GLuint text);
	void prisma_text(GLuint text, GLuint text2);
	void articulacion(float altura, float largo, float profundidad, GLuint transparente);
	void letrero(float altura, float largo, float profundidad, GLuint text);
	void puerta1(float altura, float largo, float profundidad, GLuint text);
	void ventana(float altura, float largo, float profundidad, GLuint text);
	void bruja(float altura, float largo, float profundidad, GLuint text);
	void alberca(float altura, float largo, float profundidad, GLuint text, GLuint text2);
	void murcielago(float altura, float largo, float profundidad, GLuint text);
	void plano(GLuint text); //Para el papel picado y el cartel
	void plano2(GLuint text); //Para el papel picado y el cartel
};
