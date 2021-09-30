#include "camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;

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

	return glm::lookAt(cameraPos, target, up);
}

void Camera::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		vAngle -= speed;
		if (vAngle <= 90.0f)
		{
			vAngle = 90.0f;
		}
		printf("V: %f, H: %f\n", vAngle, hAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		hAngle += speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
		printf("V: %f, H: %f\n", vAngle, hAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		vAngle += speed;
		if (vAngle >= 180.0f)
		{
			vAngle = 180.0f;
		}
		printf("V: %f, H: %f\n", vAngle, hAngle);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		glm::mat4 view = GetMatrix();
		UpdateMatrix(view, fov, nearClip, farClip);
		hAngle -= speed;
		if (abs(hAngle) >= 360.0f)
		{
			hAngle = 0.0f;
		}
		printf("V: %f, H: %f\n", vAngle, hAngle);
	}
}