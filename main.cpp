#include "Window.hpp"


int main()
{
	display::Window window = display::Window();
	try
	{
		window.init("Template", "resources/textures/icon.png", false, 1.0f);
		window.render();
		window.destroy();
	}
	catch (const char* e)
	{
		std::cerr << e << std::endl;
		window.destroy();
	}
	
	return 0;
}