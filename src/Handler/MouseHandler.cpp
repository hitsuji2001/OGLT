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

    float xpos = (float) xPosIn;
    float ypos = (float) yPosIn;

    if (MouseHandler::GetMouse()->IsFirstMouse()) {
      MouseHandler::GetMouse()->SetLastXPos(xpos);
      MouseHandler::GetMouse()->SetLastYPos(ypos);
      MouseHandler::GetMouse()->SetFirstMouse(false);
    }

    float xoffset = xpos - MouseHandler::GetMouse()->GetLastXPos();
    float yoffset = MouseHandler::GetMouse()->GetLastYPos() - ypos;

    MouseHandler::GetMouse()->SetLastXPos(xpos);
    MouseHandler::GetMouse()->SetLastYPos(ypos);

    xoffset *= MouseHandler::GetMouse()->GetSensitivity();
    yoffset *= MouseHandler::GetMouse()->GetSensitivity();

    MouseHandler::GetCamera()->a_Yaw   += xoffset;
    MouseHandler::GetCamera()->a_Pitch += yoffset;
  
    if (MouseHandler::GetCamera()->a_Pitch > 89.0f) MouseHandler::GetCamera()->a_Pitch = 89.0f;
    if (MouseHandler::GetCamera()->a_Pitch < -89.0f) MouseHandler::GetCamera()->a_Pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(MouseHandler::GetCamera()->a_Yaw)) * cos(glm::radians(MouseHandler::GetCamera()->a_Pitch));
    front.y = sin(glm::radians(MouseHandler::GetCamera()->a_Pitch));
    front.z = sin(glm::radians(MouseHandler::GetCamera()->a_Yaw)) * cos(glm::radians(MouseHandler::GetCamera()->a_Pitch));
    MouseHandler::GetCamera()->SetFrontVector(glm::normalize(front));
  }
 
  void MouseHandler::MouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    (void) window;
    (void) xoffset;

    MouseHandler::GetCamera()->a_FOV -= (float) yoffset;
    if (MouseHandler::GetCamera()->a_FOV < 1.0F) MouseHandler::GetCamera()->a_FOV = 1.0f;
    if (MouseHandler::GetCamera()->a_FOV > 45.0F) MouseHandler::GetCamera()->a_FOV = 45.0f;
  }
}
