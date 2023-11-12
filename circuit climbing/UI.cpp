#include "UI.h"

void button::Init(const char* TextureFileName, bool FlipVertically, int setting) {
    if(setting == 0)
        shader = new Shader("Level.vert", "Level.frag");
    else if(setting == 1)
        shader = new Shader("Level.vert", "Level1.frag");
    vao.Bind();
    VBO vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);
    EBO ebo(indices, sizeof(indices), GL_STATIC_DRAW);
    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
    vao.LinkAttribute(vbo, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    shader->Activate();
    if(TextureFileName != NULL)
       texture = new Texture(TextureFileName, GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, FlipVertically, 0, 0, 0, 0);
}
void button::Update() {
    shader->Activate();
    vao.Bind();
    if (texture != nullptr) {
        glActiveTexture(GL_TEXTURE0);
        texture->Bind();
    }
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void button::Delete() {
    texture->Delete();
    delete texture;
    vao.Delete();
    shader->End();
    delete shader;
}
bool button::IsTouched(double MouseXPos, double MouseYPos) {
    if (MouseXPos >= x && MouseXPos <= x + w && MouseYPos >= y && MouseYPos <= y + h)
        return true;
    else
        return false;
}