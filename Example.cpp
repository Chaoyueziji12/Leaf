#include "Window.h"

int main(int argc, char* argv[]) {
	LeafWindow* window = new LeafWindow();
	window->title = "Leaf Window";
	window->width = 800;
	window->height = 600;
	window->x = LF_WINDOWPOS_CENTERED;
	window->y = LF_WINDOWPOS_CENTERED;
	window->bgR = 255;
	window->bgG = 255;
	window->bgB = 255;
	window->Initialize();
	window->Run();
	delete window;
	return 0;
}