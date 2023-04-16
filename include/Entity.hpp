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

// own modules
#include "Texture.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

class Entity
{
protected:
	// graphics
	Graphics::Shader shader;
	Graphics::VAO vao;
	Graphics::VBO vbo;
	Graphics::EBO ebo;
	Graphics::Texture texture;

	// shader variables
	GLuint transformLoc;
	glm::mat4x4 transform;
public:
	Entity();
	void initialize(std::string vert, std::string frag, std::string path);
	void render();
	void destroy();
};

#endif // ENTITY_HPP