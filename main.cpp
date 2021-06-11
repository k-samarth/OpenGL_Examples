#include<iostream>
#include<GLFW/glfw3.h>

int main() {
	GLFWwindow* window;

	if (!glfwInit()) {
		std::cout << "Init error";
		return -1;
	}
	window = glfwCreateWindow(800, 800, "Hello", 0, 0);
	if (!window) {
		std::cout << "Window creation error";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {

		glClearColor(1.0, 0.0, 0.0, 0.0);

		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();
}