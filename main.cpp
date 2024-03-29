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
#include "Farm.h"
#include "FarmList.h"
#include "Construction.h"
#include "ConstructionList.h"
#include "Olive.h"
#include "OliveList.h"
#include "Orange.h"
#include "OrangeList.h"
#include "Almond.h"
#include "AlmondList.h"

//default value for color selector in gui
static ImVec4 fill_color = ImVec4(0.45f, 0.55f, 0.60f, 0.20f);
static ImVec4 prev_fill_color = ImVec4(0.45f, 0.55f, 0.60f, 0.20f);

//window width and height
double w;
double h;

//Generate lists for all areas and children of areas
AreaList list;
PolyArea* arealist = list.getAreas();
FarmList list2;
Farm* farmlist = list2.getFarms();
ConstructionList list3;
Construction* constructionlist = list3.getConstructions();
OliveList list4;
Olive* olivelist = list4.getOlives();
OrangeList list5;
Orange* orangelist = list5.getOranges();
AlmondList list6;
Almond* almondlist = list6.getAlmonds();

//Selected area objects & vars
int areaselected = 0;
int areaselectupdatecheck = areaselected;
int numberofareas = 1;

//Background image object
Texture background("image.png");

void GUI()
{
	ImGui::Begin("Area Editor"); //GUI which creates, edits and selects areas

	ImGui::SliderInt("Selected area", &areaselected, 0, numberofareas-1);  // Edit 1 integer with a slider

	if (areaselected != areaselectupdatecheck) { //change the GUI selected color to the color of the area once
		fill_color = arealist[areaselected].getRGBO();
		prev_fill_color = arealist[areaselectupdatecheck].getRGBO();
		arealist[areaselectupdatecheck].setRGBO((GLfloat)prev_fill_color.x, (GLfloat)prev_fill_color.y, (GLfloat)prev_fill_color.z, (GLfloat)0.2f);
		areaselectupdatecheck = areaselected;
	}

	ImGui::ColorEdit3("Fill color", (float*)&fill_color); // Edit 4 floats representing a color
	arealist[areaselected].setRGBO((GLfloat)fill_color.x, (GLfloat)fill_color.y, (GLfloat)fill_color.z, (GLfloat) 0.8f);

	if (ImGui::Button("Add area"))
		if (numberofareas <= 30) {
			numberofareas++;
			areaselected = numberofareas-1;
		}
	
	ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate); //FPS counter
	ImGui::End();

	/*-----------------------------------------------------------*/

	ImGui::Begin("Area Options"); //Dynamic GUI which shows options per area

	if (((arealist[areaselected].getFirstDotX() == farmlist[areaselected].getFirstDotX()) && (arealist[areaselected].getFirstDotY() == farmlist[areaselected].getFirstDotY())) && farmlist[areaselected].getFirstDotX() != -1) {
		//If the area is a farm:

		ImGui::Button("Add harvesting task"); //Add if statement around buttons to add functionality, button = true when clicked
		ImGui::Button("Add planting task");
		ImGui::Button("Add plowing task");
		ImGui::Button("Add milling task");
		ImGui::Button("Add shredding task");
		ImGui::Button("Add pruning task");

		if (((arealist[areaselected].getFirstDotX() == olivelist[areaselected].getFirstDotX()) && (arealist[areaselected].getFirstDotY() == olivelist[areaselected].getFirstDotY())) && olivelist[areaselected].getFirstDotX() != -1) {
			//If the area is an olive farm
			ImGui::Text("This is an olive plot");
			//Get all possible species for selected area
			std::string str = olivelist[areaselected].getPossibleSpecies()[0];
			char species0[128];
			strcpy(species0, str.c_str());
			str = olivelist[areaselected].getPossibleSpecies()[1];
			char species1[128];
			strcpy(species1, str.c_str());
			str = olivelist[areaselected].getPossibleSpecies()[2];
			char species2[128];
			strcpy(species2, str.c_str());

			//Set states for radio buttons to off
			int state0 = 1;
			int state1 = 1;
			int state2 = 1;
			if (olivelist[areaselected].getSpecies() == 0) { //Fetch state button from selected area
				state0 = 0;
			}
			else if (olivelist[areaselected].getSpecies() == 1) { 
				state1 = 0;
			}
			else if (olivelist[areaselected].getSpecies() == 2) {
				state2 = 0;
			}
			
			ImGui::Text("Select species:"); //Radio buttons to select species
			if (ImGui::RadioButton(species0, &state0, 0)) {
				olivelist[areaselected].setSpecies(0); //Set species of selected area
			}
			else if (ImGui::RadioButton(species1, &state1, 0)) {
				olivelist[areaselected].setSpecies(1);
			}
			else if (ImGui::RadioButton(species2, &state2, 0)) {
				olivelist[areaselected].setSpecies(2);
			}

			ImGui::Button("Add fertilization task");
			ImGui::Button("Add disenfection task");

		} else if (((arealist[areaselected].getFirstDotX() == orangelist[areaselected].getFirstDotX()) && (arealist[areaselected].getFirstDotY() == orangelist[areaselected].getFirstDotY())) && orangelist[areaselected].getFirstDotX() != -1) {
			//If the area is an orange farm
			ImGui::Text("This is an orange plot");
			//Get all possible species for selected area
			std::string str = orangelist[areaselected].getPossibleSpecies()[0];
			char species0[128];
			strcpy(species0, str.c_str());
			str = orangelist[areaselected].getPossibleSpecies()[1];
			char species1[128];
			strcpy(species1, str.c_str());
			str = orangelist[areaselected].getPossibleSpecies()[2];
			char species2[128];
			strcpy(species2, str.c_str());

			//Set states for radio buttons to off
			int state0 = 1;
			int state1 = 1;
			int state2 = 1;
			if (orangelist[areaselected].getSpecies() == 0) { //Fetch state button from selected area
				state0 = 0;
			}
			else if (orangelist[areaselected].getSpecies() == 1) {
				state1 = 0;
			}
			else if (orangelist[areaselected].getSpecies() == 2) {
				state2 = 0;
			}

			ImGui::Text("Select species:"); //Radio buttons to select species
			if (ImGui::RadioButton(species0, &state0, 0)) {
				orangelist[areaselected].setSpecies(0); //Set species of selected area
			}
			else if (ImGui::RadioButton(species1, &state1, 0)) {
				orangelist[areaselected].setSpecies(1);
			}
			else if (ImGui::RadioButton(species2, &state2, 0)) {
				orangelist[areaselected].setSpecies(2);
			}

			ImGui::Button("Add fertilization task");
			ImGui::Button("Add disenfection task");

		} else if (((arealist[areaselected].getFirstDotX() == almondlist[areaselected].getFirstDotX()) && (arealist[areaselected].getFirstDotY() == almondlist[areaselected].getFirstDotY())) && almondlist[areaselected].getFirstDotX() != -1) {
			//If the area is an almond farm
			ImGui::Text("This is an almond plot");
			
			//Get all possible species for selected area
			std::string str = almondlist[areaselected].getPossibleSpecies()[0];
			char species0[128];
			strcpy(species0, str.c_str());
			str = almondlist[areaselected].getPossibleSpecies()[1];
			char species1[128];
			strcpy(species1, str.c_str());
			str = almondlist[areaselected].getPossibleSpecies()[2];
			char species2[128];
			strcpy(species2, str.c_str());

			//Set states for radio buttons to off
			int state0 = 1;
			int state1 = 1;
			int state2 = 1;
			if (almondlist[areaselected].getSpecies() == 0) { //Fetch state button from selected area
				state0 = 0;
			}
			else if (almondlist[areaselected].getSpecies() == 1) {
				state1 = 0;
			}
			else if (almondlist[areaselected].getSpecies() == 2) {
				state2 = 0;
			}

			ImGui::Text("Select species:"); //Radio buttons to select species
			if (ImGui::RadioButton(species0, &state0, 0)) {
				almondlist[areaselected].setSpecies(0); //Set species of selected area
			}
			else if (ImGui::RadioButton(species1, &state1, 0)) {
				almondlist[areaselected].setSpecies(1);
			}
			else if (ImGui::RadioButton(species2, &state2, 0)) {
				almondlist[areaselected].setSpecies(2);
			}

		}
		else {
			ImGui::Text("Specify type of farm:");
			if (ImGui::Button("Make area an olive farm")) {
				Olive olive(farmlist[areaselected]);
				olivelist[areaselected] = olive;
			}
			if (ImGui::Button("Make area an orange farm")) {
				Orange orange(farmlist[areaselected]);
				orangelist[areaselected] = orange;
			}
			if (ImGui::Button("Make area an almond farm")) {
				Almond almond(farmlist[areaselected]);
				almondlist[areaselected] = almond;
			}
		}
	} else if (((arealist[areaselected].getFirstDotX() == constructionlist[areaselected].getFirstDotX()) && (arealist[areaselected].getFirstDotY() == constructionlist[areaselected].getFirstDotY())) && constructionlist[areaselected].getFirstDotX() != -1) {
		//If it area is a construction site:
		ImGui::Text("This is a construction site");
		//Fetch variables of selected area as default value for input text
		std::string str = constructionlist[areaselected].getContractor();
		char contractor[128];
		strcpy(contractor, str.c_str());
		str = constructionlist[areaselected].getStart();
		char startdate[128];
		strcpy(startdate, str.c_str());
		str = constructionlist[areaselected].getEnd();
		char enddate[128];
		strcpy(enddate, str.c_str());

		ImGui::InputText("Contractor", contractor, IM_ARRAYSIZE(contractor));
		constructionlist[areaselected].setContractor(contractor); //Set input text to variable in selected area
		ImGui::InputText("Start date", startdate, IM_ARRAYSIZE(startdate));
		constructionlist[areaselected].setStart(startdate);
		ImGui::InputText("End date", enddate, IM_ARRAYSIZE(enddate));
		constructionlist[areaselected].setEnd(enddate);
	}
	else {
		//if the area is not a farm or construction site:
		ImGui::Text("Specify type of area:");
		if (ImGui::Button("Make area a farm")) {
			Farm farm(arealist[areaselected]);
			farmlist[areaselected] = farm;
		}
		if (ImGui::Button("Make area a construction")) {
			Construction construction(arealist[areaselected]);
			constructionlist[areaselected] = construction;
		}
	}

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
	try {
		if ((ImGui::IsMouseClicked(0) || ImGui::IsMouseClicked(1)) && !ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) && !ImGui::IsWindowFocused(ImGuiFocusedFlags_AnyWindow)) {
			;
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
	}
	catch (const std::exception& e) {
		std::cout << e.what();
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

	try {
		GUI();
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
	

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	try {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1000, 1000);
		glutCreateWindow("Tree Farm Manager");
		glutDisplayFunc(render);

		w = glutGet(GLUT_WINDOW_WIDTH);
		h = glutGet(GLUT_WINDOW_HEIGHT);
		background.glInitTexture();
	}
	catch (const std::exception& e) {
		std::cout << e.what();
		exit(1);
	}

	// Setup imGui context, style & Platform/Renderer backends
	try {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGLUT_Init();
		ImGui_ImplGLUT_InstallFuncs();
		ImGui_ImplOpenGL2_Init();
	}
	catch (const std::exception& e) {
		std::cout << e.what();
		exit(1);
	}

	glutMainLoop();

	// Cleanup imGui
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();

	return 0;
}