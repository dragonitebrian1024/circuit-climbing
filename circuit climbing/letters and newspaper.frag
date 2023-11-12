#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
uniform sampler2D texture4;
uniform sampler2D texture5;
uniform sampler2D texture6;
uniform sampler2D texture7;
uniform sampler2D texture8;
uniform sampler2D texture9;
uniform sampler2D texture10;
uniform sampler2D texture11;
uniform sampler2D texture12;
uniform sampler2D texture13;
uniform sampler2D texture14;
uniform sampler2D texture15;
uniform sampler2D texture16;
uniform sampler2D texture17;
uniform sampler2D texture18;
uniform sampler2D texture19;
uniform sampler2D texture20;
uniform sampler2D texture21;
uniform sampler2D texture22;
uniform sampler2D texture23;
uniform sampler2D texture24;
uniform sampler2D texture25;
uniform sampler2D texture26;
uniform sampler2D texture27;
uniform sampler2D texture28;
uniform sampler2D texture29;
uniform sampler2D texture30;

uniform float TheimageSelected;

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
    else if(TheimageSelected == 4.0f)
       FragColor = texture(texture5, TexCoord);
    else if(TheimageSelected == 5.0f)
       FragColor = texture(texture6, TexCoord);
    else if(TheimageSelected == 6.0f)
       FragColor = texture(texture7, TexCoord);
    else if(TheimageSelected == 7.0f)
       FragColor = texture(texture8, TexCoord);
    else if(TheimageSelected == 8.0f)
       FragColor = texture(texture9, TexCoord);
    else if(TheimageSelected == 9.0f)
       FragColor = texture(texture10, TexCoord);
    else if(TheimageSelected == 10.0f)
       FragColor = texture(texture11, TexCoord);
    else if(TheimageSelected == 11.0f)
       FragColor = texture(texture12, TexCoord);
    else if(TheimageSelected == 12.0f)
       FragColor = texture(texture13, TexCoord);
    else if(TheimageSelected == 13.0f)
       FragColor = texture(texture14, TexCoord);
    else if(TheimageSelected == 14.0f)
       FragColor = texture(texture15, TexCoord);
    else if(TheimageSelected == 15.0f)
       FragColor = texture(texture16, TexCoord);
    else if(TheimageSelected == 16.0f)
       FragColor = texture(texture17, TexCoord);
    else if(TheimageSelected == 17.0f)
       FragColor = texture(texture18, TexCoord);
    else if(TheimageSelected == 18.0f)
       FragColor = texture(texture19, TexCoord);
    else if(TheimageSelected == 19.0f)
       FragColor = texture(texture20, TexCoord);
    else if(TheimageSelected == 20.0f)
       FragColor = texture(texture21, TexCoord);
    else if(TheimageSelected == 21.0f)
       FragColor = texture(texture22, TexCoord);
    else if(TheimageSelected == 22.0f)
       FragColor = texture(texture23, TexCoord);
    else if(TheimageSelected == 23.0f)
       FragColor = texture(texture24, TexCoord);
    else if(TheimageSelected == 24.0f)
       FragColor = texture(texture25, TexCoord);
    else if(TheimageSelected == 25.0f)
       FragColor = texture(texture26, TexCoord);
    else if(TheimageSelected == 26.0f)
       FragColor = texture(texture27, TexCoord);
    else if(TheimageSelected == 27.0f)
       FragColor = texture(texture28, TexCoord);
    else if(TheimageSelected == 28.0f)
       FragColor = texture(texture29, TexCoord);
    else if(TheimageSelected == 29.0f)
       FragColor = texture(texture30, TexCoord);
} 