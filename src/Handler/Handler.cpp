#include "../../header/Handler/Handler.hpp"

namespace oglt {
  Camera *Handler::m_Camera = NULL;
  Window *Handler::m_Window = NULL;
  Mouse  *Handler::m_Mouse  = NULL;

  Handler::~Handler() {
  }

  Window *Handler::GetWindow() {
    return Handler::m_Window;
  }

  Camera *Handler::GetCamera() {
    return Handler::m_Camera;
  }

  Mouse *Handler::GetMouse() {
    return Handler::m_Mouse;
  }

  void Handler::SetCamera(Camera *camera) {
    Handler::m_Camera = camera;    
  }

  void Handler::SetWindow(Window *window) {
    Handler::m_Window = window;
  }

  void Handler::SetMouse(Mouse *mouse) {
    Handler::m_Mouse = mouse;
  }
}
