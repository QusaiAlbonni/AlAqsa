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
		startGame(window);
		glfwTerminate();
		return;
	}
};