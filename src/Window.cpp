#include "Window.hpp"

namespace display
{
	Window::Window()
	{
		std::cout << "Window created" << std::endl;
	}

	void Window::init(std::string name,
					  std::string icon,
					  bool isFullscreen,
					  GLfloat gamespeed)
	{
		glfwInit();
		const GLFWvidmode* monitorMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		this->m_Name =		   name;
		this->m_IsFullscreen = isFullscreen;
		this->m_Width =		   monitorMode->width;
		this->m_Height =	   monitorMode->height;
		this->m_Framerate =    monitorMode->refreshRate;
		this->m_Gamespeed =    gamespeed;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		glfwWindowHint(GLFW_SAMPLES, 16);
		glfwWindowHint(GLFW_REFRESH_RATE, this->m_Framerate);
		//this->p_Window = glfwCreateWindow(this->m_Width, this->m_Height, this->m_Name.c_str(), glfwGetPrimaryMonitor(), NULL);
		this->p_Window = glfwCreateWindow(1280, 720, this->m_Name.c_str(), NULL, NULL);
		if (this->p_Window == NULL)
		{
			throw "WINDOW::INIT -> Failed to initialize GLFW window";
			glfwTerminate();
		}

		// Load the PNG image resource
		HMODULE hModule = GetModuleHandle(NULL);
		HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(ANCESTOR), MAKEINTRESOURCE(PNG));
		HGLOBAL hMemory = LoadResource(hModule, hResource);
		LPVOID pData = LockResource(hMemory);
		DWORD dwSize = SizeofResource(hModule, hResource);

		// set icon
		GLFWimage icons[1];
		icons[0].pixels = stbi_load_from_memory(static_cast<const stbi_uc*>(pData), dwSize, &icons[0].width, &icons[0].height, 0, STBI_rgb_alpha);
		glfwSetWindowIcon(this->p_Window, 1, icons);
		stbi_image_free(icons[0].pixels);

		glfwSetWindowAttrib(this->p_Window, GLFW_RESIZABLE, GL_FALSE);
		glfwSetInputMode(this->p_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwMakeContextCurrent(this->p_Window);
		gladLoadGL();
		std::cout << "Window initialized" << std::endl;


		glEnable(GL_BLEND);
		glEnable(GL_STENCIL_TEST);
		glEnable(GL_MULTISAMPLE);
	}

	void Window::render()
	{
		this->entity.init(ENTITY_VERT, ENTITY_FRAG, ANCESTOR);
		this->entity2.init(ENTITY_VERT, ENTITY_FRAG, ANCESTOR);
		this->entity.translate(glm::vec3(0.0f, 0.0f, 0.0f));
		this->entity2.translate(glm::vec3(0.0f, 0.3f, -1.0f));
		this->m_Camera2D.init(this->m_Width, this->m_Height);

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
				start = std::chrono::high_resolution_clock::now();

				glClearColor(0.0f, 0.0f, 0.15f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

				// physics update
				this->entity.update(deltaTime);
				this->entity2.update(deltaTime);

				glm::mat4 projection = glm::perspective(glm::radians(55.0f), (float)m_Width / (float)m_Height, 0.1f, 100.0f);

				// rendering goes here
				this->entity.render(projection, m_Camera2D.getView());	
				this->entity2.render(projection, m_Camera2D.getView());


				glfwSwapBuffers(this->p_Window);
			}
			glfwPollEvents();
		}
	}

	void Window::destroy()
	{
		glfwDestroyWindow(this->p_Window);
		glfwTerminate();
		this->entity.destroy();
		this->entity2.destroy();
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