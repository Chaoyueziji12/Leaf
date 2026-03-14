#include "ImGuiTest.h"

int main(int argc, char* argv) {
	LeafImGuiWindow window = Leaf::CreateImGuiWindow("ImGui Test", 800, 600);
	Leaf::RunImGuiWindow(window);
	return 0;
}