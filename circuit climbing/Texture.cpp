#include"Texture.h"
#include <GLFW/glfw3.h>

Texture::Texture(const char* image, GLenum slot, GLenum format, GLint horizontaldrawmode, GLint verticaldrawmode, GLint minFilterDrawAlgo, GLint magFilterDrawAlgo, bool VerticalFlip, float borderR, float borderG, float borderB, float borderA)
{
	// Assigns the type of the texture ot the texture object
	type = GL_TEXTURE_2D;

	// Stores the width, height, and the number of color channels of the image
	int widthImg, heightImg, numColCh;
	// Flips the image so it appears right side up
	stbi_set_flip_vertically_on_load(VerticalFlip);
	// Reads the image from a file and stores it in bytes

	// Generates an OpenGL texture object
	glGenTextures(1, &ID);
	// Assigns the texture to a Texture Unit
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, ID);

	// Configures the way the texture repeats (if it does at all)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, horizontaldrawmode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, verticaldrawmode);
	// Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilterDrawAlgo);//GL_NEAREST_MIPMAP_LINEAR
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilterDrawAlgo);//GL-NEAREST

	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
	if (horizontaldrawmode == GL_CLAMP_TO_BORDER || verticaldrawmode == GL_CLAMP_TO_BORDER) {
		float flatColor[] = { borderR, borderG, borderB, borderA };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);
	}

	if (bytes)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, widthImg, heightImg, 0, format, GL_UNSIGNED_BYTE, bytes);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "Loaded texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}