#include "Window.h"

int main(int argc, char* argv[]) {
	LeafWindow window = Leaf::CreateWindow("Leaf Window", 800, 600, LF_WINDOWPOS_CENTERED, LF_WINDOWPOS_CENTERED);
	Leaf::RunWindow(window);
	return 0;
}