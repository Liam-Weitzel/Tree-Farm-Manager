#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
private:
	GLuint file;
	const char* filenamer;
public:
	Texture(const char* filename);
	void glInitTexture();
	void drawImageQuad(float x, float y, float w, float h, float angle);
};

#endif