#pragma once
#ifndef VAO_HPP
#define VAO_HPP

#include<glad/glad.h>

#include"VBO.hpp"

namespace Graphics
{
	class VAO
	{
	public:
		GLuint ID;

		VAO();
		void init();
		void linkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
		void bind();
		void unbind();
		void destroy();
	};
}

#endif // VAO_HPP
