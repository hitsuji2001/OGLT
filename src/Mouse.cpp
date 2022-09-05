#include "../header/Mouse.hpp"

namespace oglt {
  Mouse::Mouse() {
    this->a_Sensitivty = 0.075f;

    this->a_XPos = 0.0f;
    this->a_YPos = 0.0f;
    this->a_LastXPos = 0.0f;
    this->a_LastYPos = 0.0f;
    this->a_FirstMouse = true;
  }

  Mouse::~Mouse() {

  }

  bool Mouse::IsFirstMouse() const {
    return this->a_FirstMouse;
  }

  float Mouse::GetSensitivity() const {
    return this->a_Sensitivty;
  }

  float Mouse::GetLastXPos() const {
    return this->a_LastXPos;
  }

  float Mouse::GetLastYPos() const {
    return this->a_LastYPos;
  }

  void Mouse::SetLastXPos(float value) {
    this->a_LastXPos = value;
  }

  void Mouse::SetLastYPos(float value) {
    this->a_LastYPos = value;
  }

  void Mouse::SetFirstMouse(bool value) {
    this->a_FirstMouse = value;
  }

  void Mouse::SetMouseInputMode(const std::shared_ptr<Window>& window, int mode, int value) {
    glfwSetInputMode(window->GetOpenGLWindow(), mode, value);
  }

  void Mouse::DisableCursor(const std::shared_ptr<Window>& window) {
    glfwSetInputMode(window->GetOpenGLWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }    

  void Mouse::SetMouseCursorCallback(void (*callback)(GLFWwindow *window, double xPosIn, double yPosIn), std::shared_ptr<Window> window) {
    glfwSetCursorPosCallback(window->GetOpenGLWindow(), callback);
  }

  void Mouse::SetMouseScrollCallback(void (*callback)(GLFWwindow *window, double xOffset, double yOffet), std::shared_ptr<Window> window) {
    glfwSetScrollCallback(window->GetOpenGLWindow(), callback);
  }
}
