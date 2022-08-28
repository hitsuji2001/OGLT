#include "../../header/Handler/Handler.hpp"

namespace oglt {
  Handler::~Handler() {
  }

  Window *Handler::GetWindow() {
    return this->m_Window;
  }

  Camera *Handler::GetCamera() {
    return this->m_Camera;
  }

  Mouse *Handler::GetMouse() {
    return this->m_Mouse;
  }

  void Handler::SetCamera(Camera *camera) {
    this->m_Camera = camera;    
  }

  void Handler::SetWindow(Window *window) {
    this->m_Window = window;
  }

  void Handler::SetMouse(Mouse *mouse) {
    this->m_Mouse = mouse;
  }
}
