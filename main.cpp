#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"
#include "PolyArea.h"
#include "Texture.h"
#include "AreaList.h"

//default value for color selector in gui
static ImVec4 fill_color = ImVec4(0.45f, 0.55f, 0.60f, 0.30f);

//window width and height
double w;
double h;

//Selected area objects & vars
AreaList list;
PolyArea* arealist = list.getAreas();
int areaselected = 0;
int areaselectupdatecheck = areaselected;
int numberofareas = 1;

//Background image object
Texture background("image.png");

void GUI()
{
	ImGui::Begin("Tree Farm Manager");

	ImGui::Text("Use right click to add points to a field, and left-click to undo the last click.");

	ImGui::SliderInt("Selected area", &areaselected, 0, numberofareas-1);  // Edit 1 integer with a slider

	if (areaselected != areaselectupdatecheck) { //change the GUI selected color to the color of the area once
		fill_color = arealist[areaselected].getRGBO();
		areaselectupdatecheck = areaselected;
	}

	ImGui::ColorEdit4("Fill color", (float*)&fill_color); // Edit 4 floats representing a color
	arealist[areaselected].setRGBO((GLfloat)fill_color.x, (GLfloat)fill_color.y, (GLfloat)fill_color.z, (GLfloat)fill_color.w);

	if (ImGui::Button("Add area"))
		if (numberofareas <= 30) {
			numberofareas++;
			areaselected = numberofareas-1;
		}
	
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
}

void mouse(int button, int mousex, int mousey) {
	if (button == 0) {
		if (arealist[areaselected].getFirstLineY() == -1) {
			arealist[areaselected].setFirstDot(mousex, h - mousey);
		}
		else {
			arealist[areaselected].setNextPoint(mousex, h - mousey);
		}

		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	else if (button == 1) {
		if (arealist[areaselected].getI() >= 1) {
			arealist[areaselected].removeLastPoint();
		}
	}
	glutPostRedisplay();
}

void render()
{
	//What mousedata ImGUI processes vs what mousedata Glut will process
	if ((ImGui::IsMouseClicked(0) || ImGui::IsMouseClicked(1)) && !ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) && !ImGui::IsWindowFocused(ImGuiFocusedFlags_AnyWindow)) { ;
		ImVec2 mousepos = ImGui::GetMousePos();
		int button = 0;
		if (ImGui::IsMouseClicked(0)) {
			button = 0;
		}
		else if (ImGui::IsMouseClicked(1)) {
			button = 1;
		}
		mouse(button, mousepos.x, mousepos.y);
		//std::cout << mousepos.x << "<<X , Y>>" << mousepos.y << "\n";
	}

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

	//Drawing all areas
	for (int i = 0; i <= numberofareas; i++) {
		arealist[i].DrawArea();
	}

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	GUI();

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Tree Farm Manager");
	glutDisplayFunc(render);

	w = glutGet(GLUT_WINDOW_WIDTH);
	h = glutGet(GLUT_WINDOW_HEIGHT);
	background.glInitTexture();

	// Setup imGui context, style & Platform/Renderer backends
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGLUT_Init();
	ImGui_ImplGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();

	glutMainLoop();

	// Cleanup imGui
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();

	return 0;
}