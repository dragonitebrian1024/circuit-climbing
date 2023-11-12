#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
out vec4 ourColor;
uniform float offsetx;
uniform float offsety;
void main()
{
    gl_Position = vec4(aPos.x + offsetx, offsety + aPos.y, aPos.z, 1.0);
    ourColor = aColor;
}