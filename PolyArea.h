#ifndef POLYAREA_H
#define POLYAREA_H
#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include <random>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"

class PolyArea 
{
	private:
		int line_x[99], line_y[99];
		int dot_x[99], dot_y[99];
		int first_dot_x, first_dot_y, first_line_x, first_line_y;
		int i;
		//float vertices[100];
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat o;
	public:
		PolyArea();
		void setFirstDot(int x, int y);
		void setLineX(int plinex[]);
		void setLineY(int pliney[]);
		void setDotX(int pdotx[]);
		void setDotY(int pdoty[]);
		void setI(int ii);
		int getFirstDotX();
		int getFirstDotY();
		int getFirstLineX();
		int getFirstLineY();
		int getI();
		void setNextPoint(int x, int y);
		void setPointAt(int i2, int x, int y);
		int* getLineX();
		int* getLineY();
		int* getDotX();
		int* getDotY();
		void DrawArea();
		/*float* getVertices();
		void constructVertices();*/
		void setRGBO(GLfloat rp, GLfloat gp, GLfloat bp, GLfloat op);
		void removeLastPoint();
		ImVec4 getRGBO();
};

#endif