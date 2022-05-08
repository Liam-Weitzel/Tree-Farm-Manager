#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include "PolyArea.h"
#include <random>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"

PolyArea::PolyArea() {
	this->first_line_y = -1;
	this->first_dot_x = -1;
	this->first_dot_y = -1;
	this->first_line_x = -1;
	this->i = 1;
	this->r = rand() % 2;
	this->g = rand() % 2;
	this->b = rand() % 2;
	this->o = 0.2f;
	//std::cout << "Im constructed! " << this->i << ", " << this->first_line_y;
}

void PolyArea::setLineX(int plinex[]) {
	memcpy(this->line_x, plinex, 99);
}
void PolyArea::setLineY(int pliney[]) {
	memcpy(this->line_y, pliney, 99);
}
void PolyArea::setDotX(int pdotx[]) {
	memcpy(this->dot_x, pdotx, 99);
}
void PolyArea::setDotY(int pdoty[]) {
	memcpy(this->dot_y, pdoty, 99);
}
void PolyArea::setI(int ii) {
	this->i = ii;
}
void PolyArea::setFirstDot(int x, int y) {
	this->first_dot_x = x;
	this->first_dot_y = y;
	this->first_line_x = x;
	this->first_line_y = y;
}

int PolyArea::getFirstDotX() {
	return this->first_dot_x;
}

int PolyArea::getFirstDotY() {
	return this->first_dot_y;
}

int PolyArea::getFirstLineX() {
	return this->first_line_x;
}

int PolyArea::getFirstLineY() {
	return this->first_line_y;
}

int PolyArea::getI() {
	return this->i;
}

void PolyArea::setNextPoint(int x, int y) {
	this->line_x[i] = x;
	this->line_y[i] = y;
	this->dot_x[i] = x;
	this->dot_y[i] = y;
	this->i++;
}

void PolyArea::setPointAt(int i2, int x, int y) {
	this->line_x[i2] = x;
	this->line_y[i2] = y;
	this->dot_x[i2] = x;
	this->dot_y[i2] = y;
}

int* PolyArea::getLineX() {
	return this->line_x;
}

int* PolyArea::getLineY() {
	return this->line_y;
}

int* PolyArea::getDotX() {
	return this->dot_x;
}

int* PolyArea::getDotY() {
	return this->dot_y;
}
/*
void PolyArea::constructVertices() {
	int counter = 0;
	for (int i3 = 0; i3 <= this->getI(); i3++) {
		this->vertices[counter] = (float)this->dot_x[i3];
		this->vertices[counter+1] = (float)this->dot_y[i3];
		counter = counter + 2;
	}
	this->vertices[0] = this->getFirstDotX();
	this->vertices[1] = this->getFirstDotY();
	this->vertices[(this->i) * 2] = this->getFirstDotX();
	this->vertices[((this->i) * 2) + 1] = this->getFirstDotY();
}

float* PolyArea::getVertices() {
	this->constructVertices();
	return this->vertices;
}*/

void PolyArea::DrawArea() {
	this->setPointAt(0, this->getFirstDotX(), this->getFirstDotY());
	this->setPointAt(this->getI(), this->getFirstDotX(), this->getFirstDotY());

	for (int k = 0; k <= this->getI() - 1; k++) {

		glPointSize(1);
		glColor4f(this->r, this->g, this->b, this->o);
		glBegin(GL_LINES);
		glVertex2i(this->getLineX()[k], this->getLineY()[k]);
		glVertex2i(this->getLineX()[k + 1], this->getLineY()[k + 1]);

		glEnd();

		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2i(this->getDotX()[k], this->getDotY()[k]);

		glEnd();

	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(this->r, this->g, this->b, this->o);

	glBegin(GL_POLYGON);
	for (int a = 0; a < this->getI(); a++)
	{
		glVertex2i(this->getDotX()[a], this->getDotY()[a]);
	}
	glEnd();

	glDisable(GL_BLEND);

	glFlush();
}

void PolyArea::setRGBO(GLfloat rp, GLfloat gp, GLfloat bp, GLfloat op) {
	this->r = rp;
	this->g = gp;
	this->b = bp;
	this->o = op;
}

ImVec4 PolyArea::getRGBO() {
	ImVec4 returner = ImVec4(this->r, this->g, this->b, this->o);
	return returner;
}

void PolyArea::removeLastPoint() {
	if (this->i > 1) {
		this->line_x[i - 1] = line_x[i];
		this->line_y[i - 1] = line_y[i];
		this->dot_x[i - 1] = dot_x[i];
		this->dot_y[i - 1] = dot_y[i];
		this->i--;
	}
	else if (this->i <= 1) {
		this->first_line_y = -1;
		this->first_dot_x = -1;
		this->first_dot_y = -1;
		this->first_line_x = -1;
		this->i = 1;
	}
	
}