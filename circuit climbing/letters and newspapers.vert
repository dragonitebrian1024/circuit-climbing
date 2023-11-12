#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec4 Position;
out vec2 TexCoord;
uniform float offsetx;
uniform float offsety;
void main()
{
    gl_Position = vec4(aPos.x + offsetx, offsety + aPos.y, aPos.z, 1.0);
    Position = gl_Position;
    TexCoord = aTexCoord;
}