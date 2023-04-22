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
		GLfloat		m_Gamespeed;

		GLFWwindow* p_Window;
		Graphics::Texture m_Icon;

		Entity entity;

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

