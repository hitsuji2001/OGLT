#include "../../header/Handler/KeyHandler.hpp"

namespace oglt {
  KeyHandler::KeyHandler() {
  }

  KeyHandler::~KeyHandler() {
  }

  KeyHandler::KeyHandler(Window *window, Camera *camera) {
    KeyHandler::SetWindow(window);
    KeyHandler::SetCamera(camera);
  }

  void KeyHandler::Handle(float deltaTime) {
    GLFWwindow *window = KeyHandler::GetWindow()->GetOpenGLWindow();
    Camera *camera = KeyHandler::GetCamera();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS or
	glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
      glfwSetWindowShouldClose(KeyHandler::GetWindow()->GetOpenGLWindow(), true);
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera->MoveUp(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera->MoveLeft(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera->MoveDown(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera->MoveRight(deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera->SetSpeed(1.5f);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) camera->SetSpeed(5.0f);
  }
}
