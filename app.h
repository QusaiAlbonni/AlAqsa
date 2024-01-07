#include "PreRender.h"
#include "GameLoop.h"


class app {
public:
	static void run() {
		GLFWwindow* window = setupWindow();
		if (window == NULL)
		{
			return;
		}
		if (!setupOpengl())
			return;
		setup_ImGUI(window);
		startGame(window);
		shutdown_ImGui();
		glfwTerminate();
		return;
	}
};