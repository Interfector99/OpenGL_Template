#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

// C++ modules
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

// OpenGL modules
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Graphics modules
#include "Texture.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

class Entity
{
protected:
	// graphics
	Graphics::Shader m_Shader;
	Graphics::VAO m_Vao;
	Graphics::VBO m_Vbo;
	Graphics::EBO m_Ebo;
	Graphics::Texture m_Texture;

	// data
	glm::vec3 m_Position;
	glm::vec3 m_Scale;
	glm::vec3 m_Rotation;

	// shader variables
	/// TODO
	GLuint m_TransformReference;
	glm::mat4x4 m_Transform;
public:
	Entity();
	void initialize(std::string vertexPath, std::string fragmentPath, std::string texturePath);
	void render();
	void destroy();
};

#endif // ENTITY_HPP