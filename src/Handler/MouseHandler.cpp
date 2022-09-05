#include "../../header/Handler/MouseHandler.hpp"

namespace oglt {
  MouseHandler::MouseHandler() {
  }

  MouseHandler::~MouseHandler() {
  }

  MouseHandler::MouseHandler(std::shared_ptr<Window>& window, std::shared_ptr<Mouse>& mouse, std::shared_ptr<Camera>& camera) {
    MouseHandler::SetWindow(window);
    MouseHandler::SetCamera(camera);
    MouseHandler::SetMouse(mouse);
  }

  MouseHandler::MouseHandler(std::shared_ptr<Window>& window, std::shared_ptr<Mouse>& mouse, std::shared_ptr<Camera>& camera, const CameraType& type) {
    MouseHandler::SetWindow(window);
    MouseHandler::SetCamera(camera);
    MouseHandler::SetMouse(mouse);
    MouseHandler::SetCameraType(type);
  }

  void MouseHandler::Handle(float deltatime) {
    (void) deltatime;
    switch (this->GetCameraType()) {
    case CameraType::PerspecCamera:
      this->HandlePerspecCamera(deltatime);
      break;
    case CameraType::OrthoCamera:
      this->HandleOrthoCamera(deltatime);
      break;
    case CameraType::Undefined:
      std::cerr << "[OpenGL][Error]: Camera type should never be undefined ?" << std::endl;
      exit(1);
      break;
    default:
      break;
    }
  }

  void MouseHandler::HandlePerspecCamera(float deltatime) {
    (void) deltatime;
    MouseHandler::GetMouse()->SetMouseCursorCallback(MouseHandler::PerspecMouseCursorCallback, MouseHandler::GetWindow());
    MouseHandler::GetMouse()->SetMouseScrollCallback(MouseHandler::PerspecMouseScrollCallback, MouseHandler::GetWindow());
  }

  void MouseHandler::HandleOrthoCamera(float deltatime) {
    (void) deltatime;
    MouseHandler::GetMouse()->SetMouseCursorCallback(MouseHandler::OrthoMouseCursorCallback, MouseHandler::GetWindow());
    MouseHandler::GetMouse()->SetMouseScrollCallback(MouseHandler::OrthoMouseScrollCallback, MouseHandler::GetWindow());
  }

  void MouseHandler::PerspecMouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn) {
    (void) window;

    std::shared_ptr<Camera> camera = MouseHandler::GetCamera();
    std::shared_ptr<Mouse>  mouse  = MouseHandler::GetMouse();

    float xpos = (float) xPosIn;
    float ypos = (float) yPosIn;

    if (mouse->IsFirstMouse()) {
      mouse->SetLastXPos(xpos);
      mouse->SetLastYPos(ypos);
      mouse->SetFirstMouse(false);
    }

    float xoffset = xpos - mouse->GetLastXPos();
    float yoffset = mouse->GetLastYPos() - ypos;

    mouse->SetLastXPos(xpos);
    mouse->SetLastYPos(ypos);

    xoffset *= mouse->GetSensitivity();
    yoffset *= mouse->GetSensitivity();

    camera->SetYaw(camera->GetYaw() + xoffset);
    camera->SetPitch(camera->GetPitch() + yoffset);
  
    if (camera->GetPitch() > 89.0f) camera->SetPitch(89.0f);
    if (camera->GetPitch() < -89.0f) camera->SetPitch(-89.0f);

    glm::vec3 front;
    front.x = cos(glm::radians(camera->GetYaw())) * cos(glm::radians(camera->GetPitch()));
    front.y = sin(glm::radians(camera->GetPitch()));
    front.z = sin(glm::radians(camera->GetYaw())) * cos(glm::radians(camera->GetPitch()));
    camera->SetFrontVector(glm::normalize(front));
  }
 
  void MouseHandler::PerspecMouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    (void) window;
    (void) xoffset;

    std::shared_ptr<Camera> camera = MouseHandler::GetCamera();

    camera->SetFOV(camera->GetFOV() - yoffset);
    if (camera->GetFOV() < 1.0f) camera->SetFOV(1.0f);
    if (camera->GetFOV() > 45.0f) camera->SetFOV(45.0f);
  }

  void MouseHandler::OrthoMouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn) {
    (void) window;
    (void) xPosIn;
    (void) yPosIn;
    assert(0 and "`OrthoMouseCursorCallback` is not implemented yet.\n");
  }

  void MouseHandler::OrthoMouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    (void) window;
    (void) xoffset;
    (void) yoffset;
    assert(0 and "`OrthoMouseScrollCallback` is not implemented yet.\n");
  }
}
