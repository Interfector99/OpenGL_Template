#pragma once
#ifndef CAMERA2D_HPP
#define CAMERA2D_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera2D
{
private:
	glm::vec3 m_Position;
public:
	Camera2D();
	void init(int screenWidth, int screenHeight);
	void update();
	glm::mat4 getView();
};

#endif // CAMERA2D_HPP