#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <vector>

class VBO {
public:
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size, GLenum usage);;
	void Bind();
	void UnBind();
	void Delete();
};

#endif
