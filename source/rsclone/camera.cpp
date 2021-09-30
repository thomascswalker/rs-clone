#include "camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;

	glm::mat4 view = GetMatrix();
	UpdateMatrix(view, fov, nearClip, farClip);
}

void Camera::UpdateMatrix(glm::mat4 view, float FOVdeg, float nearPlane, float farPlane)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 projection = glm::mat4(1.0f);

	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Sets new camera matrix
	CameraMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	// Exports camera matrix
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(CameraMatrix));
}

glm::mat4 Camera::GetMatrix() {
	// https://learnopengl.com/Getting-started/Camera
	float camX = sin(glm::radians(Angle)) * Distance;
	float camZ = cos(glm::radians(Angle)) * Distance;
	return glm::lookAt(glm::vec3(camX, 0.0, camZ),
					   glm::vec3(0.0, 0.0, 0.0),
					   glm::vec3(0.0, 1.0, 0.0));
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
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		Angle -= speed;
		if (abs(Angle) >= 360.0f)
		{
			Angle = 0.0f;
		}
		printf("Angle: %f\n", Angle);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		Angle += speed;
		if (abs(Angle) >= 360.0f)
		{
			Angle = 0.0f;
		}
		printf("Angle: %f\n", Angle);
	}
}