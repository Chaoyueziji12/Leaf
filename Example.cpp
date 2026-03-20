#include "Window.h"
#include "Rectangle.h"

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
	LeafRect* rect = new LeafRect();
	rect->width = 20;
	rect->height = 20;
	rect->x = 50;
	rect->y = 50;
	rect->window = window->window;
	rect->Draw();
	window->Run();
	delete rect;
	delete window;
	return 0;
}