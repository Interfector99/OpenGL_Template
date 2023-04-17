#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

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
		void bind();
		void unbind();
		void destroy();
	};
}

#endif // TEXTURE_HPP