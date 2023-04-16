#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Entity.hpp"

namespace display
{
	class Window
	{
	private:
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

