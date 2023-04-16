#pragma once
#ifndef VBO_HPP
#define VBO_HPP

#include<glad/glad.h>

namespace Graphics
{
	class VBO
	{
	public:
		GLuint ID;

		VBO();
		void init(GLfloat* vertices, GLsizeiptr size);
		void bind();
		void unbind();
		void destroy();
	};
}

#endif // VBO_HPP