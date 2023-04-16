#pragma once
#ifndef EBO_HPP
#define EBO_HPP

#include<glad/glad.h>

namespace Graphics
{
	class EBO
	{
	public:
		GLuint ID;

		EBO();
		void init(GLuint* indices, GLsizeiptr size);
		void bind();
		void unbind();
		void destroy();
	};
}

#endif // EBO_HPP

