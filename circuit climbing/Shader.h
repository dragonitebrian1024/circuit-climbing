#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <glm.hpp>

std::string get_file_contents(const char* filename);
class Shader
{
public:
	GLuint ID;
	Shader(const char* Vertexfile, const char* Fragmentfile);

	void Activate();
	void End();
	void checkCompileErrors(unsigned int shader, std::string type);
	GLint FindVariableinShader(const GLchar* variablename);

    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
};

#endif
