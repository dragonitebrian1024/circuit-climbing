#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
out vec4 ourColor;
out vec4 Position;
out vec2 TexCoord;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    Position = gl_Position;
    ourColor = aColor;
    TexCoord = aTexCoord;
}