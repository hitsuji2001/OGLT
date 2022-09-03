#include "../../header/Handler/KeyHandler.hpp"

namespace oglt {
  KeyHandler::KeyHandler() {
  }

  KeyHandler::~KeyHandler() {
  }

  KeyHandler::KeyHandler(std::shared_ptr<Window> window, std::shared_ptr<Camera> camera) {
    KeyHandler::SetWindow(window);
    KeyHandler::SetCamera(camera);
  }

  void KeyHandler::Handle(float deltaTime) {
    GLFWwindow *window = KeyHandler::GetWindow()->GetOpenGLWindow();
    std::shared_ptr<Camera> camera = KeyHandler::GetCamera();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS or
	glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
      glfwSetWindowShouldClose(KeyHandler::GetWindow()->GetOpenGLWindow(), true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera->MoveUp(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera->MoveLeft(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera->MoveDown(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera->MoveRight(deltaTime);
  }
}
