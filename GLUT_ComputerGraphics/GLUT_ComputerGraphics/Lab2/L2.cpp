//#define GL_SILENCE_DEPRECATION
//#include <math.h>
//#include "..\Lab2_ver_array.h"
//
//
//void drawSun()
//{
//	// add drawLightObj func
//	if (isNight)
//		glColor3f(1.0, 1.0, 1.0);
//	else
//		glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	for (GLint i = 0; i < circlePoints; i++)
//	{
//		GLdouble ang = PI * 2 / circlePoints * i;
//		glVertex2f(sizeOfSun * sin(ang) + sunPosX, sizeOfSun * cos(ang) + sunPosY);
//	}
//	glEnd();
//}
//
//void move()
//{
//	glutPostRedisplay();
//	sunPosX += 1;
//	if (sunPosX > windowWidth + sizeOfSun) {
//		sunPosX = -50;
//		isNight = !isNight;		
//	}
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glVertexPointer(2, GL_FLOAT, 0, vertices);
//	glColorPointer(3, GL_FLOAT, 0, (isNight) ? nightColor : dayColor);
//	glDrawArrays(GL_QUADS, 0, 12);
//	glDrawArrays(GL_TRIANGLES, 12, 3);
//	drawSun();
//	//glDisableClientState(GL_VERTEX_ARRAY);
//	//glDisableClientState(GL_COLOR_ARRAY);
//	glFlush();
//}
//
//void reshape(int Width, int Height)
//{
//	::windowHeight = Height;
//	::windowWidth = Width;
//	::sunPosY = windowWidth - sizeOfSun - sunUpOffset;
//	glViewport(0, 0, (GLint)Width, (GLint)Height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);
//	display();
//}
//
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(500, 200);
//	glutInitWindowSize(windowWidth, windowHeight);
//	glutCreateWindow("Second Lab");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutIdleFunc(move);
//	glutMainLoop();
//	return 0;
//}
