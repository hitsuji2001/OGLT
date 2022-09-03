#ifndef __MOUSE_HANDLER_HPP__
#define __MOUSE_HANDLER_HPP__

#include "./Handler.hpp"
#include "../Mouse.hpp"

namespace oglt {
  class MouseHandler final : public Handler {
  public:
    MouseHandler();
    MouseHandler(std::shared_ptr<Window> window, std::shared_ptr<Mouse> mouse, std::shared_ptr<Camera> camera);
    virtual ~MouseHandler();

    void Handle(float deltatime) override;

  private:
    static void MouseCursorCallback(GLFWwindow *window, double xPosIn, double yPosIn);
    static void MouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
  };
}

#endif // __MOUSE_HANDLER_HPP__
