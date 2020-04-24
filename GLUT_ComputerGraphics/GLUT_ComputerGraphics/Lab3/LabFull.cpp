#include <iostream>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <GL/glut.h>
#include <math.h>
#include "SOIL.h"

using namespace std;

#define WIN_HEIGHT 750
#define WIN_WIDTH 750

GLfloat ox_rotation = 0;
GLfloat dx_rotation = 0.5;
GLfloat oy_rotation = 0;
GLfloat dy_rotation = 0;
bool visibility = true;
GLfloat opened = 0;
GLfloat octTranslateZ = -5;
void draw_colored_oct();

GLfloat sun_rotation = 1;
GLfloat dx_sun_rotation = 1;
GLfloat light_pos[] = { 0, 0, 0, 1 };
bool light_on = true;
int sun_mode = 1;

// Cube variables
GLuint cube; // Number of display list
bool cube_flag = false; // View flag
void prepare_cube(); // Prepare cube DisplayList
void draw_cube(); // Draw cube

// Texture variables
const size_t textures_count = 8;
GLuint textures[textures_count];
const std::string textureFolder = "D:\\Projects\\ComputerGraphics\\GLUT_ComputerGraphics\\GLUT_ComputerGraphics\\Lab3\\";

// For OPENGL Callbacks
void draw();
void reshape(GLsizei w, GLsizei h);
void TimerFunction(int value);
void glutNormalKeys(unsigned char key, int x, int y);

enum class COLOR_MODE : int
{
	COLOR = 0,
	DIFFERENT_TEXTURES = 1,
	ONE_TEXTURE = 2
};

namespace KEY
{
	const char TEXTURE = 't';
	const char CUBE = 'c';
	const char VISIBLE = 'x';
	const char OPEN_OCT = 'e';
	const char SUN_MODE = 'r';
	const char EXIT = 'z';
	const char LIGHT_MODE = 'f';
	const char STOP = 'q';
	const char TURN_UP = 'w';
	const char TURN_DOWN = 's';
	const char TURN_LEFT = 'a';
	const char TURN_RIGHT = 'd';
}


COLOR_MODE texture_mode = COLOR_MODE::COLOR;

int main(int argc, char** argv)
{
	// Control information
	{
		using namespace KEY;
		cout << TURN_UP << " - turn up\n"
			<< TURN_DOWN << " - turn down\n"
			<< TURN_LEFT << " - turn left\n"
			<< TURN_RIGHT << " - turn right\n"
			<< STOP << " - stop rotation\n"
			<< OPEN_OCT << " - open octahedron\n"
			<< LIGHT_MODE << " - invert the light\n"
			<< SUN_MODE << " - change sun mode\n"
			<< VISIBLE << " - visibility mode\n"
			<< EXIT << " - exit\n"
			<< TEXTURE << " - texture mode\n"
			<< CUBE << " - cube mode" << endl;
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Dyakin Labs 3+");


	cube = glGenLists(1);
	if (cube == 0)
	{
		cout << "No free indexes" << endl;
		return 1;
	}
	prepare_cube();
	cout << "Cube Init" << endl;

	// Callback functions init
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutTimerFunc(5, TimerFunction, 0.5);
	glutKeyboardFunc(glutNormalKeys);
		
	// Light Init
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	// glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	// Textures init
	int width[textures_count];
	int height[textures_count];

	glGenTextures(textures_count, textures);
	unsigned char* images[textures_count];

	stringstream filename;
	for (int i = 0; i < textures_count; i++)
	{
		filename << textureFolder << "tex" << i << ".bmp";
		cout << filename.str();
		images[i] = SOIL_load_image(filename.str().c_str(), &width[i], &height[i], 0, SOIL_LOAD_RGB);
		if (!images[i])
		{
			std::cout << "error when load" << images[i] << std::endl;
		}
		else
		{
			std::cout << "loaded successfully." << std::endl;
		}

		glBindTexture(GL_TEXTURE_2D, textures[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[i], height[i], 0, GL_RGB, GL_UNSIGNED_BYTE, images[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		filename.str("");
	}

	for (int i = 0; i < textures_count; i++)
	{
		SOIL_free_image_data(images[i]);
	}

	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}


void draw_colored_oct()
{
	glLoadIdentity();
	glTranslatef(0, 0, octTranslateZ);
	glRotatef((ox_rotation), 0, 1, 0);
	glRotatef((oy_rotation), 1, 0, 0);

	GLfloat vertices[] = { -2 - opened, 0.0 + opened, 0.0 + opened, //0 передняя грань
						  0.0 - opened, 2 + opened, 0.0 + opened,  //1
						  0.0 - opened, 0.0 + opened, 2 + opened,  //2

						  0.0 + opened, 0.0 + opened, 2 + opened,  //2 правая боковая
						  0.0 + opened, 2 + opened, 0.0 + opened,  //1
						  2 + opened, 0.0 + opened, 0.0 + opened,  //3

						  2 + opened, 0.0 + opened, 0.0 - opened,  //3 задняя грань
						  0.0 + opened, 2 + opened, 0.0 - opened,  //1
						  0.0 + opened, 0.0 + opened, -2 - opened, //4

						  0.0 - opened, 0.0 + opened, -2 - opened, //4 левая боковая
						  0.0 - opened, 2 + opened, 0.0 - opened,  //1
						  -2 - opened, 0.0 + opened, 0.0 - opened, //0

						  -2 - opened, 0.0 - opened, 0.0 + opened, //0 нижняя передняя грань
						  0.0 - opened, -2 - opened, 0.0 + opened, //5
						  0.0 - opened, 0.0 - opened, 2 + opened,  //2

						  0.0 + opened, 0.0 - opened, 2 + opened,  //2 нижняя правая грань
						  0.0 + opened, -2 - opened, 0.0 + opened, //5
						  2 + opened, 0.0 - opened, 0.0 + opened,  //3

						  2 + opened, 0.0 - opened, 0.0 - opened,  //3 нижняя задняя грань
						  0.0 + opened, -2 - opened, 0.0 - opened, //5
						  0.0 + opened, 0.0 - opened, -2 - opened, //4

						  0.0 - opened, 0.0 - opened, -2 - opened, //4 нижняя левая  грань
						  0.0 - opened, -2 - opened, 0.0 - opened, //5
						  -2 - opened, 0.0 - opened, 0.0 - opened, //0
	};

	GLfloat normal[] = {
						 1, -1, -1,
						 1, -1, -1,
						 1, -1, -1,

						 -1, -1, -1,
						 -1, -1, -1,
						 -1, -1, -1,

						 -1, -1, 1,
						 -1, -1, 1,
						 -1, -1, 1,

						 1, -1, 1,
						 1, -1, 1,
						 1, -1, 1,

						 -1, -1, 1,
						 -1, -1, 1,
						 -1, -1, 1,

						 1, -1, 1,
						 1, -1, 1,
						 1, -1, 1,

						 1, 1, -1,
						 1, 1, -1,
						 1, 1, -1,

						 -1, -1, -1,
						 -1, -1, -1,
						 -1, -1, -1,
	};
	GLfloat texCoords[] = { 0.0, 0.0,  // Нижний левый угол
							1.0, 0.0,  // Нижний правый угол
							0.5, 1.0,  // верхняя центральная сторона
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0, };

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normal);

	GLubyte front_face[] = { 0, 1, 2 };             // передняя грань
	GLubyte right_side[] = { 3, 4, 5 };             // правая грань
	GLubyte back_face[] = { 6, 7, 8 };              // задняя грань
	GLubyte left_side[] = { 9, 10, 11 };            // левая грань
	GLubyte lower_front[] = { 12, 13, 14 };         // нижняя передняя грань
	GLubyte bottom_right_side[] = { 15, 16, 17 };   // нижняя правая грань
	GLubyte lower_back_face[] = { 18, 19, 20 };     // нижняя задняя грань
	GLubyte bottom_left_side[] = { 21, 22, 23 };    // нижняя левая грань

	switch (texture_mode)
	{
	case COLOR_MODE::COLOR:
		glEnable(GL_COLOR_MATERIAL);
		glColor4f(0.00, 0.32, 0.48, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glColor4f(0.18, 0.4, 0.32, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glColor4f(0.32, 0.16, 0.36, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glColor4f(0.82, 0.21, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glColor4f(1.0, 1.0, 1.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glColor4f(1.0, 0.0, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glColor4f(1.0, 0.0, 1.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glColor4f(0.0, 1.0, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
		break;
	case COLOR_MODE::ONE_TEXTURE:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
		glDisable(GL_TEXTURE_2D);
		break;
	case COLOR_MODE::DIFFERENT_TEXTURES:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glBindTexture(GL_TEXTURE_2D, textures[2]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glBindTexture(GL_TEXTURE_2D, textures[3]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glBindTexture(GL_TEXTURE_2D, textures[4]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glBindTexture(GL_TEXTURE_2D, textures[5]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glBindTexture(GL_TEXTURE_2D, textures[6]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glBindTexture(GL_TEXTURE_2D, textures[7]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
		glDisable(GL_TEXTURE_2D);
		break;
	default:
		cout << "error - bad texture_mode";
		break;
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

// Main draw function
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!visibility)
	{
		glEnable(GL_BLEND);
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	else
	{
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
	}

	draw_cube();

	//  Oct
	glColor4f(1, 1, 1, 0.5);
	draw_colored_oct();

	//  Light and sphere
	glLoadIdentity();
	glTranslatef(0, 0, -12);
	glRotatef(sun_rotation, 0, 1, 0);
	glTranslatef(0, 0, -10);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLUquadricObj* quadObj = gluNewQuadric();
	glColor3d(1, 1, 0);
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluSphere(quadObj, 1, 10, 10);

	glutSwapBuffers();
}

void draw_cube()
{
	if (cube_flag)
		glCallList(cube);
}

void prepare_cube()
{
	glLoadIdentity();

	glNewList(cube, GL_COMPILE);
	glColor4f(0.0, 1.0, 0.0, 1.0);
	for (int i = 0; i < 31; i++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex3f(-30, 30 - i * 2, 30);
		glVertex3f(30, 30 - i * 2, 30);
		glVertex3f(30, 30 - i * 2, -30);
		glVertex3f(-30, 30 - i * 2, -30);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(30 - i * 2, 30, 30);
		glVertex3f(30 - i * 2, -30, 30);
		glVertex3f(30 - i * 2, -30, -30);
		glVertex3f(30 - i * 2, 30, -30);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(-30, 30, 30 - i * 2);
		glVertex3f(30, 30, 30 - i * 2);
		glVertex3f(30, -30, 30 - i * 2);
		glVertex3f(-30, -30, 30 - i * 2);
		glEnd();
	}
	glEndList();
}

void reshape(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120, (GLdouble)w / h, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, (GLdouble)w, (GLdouble)h);

	draw();
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	glutTimerFunc(10, TimerFunction, 1);
	ox_rotation += dx_rotation;
	oy_rotation += dy_rotation;
	sun_rotation += dx_sun_rotation;
}

void glutNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case KEY::TEXTURE:
		if (texture_mode == COLOR_MODE::ONE_TEXTURE)
		{
			//glDisable(GL_TEXTURE_2D);
			texture_mode = COLOR_MODE::COLOR;
			std::cout << "COLOR_MODE::COLOR" << std::endl;
		}
		else if (texture_mode == COLOR_MODE::COLOR)
		{
			//glEnable(GL_TEXTURE_2D); 
			texture_mode = COLOR_MODE::DIFFERENT_TEXTURES;
			std::cout << "COLOR_MODE::DIFFERENT_TEXTURES" << std::endl;
		}
		else
		{
			texture_mode = COLOR_MODE::ONE_TEXTURE;
			std::cout << "COLOR_MODE::ONE_TEXTURE" << std::endl;
		}

		break;
	case KEY::CUBE:
		cube_flag = !cube_flag;
		break;
	case KEY::VISIBLE:
		visibility = !visibility;

		break;
	case KEY::TURN_LEFT:
		dx_rotation = -0.5;
		break;
	case KEY::TURN_RIGHT:
		dx_rotation = 0.5;
		break;
	case KEY::TURN_UP:
		dy_rotation = -0.5;
		break;
	case KEY::TURN_DOWN:
		dy_rotation = 0.5;
		break;
	case KEY::STOP:
		dy_rotation = 0;
		dx_rotation = 0;
		break;
	case KEY::OPEN_OCT:
		if (!opened)
			opened = 0.2;
		else
			opened = 0;
		break;
	case KEY::SUN_MODE:
		if (sun_mode >= 0)
		{
			sun_mode--;
			dx_sun_rotation--;
			cout << sun_mode << dx_sun_rotation << endl;
		}
		else
		{
			sun_mode = 1;
			dx_sun_rotation = 1;
		}
		break;
	case KEY::EXIT:
		exit(0);
		break;
	case KEY::LIGHT_MODE:
		if (light_on)
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		light_on = !light_on;
		break;
	default:
		break;
	}
}
