#include "../../header/Handler/MouseHandler.hpp"

namespace oglt {
  MouseHandler::MouseHandler() {
  }

  MouseHandler::~MouseHandler() {
  }

  MouseHandler::MouseHandler(Window *window, Mouse *mouse, Camera *camera) {
    MouseHandler::SetWindow(window);
    MouseHandler::SetCamera(camera);
    MouseHandler::SetMouse(mouse);
  }

  void MouseHandler::Handle(float deltatime) {
    (void) deltatime;

    MouseHandler::GetMouse()->SetMouseCursorCallback(MouseHandler::MouseCursorCallback, MouseHandler::GetWindow());
    MouseHandler::GetMouse()->SetMouseScrollCallback(MouseHandler::MouseScrollCallback, MouseHandler::GetWindow());
  }

  void MouseHandler::MouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn) {
    (void) window;

    Camera *camera = MouseHandler::GetCamera();
    Mouse  *mouse  = MouseHandler::GetMouse();

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
 
  void MouseHandler::MouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    (void) window;
    (void) xoffset;

    Camera *camera = MouseHandler::GetCamera();

    camera->SetFOV(camera->GetFOV() - yoffset);
    if (camera->GetFOV() < 1.0f) camera->SetFOV(1.0f);
    if (camera->GetFOV() > 45.0f) camera->SetFOV(45.0f);
  }
}
