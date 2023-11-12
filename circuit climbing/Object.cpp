#include "Object.h"
/*
void DefaultObject::Init(const char* TextureFileName, bool FlipVertically) {
    shader = new Shader("default.vert", "default.frag");
    vao.Bind();
    VBO vbo(vertices, sizeof(vertices), GL_DYNAMIC_DRAW);
    EBO ebo(indices, sizeof(indices), GL_DYNAMIC_DRAW);
    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
    vao.LinkAttribute(vbo, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    shader->Activate();
    texture = new Texture(TextureFileName, GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, FlipVertically, 0, 0, 0, 0);
}
void DefaultObject::Update() {
    shader->Activate();
    shader->setFloat("offsetx", offsetX);
    shader->setFloat("offsety", offsetY);
    vao.Bind();
    glActiveTexture(GL_TEXTURE0);
    texture->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void DefaultObject::Delete() {
    texture->Delete();
    delete texture;
    vao.Delete();
    shader->End();
    delete shader;
}

void Level::Init(const char* TextureFileName, bool FlipVertically, int setting) {
    if (setting == 0)
        shader = new Shader("Level.vert", "Level.frag");
    else if (setting == 1) {
        shader = new Shader("Level.vert", "Level1.frag");
    }
    vao.Bind();
    VBO vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);
    EBO ebo(indices, sizeof(indices), GL_STATIC_DRAW);
    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
    vao.LinkAttribute(vbo, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    shader->Activate();
    texture = new Texture(TextureFileName, GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, FlipVertically, 0, 0, 0, 0);
}
void Level::Update() {
    shader->Activate();
    vao.Bind();
    glActiveTexture(GL_TEXTURE0);
    texture->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void Level::Delete() {
    texture->Delete();
    delete texture;
    vao.Delete();
    shader->End();
    delete shader;
}*/