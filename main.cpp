//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

//*************variables para movimientos u animaciones
float transpuerta1 = 0.0f;
float transpuerta2 = 0.0f;
float transventana1izq = 0.0f;
float transventana1der = 0.0f;

float transpuerta11 = 0.0f;
float transpuerta22 = 0.0f;
float transventana1izq2 = 0.0f;
float transventana1der2 = 0.0f;

float movbruja = 0.0;
float arribaabajo = 0.0;
float movmurci = 0.0;

bool g_fanima = false;
bool g_fanima2 = false;

bool g_fanimacion = false;
bool g_fanimacion2 = false;

bool h_fanimacion = false;
bool h_fanimacion2 = false;

float alberca = 0; // Animacion para la alberca

#if (_MSC_VER >=1900)
#pragma comment (lib,"legacy_stdio_definitions.lib")
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


GLfloat Ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Specular Light Values
GLfloat Position[] = { 0.5f, 0.5f, 0.5f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//*******************texturas************
CTexture atardecersky;//paredes skybox
CTexture pastosky;//suelo skybox

CTexture sueloterror;
CTexture paredesterror;
CTexture techoterror;
CTexture frontalterror;
CTexture traseraterror;
CTexture transparente;
CTexture puertaterror;//puerta frontal casa terror
CTexture puerta2terror;//puerta frontal casa terror
CTexture ventanaterror;//ventana
CTexture textbruja;
CTexture letrerobienvenida;
CTexture sangre;//alberca de sangre
CTexture paredalberca;
CTexture letrero;
CTexture murcielago;

//*********************Texturas cuarto muertos****************
CTexture textcasa;//Paredes casa
CTexture textcasa2;//pared frontal de casa1 con puerta y ventanas
CTexture textcasa3;//pared trasera con una puerta casa1
CTexture textpuerta1;//Puerta frontal casa
CTexture textpapel1;//Papel Picado
CTexture textpapel2;//Papel Picado 2
CTexture textpapel3;//Papel Picado 3
CTexture textpapel4;//Papel Picado 4
CTexture textpapel5;//Papel Picado 5
CTexture textpapel6;//Papel Picado 6
CTexture textcartel;//Cartel
CTexture textcartel2;//Carte2
CTexture textcoco;//Mamá COCO
CTexture textjarra;//Jarra barro
CTexture textcempa;//Flor de cempasuchil
CTexture textahumador;//Ahumador
CTexture textpapelmesa;//Papel mesa cubre mesa
CTexture textpapeltecho1;//Papel techo 1
CTexture textpan;//Pan 1
CTexture textazucarcalavera;//Azucar calavera 1
CTexture textventana;

//*******************Figuras*********
CFiguras fig1;//fig skybox
CFiguras fig2;//fig cuarto1
CFiguras fig3;//fig para articular
CFiguras fig4;//fig puerta frontal casa terror
CFiguras fig5;//fig ventana izq casa terror
CFiguras fig6;//fig bruja
CFiguras fig7;//fig letrero
CFiguras fig8;//fig alberca
CFiguras fig9;//fig anuncio arriba de alberca
CFiguras fig10;//fig murcielago
CFiguras fig11;//fig puerta trasera casa terror
CFiguras fig12;//fig cuarto 2

//**************figuras cuarto muertos*****

CFiguras fig13;//fig mesa
CFiguras fig14;//fig cartel1
CFiguras fig15;//fig papel picado
CFiguras fig16;//fig papel picado 2
CFiguras fig17;//fig papel picado 3
CFiguras fig18;//fig papel picado 4
CFiguras fig19;//fig papel picado 5
CFiguras fig20;//fig papel picado 6
CFiguras fig21;//fig cartel2
CFiguras fig22;//fig Mamá COCO
CFiguras fig23;//fig jarra de barro
CFiguras fig24;//fig cempasuchil
CFiguras fig25;//fig ahumador
CFiguras fig26;//fig papel Mesa cubre mesa
CFiguras fig27;//fig papel techo1
CFiguras fig28;//fig Pan
CFiguras fig29;//fig Azucar calavera1

//**************Figuras 3DS*****************

CModel calabaza;
CModel esqueleto;
CModel arana;
//**************figuras 3ds cuarto muertos***********
CModel mesa;
CModel vela;
CModel vela2;
CModel calavera;
CModel calavera2;
CModel velasMesa;
CModel velasMesa2;
CModel viga;
CModel porta;
CModel plato;
/*//-------------------Texturas Cuarto 1------------------------
CTexture textcasa;//Paredes casa
CTexture textcasa2;//pared frontal de casa1 con puerta y ventanas
CTexture textcasa3;//pared trasera con una puerta casa1
CTexture textpuerta1;//Puerta frontal casa1
CTexture textventana;

//*********************Texturas cuarto 2*************************
CTexture textparedfrontalterror;//Paredes cuarto de terror
CTexture textparedtraseraterror;//Paredes cuarto de terror
CTexture textparedlateralterror;//Paredes cuarto de terror
CTexture textsueloterror;//suelo cuarto de terror
CTexture texttechoterror;//techo cuarto de terror

/*CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01


CFiguras fig2;//fig cuarto1
CFiguras fig3;//fig puerta1
CFiguras fig4;//fig ventana
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;
CModel cono;
//Animación del coche
float movKit = 0.0;

float giroLlanta= 0.0;
float giroLlanta2 = 0.0;

float esquivar = 0.0;

bool g_fanima = false;
bool g_fanima2 = false;

bool g_fanimacion = false;
bool g_fanimacion2 = false;

CModel calabaza;*/

//****************declaraciones para keyframes***********************

float movPuerta = 0.0;
float movVentana = 0.0;

#define MAX_FRAMES 20
int i_max_steps = 30;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float movPuerta;
	float movPuertaInc;
	float movVentana;
	float movVentanaInc;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 4;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];


//****************************on/off luces
bool	light = false;		// Luz ON/OFF
bool	lightlamp = false;		// Luz ON/OFF
bool	luz = false;		// Luz ON/OFF
			
void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//glLightfv(GL_LIGHT0, GL_POSITION, Position);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT3, GL_AMBIENT, Ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);//luz ambiental cuarto terror
	glEnable(GL_LIGHT1);//luz calabazas cuarto terror
	glEnable(GL_LIGHT2);//luz especular
	glEnable(GL_LIGHT3);//luz mbiental cuarto muertos

	//*************luces cuarto dos

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

	//**********declaración de texturas**********

	//*********texturas skybox*******
	atardecersky.LoadTGA("TGA/Skybox/atardecer.tga");
	atardecersky.BuildGLTexture();
	atardecersky.ReleaseImage();

	pastosky.LoadTGA("TGA/Skybox/pasto.tga");
	pastosky.BuildGLTexture();
	pastosky.ReleaseImage();

	letrerobienvenida.LoadTGA("TGA/Skybox/letrero.tga");
	letrerobienvenida.BuildGLTexture();
	letrerobienvenida.ReleaseImage();

	//************texturas casa terror*****/
	sueloterror.LoadTGA("TGA/Terror/suelo.tga");
	sueloterror.BuildGLTexture();
	sueloterror.ReleaseImage();

	paredesterror.LoadTGA("TGA/Terror/paredes.tga");
	paredesterror.BuildGLTexture();
	paredesterror.ReleaseImage();

	techoterror.LoadTGA("TGA/Terror/techo.tga");
	techoterror.BuildGLTexture();
	techoterror.ReleaseImage();

	frontalterror.LoadTGA("TGA/Terror/paredfrontal.tga");
	frontalterror.BuildGLTexture();
	frontalterror.ReleaseImage();

	traseraterror.LoadTGA("TGA/Terror/paredtrasera.tga");
	traseraterror.BuildGLTexture();
	traseraterror.ReleaseImage();

	transparente.LoadTGA("TGA/Terror/transparente.tga");
	transparente.BuildGLTexture();
	transparente.ReleaseImage();

	puertaterror.LoadTGA("TGA/Terror/puerta1.tga");
	puertaterror.BuildGLTexture();
	puertaterror.ReleaseImage();

	puerta2terror.LoadTGA("TGA/Terror/puerta1.tga");
	puerta2terror.BuildGLTexture();
	puerta2terror.ReleaseImage();

	ventanaterror.LoadTGA("TGA/Terror/ventana.tga");
	ventanaterror.BuildGLTexture();
	ventanaterror.ReleaseImage();

	textbruja.LoadTGA("TGA/Terror/bruja.tga");
	textbruja.BuildGLTexture();
	textbruja.ReleaseImage();

	sangre.LoadTGA("TGA/Terror/sangre.tga");
	sangre.BuildGLTexture();
	sangre.ReleaseImage();

	paredalberca.LoadTGA("TGA/Terror/paredalberca.tga");
	paredalberca.BuildGLTexture();
	paredalberca.ReleaseImage();

	letrero.LoadTGA("TGA/Terror/letrero.tga");
	letrero.BuildGLTexture();
	letrero.ReleaseImage();

	murcielago.LoadTGA("TGA/Terror/murcielago.tga");
	murcielago.BuildGLTexture();
	murcielago.ReleaseImage();

	//*****************texturas casa muertos********************

	textcasa.LoadTGA("TGA/Muertos/madera.tga");
	textcasa.BuildGLTexture();
	textcasa.ReleaseImage();

	textcasa2.LoadTGA("TGA/Muertos/casa1frontalpuertaventana.tga");
	textcasa2.BuildGLTexture();
	textcasa2.ReleaseImage();

	textcasa3.LoadTGA("TGA/Muertos/casa1traserapuerta.tga");
	textcasa3.BuildGLTexture();
	textcasa3.ReleaseImage();

	textpapel1.LoadTGA("TGA/Muertos/papel1.tga");
	textpapel1.BuildGLTexture();
	textpapel1.ReleaseImage();

	textpapel2.LoadTGA("TGA/Muertos/papel2.tga");
	textpapel2.BuildGLTexture();
	textpapel2.ReleaseImage();

	textpapel3.LoadTGA("TGA/Muertos/papel3.tga");
	textpapel3.BuildGLTexture();
	textpapel3.ReleaseImage();

	textpapel4.LoadTGA("TGA/Muertos/papel4.tga");
	textpapel4.BuildGLTexture();
	textpapel4.ReleaseImage();

	textpapel5.LoadTGA("TGA/Muertos/papel5.tga");
	textpapel5.BuildGLTexture();
	textpapel5.ReleaseImage();

	textpapel6.LoadTGA("TGA/Muertos/papel6.tga");
	textpapel6.BuildGLTexture();
	textpapel6.ReleaseImage();

	textcartel.LoadTGA("TGA/Muertos/cartel.tga");
	textcartel.BuildGLTexture();
	textcartel.ReleaseImage();

	textcartel2.LoadTGA("TGA/Muertos/cartel2.tga");
	textcartel2.BuildGLTexture();
	textcartel2.ReleaseImage();

	textcoco.LoadTGA("TGA/Muertos/coco.tga");
	textcoco.BuildGLTexture();
	textcoco.ReleaseImage();

	textjarra.LoadTGA("TGA/Muertos/jarra.tga");
	textjarra.BuildGLTexture();
	textjarra.ReleaseImage();

	textcempa.LoadTGA("TGA/Muertos/cempa.tga");
	textcempa.BuildGLTexture();
	textcempa.ReleaseImage();

	textahumador.LoadTGA("TGA/Muertos/ahumador.tga");
	textahumador.BuildGLTexture();
	textahumador.ReleaseImage();

	textpapelmesa.LoadTGA("TGA/Muertos/papelmesa.tga");
	textpapelmesa.BuildGLTexture();
	textpapelmesa.ReleaseImage();


	textpapeltecho1.LoadTGA("TGA/Muertos/papeltecho1.tga");
	textpapeltecho1.BuildGLTexture();
	textpapeltecho1.ReleaseImage();


	textpan.LoadTGA("TGA/Muertos/pan1.tga");
	textpan.BuildGLTexture();
	textpan.ReleaseImage();

	textazucarcalavera.LoadTGA("TGA/Muertos/azucarcalavera.tga");
	textazucarcalavera.BuildGLTexture();
	textazucarcalavera.ReleaseImage();

	//***************Figuras 3ds casa terror*********
	calabaza._3dsLoad("3DS/Terror/calabaza.3ds");
	arana._3dsLoad("3DS/Terror/arana.3ds");
	esqueleto._3dsLoad("3DS/Terror/esqueleto.3ds");

	//**************figuras 3ds casa muertos********
	mesa._3dsLoad("3DS/Muertos/mesa.3ds");
	vela._3dsLoad("3DS/Muertos/vela.3ds");
	vela2._3dsLoad("3DS/Muertos/vela2.3ds");
	calavera._3dsLoad("3DS/Muertos/calavera.3ds");
	calavera2._3dsLoad("3DS/Muertos/calavera2.3ds");
	velasMesa._3dsLoad("3DS/Muertos/velaMesa.3ds");
	velasMesa2._3dsLoad("3DS/Muertos/velaMesa2.3ds");
	viga._3dsLoad("3DS/Muertos/viga.3ds");
	porta._3dsLoad("3DS/Muertos/porta.3ds");
	plato._3dsLoad("3DS/Muertos/plato.3ds");

	/*text1.LoadTGA("bosque.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	textcasa.LoadTGA("madera.tga");
	textcasa.BuildGLTexture();
	textcasa.ReleaseImage();

	textcasa2.LoadTGA("casa1frontalpuertaventana.tga");
	textcasa2.BuildGLTexture();
	textcasa2.ReleaseImage();

	textpuerta1.LoadTGA("puerta1.tga");
	textpuerta1.BuildGLTexture();
	textpuerta1.ReleaseImage();

	textcasa3.LoadTGA("casa1traserapuerta.tga");
	textcasa3.BuildGLTexture();
	textcasa3.ReleaseImage();

	textventana.LoadTGA("ventana.tga");
	textventana.BuildGLTexture();
	textventana.ReleaseImage();

	textparedfrontalterror.LoadTGA("paredfrontalcuarto2.tga");
	textparedfrontalterror.BuildGLTexture();
	textparedfrontalterror.ReleaseImage();

	textparedtraseraterror.LoadTGA("paredtraseracuarto2.tga");
	textparedtraseraterror.BuildGLTexture();
	textparedtraseraterror.ReleaseImage();

	textparedlateralterror.LoadTGA("paredes.tga");
	textparedlateralterror.BuildGLTexture();
	textparedlateralterror.ReleaseImage();

	texttechoterror.LoadTGA("techo.tga");
	texttechoterror.BuildGLTexture();
	texttechoterror.ReleaseImage();

	textsueloterror.LoadTGA("suelo.tga");
	textsueloterror.BuildGLTexture();
	textsueloterror.ReleaseImage();

	KeyFrame[0].movPuerta = 0;
	KeyFrame[1].movPuerta = 30;
	KeyFrame[2].movPuerta = 60;
	KeyFrame[3].movPuerta = 90;

	KeyFrame[0].movVentana = 0;
	KeyFrame[1].movVentana = 30;
	KeyFrame[2].movVentana = 60;
	KeyFrame[3].movVentana = 90;

	calabaza._3dsLoad("calabaza.3ds");

	/*text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	//Carga de Figuras
	kit._3dsLoad("kitt.3ds");	
	cono._3dsLoad("cono.3ds");
	//kit.VertexNormals();
	llanta._3dsLoad("k_rueda.3ds");*/
	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);
}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del csentro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();//push camaras
		glRotatef(g_lookupdown,1.0f,0,0);
		glTranslatef(0.0, 2.0, 0.0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

		glPushMatrix();//push principal

			glPushMatrix(); //Creamos cielo push skybox
				glDisable(GL_LIGHTING);
				glTranslatef(0, 74, -65);
				fig1.skybox(180.0, 300.0, 180.0, atardecersky.GLindex, pastosky.GLindex); //altura*largo*profundidad
				glTranslatef(18.0, -80.0, 55.0);
				glRotatef(150, 0.0, 1.0, 0.0);
				fig7.letrero(20.0, 20.0, 0.0001, letrerobienvenida.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();//pop skybox

			glPushMatrix();//push cuarto de terror
				glTranslatef(-60, 15, -70);
				fig2.cuartoterror(60.0, 70.0, 120.0, paredesterror.GLindex, sueloterror.GLindex, techoterror.GLindex, frontalterror.GLindex, traseraterror.GLindex);//altura*largo*profundidad
				if (!light)
				{
					glDisable(GL_LIGHT0);
				}
				else
				{
					glEnable(GL_LIGHT0);
				}
				if (!lightlamp)
				{
					glDisable(GL_LIGHT2);
				}
				else
				{
					glEnable(GL_LIGHT2);
				}

				glPushMatrix();//push camino de calabazas

					glPushMatrix();//push calabazas lado izquierdo

						glPushMatrix();//push calabaza1
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-10.0, -27.0, 35.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza1

						glPushMatrix();//push calabaza2
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-10.0, -27.0, 15.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza2

						glPushMatrix();//push calabaza3
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-10.0, -27.0, -5.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza3

						glPushMatrix();//push calabaza4
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-10.0, -27.0, -25.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza4

						glPushMatrix();//push calabaza5
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-10.0, -27.0, -45.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza5

					glPopMatrix();//pop calabazas lado izquierdo

					//***********************comienzan calabazas lado derecho********************

					glPushMatrix();//push calabazas lado derecho

						glPushMatrix();//push calabaza1
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(10.0, -27.0, 35.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza1

						glPushMatrix();//push calabaza2
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(10.0, -27.0, 15.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza2

						glPushMatrix();//push calabaza3
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(10.0, -27.0, -5.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza3

						glPushMatrix();//push calabaza4
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(10.0, -27.0, -25.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza4

						glPushMatrix();//push calabaza5
							glEnable(GL_LIGHT1);//activamos la luz 1 para que solo afecte a la calabaza
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(10.0, -27.0, -45.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(0.5, 0.5, 0.5);
							calabaza.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
							glDisable(GL_LIGHT1);
						glPopMatrix();//pop calabaza5
						
					glPopMatrix();//pop calabazas lado derecho

					glPushMatrix();//push adornos 3ds

						glPushMatrix();//push esqueleto1
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(25.0, -30.0, -50.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(60.0, 60.0 , 60.0);
							esqueleto.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();//pop esqueleto1
					
						glPushMatrix();//push esqueleto2
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-25.0, -30.0, -20.0);
							glRotatef(40, 0.0, 1.0, 0.0);
							glScalef(60.0, 60.0 , 60.0);
							esqueleto.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();//pop esqueleto2

						glPushMatrix();//push esqueleto3
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(25.0, -30.0, 10.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(60.0, 60.0 , 60.0);
							esqueleto.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();//pop esqueleto3

						glPushMatrix();//push arana1
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(-22.0, -30.0, 10.0);
							glRotatef(30, 0.0, 1.0, 0.0);
							glScalef(500.0, 500.0 , 500.0);
							arana.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();//pop arana1

						glPushMatrix();//push arana2
							glDisable(GL_COLOR_MATERIAL);
							glTranslatef(22.0, -30.0, -15.0);
							glRotatef(-30, 0.0, 1.0, 0.0);
							glScalef(500.0, 500.0 , 500.0);
							arana.GLrender(NULL, _SHADED, 1.0);
							glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();//pop arana2


					glPopMatrix();//pop adornos 3ds

				glPopMatrix();//pop camino de calabazas*/

				glPushMatrix();//push bruja izquierda
					glRotatef(90, 0.0, 1.0, 0.0);
					glTranslatef(0, 0, 34.0);
					if (movbruja > 50)
					{
						g_fanimacion = false;
						g_fanimacion2 = true;

					}
					else if (movbruja < -50)
					{
						g_fanimacion2 = false;
						g_fanimacion = true;
						
					};
					if (arribaabajo > 15)
					{
						g_fanima = false;
						g_fanima2 = true;
					}
					else if (arribaabajo < -15)
					{
						g_fanima = true;
						g_fanima2 = false;
					};
					glTranslatef(movbruja, 0.0, 0.0);
					glTranslatef(0, arribaabajo, 0);
					fig6.bruja(10.0, 10.0, 0.1, textbruja.GLindex);//altura*largo*profundidad
				glPopMatrix();//pop bruja izquierda

				glPushMatrix();//push bruja derecha
					glRotatef(90, 0.0, 1.0, 0.0);
					glTranslatef(0, 0, -34.0);
					if (movbruja > 50)
					{
						g_fanimacion = false;
						g_fanimacion2 = true;

					}
					else if (movbruja < -50)
					{
						g_fanimacion2 = false;
						g_fanimacion = true;
						
					};
					if (arribaabajo > 15)
					{
						g_fanima = false;
						g_fanima2 = true;
					}
					else if (arribaabajo < -15)
					{
						g_fanima = true;
						g_fanima2 = false;
					};
					glTranslatef(movbruja, 0.0, 0.0);
					glTranslatef(0, arribaabajo, 0);
					fig6.bruja(10.0, 10.0, 0.1, textbruja.GLindex);//altura*largo*profundidad
				glPopMatrix();//pop bruja derecha

				glPushMatrix();//push letrero los que han entrado
					glRotatef(180, 0.0, 1.0, 0.0);
					glTranslatef(25.0, -4.0, 59.9);
					fig9.letrero(20.0, 20.0, 0.1, letrero.GLindex);
				glPopMatrix();//pop letrero los que han entrado

				glPushMatrix();//push alberca
					glTranslatef(-23.9, -27.0, -52.9);
					fig8.alberca(2.0, 22.0, 14.0, sangre.GLindex, paredalberca.GLindex);

						glPushMatrix();//push animacion alberca
							glTranslatef(0.0, 1.1, 0.0);
							glDisable(GL_LIGHTING);
							glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							glBindTexture(GL_TEXTURE_2D, sangre.GLindex);
							glBegin(GL_QUADS);
							glNormal3f(0, 0, 1);
								glTexCoord2f(0 + alberca, 0 + alberca);	glVertex3f(11, 0, -7);
								glTexCoord2f(1 + alberca, 0 + alberca);	glVertex3f(-11, 0, -7);
								glTexCoord2f(1 + alberca, 1 + alberca);	glVertex3f(-11, 0, 7);
								glTexCoord2f(0 + alberca, 1 + alberca);	glVertex3f(11, 0, 7);
							glEnd();
							glEnable(GL_LIGHTING);
							glDisable(GL_ALPHA_TEST);
							glDisable(GL_CULL_FACE);
							glDepthFunc(GL_LEQUAL);
						glPopMatrix();//pop animacion alberca

				glPopMatrix();//pop alberca

				glPushMatrix();//push grupo murcielagos
					if (movmurci > 0)
					{
						h_fanimacion = false;
						h_fanimacion2 = true;

					}
					else if (movmurci < -50)
					{
						h_fanimacion2 = false;
						h_fanimacion = true;
						
					};

					glPushMatrix();//push murcielago1
						glTranslatef(27.0, 12.0, -50.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago1

					glPushMatrix();//push murcielago2
						glTranslatef(-26.0, 0.0, -30.0);
						glRotatef(180, 0.0, 1.0, 0.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago2

					glPushMatrix();//push murcielago3
						glTranslatef(27.0, -10.0, -10.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago3

					glPushMatrix();//push murcielago4
						glTranslatef(-26.0, 18.0, 10.0);
						glRotatef(180, 0.0, 1.0, 0.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago4

					glPushMatrix();//push murcielago5
						glTranslatef(27.0, 0.0, 30.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago5

					glPushMatrix();//push murcielago6
						glTranslatef(-26.0, -10.0, 35.0);
						glRotatef(180, 0.0, 1.0, 0.0);
						glTranslatef(movmurci, 0.0, 0.0);
						fig10.murcielago(12.0, 12.0, 0.1, murcielago.GLindex);
					glPopMatrix();//pop murcielago6

				glPopMatrix();//pop grupo murcielagos

			

			glPopMatrix();//pop cuarto de terror

			glPushMatrix();//push dibuja primas para articulacion de puerta

			glTranslatef(-79.0, 0.0, -10.01);
				fig3.articulacion (15.0, 15.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion puerta1
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-7.5, -1.0, 0.0);
					glRotatef(transpuerta1, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja puerta1
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(37.5, 32.0, 0.001, puertaterror.GLindex);
					glPopMatrix(); //pop dibuja puerta1
				glPopMatrix();//pop translada articulacion puerta 1

			glPopMatrix();//pop  dibuja prima para articulacion de puerta
			//*************************************************************************************
			glPushMatrix();//push dibuja primas para articulacion de puerta trasera 

			glTranslatef(-76.8, 0.0, -130.0);
				fig3.articulacion (15.0, 15.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion puerta2
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-7.5, -1.0, 0.0);
					glRotatef(transpuerta2, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja puerta2
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(37.5, 29.0, 0.01, puerta2terror.GLindex);//altura*largo*profundidad
					glPopMatrix(); //pop dibuja puerta2
				glPopMatrix();//pop translada articulacion puerta 2

			glPopMatrix();//pop  dibuja prima para articulacion de puerta trasera



			glPushMatrix();//push dibuja prisma para articulacion de ventana izquierda
			glTranslatef(-30.0, -0.7, -0.7);
			glTranslatef(-68.5, 15, -9.2);//TRANSLADA LA FIGURA DE LA ARTICULACION
				fig3.articulacion (10.0, 10.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion ventana
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-5.5, -1.0, 0.0);
					glRotatef(transventana1izq, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja ventana1
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(15.5, 20.0, 0.001, ventanaterror.GLindex); //altura*largo*profundidad
					glPopMatrix(); //pop dibuja ventana1
				glPopMatrix();//pop translada articulacion ventana 1

			glPopMatrix();//pop dibuja prisma para articulacion de ventana izquierda



			glPushMatrix();//push dibuja prisma para articulacion de ventana derecha
			glTranslatef(-30.5, 0.0, -0.9);
			glTranslatef(-23.5, 14.7, -9);//TRANSLADA LA FIGURA DE LA ARTICULACION
				fig3.articulacion (10.0, 10.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion ventana der
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-5.5, -1.0, 0.0);
					glRotatef(transventana1der, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja ventanader
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(15.5, 20.0, 0.001, ventanaterror.GLindex); //altura*largo*profundidad
					glPopMatrix(); //pop dibuja ventanader
				glPopMatrix();//pop translada articulacion ventanader

			glPopMatrix();//pop dibuja prisma para articulacion de ventana derecha



			glPushMatrix();//push cuarto muerto
				glTranslatef(75, 15, -70);
				fig12.cuarto2(60.0, 70.0, 120.0, textcasa2.GLindex, textcasa.GLindex, textcasa3.GLindex);//altura*largo*profundidad
				if (!luz)
				{
					glDisable(GL_LIGHT3);
				}
				else
				{
					glEnable(GL_LIGHT3);
				}

			glPushMatrix(); //Mesa en 3DS **************Hice la mesa y el papel picado juntos jerarquia o algo asi
				
				glDisable(GL_COLOR_MATERIAL); //Para conservar las texturas de la mesa
				glTranslatef(17, -19, 2); 
				glScalef(1, 0.55, 2);
				mesa.GLrender(NULL, _SHADED, 1.0);//no olvidar el 1
			
				glPushMatrix(); //Push De Papel Mesa cubre mesa
					glTranslatef(0, 17, 0); //Papel picado, cubre mesa 
					glScalef(12, 10, 12);
					glRotatef(-90, 0, 1, 0);
					fig18.plano2(textpapelmesa.GLindex);//no olvidar el 1
				glPopMatrix();//pop De Papel mesa
				glEnable(GL_COLOR_MATERIAL);
			glPopMatrix();//pop de mesa en 3DS FIN


			glPopMatrix();//push cuarto muertos

			glPushMatrix();//push dibuja primas para articulacion de puerta

				glTranslatef(58.0, -3.5, -10.01);
				fig3.articulacion (15.0, 15.0, 0.000001, transparente.GLindex);

					glPushMatrix();//push translada articulacion puerta1
						glRotatef(180, 0.0, 0.0, 1.0);
						glTranslatef(-7.5, -1.0, 0.0);
						glRotatef(transpuerta11, 0.0, 1.0, 0.0);
						glPushMatrix(); //push dibuja puerta1
							glTranslatef(-10.0, 0.0, 0.0);
							fig4.puerta1(29.5, 33.5, 0.001, puertaterror.GLindex);
						glPopMatrix(); //pop dibuja puerta1
					glPopMatrix();//pop translada articulacion puerta 1

			glPopMatrix();//pop  dibuja prima para articulacion de puerta
			//*************************************************************************************
			glPushMatrix();//push dibuja primas para articulacion de puerta trasera 

			glTranslatef(57.0, -3.5, -130.0);
				fig3.articulacion (15.0, 15.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion puerta2
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-7.5, -1.0, 0.0);
					glRotatef(transpuerta22, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja puerta2
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(29.5, 34.0, 0.01, puerta2terror.GLindex);//altura*largo*profundidad
					glPopMatrix(); //pop dibuja puerta2
				glPopMatrix();//pop translada articulacion puerta 2

			glPopMatrix();//pop  dibuja prima para articulacion de puerta trasera



			glPushMatrix();//push dibuja prisma para articulacion de ventana izquierda
			glTranslatef(105.0, -10.0, -0.7);
			glTranslatef(-68.5, 15, -9.2);//TRANSLADA LA FIGURA DE LA ARTICULACION
				fig3.articulacion (10.0, 10.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion ventana
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-5.5, -1.0, 0.0);
					glRotatef(transventana1izq2, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja ventana1
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(13.5, 21.0, 0.001, ventanaterror.GLindex); //altura*largo*profundidad
					glPopMatrix(); //pop dibuja ventana1
				glPopMatrix();//pop translada articulacion ventana 1

			glPopMatrix();//pop dibuja prisma para articulacion de ventana izquierda



			glPushMatrix();//push dibuja prisma para articulacion de ventana derecha
			glTranslatef(106.0, -9.6, -1.0);
			glTranslatef(-23.5, 14.7, -9);//TRANSLADA LA FIGURA DE LA ARTICULACION
				fig3.articulacion (10.0, 10.0, 0.000001, transparente.GLindex);

				glPushMatrix();//push translada articulacion ventana der
					glRotatef(180, 0.0, 0.0, 1.0);
					glTranslatef(-5.5, -1.0, 0.0);
					glRotatef(transventana1der2, 0.0, 1.0, 0.0);
					glPushMatrix(); //push dibuja ventanader
						glTranslatef(-10.0, 0.0, 0.0);
						fig4.puerta1(13.5, 20.0, 0.001, ventanaterror.GLindex); //altura*largo*profundidad
					glPopMatrix(); //pop dibuja ventanader
				glPopMatrix();//pop translada articulacion ventanader

			glPopMatrix();//pop dibuja prisma para articulacion de ventana derecha


		glPopMatrix();//pop principal

	glPopMatrix();//pop camaras


	glutSwapBuffers ( );

}

void animacion()
{

	if (g_fanimacion)
	{
		movbruja += 0.9; //movimiento de la bruja
		movmurci += 0.9; //movimiento del murcielago

	}

	if (g_fanimacion2)
	{
		movbruja -= 0.9; //movimiento de la bruja
		movmurci -= 0.9; //movimiento del murcielago
	}

	if (h_fanimacion)
	{
		movmurci += 0.9; //movimiento del murcielago

	}

	if (h_fanimacion2)
	{
		movmurci -= 0.9; //movimiento del murcielago
	}

	if (g_fanima)
	{
		arribaabajo += 0.6f;
	}

	if (g_fanima2)
	{
		arribaabajo -= 0.6f;
	}

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				KeyFrame[playIndex].movPuertaInc = (KeyFrame[playIndex + 1].movPuerta - KeyFrame[playIndex].movPuerta) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movVentanaInc = (KeyFrame[playIndex + 1].movVentana - KeyFrame[playIndex].movVentana) / i_max_steps;		//100 frames

			}
		}
		else
		{	//Draw information
			movPuerta += KeyFrame[playIndex].movPuertaInc;
			movVentana += KeyFrame[playIndex].movVentanaInc;
			i_curr_steps++;
		}

	}

	// ***** Animacion Alberca ***** //
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


void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 250.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) 
	{
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.02 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.02));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.04));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.04 );
			break;

		/*case 'k':		//
		case 'K':
			if (FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n", FrameIndex);

				KeyFrame[FrameIndex].movPuerta = movPuerta;
				KeyFrame[FrameIndex].movVentana = movVentana;

				FrameIndex++;
			}

			break;*/

		case 'z':
			transpuerta1 -= 3.0f;
			break;

		case 'Z':
			transpuerta1 += 3.0f;
			break;

		case 'x':
			transpuerta2 -= 3.0f;
			break;

		case 'X':
			transpuerta2 += 3.0f;
			break;

		case 'i':
			transventana1izq -= 3.0f;
			break;

		case 'I':
			transventana1izq += 3.0f;
			break;

		case 'o':
			transventana1der -= 3.0f;
			break;

		case 'O':
			transventana1der += 3.0f;
			break;
		case 'c':
			transpuerta11 -= 3.0f;
			break;

		case 'C':
			transpuerta11 += 3.0f;
			break;

		case 'v':
			transpuerta22 -= 3.0f;
			break;

		case 'V':
			transpuerta22 += 3.0f;
			break;

		case 'k':
			transventana1izq2 -= 3.0f;
			break;

		case 'K':
			transventana1izq2 += 3.0f;
			break;

		case 'l':
			transventana1der2 -= 3.0f;
			break;

		case 'L':
			transventana1der2 += 3.0f;
			break;

		case 'f':   //Activamos/desactivamos luz
		case 'F':
			light = !light;
			PlaySound(TEXT("Sonidos/foco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;

		case 'r':   //Activamos/desactivamos luz
		case 'R':
			luz = !luz;
			PlaySound(TEXT("Sonidos/foco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;

		case 'g':   //Activamos/desactivamos luz
		case 'G':
			lightlamp = !lightlamp;
			PlaySound(TEXT("Sonidos/foco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;

		/*case 'l':
		case 'L':
			if (play == false && (FrameIndex>1))
			{

				movPuerta = KeyFrame[0].movPuerta;
				movVentana = KeyFrame[0].movVentana;

				//First Interpolation
				KeyFrame[playIndex].movPuertaInc = (KeyFrame[playIndex + 1].movPuerta - KeyFrame[playIndex].movPuerta) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movVentanaInc = (KeyFrame[playIndex + 1].movVentana - KeyFrame[playIndex].movVentana) / i_max_steps;		//100 frames

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;*/

		case ' ':		//Poner algo en movimiento
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			h_fanimacion ^= true;
			g_fanima ^= true;
			PlaySound(TEXT("Sonidos/cancionterror.wav"), NULL, SND_LOOP | SND_ASYNC);
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;

		case '1'://camara1
			objCamera.mPos.x = -60.00;
			objCamera.mPos.y = 0.50;
			objCamera.mPos.z = -70.00;
			objCamera.mView.x = -60.00;
			objCamera.mView.y = 0.0;
			objCamera.mView.z = -80.00;
			g_lookupdown = 0.00;
			break;
			//camara2
		case '2':
			objCamera.mPos.x = 60.00;
			objCamera.mPos.y = 0.50;
			objCamera.mPos.z = -70.00;
			objCamera.mView.x = 60.00;
			objCamera.mView.y = 0.50;
			objCamera.mView.z = -11.50;
			g_lookupdown = 0.00;
			break;
			//camara3
		case '3':
			objCamera.mPos.x = 11.00;
			objCamera.mPos.y = 4.500;
			objCamera.mPos.z = -13.45;
			objCamera.mView.x = 0.00;
			objCamera.mView.y = 4.25;
			objCamera.mView.z = -20.50;
			g_lookupdown = 1.00;
			break;
  }

  glutPostRedisplay();
 
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;
	/*case GLUT_KEY_F1:
		PlaySound(TEXT("cancionterror.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;*/

    default:
		break;
  }
  glutPostRedisplay();
  
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto final Lab"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
