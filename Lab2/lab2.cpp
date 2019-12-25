#define GL_SILENCE_DEPRECATION
#include <math.h>
#include <GLUT/glut.h>
#define PI 3.1415926535898
GLint circlePoints=100;
GLint sizeOfSun = 50;
bool isNight = false;
GLint sunPosX = 500;
GLint sunPosY = 500;


static GLfloat vertices[] = 
{
    0.0, 0.0, //grass
    0.0, 300.0,
    600.0, 300.0,
    600.0, 0.0,

    0.0, 300.0, //sky
    0.0, 600.0,
    600.0, 600.0,
    600.0, 300.0,

    50.0, 100.0, //house
    50.0, 250.0,
    200.0, 250.0,
    200.0, 100.0,

    25.0, 250.0, //roof
    125.0, 350.0,
    225.0, 250.0

};

static GLfloat nightColor[] = 
{
    0.0, 0.5, 0.0, //grass
    0.0, 0.5, 0.0,
    0.0, 0.5, 0.0,
    0.0, 0.5, 0.0,

    0.0, 0.1, 0.2, //sky
    0.0, 0.1, 0.2,
    0.0, 0.1, 0.2,
    0.0, 0.1, 0.2,

    0.2, 0.1, 0.0, //house
    0.2, 0.1, 0.0,
    0.2, 0.1, 0.0,
    0.2, 0.1, 0.0,

    0.25, 0.2, 0.0, //roof
    0.25, 0.2, 0.0,
    0.25, 0.2, 0.0,
    0.25, 0.2, 0.0   
};

static GLfloat dayColor[] = 
{
    0.0, 0.9, 0.0, //grass
    0.0, 0.9, 0.0,
    0.0, 0.9, 0.0,
    0.0, 0.9, 0.0,

    0.0, 1.0, 1.0, //sky
    0.0, 1.0, 1.0,
    0.0, 1.0, 1.0,
    0.0, 1.0, 1.0,

    0.4, 0.2, 0.0, //house
    0.4, 0.2, 0.0,
    0.4, 0.2, 0.0,
    0.4, 0.2, 0.0,

    0.5, 0.4, 0.0, //roof
    0.5, 0.4, 0.0,
    0.5, 0.4, 0.0,
    0.5, 0.4, 0.0
};

void drawSun()
{
    if(isNight)
        glColor3f(1.0, 1.0, 1.0);
    else
        glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        for(GLint i = 0; i < circlePoints; i++)
        {
            GLdouble ang = PI * 2 / circlePoints * i;
            glVertex2d(sizeOfSun * sin(ang) + sunPosX, sizeOfSun * cos(ang) + sunPosY);
        }
    glEnd();
}

void move ()
{
    glutPostRedisplay();
    sunPosX-=10;
    if (sunPosX < -50) {
        sunPosX = 649;
        if (isNight)
            isNight = false;
        else
            isNight = true;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, (isNight)? nightColor : dayColor);
    glDrawArrays(GL_QUADS, 0, 12);
    glDrawArrays(GL_TRIANGLES, 12, 3);
    drawSun();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
}

void reshape(int Width, int Height)
{
    if (Height == 0)
        Height = 1;
    glViewport(0, 0, (GLint)Width, (GLint)Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);
    display();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(500, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("First Lab");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(move);
    glutMainLoop();
    return 0;
}
