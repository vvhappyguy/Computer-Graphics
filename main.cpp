#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <GL/gl.h>

int const WINDOW_HEIGHT = 800, WINDOW_WIDTH = 800;
int const WINDOW_POSITION_X = 500, WINDOW_POSITION_Y = 200;

double rotateCubeY = 45, rotateCubeX = 45;
double rotateSpereY = 0;
double rotateBigCubeY = 30, rotateBigCubeX = 30;

bool isLight = true;// начальные значения
bool isBigCube = false;
bool cubeIsTransparent = false;
bool cubeIsColored = false;
bool cubeIsOpened = false;
bool isMonoTexture = false;

bool isCubeRotatingLeft = true;
bool isCubeRotatingRight = false;
bool isSphereRotatingLeft = false;
bool isSphereRotatingRight = true;
bool isBigCubeRotateLeft = false;
bool isBigCubeRotateRight = false;

double lightRadius = 0.9;//расстояние от сферы до куба

float cubeSideWidth = 0.5;
float spaceBetweenCubeSides = 0;//расстояние между стенок куба

GLuint textures[6];//массив текстур

GLuint idCube = 1;//идентификатор списка

void drawCube()//отрисовываем куб
{
    float delta = spaceBetweenCubeSides;
    float x = cubeSideWidth/2, y=cubeSideWidth/2, z=cubeSideWidth/2;
    // FRONT
    if(cubeIsColored) glColor3f(1,0,0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, -1);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(x, -y, -z-delta);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(x, y, -z-delta);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(-x, y, -z-delta);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(-x, -y, -z-delta);
    glEnd();

    // BACK
    if(cubeIsColored) glColor3f(0,1,0);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(x, -y, z+delta);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(-x, -y, z+delta);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(-x, y, z+delta);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(x, y, z+delta);
    glEnd();

    // RIGHT
    if(cubeIsColored) glColor3f(0,0,1);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_POLYGON);
        glNormal3f(1, 0, 0);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(x+delta, -y, -z);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(x+delta, -y, z);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(x+delta, y, z);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(x+delta, y, -z);
    glEnd();

    // LEFT
    if(cubeIsColored) glColor3f(1,1,0);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_POLYGON);
        glNormal3f(-1, 0, 0);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(-x-delta, -y, z);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(-x-delta, -y, -z);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(-x-delta, y, -z);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(-x-delta, y, z);
    glEnd();

    // UP
    if(cubeIsColored) glColor3f(1,0,1);
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 1, 0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(x, y+delta, z);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(-x, y+delta, z);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(-x, y+delta, -z);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(x, y+delta, -z);
    glEnd();

    // DOWN
    if(cubeIsColored) glColor3f(0,1,1);
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_POLYGON);
        glNormal3f(0, -1, 0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(x, -y-delta, -z);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(-x, -y-delta, -z);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(-x, -y-delta, z);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(x, -y-delta, z);
    glEnd();
}

void loadTextires()//загружаем текстуры
{
	AUX_RGBImageRec
		*texture1,
		*texture2,
		*texture3,
		*texture4,
		*texture5,
		*texture6;

		if(isMonoTexture)//условие когда монотекстуры
        {
            texture1 = auxDIBImageLoad("tex5.bmp");
            texture2 = auxDIBImageLoad("tex5.bmp");
            texture3 = auxDIBImageLoad("tex5.bmp");
            texture4 = auxDIBImageLoad("tex5.bmp");
            texture5 = auxDIBImageLoad("tex5.bmp");
            texture6 = auxDIBImageLoad("tex5.bmp");
        }
		else
        {
            texture1 = auxDIBImageLoad("tex.bmp");
            texture2 = auxDIBImageLoad("tex1.bmp");
            texture3 = auxDIBImageLoad("tex2.bmp");
            texture4 = auxDIBImageLoad("tex3.bmp");
            texture5 = auxDIBImageLoad("tex4.bmp");
            texture6 = auxDIBImageLoad("tex5.bmp");
        }


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(6, &textures[0]);

	glBindTexture(GL_TEXTURE_2D, textures[0]);//привязывает текстуры
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);

	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture3->sizeX, texture3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture3->data);

	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture4->sizeX, texture4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture4->data);

	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture5->sizeX, texture5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture5->data);

	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture6->sizeX, texture6->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture6->data);

}

void bigCube()
{
	int number = 20;
	GLfloat x = 0.5;
	GLfloat y = 0.5;
	GLfloat z = 0.5;
	GLfloat side = 0.05;
	for (int i = 0; i < number; ++i)
	{
		if (i % 2) y = 0.5;
		else y = 0.5 - side;
		for (int j = 0; j < number; j += 2)
		{
        glBegin(GL_QUADS);
			glNormal3f(-x, -y, -z);
			glVertex3f(x, y, z);

			x -= side;
			glNormal3f(-x, -y, -z);
			glVertex3f(x, y, z);

			y -= side;
			glNormal3f(-x, -y, -z);
			glVertex3f(x, y, z);

			x += side;
			glNormal3f(-x, -y, -z);
			glVertex3f(x, y, z);

        glEnd();

			y -= side;
		}
		x -= side;
	}
}

void drawBigCube()
{
    glColor3f(1, 1, 1);
	glPushMatrix();

	bigCube();

	for (int i = 0; i < 3; i++)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
		bigCube();
	}
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	bigCube();

	glRotatef(180.0, 1.0, 0.0, 0.0);
	bigCube();

	glPopMatrix();
}

void drawSphere()// рисуем сферу
{
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(lightRadius,0,0);
	glutWireSphere(0.05, 10, 10);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    isLight?glEnable(GL_LIGHT0):glDisable(GL_LIGHT0);

    if (isBigCube)
    {


        glPushMatrix();
		glLoadIdentity();
		glRotatef(rotateBigCubeX, 1.0, 0.0, 0.0);
		glRotatef(rotateBigCubeY, 0.0, 1.0, 0.0);
		glCallList(idCube);
		glPopMatrix();
    }

    if (cubeIsTransparent){
        glEnable(GL_BLEND);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    }
    if (!cubeIsColored){
        glEnable(GL_TEXTURE_2D);
    }

    glPushMatrix();
    glRotatef(rotateCubeX, 1.0, 0.0, 0.0);
    glRotatef(rotateCubeY, 0.0, 1.0, 0.0);
    drawCube();
    glPopMatrix();

    if(!cubeIsColored){
        glDisable(GL_TEXTURE_2D);
    }
    if (cubeIsTransparent){
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    }

    glPushMatrix();
    glRotatef(rotateSpereY, 0.0, 1.0, 0.0);
    drawSphere();
    GLfloat lightPosition[] = {lightRadius,0,0,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height)//отображение куба в окне
{
    int frameWH = width>height?height:width;
    glViewport((width-frameWH)/2, (height-frameWH)/2, frameWH,frameWH );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(1.0, (float)WINDOW_WIDTH / WINDOW_HEIGHT, 1,1);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat outside_light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, outside_light_diffuse);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    idCube = glGenLists(1);
	glNewList(idCube, GL_COMPILE);
	drawBigCube();
	glEndList();

    loadTextires();

}

void timer(int value)
{
    if(isCubeRotatingLeft)
    {
        rotateCubeY==360?rotateCubeY=2:rotateCubeY+=2;
    }
    if(isCubeRotatingRight)
    {
        rotateCubeY==0?rotateCubeY=358:rotateCubeY-=2;
    }
    if(isSphereRotatingLeft)
    {
        rotateSpereY==360?rotateSpereY=4:rotateSpereY+=4;
    }
    if(isSphereRotatingRight)
    {
        rotateSpereY==0?rotateSpereY=356:rotateSpereY-=4;
    }
    if(isBigCubeRotateLeft)
    {
        rotateBigCubeY==360?rotateBigCubeY=0.5:rotateBigCubeY+=0.5;
    }
    if(isBigCubeRotateRight)
    {
        rotateBigCubeY==0?rotateBigCubeY=359.5:rotateBigCubeY -= 0.5;
    }
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}

void keys( int key, int x, int y )
{
    switch(key){
    case GLUT_KEY_LEFT:
        rotateCubeY == 360 ? rotateCubeY=5 :rotateCubeY+=5;
        break;
    case GLUT_KEY_RIGHT:
        rotateCubeY==0?rotateCubeY=355:rotateCubeY-=5;
        break;
    case GLUT_KEY_UP:
        rotateCubeX==360?rotateCubeX=5:rotateCubeX+=5;
        break;
    case GLUT_KEY_DOWN:
        rotateCubeX==0?rotateCubeX=355:rotateCubeX-=5;
        break;
    }
    glutPostRedisplay();
}

void spaceKey(unsigned char key,int x,int y ){
    switch(key) {
    case 'a'://движение сферы налево
        rotateSpereY==360?rotateSpereY=5:rotateSpereY+=5;
        break;
    case 'd'://движение сферы направо
        rotateSpereY==0?rotateSpereY=355:rotateSpereY-=5;
        break;
    case 'l'://включение, выключение света
        isLight = !isLight;
        break;
    case ' '://расстояние между гранями куба
        cubeIsOpened?spaceBetweenCubeSides-=0.05:spaceBetweenCubeSides+=0.05;
        cubeIsOpened = !cubeIsOpened;
        break;
    case 't'://включение, выключение прозрачности
        cubeIsTransparent = !cubeIsTransparent;
        break;
    case 'c'://цвет куба
        cubeIsColored = !cubeIsColored;
        break;
    case '1'://вращение куба налево
        isCubeRotatingLeft = !isCubeRotatingLeft;
        isCubeRotatingRight = false;
        break;
    case '2'://вращение куба направо
        isCubeRotatingRight = !isCubeRotatingRight;
        isCubeRotatingLeft = false;
        break;
    case '3'://вращение источника света налево
        isSphereRotatingLeft = !isSphereRotatingLeft;
        isSphereRotatingRight = false;
        break;
    case '4'://вращение источника света направо
        isSphereRotatingRight = !isSphereRotatingRight;
        isSphereRotatingLeft = false;
        break;
    case '5'://включение, выключение большого куба
        isBigCube = !isBigCube;
        break;
    case 'q'://вращение большого куба налево
        isBigCubeRotateLeft = !isBigCubeRotateLeft;
        isBigCubeRotateRight = false;
        break;
    case 'e'://вращение большого куба направо
        isBigCubeRotateRight = !isBigCubeRotateRight;
        isBigCubeRotateLeft = false;
        break;
    case '8'://вращение большого куба наверх
        rotateBigCubeX==360?rotateBigCubeX=0.5:rotateBigCubeX+=0.5;
        break;
    case '9'://ращение большого куба вниз
        rotateBigCubeX==0?rotateBigCubeX=359.5:rotateBigCubeX-=0.5;
        break;
    case '0'://включение, выключение монотекстур
        isMonoTexture = !isMonoTexture;
        loadTextires();
        break;
    }

}

int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("Lab3");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keys);
    glutKeyboardFunc(spaceKey);
    glutTimerFunc(50,timer,0);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
