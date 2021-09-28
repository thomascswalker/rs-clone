#include <iostream>
#include <string>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "shaderclass.h"
#include "vao.h"
#include "vbo.h"
#include "ebo.h"

// Vertices coordinates
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we're using
	// Currently using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// This means we'll only use the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Initial window size
	auto title = "RS Clone";
	int sizeX = 1280;
	int sizeY = 720;

	// Create a new window object
	GLFWwindow* window = glfwCreateWindow(sizeX, sizeY, title, NULL, NULL);

	// If the window can't be created
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;

		// Terminate GLFW
		glfwTerminate();
		return -1;
	}


	// Set the current GLFW context to the main window
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL(glfwGetProcAddress);

	// Create the viewport
	glViewport(0, 0, sizeX, sizeY);

	///////// Draw stuff

	Shader shaderProgram("default.vert", "default.frag");
	VAO vao;
	vao.Bind();
	VBO vbo(vertices, sizeof(vertices));
	EBO ebo(indices, sizeof(indices));

	vao.LinkVBO(vbo, 0);
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();

	// Run the main window loop
	while (!glfwWindowShouldClose(window))
	{
		// Handle all GLFW events
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		vao.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	shaderProgram.Delete();

	// Delete the window instance
	glfwDestroyWindow(window);

	// Terminate GLFW
	glfwTerminate();

	// Exit
	return 0;
}
