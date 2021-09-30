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

glm::mat4 getMatrix(const glm::vec3& X, const glm::vec3& Y, const glm::vec3& Z, const glm::vec3& T)
{
	return glm::mat4(
		glm::vec4(X, 0.0f),
		glm::vec4(Y, 0.0f),
		glm::vec4(Z, 0.0f),
		glm::vec4(T, 1.0f));
}

glm::vec3 Camera::RotateAround(float yaw) {
	glm::vec4 cp;
	float hoverRadius = 5.0f;
	cp.x = hoverRadius * sin(glm::radians(yaw));
	cp.z = hoverRadius * cos(glm::radians(yaw));

	return glm::vec3(Target.x + cp.x,
					 Target.y + 3.0f,
					 Target.z + cp.z + 20.0f);
}

// https://learnopengl.com/Getting-started/Camera


void Camera::Inputs(GLFWwindow* window)
{
	const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	glm::mat4 view;
	view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		glm::vec3 cameraDirection = glm::normalize(Position - Target);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
		glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);


		Angle -= speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		glm::vec3 offset(0, 3, 20);
		glm::vec3 cp = glm::rotateY(Position, Angle);
		Position = Target + cp + offset;
		Angle += speed;

		printf("Angle: %f\n", float(Angle));
	}
}