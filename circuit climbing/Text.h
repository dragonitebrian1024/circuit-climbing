#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <map>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <glm.hpp>
#include <ft2build.h>
#include <string>
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include <ft2build.h>
#include FT_FREETYPE_H 
    //leave TextWidth 0 if you are using a font like arial on default width
void TextInit(const char* Font, int SCR_WIDTH, int SCR_HEIGHT, int TextWidth, int TextHeight, Shader &TextShader);
static int textwidth, textheight;
void RenderText(std::string text, float x, float y, float scale, glm::vec3 color, Shader& TextShader, VAO vao);
void ChangeTextWidth(int Textwidth);
void ChangeTextHeight(int Textheight);