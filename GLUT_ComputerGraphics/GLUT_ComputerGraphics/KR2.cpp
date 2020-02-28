//#include <iostream>
//#include <windows.h>
//#include <stdio.h>
//#include <stdarg.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/gl.h>
////#include <SOIL.h>
//#include <math.h>
//
//using namespace std;
//
//int const WINDOW_HEIGHT = 600, WINDOW_WIDTH = 600;
//
//double rotateSpereY = 360;
//
//
//
//int limit_spheres = 20;
//int iter_shpere = 1;
//double sphereRadius = 0.9;
//
//void draw_circle()
//{
//	glColor3f(1, 1, 1);
//	GLfloat twicePi = 2.0 * 3.141592;
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= 100; i++)
//	{
//		glVertex3f(
//			(sphereRadius * cos(i * twicePi / 100)), (sphereRadius * sin(i * twicePi / 100)), (sphereRadius * sin(i * twicePi / 100))
//		);
//	}
//	glEnd();
//}
//
//void drawSphere()
//{
//	glColor3f(1.0, 0, 0);
//	glTranslatef(sphereRadius, 0, 0);
//	glutWireSphere(0.07, 10, 100);
//}
//
//void drawSpheres(int limit)
//{
//	GLfloat angle = 360 / limit;
//
//	glPushMatrix();
//	for (int i = 0; i < limit; i++)
//	{
//
//		drawSphere();
//		glTranslatef(-sphereRadius, 0, 0);
//		glRotatef(angle, 0.0, 1.0, 0.0);
//
//
//	}
//	glPopMatrix();
//}
//
//void rotatingFunc(int idTimer)
//{
//
//	if (rotateSpereY == 0)
//	{
//		rotateSpereY = 356;
//		if (iter_shpere < limit_spheres)
//			iter_shpere++;
//	}
//	else rotateSpereY -= 4;
//
//
//	glutPostRedisplay();
//	glutTimerFunc(50, rotatingFunc, 0);
//}
//
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	// draw_circle();
//	glPushMatrix();
//	glLoadIdentity();
//	glRotatef(90, 1, 0, 0);
//	glRotatef(rotateSpereY, 0.0, 1.0, 0.0);
//	drawSpheres(iter_shpere);
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glEnable(GL_DEPTH_TEST);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat light_diffuse[] = { 0.4, 0.77, 0.2 };
//	GLfloat light_posiiton[] = { 0, 0, 0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_posiiton);
//	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
//
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_NORMALIZE);
//
//
//}
//
//void reshape(int width, int height)
//{
//	int frameWH = width > height ? height : width;
//	glViewport((width - frameWH) / 2, (height - frameWH) / 2, frameWH, frameWH);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(1.0, (float)WINDOW_WIDTH / WINDOW_HEIGHT, 1, 1);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
//	glutCreateWindow("");
//	init();
//	glutDisplayFunc(display);
//
//
//	glutTimerFunc(50, rotatingFunc, 0);
//
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//
//	return 0;
//}
