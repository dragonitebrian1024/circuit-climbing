#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include "VAO.h"
#include "EBO.h"
#include "Shader.h"
#include"stb/stb_image.h"
#include <iostream>
#include "Texture.h"
#include "Text.h"
#include "Framerate.h"
#include <vector>
#include "Collision.h"
#include "Audio.h"
#include "Physics.h"
#include "Input.h"
#include "EnemyAI.h"
#include <random>
#include <fstream>
#include <memory>
#include "Object.h"
#include "UI.h"
bool leveled = false;
bool rightMouse, leftMouse;
//font:https://fontineed.com/font/Small_Pixel
GLFWwindow* window;
bool rotatedright = false;
bool rotatedup = true;
bool rotateddown = false;
bool rotatedleft = false;
float speedofscroll = -0.001;
bool foundLetterandNewspaper = true;
bool currentlyinconversation[20];
bool shot = 0;
int currentline = 0;

/// <summary>
///do enemy stuff and levels
/// </summary>
struct enemy {

    Shader* shader;
    bool firing, rotatedright, rotatedleft, rotatedup;
    bool rotatedown = true;
    Texture* texture;
    Texture* textureFire;
    float hp;
    bool init = false;
    float offsetX, offsetY;
    AABB Collider = {glm::vec2(0, 0), glm::vec2(0, 0)}, firecollider;
    float vertices[20]{
        //log
        0.0f, 0.0f, 0.0f, 1.0, 1.0,//top right
        0.0f, 0.0f, 0.0f,1.0, 0.0,//bottom right
        0.0f, 0.0f, 0.0f,0.0, 0.0,//bottom left
        0.0f, 0.0f, 0.0f,0.0, 1.0,//top left
    };
    unsigned int indices[6]{
        0, 1, 3,
        1, 2, 3,
    };
    void extendleftside(float howmuch) {
        vertices[10] -= howmuch;
        vertices[15] -= howmuch;
        Collider.min.x -= howmuch;
    }
    void extendrightside(float howmuch) {
        vertices[0] += howmuch;
        vertices[5] += howmuch;
        Collider.max.x += howmuch;
    }
    void extendupside(float howmuch) {
        vertices[6] += howmuch;
        vertices[11] += howmuch;
        Collider.max.y += howmuch;
    }
    void extenddownside(float howmuch) {
        vertices[1] -= howmuch;
        vertices[16] -= howmuch;
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
        Collider.min.x + howmuch;
        Collider.max.x + howmuch;
    }
    //1 for police 2 for black and tans 3 for british army 4 for armoured car
    void Init(VAO vao, int enemysetting) {
        shader = new Shader("third.vert", "third.frag");
        vao.Bind();
        offsetX = 0;
        offsetY = 0;
        VBO vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);
        EBO ebo(indices, sizeof(indices), GL_STATIC_DRAW);
        vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.LinkAttribute(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        if (enemysetting == 1) {
            texture = new Texture("IRA member.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, true, 0, 0, 0, 0);
            textureFire = new Texture("IRA member fire.png", GL_TEXTURE1, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, true, 0, 0, 0, 0);
       }
        theimageselected = 0;
        shader->Activate();
        shader->setInt("texture1", 0);
        shader->setInt("texture2", 1);
        init = true;
    };
    float theimageselected = 0;
    int deathtimer;
    void Update(VAO vao, AABB crosshair) {
        if (CheckAABBCollision(crosshair, Collider) && leftMouse == true) {
            MoveY(10);
            MoveX(2000);
            deathtimer = 30;
        }
        deathtimer -= 1;
        shader->Activate();
        shader->setFloat("offsetx", offsetX);
        shader->setFloat("offsety", offsetY);
        shader->setFloat("TheimageSelected", theimageselected);
        if (Collider.max.x < crosshair.min.x && deathtimer > 0) {
            theimageselected = 1;
            shot = 1;
        }
        MoveX(speedofscroll);
        std::cout << "EnemyMinX:" << Collider.min.x << std::endl;
        std::cout <<offsetX << " " << offsetY << std::endl;
        vao.Bind();
        glActiveTexture(GL_TEXTURE0);
        texture->Bind();
        glActiveTexture(GL_TEXTURE1);
        textureFire->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Delete(VAO vao) {
        texture->Delete();
        delete texture;
        textureFire->Delete();
        delete textureFire;
        vao.Delete();
        shader->End();
        delete shader;
    };
};

float level = 0;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput();
const unsigned int SCR_WIDTH = 1919;
const unsigned int SCR_HEIGHT = 1000;
float speedgainadder = 0;
bool firing;


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int jumptimer, firetimer;
unsigned int indices4[]{

    3, 1, 0,
    3, 2, 1,

    7, 5, 4,
    7, 6, 5,

    12, 13, 15,
    13, 14, 15
};

int seed;
int mode = 0;
float offsetxPlayer, offsetyPlayer, PlayerSprite;
double Mousexpos, Mouseypos;
glm::mat4 Playertrans = glm::mat4(1.0f);
Shader* Player;
AABB playercollider, playerfire;
int main()
{

    std::cout << "Type in a random number:";
   // std::cin >> seed;
    srand(seed);
    sound* candleSound;
    sound* attack_sound;
    candleSound = new sound("candle sound.mp3");
    attack_sound = new sound("attack.wav");
    candleSound->pan = 0.5f;
    candleSound->playspeed = 1.0f;
    candleSound->volume = 1.0f;
    frame_rater<60> fr;
    Audio* audio = new Audio;
    audio->init();
  //  audio->play(candleSound);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "S.A Noire", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction
    Shader Text("Text.vert", "Text.frag");
    Shader LetterandNewspaper("letters and newspapers.vert", "letters and newspaper.frag");
    Shader titlescreenshader("simple picture.vert", "simple picture.frag");
    Shader playerCabinShader("player cabin.vert", "player cabin.frag");
    VAO titlescreenvao,LetterandNewspapervao,Playercabinvao;
    float titlescreenOffsetX = 0, titlescreenOffsetY = 0;
    float screenvertices[20]{
        //log
        1.0f, 1.0f,0.0,1.0, 1.0,//top right
        1.0f, -1.0f, 0.0f,1.0, 0.0,//bottom right
        -1.0f, -1.0f, 0.0f,0.0, 0.0,//bottom left
        -1.0f, 1.0f, 0.0f,0.0, 1.0,//top left
    };
    unsigned int Basicindices[6]{
        0, 1, 3,
        1, 2, 3,
    };
    unsigned int Basicindices1[6]{
        0, 1, 3,
        1, 2, 3,
    };

    float LetterandNewspapervertices[20]{
        
        0.5f, 0.5f,0.0,1.0, 1.0,//top right
        0.5f, -0.5f, 0.0f,1.0, 0.0,//bottom right
        -0.5f, -0.5f, 0.0f,0.0, 0.0,//bottom left
        -0.5f, 0.5f, 0.0f,0.0, 1.0,//top left
    };
    titlescreenvao.Bind();
    VBO vbotitlescreen(screenvertices, sizeof(screenvertices), GL_STATIC_DRAW);
    EBO ebotitlescreen(Basicindices, sizeof(Basicindices), GL_STATIC_DRAW);
    titlescreenvao.LinkAttribute(vbotitlescreen, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    titlescreenvao.LinkAttribute(vbotitlescreen, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    Texture titlescreenTexture("S.A Noire title screen.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, true, 0, 0, 0, 0);

    LetterandNewspapervao.Bind();
    VBO vboLetterandNewspaper(LetterandNewspapervertices, sizeof(LetterandNewspapervertices), GL_STATIC_DRAW);
    EBO eboLetterandNewspaper(Basicindices, sizeof(Basicindices1), GL_STATIC_DRAW);
    LetterandNewspapervao.LinkAttribute(vboLetterandNewspaper, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    LetterandNewspapervao.LinkAttribute(vboLetterandNewspaper, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    Texture LetterandNewspaperTexture1("god awful letter One.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, true, 0, 0, 0, 0);
    LetterandNewspaper.Activate();
    LetterandNewspaper.setInt("texture1", 0);

    Playercabinvao.Bind();
    VBO Playercabintitlescreenvbo(screenvertices, sizeof(screenvertices), GL_STATIC_DRAW);
    EBO Playercabintitlescreenebo(Basicindices, sizeof(Basicindices), GL_STATIC_DRAW);
    Playercabinvao.LinkAttribute(Playercabintitlescreenvbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    Playercabinvao.LinkAttribute(Playercabintitlescreenvbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    Texture PlayercabinTexture("player house 1.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, true, 0, 0, 0, 0);

    VAO Textvao;
    TextInit("small_pixel.ttf", SCR_WIDTH, SCR_HEIGHT,25, 25, Text);

   /* shader4.Activate();
    Texture texture5("pencil boy.png", GL_TEXTURE0, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
    Texture texture6("eraser girl.png", GL_TEXTURE1, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
    Texture texture8("Paper.png", GL_TEXTURE3, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST, false, 0, 0, 0, 0);
    shader4.setInt("texture1", 0);
    shader4.setInt("texture2", 1);
    shader4.setInt("texture4", 3);*/
    while (!glfwWindowShouldClose(window))
    {
        glfwGetCursorPos(window, &Mousexpos, &Mouseypos);
        //std::cout << Mousexpos << " " << Mouseypos << std::endl;
        if (mode <= 1) 
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        else 
            glClearColor(0.0f, 0.3f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        processInput();
        glfwSetKeyCallback(window, key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        if (mode == 0) {
            //RenderText("Irish war of independence", 600, 750, 2.2, glm::vec3(0, 0, 0), Text, Textvao);
            if (leveled == false) {
                audio->loop(candleSound, -1);
                audio->play(candleSound);
            }
            leveled = true;
            titlescreenshader.Activate();
            titlescreenvao.Bind();
            glActiveTexture(GL_TEXTURE0);
            titlescreenTexture.Bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            std::cout << "MousexPos:" << Mousexpos << " MouseyPos:" << Mouseypos << std::endl;
            if (Mousexpos >= (-0.35 + titlescreenOffsetX + 1.35) * 959.5 && Mousexpos <= (0.35 + titlescreenOffsetX + 0.7) * 959.5 && Mouseypos >= (-0.9 + 1.35) * 499 && Mouseypos <= (0.35 + 1.35) * 499)//make sure if the numbers end up negative it *negative numbr but positive it just * positive number
                std::cout << "gigga";
        }
        if (mode == 1) {
            if (leveled == true)
                audio->stop(candleSound);
            leveled = false;
            if(foundLetterandNewspaper == true) {
                RenderText("Press space to continue", 600, 150, 2.2, glm::vec3(0, 0, 0), Text, Textvao);
                LetterandNewspaper.Activate();
                LetterandNewspapervao.Bind();
                glActiveTexture(GL_TEXTURE0);
                LetterandNewspaperTexture1.Bind();
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            }
            currentlyinconversation[0] = true;
            if (currentlyinconversation[0] == true) {
                if (currentline == 0) {

                }
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
        fr.sleep();
    }


    glfwTerminate();
    delete candleSound;
    delete attack_sound;
    delete audio;
    Text.End();
    return 0;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    key_update(window, key, scancode, action, mods);
    if (TheKeys.at(key_enter) && mode == 0) {
        mode = 1;
        leveled = true;
    }
    if (TheKeys.at(key_space) && mode == 1 && foundLetterandNewspaper == true) {
        foundLetterandNewspaper = false;
        leveled = true;
    }
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        rightMouse = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        rightMouse = false;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        leftMouse = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        leftMouse = false;
    }
}


void processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window,int width, int height)
{
    glViewport(0, 0, width, height);
}
