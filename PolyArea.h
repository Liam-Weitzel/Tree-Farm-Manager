#ifndef POLYAREA_H
#define POLYAREA_H

class PolyArea 
{
	private:
		int line_x[100], line_y[100];
		int dot_x[100], dot_y[100];
		int first_dot_x, first_dot_y, first_line_x, first_line_y;
		int i;
		float vertices[100];
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat o;
	public:
		PolyArea();
		void setFirstDot(int x, int y);
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
};

#endif