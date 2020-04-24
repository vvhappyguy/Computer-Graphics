#pragma once
#include <GL/glut.h>

#define PI 3.1415926535898
GLint circlePoints = 100;
GLint sizeOfSun = 50;
int sunUpOffset = 50;
bool isNight = false;

int windowHeight = 600;
int windowWidth = 600;

GLint sunPosX = 50;
GLint sunPosY = windowWidth - sizeOfSun - sunUpOffset;

static GLfloat vertices[] =
{
	0.0, 0.0, //grass
	0.0, windowHeight / 2,
	windowWidth, windowHeight / 2,
	windowWidth, 0.0,

	0.0, windowHeight / 2, //sky
	0.0, windowHeight,
	windowWidth, windowHeight,
	windowWidth, windowHeight / 2,

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