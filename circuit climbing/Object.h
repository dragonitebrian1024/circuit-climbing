#pragma once
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Collision.h"
#include "Texture.h"
#include <vector>

//example of a custom struct/object
/*struct Enemy {
    float Enemyx = -0.36f;
    float Enemyy = -0.24f;
    float EnemyOffsetX = 0;
    float EnemyOffsetY = 0;
    int Type = rand() % 6;
    float theRotate = 0;
    Shader* EnemyShader;
    Texture* texture1;
    Texture* texture2;//tomorrow do wave system and sound system and cleaning up and deployment
    AABB EnemyBorder = { glm::vec2(Enemyx, Enemyy), glm::vec2(Enemyx + 0.04, Enemyy + 0.12) };
    void Init(VAO vao) {
        GLfloat vertices[]{
            -0.32f, -0.12f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
            -0.32f, -0.24f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.36f, -0.24f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            -0.36f, -0.12f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
        };
        unsigned int indices[]{
            0, 1, 3,
            1, 2, 3
        };
        EnemyShader = new Shader("fifth.vert", "fifth.frag");
        vao.Bind();
        VBO vbo(vertices, sizeof(vertices), GL_DYNAMIC_DRAW);
        EBO ebo(indices, sizeof(indices), GL_DYNAMIC_DRAW);
        vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
        vao.LinkAttribute(vbo, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float)));
        EnemyShader->Activate();
        if (Type == 0) {
            texture1 = new Texture("left colon.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
            texture2 = new Texture("right colon.png", GL_TEXTURE1, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
        }
        else if (Type == 1 || Type == 2 || Type == 3) {
            texture1 = new Texture("left comma.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
            texture2 = new Texture("right comma.png", GL_TEXTURE1, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
        }
        else if (Type == 4 || Type == 5) {
            texture1 = new Texture("period.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
            texture2 = new Texture("period.png", GL_TEXTURE1, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
        }
    };
    void Update(VAO vao) {
        EnemyShader->Activate();
        EnemyShader->setFloat("Enemyoffsetx", EnemyOffsetX);
        EnemyShader->setFloat("Enemyoffsety", EnemyOffsetY);
        vao.Bind();
        if (theRotate <= 0.6f)
            EnemyShader->setFloat("TheimageSelected", 1);
        else if (theRotate >= 0.6f)
            EnemyShader->setFloat("TheimageSelected", 2);
        glActiveTexture(GL_TEXTURE0);
        texture1->Bind();
        glActiveTexture(GL_TEXTURE1);
        texture2->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        if (theRotate >= 1.2f)
            theRotate = 0.0f;
    };

    void End(VAO vao) {
        texture1->Delete();
        delete texture1;
        texture2->Delete();
        delete texture2;
        vao.Delete();
        EnemyShader->End();
        delete EnemyShader;
    };
};*/
//default positions:left=-0.50,right=-0.25,up=-0.25,down=-0.50
struct DefaultObject {
    Shader* shader;
    Texture* texture;
    VAO vao;
    float offsetX, offsetY;
    AABB Collider = { glm::vec2(-0.50f, -0.50f), glm::vec2(-0.25f, -0.25) };
    GLfloat vertices[36]{
        -0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.25f, -0.50f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.50f, -0.50f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.50f, -0.25f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    unsigned int indices[6]{
        0, 1, 3,
        1, 2, 3
    };
    void Init(const char* TextureFileName, bool FlipVertically);
    void Update();
    void Delete();
    //put a negative number if you want it to extend left
    void extendleftside(float howmuch) {
        vertices[18] -= howmuch;
        vertices[27] -= howmuch;
        Collider.min.x -= howmuch;
    }
    void extendrightside(float howmuch) {
        vertices[0] += howmuch;
        vertices[9] += howmuch;
        Collider.max.x += howmuch;
    }
    void extendupside(float howmuch) {
        vertices[1] += howmuch;
        vertices[28] += howmuch;
        Collider.max.y += howmuch;
    }
    void extenddownside(float howmuch) {
        vertices[10] -= howmuch;
        vertices[19] -= howmuch;
        Collider.min.y -= howmuch;
    }
    void MoveY(float howmuch)
    {
        offsetY += howmuch;
        Collider.min.y += howmuch;
        Collider.max.y += howmuch;
    }
    void MoveX(float howmuch)
    {
        offsetX += howmuch;
        Collider.min.x += howmuch;
        Collider.max.x += howmuch;
    }
};

struct Level : DefaultObject {
    GLfloat vertices[36]{
         1.0f,  1.0f, 0.0f, 0, 0, 0, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f, 0.0f,0, 0, 0, 1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,0, 0, 0, 1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,0, 0, 0, 1.0f, 0.0f, 1.0f
    };
    VAO vao;
    Shader* shader;
    Texture* texture;
    AABB leftborder = { glm::vec2(-1.0, -1.0), glm::vec2(-0.98, 1.0) };
    AABB rightborder = { glm::vec2(0.98, -1.0), glm::vec2(1.0, 1.0)};
    AABB upborder = { glm::vec2(-1.0, 0.98), glm::vec2(1.0, 1.0) };
    AABB downborder = { glm::vec2(-1.0, -1.0), glm::vec2(1.0, -0.98) };
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
    void Init(const char* TextureFileName, bool FlipVertically, int setting);
    void Update();
    void Delete();
};
