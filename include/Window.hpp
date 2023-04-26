#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Entity.hpp"
#include "Camera2D.hpp"

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
		GLfloat		m_Gamespeed;

		GLFWwindow* p_Window;

		Camera2D m_Camera2D;

		Entity entity;
		Entity entity2;

	public:
		Window();
		void init(std::string name,
				  std::string icon,
				  bool isFullscreen, 
				  GLfloat gamespeed);
		void render();
		void destroy();

		void processInput();
	};
}

#endif // WINDOW_HPP

