#include "camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Makes camera look in the right direction from the right position
	// https://stackoverflow.com/questions/51921702/how-do-i-rotate-my-camera-around-my-object

	view = glm::lookAt(Position, Target, Up);
	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Exports the camera matrix to the Vertex Shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		//https://gamedev.stackexchange.com/questions/20758/how-can-i-orbit-a-camera-about-its-target-point
		float x = Distance * -sinf(glm::radians(Angle) * cosf(glm::radians(Angle)));
		//float x = Distance * cos(Angle);
		//float z = Distance * sin(Angle);

		//Position.x = x;
		//Position.z = z;

		//Angle -= .01f;
		//printf("X: %f, Y: %f\n", x, z);
		//printf("Angle: %f\n", float(Angle));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		float x = Distance * cos(Angle);
		float z = Distance * sin(Angle);

		Position.x = x;
		Position.z = z;

		Angle += .01f;
		printf("X: %f, Y: %f\n", x, z);
		printf("Angle: %f\n", float(Angle));
	}
}