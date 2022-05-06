/*#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>

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

	//Drawing the background quad:
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(-1.0f, -1.0f);
	glTexCoord2f(1, 0);
	glVertex2f(1.0f, -1.0f);
	glTexCoord2f(1, 1);
	glVertex2f(1.0f, 1.0f);
	glTexCoord2f(0, 1);
	glVertex2f(-1.0f, 1.0f);
	glEnd();

	glPopMatrix();

	//Drawing the dots & lines
	line_x[i] = first_line_x;
	line_y[i] = first_line_y;
	line_y[0] = first_line_y;
	line_x[0] = first_line_x;
	dot_x[0] = first_dot_x;
	dot_y[0] = first_dot_y;

	for (int k = 0; k <= i - 1; k++) {

		glColor3f(1, 0, 0);
		glPointSize(1);
		glBegin(GL_LINES);
		glVertex2i(line_x[k], line_y[k]);
		glVertex2i(line_x[k + 1], line_y[k + 1]);

		glEnd();

		glColor3f(1, 0, 0);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2i(dot_x[k], dot_y[k]);

		glEnd();

		std::cout << "Point: " << k << ", x: " << dot_x[k] << ", y: " << dot_y[k] << "\n";

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
	return 0;
}*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

GLuint texture;

GLuint glInitTexture(const char* filename)
{
	FILE* f = NULL;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		fprintf(stderr, "cannot load file %s!", filename);
		exit(1);
	}
	GLuint t = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	glBindTexture(GL_TEXTURE_2D, t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return t;
}

void drawImage(GLuint file,
	float x,
	float y,
	float w,
	float h,
	float angle)
{
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, file);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0f);
	glTexCoord2f(0.0, 2.0); glVertex3f(x, y + h, 0.0f);
	glTexCoord2f(2.0, 2.0); glVertex3f(x + w, y + h, 0.0f);
	glTexCoord2f(2.0, 0.0); glVertex3f(x + w, y, 0.0f);
	glEnd();

	glPopMatrix();
}

void render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const double w = glutGet(GLUT_WINDOW_WIDTH);
	const double h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(45.0, w / h, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -5);

	drawImage(texture, -1.18f, -1.01f, 9.35f, 8.2f, 0.0);

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 1200);
	glutCreateWindow("Applying Textures");
	glutDisplayFunc(render);

	texture = glInitTexture("image.png");

	glutMainLoop();
	return 0;
}