#include<iostream>
#include<GLFW/glfw3.h>
#include<math.h>

const int steps = 100;

void  drawCircle(float red, float green, float blue) {
	float radius = 1.;
	const float angle = 3.1415926 * 2 / steps;
	float oldX = 0;
	float oldY = 1;
	for (int i = 0; i <= steps; i++)
	{
		float newX = radius * sin(angle * i);
		float newY = -radius * cos(angle * i);

		glColor3f(red, green, blue);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(oldX, oldY, 0.0f);
		glVertex3f(newX, newY, 0.0f);
		glEnd();

		oldX = newX;
		oldY = newY;
	}
}

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

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(0.1, 0.1, 1);

	float angle = 0;
	float Moonangle = 0;
	while (!glfwWindowShouldClose(window)) {
		angle += .1;
		Moonangle += 1;
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//sun
		drawCircle(1, 1, 0);

		{
			glPushMatrix();
			glRotatef(angle, 0, 0, 1);
			glTranslatef(0, 5, 0);
			glScalef(0.6, 0.6, 1);
			drawCircle(0, 0.3, 1);
			{
				glPushMatrix();
				glRotatef(Moonangle, 0, 0, 1);
				glTranslatef(0, 3, 0);
				glScalef(0.5, 0.5, 1);
				drawCircle(0.5, 0.5, 0.5);
				glPopMatrix();
			}
			glPopMatrix();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}
