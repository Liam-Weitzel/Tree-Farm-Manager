#include<GL/Glut.h>
#include<stdlib.h>
#include<iostream>
#include "RGBpixmap.h"

int i = 1;
int line_x[100], line_y[100];
int dot_x[100], dot_y[100];
int first_dot_x, first_dot_y, first_line_x, first_line_y = -1;

int width = 640;
int height = 480;
float width_f = 640;
float height_f = 480;

void mouse(int button, int state, int mousex, int mousey) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (first_line_y == -1) {
			first_dot_x = mousex;
			first_dot_y = height - mousey;
			first_line_x = mousex;
			first_line_y = height - mousey;
		}
		else {
			line_x[i] = mousex;
			line_y[i] = height - mousey;

			dot_x[i] = mousex;
			dot_y[i] = height - mousey;

			i++;
		}
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
}

void display(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width_f, 0.0, height_f);

	line_x[i] = first_line_x;
	line_y[i] = first_line_y;
	line_y[0] = first_line_y;
	line_x[0] = first_line_x;
	dot_x[0] = first_dot_x;
	dot_y[0] = first_dot_y;

	for (int k = 0; k <= i-1; k++) {

		glColor3f(1, 0, 0);
		glPointSize(2);
		glBegin(GL_LINES);
		glVertex2i(line_x[k], line_y[k]);
		glVertex2i(line_x[k + 1], line_y[k + 1]);

		glEnd();

		glColor3f(1, 0, 0);
		glPointSize(10);
		glBegin(GL_POINTS);
		glVertex2i(dot_x[k], dot_y[k]);

		glEnd();
	}

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Tree Farm Manager");

	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}