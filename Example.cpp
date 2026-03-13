#include "Leaf.h"

int main(int argc, char* argv[]) {
	LeafWindow window = Leaf::CreateWindow("Leaf Window", 
		800, 600, 
		LF_WINDOWPOS_CENTERED, LF_WINDOWPOS_CENTERED,
		10, 255, 255, 255
		);
	Leaf::CreateRectangle(20, 20, 50, 50, 0, 255, 0, 255, window);
	Leaf::RunWindow(window);
	return 0;
}