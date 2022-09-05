#ifndef __HANDLER_HPP__
#define __HANDLER_HPP__

#include <memory>

#include "../Camera/Camera.hpp"
#include "../Window.hpp"
#include "../Mouse.hpp"
#include "./KeyboardAndMouse.hpp"

namespace oglt {
  class Handler {
  public:
    virtual ~Handler() = 0;
    virtual void Handle(float deltatime) = 0;

    static const std::shared_ptr<Camera>& GetCamera();
    static const std::shared_ptr<Mouse>&  GetMouse();
    static const std::shared_ptr<Window>& GetWindow();
    static const CameraType& GetCameraType();

    static void SetWindow(const std::shared_ptr<Window>& window);
    static void SetCamera(const std::shared_ptr<Camera>& camera);
    static void SetMouse(const std::shared_ptr<Mouse>& mouse);
    static void SetCameraType(const CameraType& type);

  private:
    static CameraType              a_Type;
    static std::shared_ptr<Camera> m_Camera;
    static std::shared_ptr<Mouse>  m_Mouse;
    static std::shared_ptr<Window> m_Window;
  };
}

#endif // __HANDLER_HPP__
