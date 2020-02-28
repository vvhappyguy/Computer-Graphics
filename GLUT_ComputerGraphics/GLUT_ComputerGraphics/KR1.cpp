//#include <windows.h>
//#include <stdio.h>
//#include <stdarg.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//// #include <GL/glaux.h>
//#include <GL/gl.h>
//
//int const WINDOW_HEIGHT = 450, WINDOW_WIDTH = 450;
//double rotateX = 10, rotateY = 15;
//double moving = 0;
//int numTor = 9;
//
//bool isPressed = false;
//bool isLight = true;
//
//double maxSpanBetweenRings = 0.5;
//
//void drawSpring()
//{
//	double span = maxSpanBetweenRings;
//
//	glPushMatrix();
//	glRotatef(90, 0.0, 1, 0.0);
//
//	if (numTor % 2 == 1) {
//		glutSolidTorus(span * 0.2, 0.75, 64, 64);//�� ��������
//	}
//
//
//	for (int i = 0; i < numTor / 2; i++)
//	{
//		glTranslatef(0, 0, span - moving);
//		glutSolidTorus(span * 0.2, 0.75, 64, 64);
//	}
//
//	glTranslatef(0, 0, (-span + moving) * (numTor / 2));
//
//	for (int i = 0; i < numTor / 2; i++) {
//		glTranslatef(0, 0, -span + moving);
//		glutSolidTorus(span * 0.2, 0.75, 64, 64);
//	}
//	/*
//	glTranslatef(0,0,0.5-moving);
//	glutSolidTorus(0.1,0.75,64,64);
//
//	glTranslatef(0,0,0.5-moving);
//	glutSolidTorus(0.1,0.75,64,64);
//
//	glTranslatef(0,0,-1.5+moving*3);
//	glutSolidTorus(0.1,0.75,64,64);
//
//	glTranslatef(0,0,-0.5+moving);
//	glutSolidTorus(0.1,0.75,64,64);
//	*/
//
//	glPopMatrix();
//
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	isLight ? glEnable(GL_LIGHT0) : glDisable(GL_LIGHT0);
//
//	glPushMatrix();
//	glRotatef(rotateX, 1, 0.0, 0.0);
//	glRotatef(rotateY, 0, 1, 0.0);
//	drawSpring();
//	glPopMatrix();
//
//	glFlush();
//	glutPostRedisplay();
//	glutSwapBuffers();
//}
//
//void timer(int value)
//{
//	double maxMoving = 0.3;
//	double minMoving = 0;
//	if (numTor % 2 == 0) {
//		maxMoving += 0.1;
//	}
//
//	if (moving > maxMoving) {
//		isPressed = !isPressed;
//	}
//
//	if (moving < minMoving) {
//		isPressed = !isPressed;
//	}
//
//	if (!isPressed) {
//		moving += 0.01;
//	}
//	else {
//		moving -= 0.01;
//	}
//
//	glutPostRedisplay();
//	glutTimerFunc(50, timer, 0);
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
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glEnable(GL_DEPTH_TEST);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat outside_light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, outside_light_diffuse);
//	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
//
//	glEnable(GL_COLOR_MATERIAL);
//	//glEnable(GL_NORMALIZE);
//
//}
//
//void spaceKey(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'a':
//		rotateY += 5;
//		break;
//	case 'd':
//		rotateX += 5;
//		break;
//	case 'w':
//		isLight = !isLight;
//		break;
//	}
//}
//
////int main(int argc, char* argv[])
////{
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
////	glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
////	glutCreateWindow("SPRING");
////	glutDisplayFunc(display);
////	init();
////
////	glutKeyboardFunc(spaceKey);
////	glutTimerFunc(50, timer, 0);
////
////	glutReshapeFunc(reshape);
////	glutMainLoop();
////
////	return 0;
////}
