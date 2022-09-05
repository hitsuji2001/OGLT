#include "../../header/Handler/KeyHandler.hpp"

namespace oglt {
  KeyHandler::KeyHandler() {
  }

  KeyHandler::~KeyHandler() {
  }

  KeyHandler::KeyHandler(std::shared_ptr<Window>& window, std::shared_ptr<Camera>& camera, const CameraType& type) {
    KeyHandler::SetWindow(window);
    KeyHandler::SetCamera(camera);
    KeyHandler::SetCameraType(type);
  }

  KeyHandler::KeyHandler(std::shared_ptr<Window>& window, std::shared_ptr<Camera>& camera) {
    KeyHandler::SetWindow(window);
    KeyHandler::SetCamera(camera);
  }

  void KeyHandler::HandlePerspecCamera(float deltatime) {
    GLFWwindow *window = KeyHandler::GetWindow()->GetOpenGLWindow();
    std::shared_ptr<Camera> camera = KeyHandler::GetCamera();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS or
	glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
      glfwSetWindowShouldClose(KeyHandler::GetWindow()->GetOpenGLWindow(), true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera->MoveUp(deltatime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera->MoveLeft(deltatime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera->MoveDown(deltatime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera->MoveRight(deltatime);
  }

  void KeyHandler::HandleOrthoCamera(float deltatime) {
    (void) deltatime;
    assert(0 and "`HandleOrthoCamera` is not implemented yet.\n");
  }

  void KeyHandler::Handle(float deltaTime) {
    switch (this->GetCameraType()) {
    case CameraType::PerspecCamera:
      this->HandlePerspecCamera(deltaTime);
      break;
    case CameraType::OrthoCamera:
      this->HandleOrthoCamera(deltaTime);
      break;
    case CameraType::Undefined:
      std::cerr << "[OpenGL][Error]: Camera type should never be undefined ?" << std::endl;
      exit(1);
      break;
    default:
      break;
    }
  }
}
