#include "../../header/Handler/Handler.hpp"

namespace oglt {
  std::shared_ptr<Camera> Handler::m_Camera	= nullptr;
  std::shared_ptr<Mouse>  Handler::m_Mouse	= nullptr;
  std::shared_ptr<Window> Handler::m_Window	= nullptr;

  Handler::~Handler() {
  }

  std::shared_ptr<Window> Handler::GetWindow() {
    return Handler::m_Window;
  }

  std::shared_ptr<Camera> Handler::GetCamera() {
    return Handler::m_Camera;
  }

  std::shared_ptr<Mouse> Handler::GetMouse() {
    return Handler::m_Mouse;
  }

  void Handler::SetCamera(std::shared_ptr<Camera> camera) {
    Handler::m_Camera = camera;
  }

  void Handler::SetWindow(std::shared_ptr<Window> window) {
    Handler::m_Window = window;
  }

  void Handler::SetMouse(std::shared_ptr<Mouse> mouse) {
    Handler::m_Mouse = mouse;
  }
}
