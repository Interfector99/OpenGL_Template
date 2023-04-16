#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include<glad/glad.h>
#include<stb/stb_image.h>

#include "Shader.hpp"

namespace Graphics
{
	class Texture
	{
	public:
		GLuint ID;
		GLenum type;

		void init(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
		Texture();
		void setTextureUnit(Shader& shader, const char* uniform, GLuint unit);
		void bind();
		void unbind();
		void destroy();
	};
}

#endif // TEXTURE_HPP