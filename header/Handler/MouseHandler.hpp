#ifndef __MOUSE_HANDLER_HPP__
#define __MOUSE_HANDLER_HPP__

#include "./Handler.hpp"
#include "../Mouse.hpp"

namespace oglt {
  class MouseHandler final : public Handler {
  public:
    MouseHandler();
    MouseHandler(std::shared_ptr<Window>& window, std::shared_ptr<Mouse>& mouse, std::shared_ptr<Camera>& camera, const CameraType& type);
    MouseHandler(std::shared_ptr<Window>& window, std::shared_ptr<Mouse>& mouse, std::shared_ptr<Camera>& camera);
    virtual ~MouseHandler();

    void Handle(float deltatime) override;

  private:
    void HandlePerspecCamera(float deltatime);
    void HandleOrthoCamera(float deltatime);

    static void PerspecMouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn);
    static void PerspecMouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset);

    static void OrthoMouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn);
    static void OrthoMouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
  };
}

#endif // __MOUSE_HANDLER_HPP__
