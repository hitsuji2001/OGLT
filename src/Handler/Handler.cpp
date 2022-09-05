#include "../../header/Handler/Handler.hpp"

namespace oglt {
  std::shared_ptr<Camera> Handler::m_Camera	= nullptr;
  std::shared_ptr<Mouse>  Handler::m_Mouse	= nullptr;
  std::shared_ptr<Window> Handler::m_Window	= nullptr;
  CameraType              Handler::a_Type       = CameraType::Undefined;

  Handler::~Handler() {
  }

  const std::shared_ptr<Window>& Handler::GetWindow() {
    return Handler::m_Window;
  }

  const std::shared_ptr<Camera>& Handler::GetCamera() {
    return Handler::m_Camera;
  }

  const std::shared_ptr<Mouse>& Handler::GetMouse() {
    return Handler::m_Mouse;
  }

  const CameraType& Handler::GetCameraType() {
    return Handler::a_Type;
  }

  void Handler::SetCamera(const std::shared_ptr<Camera>& camera) {
    Handler::m_Camera = camera;
  }

  void Handler::SetWindow(const std::shared_ptr<Window>& window) {
    Handler::m_Window = window;
  }

  void Handler::SetMouse(const std::shared_ptr<Mouse>& mouse) {
    Handler::m_Mouse = mouse;
  }

  void Handler::SetCameraType(const CameraType& type) {
    Handler::a_Type = type;
  }
}
