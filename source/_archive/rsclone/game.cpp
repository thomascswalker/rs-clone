#include "game.h"

Game::Game()
{

}

Game::~Game()
{
}

bool Game::Init()
{
	camera = Camera(glm::vec3(0.0f, 50.0f, 3.0f));

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	window = glfwCreateWindow(WIDTH, HEIGHT, "RS Clone", NULL, NULL);

	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	//glfwSetScrollCallback(window, ScrollCallback);
	//glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
	//glfwSetCursorPosCallback(window, MouseCallback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	//Load GLAD so it configures OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_MODELVIEW);

	return true;
}

void Game::Loop()
{
	while (!glfwWindowShouldClose(window))
	{
		// Per-frame logic
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Camera input
		ProcessInput(window);

		//glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
		glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)

		glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw our model
		// view/projection transformations
		shaders[0].use();
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, nearClip, farClip);
		glm::mat4 view = camera.GetViewMatrix();
		shaders[0].setMat4("projection", projection);
		shaders[0].setMat4("view", view);

		// render the loaded model
		glm::mat4 temp = glm::mat4(1.0f);
		shaders[0].setMat4("model", temp);

		// Draw all the models which were loaded
		for (unsigned int i = 0; i < models.size(); i++)
		{
			models[i].Draw(shaders[0]);
		}

		// Swap the back buffer with the front buffer
		// Take care of all GLFW events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Game::Clear()
{
	// Delete window before ending the program
	glfwDestroyWindow(window);

	// Terminate GLFW before ending the program
	glfwTerminate();
}

bool Game::LoadAssets()
{
	// Load in a model
	Model model(FileSystem::getPath("../assets/prod/scene.fbx"));
	Model player(FileSystem::getPath("../assets/prod/playercharacter.fbx"));

	models.push_back(model);
	models.push_back(player);

	// Generates Shader object using shaders default.vert and default.frag
	Shader defaultShader("default.vert", "default.frag");
	defaultShader.use();

	shaders.push_back(defaultShader);

	return true;
}

Camera Game::GetCamera()
{
	return camera;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Game::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

