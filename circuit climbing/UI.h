
#pragma once
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"
#include "Texture.h"
#include "Shader.h"//tomorrow finish button and start doing text fields
struct button {
		float x, y, w, h;
        float R, G, B;
        VAO vao;
        Shader* shader;
        Texture* texture = nullptr;
        GLfloat vertices[36]{
             -0.25f, -0.25f, 0.0f, R, G, B, 1.0f, 1.0f, 1.0f,
             -0.25f, -0.50f, 0.0f,R, G, B, 1.0f, 1.0f, 0.0f,
            -0.50f, -0.50f, 0.0f,R, G, B, 1.0f, 0.0f, 0.0f,
            -0.50f, -0.25f, 0.0f,R, G, B, 1.0f, 0.0f, 1.0f
        };
        unsigned int indices[6]{
        0, 1, 3,
        1, 2, 3
        };
        void Init(const char* TextureFileName, bool FlipVertically, int setting);
        void Update();
        void Delete();
        //works best at fullscreen
		bool IsTouched(double MouseX, double MouseY);
        void setR(float R) {
            vertices[3] = R;
            vertices[12] = R;
            vertices[21] = R;
            vertices[30] = R;
        }
        void setB(float B) {
            vertices[4] = B;
            vertices[13] = B;
            vertices[22] = B;
            vertices[31] = B;
        }
        void setG(float G) {
            vertices[5] = G;
            vertices[14] = G;
            vertices[23] = G;
            vertices[32] = G;
        }
        void setA(float A) {
            vertices[6] = A;
            vertices[15] = A;
            vertices[24] = A;
            vertices[33] = A;
        }
	};
