#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

// C++ modules
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

// OpenGL modules
#include <GLFW/glfw3.h>

// own modules
#include "Texture.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

class Entity
{
protected:
	// window
	GLuint	m_Width;
	GLuint	m_Height;
	GLfloat	m_Gamespeed;

	// graphics
	Graphics::Shader  m_Shader;
	Graphics::VAO	  m_Vao;
	Graphics::VBO	  m_Vbo;
	Graphics::EBO	  m_Ebo;
	Graphics::Texture m_Texture;

	// data
	glm::vec3 m_Position;
	glm::vec3 m_Scale;
	glm::vec3 m_Rotation;

	// shader uniforms
	glm::mat4x4 m_Transform;
public:
	Entity();
	// receive the window object
	void initialize(int vertexPath, int fragmentPath, int texturePath);
	void render();
	void update(float deltaTime);
	void destroy();
};

#endif // ENTITY_HPP