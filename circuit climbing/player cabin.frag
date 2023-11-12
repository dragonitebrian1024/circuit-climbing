#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform float TheimageSelected;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
uniform sampler2D texture4;
in vec4 Position;
void main()
{
    if(TheimageSelected == 0.0f)
       FragColor = texture(texture1, TexCoord);
    else if(TheimageSelected == 1.0f)
       FragColor = texture(texture2, TexCoord);
    else if(TheimageSelected == 2.0f)
       FragColor = texture(texture3, TexCoord);
       else if(TheimageSelected == 3.0f)
       FragColor = texture(texture4, TexCoord);
} 