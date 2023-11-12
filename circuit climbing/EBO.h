#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO {
public:
	GLuint ID;
	EBO(GLuint* indices, GLsizeiptr size, GLenum usage);

	void Bind();
	void UnBind();
	void Delete();
};

#endif
