////#define GL_SILENCE_DEPRECATION
//#include <math.h>
//#include <GL/glut.h>
//#define PI 3.1415926535898
//GLint circlePoints=100;
//GLint sizeOfSun = 50;
//bool isNight = false;
//GLint sunPosX = 50;
//GLint sunPosY = 500;
//
//void drawGrass()
//{
//    if(isNight)
//        glColor3f(0.0, 0.5, 0.0);
//    else
//        glColor3f(0.0, 0.9, 0.0);
//    glBegin(GL_QUADS);
//        glVertex2f(0.0, 0.0);
//        glVertex2f(0.0, 300.0);
//        glVertex2f(600.0, 300.0);
//        glVertex2f(600.0, 0.0);
//    glEnd();
//}
//
//void drawSky()
//{
//    if(isNight)
//        glColor3f(0.0, 0.1, 0.2);
//    else
//        glColor3f(0.0, 1.0, 1.0);
//    glBegin(GL_QUADS);
//        glVertex2f(0.0, 300.0);
//        glVertex2f(0.0, 600.0);
//        glVertex2f(600.0, 600.0);
//        glVertex2f(600.0, 300.0);
//    glEnd();
//}
//
//void drawHouseFrame()
//{
//    if(isNight)
//        glColor3f(0.2, 0.1, 0.0);
//    else
//        glColor3f(0.4, 0.2, 0.0);
//    glBegin(GL_QUADS);
//        glVertex2f(50.0, 100.0);
//        glVertex2f(50.0, 250.0);
//        glVertex2f(200.0, 250.0);
//        glVertex2f(200.0, 100.0);
//    glEnd();
//   
//}
//
//void drawRoof()
//{
//    if(isNight)
//        glColor3f(0.25, 0.2, 0.0);
//    else
//        glColor3f(0.5, 0.4, 0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex2f(25.0, 250.0);
//        glVertex2f(125.0, 350.0);
//        glVertex2f(225.0, 250.0);
//    glEnd();
//}
//
//void drawWindow()
//{
//   if(isNight)
//        glColor3f(1.0, 1.0, 0.0);
//    else
//        glColor3f(0.0, 0.5, 0.75);
//    glBegin(GL_QUADS);
//        glVertex2f(100.0, 150.0);
//        glVertex2f(100.0, 190.0);
//        glVertex2f(150.0, 190.0);
//        glVertex2f(150.0, 150.0);
//    glEnd(); 
//}
//
//void drawLightObj()
//{
//    if(isNight)
//        glColor3f(1.0, 1.0, 1.0);
//    else
//        glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_POLYGON);
//        for(GLint i = 0; i < circlePoints; i++)
//        {
//            GLdouble ang = PI * 2 / circlePoints * i;
//            glVertex2f(sizeOfSun * sin(ang) + sunPosX, sizeOfSun * cos(ang) + sunPosY);
//        }
//    glEnd();
//}
//
//void move ()
//{
//    glutPostRedisplay();
//    sunPosX+=1;
//    if (sunPosX > 650) {
//        sunPosX = -50;
//        isNight = !isNight;
//    }
//}
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawGrass();
//    drawSky();
//    drawHouseFrame();
//    drawRoof();
//    drawWindow();
//    drawLightObj();
//    glFlush();
//}
//
//void reshape(int Width, int Height)
//{
//    if (Height == 0)
//        Height = 1;
//    glViewport(0, 0, (GLint)Width, (GLint)Height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);
//    display();
//}
//
//void init()
//{
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//}
//
//int main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//    glutInitWindowPosition(500, 200);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("First Lab");
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutIdleFunc(move);
//    glutMainLoop();
//
//    return 0;
//}
