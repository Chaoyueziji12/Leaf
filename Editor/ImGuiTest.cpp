#include "ImGuiTest.h"

int main() {
	LeafImGuiWindow window = Leaf::CreateImGuiWindow("ImGui Test", 800, 600);
	Leaf::RunImGuiWindow(window);
}