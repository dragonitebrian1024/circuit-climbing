#version 330 core
out vec4 FragColor;
in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float TheimageSelected;

in vec4 Position;
void main()
{
    if(TheimageSelected == 0.0f)
       FragColor = texture(texture1, TexCoord);
    else if(TheimageSelected == 1.0f)
       FragColor = texture(texture2, TexCoord);
} 