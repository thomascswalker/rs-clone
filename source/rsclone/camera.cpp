#include "camera.h"

Camera::Camera(int width, int height)
{
	Camera::width = width;
	Camera::height = height;

	glm::mat4 view = GetMatrix();
	UpdateMatrix(view);
}

void Camera::UpdateMatrix(glm::mat4 view)
{
	ProcessMouseScroll(0);

	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 projection = glm::mat4(1.0f);

	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(fov), (float)width / height, nearClip, farClip);

	// Sets new camera matrix
	cameraMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	

	// Exports camera matrix
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

glm::mat4 Camera::GetMatrix() {
	// https://learnopengl.com/Getting-started/Camera
	// http://disq.us/p/2cdpy9j

	glm::vec3 cameraRight = glm::vec3(1.0f);
	glm::vec3 radial = glm::vec3(1.0f);

	float v = glm::radians(vAngle);
	float h = glm::radians(hAngle);

	radial.x = distance * cos(h);
	radial.y = distance * sin(v);
	radial.z = distance * sin(h);

	glm::vec3 cameraPos = glm::vec3(target.x + radial.x, radial.y, target.z + radial.z);

	cameraRight = glm::normalize(glm::cross(up, cameraPos - target));
	translation = cameraPos;

	return glm::lookAt(cameraPos, target, up);
}

void Camera::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view);
		vAngle -= speed;
		if (vAngle <= 90.0f)
		{
			vAngle = 90.0f;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view);
		hAngle += speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view);
		vAngle += speed;
		if (vAngle >= 180.0f)
		{
			vAngle = 180.0f;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view);
		hAngle -= speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
	}
}

void Camera::ProcessMouseScroll(double delta)
{
	distance -= (float)delta;
	if (distance < 1.0f)
		distance = 1.0f;
	if (distance > 500.0f)
		distance = 500.0f;
}