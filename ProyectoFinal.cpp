//Semestre 2019 - 1
//****************************************************************//
//****************************************************************//
//********Alumno (s):	Bustos Ramírez Luis Enrique		**********//
//********				Galindo Hernandez Luis Antonio	**********//
//**************		Hernandez Flores Manuel Irvin ************//
//****************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

#if (_MSC_VER >=1900)
#pragma comment (lib,"legacy_stdio_definitions.lib")
#endif

/*------------------------------OBJETOS DE LA CAMARA----------------------------*/
CCamera objCamera;
GLfloat g_lookupdown = 0.0f;
/*------------------------------OBJETOS DE LAS LUCES----------------------------*/

bool light = false;
bool luzpecebre = false;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f};
GLfloat Specular[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };		
//Verde
GLfloat mat_ambient1[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse1[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat mat_specular1[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_shininess1[] = { 100.0 };
//Rojo
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 100.0 };
//Cafe
GLfloat mat_ambient2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse2[] = { 0.5, 0.4, 0.3, 1.0 };
GLfloat mat_specular2[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_shininess2[] = { 100.0 };
/*-------------------------------SKYBOX----------------------------------*/
CTexture cielo;
CTexture pasto;
/*-------------------------------CASA------------------------------------*/
CTexture t_Pared;
CTexture t_ParedPuerta;
CTexture t_Piso;
CTexture t_ParedTracera;
CTexture t_Puerta;
CTexture t_VentanaDer;
CTexture t_VentanaIzq;
/*-----------------------------ADORNOS---------------------------------*/
CTexture t_flor;
CTexture t_florPino;
CTexture t_escar;
CTexture t_paja;
CTexture t_Papel1;
CTexture t_Papel2;
CTexture t_Papel3;
CTexture t_Papel4;
CTexture t_Papel5;
CTexture t_Papel6;
CTexture t_agua;
CTexture t_lava;
CTexture t_cerca;
CTexture t_sueloPaja;
CTexture t_Santa;
/*-----------------------------MUÑECO----------------------------------*/
CTexture t_cabeza;
CTexture t_torso;
CTexture t_brazoDerecho;
CTexture t_brazoIzquierdo;
CTexture t_piernaIzquierdo;
CTexture t_piernaDerecho;
/*------------------------------FIGURAS----------------------------*/
CFiguras fig1;	//cielo
CFiguras fig4;	//Pasto
CFiguras fig5;	//Casa
CFiguras fig7;	//agua y lava
/*------------------------------FIGURAS 3DS----------------------------*/
CModel mesa;
CModel vela;
CModel regalo;
CModel niño;
CModel animal1;
CModel animal2;
CModel animal3;
CModel animal4;
CModel animal5;
CModel animal6;
CModel animal7;
CModel animal8;

/*------------------------------VARIABLES DE CAMARA----------------------------*/
int cam = 1;
float c1PosX = 0.13, c1PosY = 8.8, c1PosZ = 64.84, c1ViewX = 0.13, c1ViewY = 8.8, c1ViewZ = 61.84, c1UpX = 0, c1UpY = 1, c1UpZ = 0;
float c2PosX = 0.13, c2PosY = 8.8, c2PosZ = 30.01, c2ViewX = 0.34, c2ViewY = 8.8, c2ViewZ = 27.018, c2UpX = 0, c2UpY = 1, c2UpZ = 0;
float c3PosX = 0.86, c3PosY = 3.2, c3PosZ = -8.09, c3ViewX = 0.81, c3ViewY = 3.2, c3ViewZ = -11.09, c3UpX = 0, c3UpY = 1, c3UpZ = 0;
/*------------------------------VARIABLE MOVIMIENTO----------------------------*/
float alberca = 0;
float santaX = 0;
float giraSanta = 0;
bool g_fanimacion = false, avanzaSanta = true, retrocedeSanta = false;
//float cuello = 0, hombroDer = 0, hombroIzq = 0, piernaDer = 0, piernaIzq = 0;

/*------------------------------VARIABLE KEYFRAMES----------------------------*/
float rotPuerta = 0, rotVentanaDer = 0, rotVentanaIzq = 0;
float rotCuello = 0, rotHomDer = 0, rotHomIzq = 0, rotPierDer = 0, rotPierIzq = 0;

#define MAX_FRAMES 10
int i_max_steps = 30;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float rotPuerta;
	float incPuerta;
	float rotVentanaDer;
	float incVentanaDer;
	float rotVentanaIzq;
	float incVentanaIzq;

	float rotCuello;
	float incCuello;
	float rotHomDer;
	float incHomDer;
	float rotHomIzq;
	float incHomIzq;
	float rotPierDer;
	float incPierDer;
	float rotPierIzq;
	float incPierIzq;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 7;
bool play = false;
int playIndex = 0;
int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];
/*------------------------------VARIABLE QUE NO CONOZCO----------------------------*/
//int font = (int)GLUT_BITMAP_HELVETICA_18;
		
void InitGL ( GLvoid ) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals

	GLfloat luz_ambiente[] = { 0.5f,0.5f, 0.5f, 0.0f};
	GLfloat luz_difusa[] = { 1,1,1,1 }; //color Luz

	//Add positioned light
	GLfloat diffuseLightColor0[] = { 0.5f , 0.0f, 0.0f, 1.0f };
	GLfloat specularLightColor0[] = { 1,1,1,1 };
	GLfloat lightPos0[] = { 1.0f, 1.0f, 0.0f, 0.0f };
	GLfloat lightPos1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLightColor0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	glLightfv(GL_LIGHT1, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glEnable ( GL_COLOR_MATERIAL );
	glClearDepth(1.0f);								
	glEnable(GL_DEPTH_TEST);							
	glDepthFunc(GL_LEQUAL);						
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_BLEND);											

	/*----------------------------SKYBOX-----------------------------------*/
	cielo.LoadTGA("city/paisaje.tga");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	pasto.LoadTGA("city/nieve.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();
	/*-----------------------------CASA------------------------------------*/
	t_Pared.LoadTGA("city/pared.tga");
	t_Pared.BuildGLTexture();
	t_Pared.ReleaseImage();

	t_ParedPuerta.LoadTGA("city/pared1.tga");
	t_ParedPuerta.BuildGLTexture();
	t_ParedPuerta.ReleaseImage();

	t_ParedTracera.LoadTGA("city/pared2.tga");
	t_ParedTracera.BuildGLTexture();
	t_ParedTracera.ReleaseImage();

	t_Piso.LoadTGA("city/piso.tga");
	t_Piso.BuildGLTexture();
	t_Piso.ReleaseImage();

	t_Puerta.LoadTGA("city/Puerta.tga");
	t_Puerta.BuildGLTexture();
	t_Puerta.ReleaseImage();

	t_VentanaDer.LoadTGA("city/ventanader.tga");
	t_VentanaDer.BuildGLTexture();
	t_VentanaDer.ReleaseImage();

	t_VentanaIzq.LoadTGA("city/ventanaizq.tga");
	t_VentanaIzq.BuildGLTexture();
	t_VentanaIzq.ReleaseImage();
	/*-----------------------------ADORNOS---------------------------------*/
	t_Papel1.LoadTGA("city/papel1.tga");
	t_Papel1.BuildGLTexture();
	t_Papel1.ReleaseImage();

	t_Papel2.LoadTGA("city/papel2.tga");
	t_Papel2.BuildGLTexture();
	t_Papel2.ReleaseImage();

	t_Papel3.LoadTGA("city/papel3.tga");
	t_Papel3.BuildGLTexture();
	t_Papel3.ReleaseImage();

	t_Papel4.LoadTGA("city/papel4.tga");
	t_Papel4.BuildGLTexture();
	t_Papel4.ReleaseImage();

	t_Papel5.LoadTGA("city/papel5.tga");
	t_Papel5.BuildGLTexture();
	t_Papel5.ReleaseImage();

	t_Papel6.LoadTGA("city/papel6.tga");
	t_Papel6.BuildGLTexture();
	t_Papel6.ReleaseImage();

	t_agua.LoadTGA("city/agua.tga");
	t_agua.BuildGLTexture();
	t_agua.ReleaseImage();

	t_lava.LoadTGA("city/lava.tga");
	t_lava.BuildGLTexture();
	t_lava.ReleaseImage();

	t_cerca.LoadTGA("city/cerca.tga");
	t_cerca.BuildGLTexture();
	t_cerca.ReleaseImage();

	t_sueloPaja.LoadTGA("city/sueloPaja.tga");
	t_sueloPaja.BuildGLTexture();
	t_sueloPaja.ReleaseImage();

	t_flor.LoadTGA("city/flor.tga");
	t_flor.BuildGLTexture();
	t_flor.ReleaseImage();

	t_florPino.LoadTGA("city/corona.tga");
	t_florPino.BuildGLTexture();
	t_florPino.ReleaseImage();

	t_escar.LoadTGA("city/escarcha.tga");
	t_escar.BuildGLTexture();
	t_escar.ReleaseImage();

	t_paja.LoadTGA("city/paja.tga");
	t_paja.BuildGLTexture();
	t_paja.ReleaseImage();

	t_Santa.LoadTGA("city/santa.tga");
	t_Santa.BuildGLTexture();
	t_Santa.ReleaseImage();
	/*-------------------------------MUÑECO--------------------------------*/
	t_cabeza.LoadTGA("city/cabeza.tga");
	t_cabeza.BuildGLTexture();
	t_cabeza.ReleaseImage();

	t_torso.LoadTGA("city/torso.tga");
	t_torso.BuildGLTexture();
	t_torso.ReleaseImage();

	t_brazoDerecho.LoadTGA("city/brazoDerecho.tga");
	t_brazoDerecho.BuildGLTexture();
	t_brazoDerecho.ReleaseImage();

	t_brazoIzquierdo.LoadTGA("city/brazoIzquierdo.tga");
	t_brazoIzquierdo.BuildGLTexture();
	t_brazoIzquierdo.ReleaseImage();

	t_piernaDerecho.LoadTGA("city/piernaDerecho.tga");
	t_piernaDerecho.BuildGLTexture();
	t_piernaDerecho.ReleaseImage();

	t_piernaIzquierdo.LoadTGA("city/piernaIzquierda.tga");
	t_piernaIzquierdo.BuildGLTexture();
	t_piernaIzquierdo.ReleaseImage();
	/*-----------------------------Figuras 3DS----------------------------------------*/
	mesa._3dsLoad("city/table.3ds");
	vela._3dsLoad("city/vela.3ds");
	regalo._3dsLoad("city/regalo.3ds");
	niño._3dsLoad("city/niño.3ds");
	animal1._3dsLoad("city/animal1.3ds");
	animal2._3dsLoad("city/animal2.3ds");
	animal3._3dsLoad("city/animal3.3ds");
	animal4._3dsLoad("city/animal4.3ds");
	animal5._3dsLoad("city/animal5.3ds");
	animal6._3dsLoad("city/animal6.3ds");
	animal7._3dsLoad("city/animal7.3ds");
	animal8._3dsLoad("city/animal8.3ds");

	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);

	for (int i = 0; i < MAX_FRAMES; i++){
		KeyFrame[i].rotPuerta = 0;
		KeyFrame[i].rotVentanaDer = 0;
		KeyFrame[i].rotVentanaIzq = 0;

		KeyFrame[i].rotCuello = 0;
		KeyFrame[i].incCuello = 0;
		KeyFrame[i].rotHomDer = 0;
		KeyFrame[i].incHomDer = 0;
		KeyFrame[i].rotHomIzq = 0;
		KeyFrame[i].incHomIzq = 0;
		KeyFrame[i].rotPierDer = 0;
		KeyFrame[i].incPierDer = 0;
		KeyFrame[i].rotPierIzq = 0;
		KeyFrame[i].incPierIzq = 0;
	}

	KeyFrame[0].rotPuerta = 0;
	KeyFrame[0].rotVentanaDer = 0;
	KeyFrame[0].rotVentanaIzq = 0;

	/*-----------------------------------VALORES DE KEYFRAMES------------------------------------------*/

	KeyFrame[0].rotCuello = 0;
	KeyFrame[0].rotHomDer = 0;
	KeyFrame[0].rotHomIzq = 0;
	KeyFrame[0].rotPierDer = 0;
	KeyFrame[0].rotPierIzq = 0;

	KeyFrame[1].rotCuello = 0;
	KeyFrame[1].rotHomDer = 190;
	KeyFrame[1].rotHomIzq = 0;
	KeyFrame[1].rotPierDer = 0;
	KeyFrame[1].rotPierIzq = 0;

	KeyFrame[2].rotCuello = 0;
	KeyFrame[2].rotHomDer = 90;
	KeyFrame[2].rotHomIzq = 0;
	KeyFrame[2].rotPierDer = 0;
	KeyFrame[2].rotPierIzq = 0;

	KeyFrame[3].rotCuello = 0;
	KeyFrame[3].rotHomDer = 0;
	KeyFrame[3].rotHomIzq = 0;
	KeyFrame[3].rotPierDer = 0;
	KeyFrame[3].rotPierIzq = 0;

	KeyFrame[4].rotCuello = 23;
	KeyFrame[4].rotHomDer = 140;
	KeyFrame[4].rotHomIzq = -140;
	KeyFrame[4].rotPierDer = 25;
	KeyFrame[4].rotPierIzq = -25;

	KeyFrame[5].rotCuello = 0;
	KeyFrame[5].rotHomDer = 0;
	KeyFrame[5].rotHomIzq = 0;
	KeyFrame[5].rotPierDer = 0;
	KeyFrame[5].rotPierIzq = 0;
	
	KeyFrame[6].rotCuello = -23;
	KeyFrame[6].rotHomDer = 140;
	KeyFrame[6].rotHomIzq = -140;
	KeyFrame[6].rotPierDer = 25;
	KeyFrame[6].rotPierIzq = -25;
}

void cuarto1(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4) {
	GLfloat vertice[8][3] = {
		{-0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
		{-0.5, -0.5, -0.5},
		{0.5, -0.5, -0.5},
		{0.5, 0.5, -0.5},
		{-0.5, 0.5, -0.5},
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);  //Up
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura4);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();
}

void cuarto2(GLuint textura1, GLuint textura2, GLuint textura3) {
	GLfloat vertice[8][3] = {
		{-0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
		{-0.5, -0.5, -0.5},
		{0.5, -0.5, -0.5},
		{0.5, 0.5, -0.5},
		{-0.5, 0.5, -0.5},
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //Up
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();
}

void puerta(GLuint textura1) {
	GLfloat vertice[4][3] = {
		{-0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();
}

void ventana(GLuint textura1) {
	GLfloat vertice[4][3] = {
		{-0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();
}

void papel(GLuint textura1) {
	GLfloat vertice[4][3] = {
		{-0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();
}

void muñeco() {
	glPushMatrix();

		//Cabeza
		glPushMatrix();
			glTranslatef(0, .45, 0);
			glRotatef(rotCuello, 0, 0, 1);
			glPushMatrix();
				glTranslatef(0, .5, 0);
				papel(t_cabeza.GLindex);
			glPopMatrix();
		glPopMatrix();

		//Brazo Derecho
		glPushMatrix();
			glTranslatef(0.5, .35, 0);
			glRotatef(rotHomDer, 0, 0, 1);

			glPushMatrix();
				glTranslatef(0, -.4, 0);
				glScalef(0.3, 1, 1);
				papel(t_brazoDerecho.GLindex);
			glPopMatrix();
		glPopMatrix();

		//Brazo Izquierdo
		glPushMatrix();
			glTranslatef(-0.5, .35, 0);
			glRotatef(rotHomIzq, 0, 0, 1);

			glPushMatrix();
				glTranslatef(0, -.4, 0);
				glScalef(0.3, 1, 1);
				papel(t_brazoIzquierdo.GLindex);
			glPopMatrix();
		glPopMatrix();

		//Pierna Derecha
		glPushMatrix();
			glTranslatef(0.25, -1, 0);
			glRotatef(rotPierDer, 0, 0, 1);
				
			glPushMatrix();
				glTranslatef(0, -.55, 0);
				glScalef(0.4, 1, 1);
				papel(t_piernaDerecho.GLindex);
			glPopMatrix();
		glPopMatrix();

		//Pierna Izquierda
		glPushMatrix();
			glTranslatef(-0.25, -1, 0);
			glRotatef(rotPierIzq, 0, 0, 1);
				
			glPushMatrix();
				glTranslatef(0, -.55, 0);
				glScalef(0.4, 1, 1);
				papel(t_piernaIzquierdo.GLindex);
			glPopMatrix();
		glPopMatrix();

		glTranslatef(0, -.3, 0);
		glScalef(0.7, 1.5, 1);
		papel(t_torso.GLindex);
	glPopMatrix();
}

void interpolado() {
	KeyFrame[playIndex].incCuello = (KeyFrame[playIndex + 1].rotCuello - KeyFrame[playIndex].rotCuello) / i_max_steps;
	KeyFrame[playIndex].incHomDer = (KeyFrame[playIndex + 1].rotHomDer - KeyFrame[playIndex].rotHomDer) / i_max_steps;
	KeyFrame[playIndex].incHomIzq = (KeyFrame[playIndex + 1].rotHomIzq - KeyFrame[playIndex].rotHomIzq) / i_max_steps;
	KeyFrame[playIndex].incPierDer = (KeyFrame[playIndex + 1].rotPierDer - KeyFrame[playIndex].rotPierDer) / i_max_steps;
	KeyFrame[playIndex].incPierIzq = (KeyFrame[playIndex + 1].rotPierIzq - KeyFrame[playIndex].rotPierIzq) / i_max_steps;
}

void resetElementsM() {
	playIndex = 0;
	rotCuello = KeyFrame[0].rotCuello;
	rotHomDer = KeyFrame[0].rotHomDer;
	rotHomIzq = KeyFrame[0].rotHomIzq;
	rotPierDer = KeyFrame[0].rotPierDer;
	rotPierIzq = KeyFrame[0].rotPierIzq;
}

void florPino() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_florPino.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_florPino.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_florPino.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_florPino.GLindex);
	glPopMatrix();
}

void estrella() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_Papel4.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_Papel4.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_Papel4.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_Papel4.GLindex);
	glPopMatrix();
}

void esferas() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_Papel2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_Papel2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_Papel2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_Papel2.GLindex);
	glPopMatrix();
}

void escarcha() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_escar.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_escar.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_escar.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_escar.GLindex);
	glPopMatrix();
}

void corona() {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / 12;
	float x = 0, y = 0, r = 1;

	for (int i = 0; i <= 12; i ++) {
		glPushMatrix();
			glTranslatef(r * cos(x), 0, r * sin(y));
			x = i * angulo, y = i * angulo;
			florPino();
		glPopMatrix();
	}	
}

void corona1(float r) {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / 15;
	float x = 0, y = 0;

	for (int i = 0; i <= 15; i++) {
		glPushMatrix();
			glScalef(0.7, 0.7, 0.7);
			glTranslatef(r * cos(x), 0, r * sin(y));
			x = i * angulo, y = i * angulo;
			escarcha();
		glPopMatrix();
	}
}

void esfera(float r, int latitudes, int longitudes)
{
	const float pi = 3.14159265358979323846;
	float anguloA = (2 * pi) / latitudes;
	float anguloB = (2 * pi) / longitudes;
	float x = 0, y = 0;


	for (int i = 0; i < latitudes / 2; i++) {
		for (int j = 0; j < longitudes; j++) {
			glBegin(GL_POLYGON);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
			x = i * anguloA, y = j * anguloB;
			glNormal3f(r * sin(x) * cos(y), r * sin(x) * sin(y), r * cos(x));
			glVertex3f(r * sin(x) * cos(y), r * sin(x) * sin(y), r * cos(x));
			x = (i + 1) * anguloA;
			glVertex3f(r * sin(x) * cos(y), r * sin(x) * sin(y), r * cos(x));
			y = (j + 1) * anguloB;
			glVertex3f(r * sin(x) * cos(y), r * sin(x) * sin(y), r * cos(x));
			x = (i - 1) * anguloA;
			glVertex3f(r * sin(x) * cos(y), r * sin(x) * sin(y), r * cos(x));
			glEnd();
		}
	}
}

void cono(float r, int lados) {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / lados;
	float x = 0, y = 0;

	for (int i = 0; i <= lados; i++) {
		glBegin(GL_POLYGON);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
		glNormal3f(r * cos(x), r * sin(y), -0.3f);

		glVertex3f(r * cos(x), r * sin(y), 0.5);
		x = i * angulo, y = i * angulo;
		glVertex3f(r * cos(x), r * sin(y), 0.5);
		glVertex3f(0, 0, -0.5);
		glEnd();
	}
}

void tronco(float r, int lados) {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / lados;
	float x = 0, y = 0;

	for (int i = 0; i <= lados; i++) {
		glBegin(GL_POLYGON);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
		glVertex3f(r * cos(x), r * sin(y), 1);
		glVertex3f(r * cos(x), r * sin(y), -1);
		x = i * angulo, y = i * angulo;
		glNormal3f(r * cos(x), r * sin(y), 0);
		glVertex3f(r * cos(x), r * sin(y), -1);
		glVertex3f(r * cos(x), r * sin(y), 1);
		glEnd();
	}
}

void cilindro(float r, int lados) {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / lados;
	float x = 0, y = 0;

	for (int i = 0; i <= lados; i++) {
		glBegin(GL_POLYGON);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
		glVertex3f(r * cos(x), r * sin(y), 1);
		glVertex3f(r * cos(x), r * sin(y), -1);
		x = i * angulo, y = i * angulo;
		glNormal3f(r * cos(x), r * sin(y), 0);
		glVertex3f(r * cos(x), r * sin(y), -1);
		glVertex3f(r * cos(x), r * sin(y), 1);
		glEnd();
	}
}

void piñata() {
	glPushMatrix(); //esferea
		glTranslatef(0,0,0);
		glScalef(1, 1, 1);
		esfera(1,100,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glTranslatef(1.7,0,0);
		glScalef(2, 0.5, 0.5);
		glRotatef(-90, 0, 1, 0);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glTranslatef(-1.7,0,0);
		glScalef(2, 0.5, 0.5);
		glRotatef(90, 0, 1, 0);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glRotatef(-90, 1, 0, 0);
		glTranslatef(0, 0, -1.7);
		glScalef(0.5, 0.5, 2);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glTranslatef(0, 0, -1.7);
		glScalef(0.5, 0.5, 2);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glRotatef(180, 1, 0, 0);
		glTranslatef(0, 0, -1.7);
		glScalef(0.5, 0.5, 2);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glRotatef(90, 1, 0, 0);
		glTranslatef(0, 0, -0.7);
		glScalef(0.5, 0.5, 0.5);
		cilindro(1,100);
	glPopMatrix();

}

void arbol() {
	glPushMatrix(); //cono
		glTranslatef(0, 2, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(2, 2, 4);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glTranslatef(0, 0, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(3, 3, 6);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //cono
		glTranslatef(0, -2, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 4, 8);
		cono(1,100);
	glPopMatrix();

	glPushMatrix(); //tronco
		glTranslatef(0,-4,0);
		glRotatef(90, 1, 0, 0);
		glScalef(1, 1, 4);
		tronco(1,100);
	glPopMatrix();

	glPushMatrix();  //escarcha
		glTranslatef(0, 1, -0.8);
		glScalef(2, 1, 2);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				corona1(1.3);
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //escarcha
		glTranslatef(0, -1.5, -0.8);
		glScalef(2, 1, 2);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				corona1(2);
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //escarcha
		glTranslatef(0, -4.3, -0.8);
		glScalef(2, 1, 2);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				corona1(2.5);
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //estrella
		glTranslatef(0, 4.3, -1);
		glScalef(2, 1, 2);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				estrella();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(2, -.3, 0);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(0, -.3, 2);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(-2, -.3, 0);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(0, -.3, -2.2);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(3, -3.3, 0);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(-3, -3.3, 0);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(0, -3.3, 3);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();  //esfera
		glTranslatef(0, -3.3, -3.3);
		glScalef(.5, .5, .5);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				esferas();
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void flor() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_flor.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_flor.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_flor.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_flor.GLindex);
	glPopMatrix();
}

void paja() {
	glPushMatrix();
		glScalef(1, 1.3, 1);
		papel(t_paja.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.5,0,.5);
		glScalef(1, 1.3, 1);
		glRotatef(90, 0, 1, 0);
		papel(t_paja.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-.4,0, .15);
		glScalef(1, 1.3, 1);
		glRotatef(45, 0, 1, 0);
		papel(t_paja.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(.4,0, .2);
		glScalef(1, 1.3, 1);
		glRotatef(-45, 0, 1, 0);
		papel(t_paja.GLindex);
	glPopMatrix();
}

void nacim(float r) {
	const float pi = 3.14159265358979323846;
	float angulo = (2 * pi) / 15;
	float x = 0, y = 0;

	for (int i = 0; i <= 15; i++) {
		glPushMatrix();
		glScalef(0.7, 0.7, 0.7);
		glTranslatef(r * cos(x), 0, r * sin(y));
		x = i * angulo, y = i * angulo;
		paja();
		glPopMatrix();
	}
}

void casa (){
	glPushMatrix(); //cuarto principal
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0,1.0,2.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				cuarto1(t_ParedPuerta.GLindex, t_Pared.GLindex, t_ParedTracera.GLindex, t_Piso.GLindex);
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix(); //Cuarto del pecebre
		glTranslatef(0, 0, -2.001);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0,1.0,2.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				cuarto2(t_ParedTracera.GLindex, t_Pared.GLindex, t_Piso.GLindex);
			glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}

void display ( void ) {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);
		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z, objCamera.mView.x, objCamera.mView.y, objCamera.mView.z, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	
		glPushMatrix();		
			
			glPushMatrix(); //Creamos el cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0, cielo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Creamos el pasto
				glTranslatef(0, 0, 0);
				glScalef(140,0.1,140);
				glDisable(GL_LIGHTING);
				fig4.prisma_text(pasto.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			if (!light)
			{
				glDisable(GL_LIGHT0);
			}
			else
			{
				glEnable(GL_LIGHT0);
			}

			glPushMatrix(); //Creamos la casa
				glTranslatef(0, 7.6, 26);
				glScalef(15, 15, 15);
				
				casa();
			glPopMatrix();

			glPushMatrix(); //Puerta
				glTranslatef(-5.5, 6.6, 41);
				glRotatef(rotPuerta, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);
				glPushMatrix();
					glTranslatef(5.5, 0, -0.5);
					glScalef(10.9,13.0,1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							puerta(t_Puerta.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //Ventana Izquierda
				glTranslatef(-14, 9, 41);
				glRotatef(rotVentanaIzq, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(3.8, -0.1, -0.5);
					glScalef(7.7, 7.85, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							ventana(t_VentanaIzq.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //Ventana Derecha
				glTranslatef(14.2, 9, 41);
				glRotatef(rotVentanaDer, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -0.5);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							ventana(t_VentanaDer.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(14.2, 9, 11.1);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -0.5);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(-6, 9, 12);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -1.4);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(14.2, 9, 10.9);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -0.5);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(-6, 9, 11.8);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -1.4);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(14.2, 9, -19);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -0.5);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 1
				glTranslatef(-6, 9, -18.1);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -1.4);
					glScalef(7.6, 7.88, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel1.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 5
				glTranslatef(3.8, 11.3, 12);
				glRotatef(-90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(13.5, 2, -11.6);
					glScalef(2, 2, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel5.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 5
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-13.5, 2, -19.2);
					glScalef(2, 2, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel5.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, 12);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -1.4);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-5, -0.1, 10.65);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-22, -0.1, 10.65);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-5, -0.1, -19.2);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-22, -0.1, -19.2);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 5
				glTranslatef(3.8, 11.3, -18);
				glRotatef(-90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(13.5, 2, -11.6);
					glScalef(2, 2, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel5.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 5
				glTranslatef(3.8, 11.3, -18);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-13.5, 2, -19.2);
					glScalef(2, 2, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel5.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, -18);
				glRotatef(0, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-3.8, -0.1, -1.4);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, -18);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-5, -0.1, 10.65);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, -18);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-22, -0.1, 10.65);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, -18);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-5, -0.1, -19.2);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 6
				glTranslatef(3.8, 11.3, -18);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-22, -0.1, -19.2);
					glScalef(12, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel6.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //muñeco1
				glTranslatef(3.8, 11.3, 12);
				glRotatef(90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(-13.5, -4, -19.2);
					glScalef(5, 3, 1.0);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							muñeco();
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //papel 3
				glTranslatef(3.8, 11.3, 12);
				glRotatef(-90, 0, 1, 0);
				glColor3f(1.0, 1.0, 1.0);

				glPushMatrix();
					glTranslatef(13.5, -2.5, -11.6);
					glScalef(4.5, 4.5, 1.0);
					glRotatef(-30, 0, 0, 1);
					
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							papel(t_Papel3.GLindex);
						glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
					
				glPopMatrix();
			glPopMatrix();

			glPushMatrix();  //Flor
				glTranslatef(11, 2.15, 11);
				glScalef(3, 3, 3);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						flor();
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix();  //Flor
				glTranslatef(-11, 2.15, 37);
				glScalef(3, 3, 3);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						flor();
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix();  //Flor
				glTranslatef(11, 2.15, 37);
				glScalef(3, 3, 3);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						flor();
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //Mesa
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(11.9, 2, 25.5);
				glScalef(1, .5, 1);
				glRotatef(90, 0, 1, 0);
				mesa.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			
			glPushMatrix();  //Corona
				glTranslatef(11.9, 4.5, 24.5);
				glScalef(2, 1, 2);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						corona();
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //Vela
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(13, 4, 25.5);
				glScalef(0.1, 0.05, 0.1);
				vela.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //Vela
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(11, 4, 25.5);
				glScalef(0.1, 0.05, 0.1);
				vela.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //Vela
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(12, 4, 26.5);
				glScalef(0.1, 0.05, 0.1);
				vela.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //Vela
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(12, 4, 24.5);
				glScalef(0.1, 0.05, 0.1);
				vela.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //santa
				glTranslatef(0,30,0);
				glTranslatef(santaX * 2, 0, 0);
				glRotatef(giraSanta,0,1,0);
				glScalef(17, 13, 1);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.7);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_Santa.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //piñata
				glTranslatef(0, 13, 25);
				glScalef(1, 1, 1);
				piñata();
			glPopMatrix();

			glPushMatrix(); //arbol
				glTranslatef(-10, 8, 18);
				glScalef(1, 1, 1);
				arbol();
			glPopMatrix();

			glPushMatrix(); //regalo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-11, 0.2, 22);
				glScalef(1, 1, 1);
				regalo.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //regalo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-7, 0.2, 21);
				glScalef(1, 1, 1);
				regalo.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //regalo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-5.5, 0.2, 18);
				glScalef(1, 1, 1);
				regalo.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //regalo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-6, 0.2, 15);
				glScalef(1, 1, 1);
				regalo.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();  //Corona
				glTranslatef(0, 0.5, -18);
				glScalef(2, 1, 2);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						nacim(0.5);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //niño
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(0, 1, -17.3);
				glRotatef(-90, 1, 0, 0);
				glScalef(0.01, 0.01, 0.01);
				niño.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //caballo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-2, -0.4, -15);
				glRotatef(120, 0, 1, 0);
				glScalef(0.03, 0.03, 0.03);
				animal1.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //gallina
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(0, 3.6, -15);
				glRotatef(180, 0, 1, 0);
				glScalef(0.15, 0.15, 0.15);
				animal2.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //cabra
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(3, 3.85, -15.5);
				glRotatef(-120, 0, 1, 0);
				glScalef(0.3, 0.3, 0.3);
				animal3.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //bufalo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(5, 2, -17.5);
				glRotatef(90, 0, 1, 0);
				glScalef(6, 6, 6);
				animal5.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //cerdo
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-4, 3.4, -17.5);
				glRotatef(90, 0, 1, 0);
				glScalef(0.5, 0.5, 0.5);
				animal6.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //perro
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(2, 3.8, -15);
				glRotatef(-150, 0, 1, 0);
				glScalef(0.5, 0.5, 0.5);
				animal7.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //borrego
				glDisable(GL_COLOR_MATERIAL);
				glTranslatef(-4, 3.3, -16);
				glRotatef(120, 0, 1, 0);
				glScalef(0.5, 0.5, 0.5);
				animal8.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix(); //cerca
				glTranslatef(-4, 1.5, -19);
				glScalef(5, 7, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_cerca.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //cerca
				glTranslatef(1, 1.5, -19);
				glScalef(5, 7, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_cerca.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //cerca
				glTranslatef(6, 1.5, -19);
				glScalef(5, 7, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_cerca.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //cerca
				glTranslatef(-7, 1.5, -16);
				glRotatef(90, 0, 1, 0);
				glScalef(5, 7, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_cerca.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //cerca
				glTranslatef(8, 1.5, -16);
				glRotatef(90, 0, 1, 0);
				glScalef(5, 7, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_cerca.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //Suelo paja
				glTranslatef(1, 0.7, -16);
				glRotatef(90, 1, 0, 0);
				glScalef(15, 5, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_sueloPaja.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix(); //techo madera pecebre
			if (!luzpecebre)
			{
				glDisable(GL_LIGHT1);
			}
			else
			{
				glEnable(GL_LIGHT1);
			}
				glTranslatef(1, 5.4, -16);
				glRotatef(90, 1, 0, 0);
				glScalef(15, 5, 1.0);
				
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						papel(t_Pared.GLindex);
					glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();

			glPushMatrix();//agua
				glTranslatef(-10.7, 0, -16);
				glScalef(0.3, 0.3, 0.3);
				fig7.alberca(2.0, 22.0, 14.0, t_agua.GLindex, 0);

					glPushMatrix();
						glTranslatef(0.0, 1.1, 0.0);
						
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						glBindTexture(GL_TEXTURE_2D, t_agua.GLindex);
						glBegin(GL_QUADS);
						glNormal3f(0, 0, 1);
							glTexCoord2f(0 + alberca, 0 + alberca);	glVertex3f(11, 0, -7);
							glTexCoord2f(1 + alberca, 0 + alberca);	glVertex3f(-11, 0, -7);
							glTexCoord2f(1 + alberca, 1 + alberca);	glVertex3f(-11, 0, 7);
							glTexCoord2f(0 + alberca, 1 + alberca);	glVertex3f(11, 0, 7);
						glEnd();
						
						glDisable(GL_ALPHA_TEST);
						glDisable(GL_CULL_FACE);
						glDepthFunc(GL_LEQUAL);
					glPopMatrix();
			glPopMatrix();

			glPushMatrix();//lava
				glTranslatef(11.7, 0, -16);
				glScalef(0.25, 0.3, 0.3);
				fig7.alberca(2.0, 22.0, 14.0, t_lava.GLindex, 0);

					glPushMatrix();
						glTranslatef(0.0, 1.1, 0.0);
						
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						glBindTexture(GL_TEXTURE_2D, t_lava.GLindex);
						glBegin(GL_QUADS);
						glNormal3f(0, 0, 1);
							glTexCoord2f(0 + alberca, 0 + alberca);	glVertex3f(11, 0, -7);
							glTexCoord2f(1 + alberca, 0 + alberca);	glVertex3f(-11, 0, -7);
							glTexCoord2f(1 + alberca, 1 + alberca);	glVertex3f(-11, 0, 7);
							glTexCoord2f(0 + alberca, 1 + alberca);	glVertex3f(11, 0, 7);
						glEnd();
						
						glDisable(GL_ALPHA_TEST);
						glDisable(GL_CULL_FACE);
						glDepthFunc(GL_LEQUAL);
					glPopMatrix();
			glPopMatrix();

		glPopMatrix();
	
	glPopMatrix();

	glutSwapBuffers ();
}

void animacion() {
	if(g_fanimacion){
		if (santaX >= 20 || santaX <= -20) {
			avanzaSanta = !avanzaSanta;
			retrocedeSanta = !retrocedeSanta;
			giraSanta += 180;
		}

		if (avanzaSanta == true)
			santaX += 0.1;

		if (retrocedeSanta == true)
			santaX -= 0.1;
	}

	if (play){

		if (i_curr_steps >= i_max_steps){
			playIndex++;
			if (playIndex > FrameIndex - 2){
				printf("termina anim\n");
				playIndex = 0;
				play = false;
				resetElementsM();
			} else {
				i_curr_steps = 0; 

				interpolado();

				KeyFrame[playIndex].incPuerta = (KeyFrame[playIndex + 1].rotPuerta - KeyFrame[playIndex].rotPuerta) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incVentanaDer = (KeyFrame[playIndex + 1].rotVentanaDer - KeyFrame[playIndex].rotVentanaDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incVentanaIzq = (KeyFrame[playIndex + 1].rotVentanaIzq - KeyFrame[playIndex].rotVentanaIzq) / i_max_steps;		//100 frames
			}
		}

		else{
			rotPuerta += KeyFrame[playIndex].incPuerta;
			rotVentanaDer += KeyFrame[playIndex].incVentanaDer;
			rotVentanaIzq += KeyFrame[playIndex].incVentanaIzq;

			rotCuello += KeyFrame[playIndex].incCuello;
			rotHomDer += KeyFrame[playIndex].incHomDer;
			rotHomIzq += KeyFrame[playIndex].incHomIzq;
			rotPierDer += KeyFrame[playIndex].incPierDer;
			rotPierIzq += KeyFrame[playIndex].incPierIzq;

			i_curr_steps++;
		}
	}

	alberca += 0.002;

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height ) {
  if (height==0)
		height=1;

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);					
	glLoadIdentity();

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y ) {
	switch ( key ) {
		case '0':
			printf("%f\n", objCamera.mPos.x);
			printf("%f\n", objCamera.mPos.y);
			printf("%f\n", objCamera.mPos.z);

			printf("%f\n", objCamera.mView.x);
			printf("%f\n", objCamera.mView.y);
			printf("%f\n", objCamera.mView.z);

			printf("%f\n", objCamera.mUp.x);
			printf("%f\n", objCamera.mUp.y);
			printf("%f\n", objCamera.mUp.z);
		break;

		case '1':
			cam = 1;
			objCamera.mPos.x = c1PosX;
			objCamera.mPos.y = c1PosY;
			objCamera.mPos.z = c1PosZ;

			objCamera.mView.x = c1ViewX;
			objCamera.mView.y = c1ViewY;
			objCamera.mView.z = c1ViewZ;

			objCamera.mUp.x = c1UpX;
			objCamera.mUp.y = c1UpY;
			objCamera.mUp.z = c1UpZ;
		break;
			
		case '2':
			cam = 2;
			objCamera.mPos.x = c2PosX;
			objCamera.mPos.y = c2PosY;
			objCamera.mPos.z = c2PosZ;

			objCamera.mView.x = c2ViewX;
			objCamera.mView.y = c2ViewY;
			objCamera.mView.z = c2ViewZ;

			objCamera.mUp.x = c2UpX;
			objCamera.mUp.y = c2UpY;
			objCamera.mUp.z = c2UpZ;

			PlaySound(TEXT("sonidos/cuarto1.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;

		case '3':
			cam = 3;
			objCamera.mPos.x = c3PosX;
			objCamera.mPos.y = c3PosY;
			objCamera.mPos.z = c3PosZ;

			objCamera.mView.x = c3ViewX;
			objCamera.mView.y = c3ViewY;
			objCamera.mView.z = c3ViewZ;

			objCamera.mUp.x = c3UpX;
			objCamera.mUp.y = c3UpY;
			objCamera.mUp.z = c3UpZ;

			PlaySound(TEXT("sonidos/cuarto2.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;

		case 'w':
		case 'W':
			if (cam == 1) {
				objCamera.Move_Camera(CAMERASPEED + 0.2);

				c1PosX = objCamera.mPos.x;
				c1PosY = objCamera.mPos.y;
				c1PosZ = objCamera.mPos.z;

				c1ViewX = objCamera.mView.x;
				c1ViewY = objCamera.mView.y;
				c1ViewZ = objCamera.mView.z;

				c1UpX = objCamera.mUp.x;
				c1UpY = objCamera.mUp.y;
				c1UpZ = objCamera.mUp.z;
			}

			if (cam == 2) {
				c2PosX = objCamera.mPos.x;
				c2PosY = objCamera.mPos.y;
				c2PosZ = objCamera.mPos.z;

				c2ViewX = objCamera.mView.x;
				c2ViewY = objCamera.mView.y;
				c2ViewZ = objCamera.mView.z;

				c2UpX = objCamera.mUp.x;
				c2UpY = objCamera.mUp.y;
				c2UpZ = objCamera.mUp.z;
			}

			if (cam == 3) {
				c3PosX = objCamera.mPos.x;
				c3PosY = objCamera.mPos.y;
				c3PosZ = objCamera.mPos.z;

				c3ViewX = objCamera.mView.x;
				c3ViewY = objCamera.mView.y;
				c3ViewZ = objCamera.mView.z;

				c3UpX = objCamera.mUp.x;
				c3UpY = objCamera.mUp.y;
				c3UpZ = objCamera.mUp.z;
			}
			break;

		case 's':
		case 'S':
			if (cam == 1) {
				objCamera.Move_Camera(-(CAMERASPEED + 0.2));

				c1PosX = objCamera.mPos.x;
				c1PosY = objCamera.mPos.y;
				c1PosZ = objCamera.mPos.z;

				c1ViewX = objCamera.mView.x;
				c1ViewY = objCamera.mView.y;
				c1ViewZ = objCamera.mView.z;

				c1UpX = objCamera.mUp.x;
				c1UpY = objCamera.mUp.y;
				c1UpZ = objCamera.mUp.z;
			}

			if (cam == 2) {
				c2PosX = objCamera.mPos.x;
				c2PosY = objCamera.mPos.y;
				c2PosZ = objCamera.mPos.z;

				c2ViewX = objCamera.mView.x;
				c2ViewY = objCamera.mView.y;
				c2ViewZ = objCamera.mView.z;

				c2UpX = objCamera.mUp.x;
				c2UpY = objCamera.mUp.y;
				c2UpZ = objCamera.mUp.z;
			}

			if (cam == 3) {
				c3PosX = objCamera.mPos.x;
				c3PosY = objCamera.mPos.y;
				c3PosZ = objCamera.mPos.z;

				c3ViewX = objCamera.mView.x;
				c3ViewY = objCamera.mView.y;
				c3ViewZ = objCamera.mView.z;

				c3UpX = objCamera.mUp.x;
				c3UpY = objCamera.mUp.y;
				c3UpZ = objCamera.mUp.z;
			}
			break;

		case 'a':
		case 'A':
			if (cam == 1) {
				objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));

				c1PosX = objCamera.mPos.x;
				c1PosY = objCamera.mPos.y;
				c1PosZ = objCamera.mPos.z;

				c1ViewX = objCamera.mView.x;
				c1ViewY = objCamera.mView.y;
				c1ViewZ = objCamera.mView.z;

				c1UpX = objCamera.mUp.x;
				c1UpY = objCamera.mUp.y;
				c1UpZ = objCamera.mUp.z;
			}

			if (cam == 2) {
				c2PosX = objCamera.mPos.x;
				c2PosY = objCamera.mPos.y;
				c2PosZ = objCamera.mPos.z;

				c2ViewX = objCamera.mView.x;
				c2ViewY = objCamera.mView.y;
				c2ViewZ = objCamera.mView.z;

				c2UpX = objCamera.mUp.x;
				c2UpY = objCamera.mUp.y;
				c2UpZ = objCamera.mUp.z;
			}

			if (cam == 3) {
				c3PosX = objCamera.mPos.x;
				c3PosY = objCamera.mPos.y;
				c3PosZ = objCamera.mPos.z;

				c3ViewX = objCamera.mView.x;
				c3ViewY = objCamera.mView.y;
				c3ViewZ = objCamera.mView.z;

				c3UpX = objCamera.mUp.x;
				c3UpY = objCamera.mUp.y;
				c3UpZ = objCamera.mUp.z;
			}
			break;

		case 'd':
		case 'D':
			if (cam == 1) {
				objCamera.Strafe_Camera(CAMERASPEED + 0.4);
				
				c1PosX = objCamera.mPos.x;
				c1PosY = objCamera.mPos.y;
				c1PosZ = objCamera.mPos.z;

				c1ViewX = objCamera.mView.x;
				c1ViewY = objCamera.mView.y;
				c1ViewZ = objCamera.mView.z;

				c1UpX = objCamera.mUp.x;
				c1UpY = objCamera.mUp.y;
				c1UpZ = objCamera.mUp.z;
			}

			if (cam == 2) {
				c2PosX = objCamera.mPos.x;
				c2PosY = objCamera.mPos.y;
				c2PosZ = objCamera.mPos.z;

				c2ViewX = objCamera.mView.x;
				c2ViewY = objCamera.mView.y;
				c2ViewZ = objCamera.mView.z;

				c2UpX = objCamera.mUp.x;
				c2UpY = objCamera.mUp.y;
				c2UpZ = objCamera.mUp.z;
			}

			if (cam == 3) {
				c3PosX = objCamera.mPos.x;
				c3PosY = objCamera.mPos.y;
				c3PosZ = objCamera.mPos.z;

				c3ViewX = objCamera.mView.x;
				c3ViewY = objCamera.mView.y;
				c3ViewZ = objCamera.mView.z;

				c3UpX = objCamera.mUp.x;
				c3UpY = objCamera.mUp.y;
				c3UpZ = objCamera.mUp.z;
			}
			break;

		case 'k':		//
		case 'K':
			if (FrameIndex < MAX_FRAMES){
				printf("frameindex %d\n", FrameIndex);

				KeyFrame[FrameIndex].rotPuerta = rotPuerta;
				KeyFrame[FrameIndex].rotVentanaDer = rotVentanaDer;
				KeyFrame[FrameIndex].rotVentanaIzq = rotVentanaIzq;

				KeyFrame[FrameIndex].rotCuello = rotCuello;
				KeyFrame[FrameIndex].rotHomDer = rotHomDer;
				KeyFrame[FrameIndex].rotHomIzq = rotHomIzq;
				KeyFrame[FrameIndex].rotPierDer = rotPierDer;
				KeyFrame[FrameIndex].rotPierIzq = rotPierIzq;

				FrameIndex++;
			}

			printf("cuello: %f\n", rotCuello);
			printf("homDer: %f\n", rotHomDer);
			printf("homIzq: %f\n", rotHomIzq);
			printf("pierDer: %f\n", rotPierDer);
			printf("pierIzq: %f\n", rotPierIzq);




			break;

		case 'l':
		case 'L':
			if (play == false && (FrameIndex > 1)){
				rotPuerta = KeyFrame[0].rotPuerta;
				rotVentanaDer = KeyFrame[0].rotVentanaDer;
				rotVentanaIzq = KeyFrame[0].rotVentanaIzq;

				rotCuello = KeyFrame[0].rotCuello;
				rotHomDer = KeyFrame[0].rotHomDer;
				rotHomIzq = KeyFrame[0].rotHomIzq;
				rotPierDer = KeyFrame[0].rotPierDer;
				rotPierIzq = KeyFrame[0].rotPierIzq;

				//First Interpolation
				KeyFrame[playIndex].incPuerta = (KeyFrame[playIndex + 1].rotPuerta - KeyFrame[playIndex].rotPuerta) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incVentanaDer = (KeyFrame[playIndex + 1].rotVentanaDer - KeyFrame[playIndex].rotVentanaDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incVentanaIzq = (KeyFrame[playIndex + 1].rotVentanaIzq - KeyFrame[playIndex].rotVentanaIzq) / i_max_steps;		//100 frames

				KeyFrame[playIndex].incCuello = (KeyFrame[playIndex + 1].rotCuello - KeyFrame[playIndex].rotCuello) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incHomDer = (KeyFrame[playIndex + 1].rotHomDer - KeyFrame[playIndex].rotHomDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incHomIzq = (KeyFrame[playIndex + 1].rotHomIzq - KeyFrame[playIndex].rotHomIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incPierDer = (KeyFrame[playIndex + 1].rotPierDer - KeyFrame[playIndex].rotPierDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incPierIzq = (KeyFrame[playIndex + 1].rotPierIzq - KeyFrame[playIndex].rotPierIzq) / i_max_steps;		//100 frames
				
				play = true;
				playIndex = 0;
				i_curr_steps = 0;

			}else
				play = false;
			break;

		case 'n':
			rotVentanaDer++;
			break;

		case 'N':
			rotVentanaDer--;
			break;

		case 'b':
			rotPuerta++;
			break;

		case 'B':
			rotPuerta--;
			break;

		case 'v':
			rotVentanaIzq++;
			break;

		case 'V':
			rotVentanaIzq--;
			break;

		case 'y':
			rotCuello++;
			break;

		case 'Y':
			rotCuello--;
			break;

		case 'u':
			rotHomDer++;
			break;

		case 'U':
			rotHomDer--;
			break;

		case 't':
			rotHomIzq++;
			break;

		case 'T':
			rotHomIzq--;
			break;

		case 'j':
			rotPierDer++;
			break;

		case 'J':
			rotPierDer--;
			break;

		case 'g':
			rotPierIzq++;
			break;

		case 'G':
			rotPierIzq--;
			break;
		case 'z':   //Activamos/desactivamos luz
		case 'Z':
			light = !light;
			break;

		case 'x':   //Activamos/desactivamos luz
		case 'X':
			luzpecebre = !luzpecebre;
			break;


		case ' ':		//Poner algo en movimiento
			g_fanimacion = !g_fanimacion; //Activamos/desactivamos la animacíon
			break;

		case 27:
			exit ( 0 );
			break;        
		default:
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y ) {

	switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		if (cam == 1) {
			objCamera.UpDown_Camera(CAMERASPEED);

			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (cam == 1) {
			objCamera.UpDown_Camera(-CAMERASPEED);

			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}

		break;

    case GLUT_KEY_UP:
		g_lookupdown -= 1.0f;

		if (cam == 1) {
			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}
		break;

    case GLUT_KEY_DOWN:
		g_lookupdown += 1.0f;

		if (cam == 1) {
			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);

		if (cam == 1) {
			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);

		if (cam == 1) {
			c1PosX = objCamera.mPos.x;
			c1PosY = objCamera.mPos.y;
			c1PosZ = objCamera.mPos.z;

			c1ViewX = objCamera.mView.x;
			c1ViewY = objCamera.mView.y;
			c1ViewZ = objCamera.mView.z;

			c1UpX = objCamera.mUp.x;
			c1UpY = objCamera.mUp.y;
			c1UpZ = objCamera.mUp.z;
		}

		if (cam == 2) {
			c2PosX = objCamera.mPos.x;
			c2PosY = objCamera.mPos.y;
			c2PosZ = objCamera.mPos.z;

			c2ViewX = objCamera.mView.x;
			c2ViewY = objCamera.mView.y;
			c2ViewZ = objCamera.mView.z;

			c2UpX = objCamera.mUp.x;
			c2UpY = objCamera.mUp.y;
			c2UpZ = objCamera.mUp.z;
		}

		if (cam == 3) {
			c3PosX = objCamera.mPos.x;
			c3PosY = objCamera.mPos.y;
			c3PosZ = objCamera.mPos.z;

			c3ViewX = objCamera.mView.x;
			c3ViewY = objCamera.mView.y;
			c3ViewZ = objCamera.mView.z;

			c3UpX = objCamera.mUp.x;
			c3UpY = objCamera.mUp.y;
			c3UpZ = objCamera.mUp.z;
		}
		break;

    default:
		break;
  }

  glutPostRedisplay();
}

int main ( int argc, char** argv ) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Proyecto Final");
  InitGL();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);	
  glutSpecialFunc(arrow_keys);	
  glutIdleFunc(animacion);
  glutMainLoop();     

  return 0;
}