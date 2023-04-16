#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

// include C++ modules
#include <iostream>
#include <chrono>

// include OpenGL and GLFW modules
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// include external modules
#include <stb/stb_image.h>

// include own modules
#include "Entity.hpp"

namespace display
{
	class Window
	{
	private:
		// window settings
		std::string m_Name;
		bool		m_IsFullscreen;
		GLuint		m_Width;
		GLuint		m_Height;
		GLuint		m_Framerate;


		GLFWwindow* p_Window;

		Entity entity;

	public:
		Window();
		void init(std::string, bool, GLuint, GLuint, GLuint);
		void render();
		void destroy();

		void processInput();
	};
}

#endif // WINDOW_HPP

