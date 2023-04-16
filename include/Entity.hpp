#pragma once
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

#include "stb/stb_image.h"

using namespace std;

class Entity
{
protected:
	// graphics
	Shader shader;
	VAO vao;
	VBO vbo;
	EBO ebo;
	Texture texture;

	// overall scale
	GLuint scaleLoc;
	float scale;

	// position
	GLuint positionLoc;
	glm::vec2 position;
public:
	Entity();
	void initialize(string vert, string frag, string path, float scale);
	void render();
	void destroy();

	void setPosition(glm::vec2 position);
	glm::vec2 getPosition();
};

