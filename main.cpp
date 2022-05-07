#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include "PolyArea.h"
#include "Texture.h"

double w;
double h;

PolyArea firstarea;
PolyArea secondarea;

Texture background("image.png");

void mouse(int button, int state, int mousex, int mousey) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (firstarea.getFirstLineY() == -1) {
			firstarea.setFirstDot(mousex, h - mousey);
		}
		else {
			firstarea.setNextPoint(mousex, h - mousey);
		}

		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (secondarea.getFirstLineY() == -1) {
			secondarea.setFirstDot(mousex, h - mousey);
		}
		else {
			secondarea.setNextPoint(mousex, h - mousey);
		}

		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
}

void render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Setting view
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, w / h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0, 0, -5);

	//Drawing background
	background.drawImageQuad(-1.05f, -1.05f, 8.3f, 8.3f, 0.0);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, w, 0.0, h);

	//Drawing firstarea
	firstarea.DrawArea();

	//Drawing secondarea
	secondarea.DrawArea();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Tree Farm Manager");
	glutDisplayFunc(render);
	glutMouseFunc(mouse);

	w = glutGet(GLUT_WINDOW_WIDTH);
	h = glutGet(GLUT_WINDOW_HEIGHT);
	background.glInitTexture();
	firstarea.setRGBO(0.6f, 0.0f, 0.3f, 0.3f);
	secondarea.setRGBO(0.2f, 0.8f, 0.6f, 0.5f);

	glutMainLoop();
	return 0;
}