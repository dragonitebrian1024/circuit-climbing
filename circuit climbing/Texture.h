#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include "stb/stb_image.h"

#include "Shader.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	//normal texture
	Texture(const char* image, GLenum slot, GLenum format, GLint horizontaldrawmode, GLint verticaldrawmode, GLint minFilterDrawAlgo, GLint magFilterDrawAlgo, bool VerticalFlip, float borderR, float borderG, float borderB, float borderA);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};
#endif
