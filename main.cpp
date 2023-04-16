#include "Window.hpp"

int main()
{
	display::Window window = display::Window();
	try
	{
		window.init("Template", false, 800, 800, 60);
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