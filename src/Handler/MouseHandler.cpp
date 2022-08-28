#include "../../header/Handler/MouseHandler.hpp"

namespace oglt {
  Camera *MouseHandler::m_Camera = NULL;
  Mouse  *MouseHandler::m_Mouse = NULL;

  MouseHandler::MouseHandler() {
  }

  MouseHandler::~MouseHandler() {
  }

  MouseHandler::MouseHandler(Window *window, Mouse *mouse, Camera *camera) {
    this->SetWindow(window);
    this->m_Mouse = mouse;
    this->SetCamera(camera);
  }

  void MouseHandler::Handle(float deltatime) {
    (void) deltatime;

    this->GetMouse()->SetMouseCursorCallback(MouseHandler::MouseCursorCallback, this->GetWindow());
    this->GetMouse()->SetMouseScrollCallback(MouseHandler::MouseScrollCallback, this->GetWindow());
  }

  void MouseHandler::MouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn) {
    (void) window;
    (void) xPosIn;
    (void) yPosIn;
    // float xpos = (float) xPosIn;
    // float ypos = (float) yPosIn;

    // if (MouseHandler::m_Mouse->IsFirstMouse()) {
    //   MouseHandler::m_Mouse->SetLastXPos(xpos);
    //   MouseHandler::m_Mouse->SetLastYPos(ypos);
    //   MouseHandler::m_Mouse->SetFirstMouse(false);
    // }

    // float xoffset = xpos - MouseHandler::m_Mouse->GetLastXPos();
    // float yoffset = MouseHandler::m_Mouse->GetLastYPos() - ypos;

    // MouseHandler::m_Mouse->SetLastXPos(xpos);
    // MouseHandler::m_Mouse->SetLastYPos(ypos);

    // xoffset *= MouseHandler::m_Mouse->GetSensitivity();
    // yoffset *= MouseHandler::m_Mouse->GetSensitivity();

    // MouseHandler::m_Camera->a_Yaw   += xoffset;
    // MouseHandler::m_Camera->a_Pitch += yoffset;
  
    // if (MouseHandler::m_Camera->a_Pitch > 89.0f) MouseHandler::m_Camera->a_Pitch = 89.0f;
    // if (MouseHandler::m_Camera->a_Pitch < -89.0f) MouseHandler::m_Camera->a_Pitch = -89.0f;

    // glm::vec3 front;
    // front.x = cos(glm::radians(MouseHandler::m_Camera->a_Yaw)) * cos(glm::radians(MouseHandler::m_Camera->a_Pitch));
    // front.y = sin(glm::radians(MouseHandler::m_Camera->a_Pitch));
    // front.z = sin(glm::radians(MouseHandler::m_Camera->a_Yaw)) * cos(glm::radians(MouseHandler::m_Camera->a_Pitch));
    // MouseHandler::m_Camera->SetFrontVector(glm::normalize(front));
  }
 
  void MouseHandler::MouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    (void) window;
    (void) xoffset;
    (void) yoffset;

    MouseHandler::m_Camera->a_FOV -= (float) yoffset;
    if (MouseHandler::m_Camera->a_FOV < 1.0F) MouseHandler::m_Camera->a_FOV = 1.0f;
    if (MouseHandler::m_Camera->a_FOV > 45.0F) MouseHandler::m_Camera->a_FOV = 45.0f;
  }
}
