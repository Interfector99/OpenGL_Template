#pragma once
#ifndef VAO_HPP
#define VAO_HPP

// include OpenGL and GLFW modules
#include<glad/glad.h>

// include own modules
#include"VBO.hpp"

class VAO
{
public:
	GLuint ID;

	VAO();
	void init();
	void LinkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};

#endif // VAO_HPP
