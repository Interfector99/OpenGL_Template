#include "Camera2D.hpp"

Camera2D::Camera2D()
{

}

void Camera2D::init(int screenWidth, int screenHeight)
{
	m_Position = glm::vec3(0.0f, 0.0f, -1.0f);
}

void Camera2D::update()
{

}

glm::mat4 Camera2D::getView()
{
	return glm::translate(glm::mat4(1.0f), m_Position);
}