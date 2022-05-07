#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include "Texture.h"

Texture::Texture(const char* filename) {
	this->filenamer = filename;
}

void Texture::glInitTexture()
{
	FILE* f = NULL;
	f = fopen(this->filenamer, "r");
	if (f == NULL)
	{
		fprintf(stderr, "cannot load file %s!", this->filenamer);
		exit(1);
	}
	GLuint t = SOIL_load_OGL_texture(this->filenamer, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	glBindTexture(GL_TEXTURE_2D, t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	this->file = t;
}

void Texture::drawImageQuad(float x,
	float y,
	float w,
	float h,
	float angle)
{
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, this->file);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0f);
	glTexCoord2f(0.0, 2.0); glVertex3f(x, y + h, 0.0f);
	glTexCoord2f(2.0, 2.0); glVertex3f(x + w, y + h, 0.0f);
	glTexCoord2f(2.0, 0.0); glVertex3f(x + w, y, 0.0f);
	glEnd();

	glPopMatrix();
}