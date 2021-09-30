#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderclass.h"

class Camera
{
public:
	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	// Updates and exports the camera matrix to the Vertex Shader
	void Matrix(Shader& shader, const char* uniform);
	void UpdateMatrix(glm::mat4 view, float FOVdeg, float nearPlane, float farPlane);
	glm::mat4 GetMatrix();

	// Handles camera inputs
	void Inputs(GLFWwindow* window);

	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 CameraMatrix = glm::mat4(1.0f);

	// Target position
	int Distance = 5;
	float fov = 50.0f;
	float nearClip = 1.0f;
	float farClip = 1000.0f;
	float Angle = 0.0f;
	glm::vec3 Target = glm::vec3(0.0f, 0.0f, 0.0f);

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 1.0f;
};
#endif