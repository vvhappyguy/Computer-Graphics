///*
//	KR1 - Пружина
//	KR2 - Шарики
//*/
//
//#include <iostream>
//#include <vector>
//#include <GL/freeglut.h>
//#include <cmath>
//
//
//using namespace std;
//
//#define PI 3.14
//
//GLfloat light_pos[4] = { 0., 1., -1. };
//
//float angle_1 = 0.0;
//float angle_2 = 0.0;
//float angle_3 = 0.0;
//
//
//void ProcessNormalKeys(unsigned char key, int x, int y);
//void ProcessSpecialKeys(int key, int x, int y);
//
//void display();
//void reshape(int w, int h);
//
//void changes();
//
//void Init();
//void DrawAtom();
//void DrawElectron(float x, float y, float z);
//void DrawTrajectory(float centr_x, float centr_y, float centr_z, float radius_x, float radius_y, float radius_z);
//
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
//	glutInitWindowPosition(500, 100);
//	glutInitWindowSize(350, 350);
//	glutCreateWindow("ekz_work");
//
//	Init();
//	glEnable(GL_DEPTH_TEST);
//
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutIdleFunc(display);
//
//	glutKeyboardFunc(ProcessNormalKeys);
//	glutSpecialFunc(ProcessSpecialKeys);
//
//	glutMainLoop();
//	return 0;
//}
//
//void ProcessNormalKeys(unsigned char key, int x, int y)
//{
//
//}
//
//void ProcessSpecialKeys(int key, int x, int y)
//{
//	switch (key)
//	{
//	default:
//
//		break;
//	}
//}
//
//void display()
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glColor4f(1.0, 0.0, 0.0, 1.0);
//
//	DrawAtom();
//
//
//	glColor4f(0.0, 1.0, 0.0, 1.0);
//	DrawElectron(1.5 * cos(angle_1 * PI / 180), 0, sin(angle_1 * PI / 180));
//	glLoadIdentity();
//	DrawTrajectory(0, 0, 0, 1.5, 0, 1);
//
//	glColor4f(0.0, 1.0, 1.0, 1.0);
//	DrawElectron(-1.5 * cos(angle_2 * PI / 180), -sin(angle_2 * PI / 180), 0);
//	glLoadIdentity();
//	DrawTrajectory(0, 0, 0, 1.5, 1, 0);
//
//	glColor4f(1.0, 0.0, 1.0, 1.0);
//	DrawElectron(0, 1.5 * cos(angle_3 * PI / 180), 2 * sin(angle_3 * PI / 180));
//	glLoadIdentity();
//	DrawTrajectory(0, 0, 0, 0, 1.5, 2);
//
//	glLoadIdentity();
//
//	changes();
//
//	glutSwapBuffers();
//	glFlush();
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(90, (GLdouble)w / h, 0.01, 100.0);//насколько широко открыто око камеры (120 градусов)
//	gluLookAt(2., 1., 2., 0., 0., 0., 0., 1., 0.);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void Init()
//{
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);
//
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
//}
//
//void changes()
//{
//	angle_1++;
//	angle_2++;
//	angle_3++;
//}
//
//void DrawAtom()
//{
//	glColor4f(1.0, 0.0, 0.0, 1.0);
//	GLUquadricObj* quadObj;
//	quadObj = gluNewQuadric();
//	gluSphere(quadObj, 0.5, 100, 10);
//}
//
//void DrawElectron(float x, float y, float z)
//{
//	GLUquadricObj* quadObj;
//	quadObj = gluNewQuadric();
//	glTranslatef(x, y, z);
//	gluSphere(quadObj, 0.1, 100, 10);
//}
//
//void DrawTrajectory(float centr_x, float centr_y, float centr_z, float radius_x, float radius_y, float radius_z)
//{
//	int lineAmount = 100;
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= lineAmount; i++) {
//		if (i % 2 == 1) {
//			if (radius_z != 0)
//				glVertex3f(
//					centr_x + (radius_x * cos(i * 2 * PI / lineAmount)),
//					centr_y + (radius_y * cos(i * 2 * PI / lineAmount)),
//					centr_z + (radius_z * sin(i * 2 * PI / lineAmount))
//				);
//			else
//				glVertex3f(
//					centr_x + (radius_x * cos(i * 2 * PI / lineAmount)),
//					centr_y + (radius_y * sin(i * 2 * PI / lineAmount)),
//					centr_z + (radius_z * sin(i * 2 * PI / lineAmount))
//				);
//		}
//	}
//	glEnd();
//}