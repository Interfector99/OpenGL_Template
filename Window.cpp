#include "Window.hpp"

namespace display
{
	Window::Window()
	{
		std::cout << "Window created" << std::endl;
	}

	void Window::init(std::string m_Name,
					  bool m_IsFullscreen,
					  GLuint m_Width,
					  GLuint m_Height,
					  GLuint m_Framerate)
	{
		this->m_Name =		   m_Name;
		this->m_IsFullscreen = m_IsFullscreen;
		this->m_Width =		   m_Width;
		this->m_Height =	   m_Height;
		this->m_Framerate =	   m_Framerate;

		glfwInit();
		this->p_Window = glfwCreateWindow(this->m_Width, this->m_Height, this->m_Name.c_str(), NULL, NULL);
		if (this->p_Window == NULL)
		{
			throw "Failed to initialize GLFW window";
			glfwTerminate();
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwMakeContextCurrent(this->p_Window);
		gladLoadGL();
		std::cout << "Window initialized" << std::endl;
	}

	void Window::render()
	{
		auto start = std::chrono::high_resolution_clock::now();
		while (!glfwWindowShouldClose(this->p_Window))
		{
			this->processInput();

			// update rendering according to the framerate
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			if (duration.count() >= (1.0f / this->m_Framerate) * 1000.0f)
			{
				auto deltaTime = duration.count() / 1000.0f;
				std::cout << deltaTime << std::endl;
				start = std::chrono::high_resolution_clock::now();

				glClearColor(0.4f, 0.2f, 0.8f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				// rendering goes here

				glfwSwapBuffers(this->p_Window);
			}
			glfwPollEvents();
		}
	}

	void Window::destroy()
	{
		glfwDestroyWindow(this->p_Window);
		glfwTerminate();
		std::cout << "Window destroyed" << std::endl;
	}

	void Window::processInput()
	{
		// esc means quit
		if (glfwGetKey(this->p_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(this->p_Window, true);
		}
	}
}