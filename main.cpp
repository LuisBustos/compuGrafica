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

//*************variables para las camaras
int cam = 0;
float c1PosX = 7.617214, c1PosY = 0.5, c1PosZ = 14.272827, c1ViewX = 8.109015, c1ViewY = 0.05, c1ViewZ = -44.224670, c1UpX = 0, c1UpY = 1, c1UpZ = 0;
float c2PosX = 7.617214, c2PosY = 0.5, c2PosZ = 14.272827, c2ViewX = 8.109015, c2ViewY = 0.05, c2ViewZ = -44.224670, c2UpX = 0, c2UpY = 1, c2UpZ = 0;
float c3PosX = 7.617214, c3PosY = 0.5, c3PosZ = 14.272827, c3ViewX = 8.109015, c3ViewY = 0.05, c3ViewZ = -44.224670, c3UpX = 0, c3UpY = 1, c3UpZ = 0;

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



CTexture transparente;
CTexture puertaterror;//puerta frontal casa terror
CTexture puerta2terror;//puerta frontal casa terror
CTexture ventanaterror;//ventana
CTexture letrerobienvenida;
CTexture sangre;//alberca de sangre

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
CTexture textpapelmesa;//Papel mesa cubre mesa

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
	atardecersky.LoadTGA("TGA/Skybox/paisaje.tga");
	atardecersky.BuildGLTexture();
	atardecersky.ReleaseImage();

	pastosky.LoadTGA("TGA/Skybox/nieve.tga");
	pastosky.BuildGLTexture();
	pastosky.ReleaseImage();

	letrerobienvenida.LoadTGA("TGA/Skybox/letrero.tga");
	letrerobienvenida.BuildGLTexture();
	letrerobienvenida.ReleaseImage();

	//************texturas casa terror*****/
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
	
	/*sangre.LoadTGA("TGA/Terror/sangre.tga");
	sangre.BuildGLTexture();
	sangre.ReleaseImage();*/

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
	//---------------------

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

	textpapelmesa.LoadTGA("TGA/Muertos/papelmesa.tga");
	textpapelmesa.BuildGLTexture();
	textpapelmesa.ReleaseImage();

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
				glTranslatef(38.0, -80.0, 65.0);
				glRotatef(150, 0.0, 1.0, 0.0);
				fig7.letrero(20.0, 20.0, 0.0001, letrerobienvenida.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();//pop skybox

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

			
			glPushMatrix();//push cuarto muerto
				glTranslatef(0, 15, -70);
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
					glTranslatef(17, -30, 2); 
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


				glPushMatrix();//push dibuja primas para articulacion de puerta
					glTranslatef(-45.0, -15.0, 70.0);
					glTranslatef(28.0, -3.5, -10.01);
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
					glTranslatef(-45.0, -15.0, 70.0);
					glTranslatef(27.0, -3.5, -130.0);
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
					glTranslatef(-45.0, -15.0, 70.0);
					glTranslatef(75.0, -10.0, -0.7);
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
					glTranslatef(-45.0, -15.0, 70.0);
					glTranslatef(76.0, -9.6, -1.0);
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
			glPopMatrix();//push cuarto muertos

		glPopMatrix();//pop principal

	glPopMatrix();//pop camaras


	glutSwapBuffers();
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
	case 'w':
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);

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

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));

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

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));

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

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);

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

		case '0': //posicion actual de la camara
			printf("######################\nCamara: %i\n", cam);
			printf("%f\n", objCamera.mPos.x);
			printf("%f\n", objCamera.mPos.y);
			printf("%f\n", objCamera.mPos.z);
			printf("----------------------\n");
			printf("%f\n", objCamera.mView.x);
			printf("%f\n", objCamera.mView.y);
			printf("%f\n", objCamera.mView.z);
			printf("----------------------\n");
			printf("%f\n", objCamera.mUp.x);
			printf("%f\n", objCamera.mUp.y);
			printf("%f\n", objCamera.mUp.z);
		break;

		case '1'://camara1
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
			
		case '2'://camara2
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
			break;

		case '3'://camara3
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
			break;
  }

  glutPostRedisplay();
 
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);

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

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);

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

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
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

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
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
  glutCreateWindow    ("Proyecto final"); // Nombre de la Ventana
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
