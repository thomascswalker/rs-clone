#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/GLU.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include "shader.h"
#include "camera.h"
#include "filesystem.h"
#include "model.h"

class Game
{


	const unsigned int WIDTH = 1280;
	const unsigned int HEIGHT = 720;
	const float ASPECT = float(WIDTH) / HEIGHT;

	
	float nearClip = 1.0f;
	float farClip = 10000.0f;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	std::vector<Model> models;
	std::vector<Shader> shaders;

public:
	Game();
	~Game();

	bool Init();
	void Loop();
	void Clear();
	bool LoadAssets();

	Camera GetCamera();

	GLFWwindow* window;
	Camera camera;



private:
	void ProcessInput(GLFWwindow* window);
};



#endif