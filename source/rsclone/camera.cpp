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
	float camX = sin(glm::radians(hAngle)) * distance;
	float camY = cosf(glm::radians(vAngle)) * distance;
	float camZ = cos(glm::radians(hAngle)) * distance;
	return glm::lookAt(glm::vec3(camX, camY, camZ),
					   glm::vec3(0.0, 0.0, 0.0),
					   glm::vec3(0.0, 1.0, 0.0));
}

void Camera::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		vAngle += speed;
		if (abs(vAngle) >= 180.0f)
		{
			vAngle = 180.0f;
		}
		printf("Angle: %f\n", vAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		hAngle -= speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
		printf("Angle: %f\n", hAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		vAngle -= speed;
		if (abs(vAngle) <= 0.0f)
		{
			vAngle = 0.0f;
		}
		printf("Angle: %f\n", vAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		hAngle += speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
		printf("Angle: %f\n", hAngle);
	}
}