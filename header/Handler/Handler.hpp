#ifndef __HANDLER_HPP__
#define __HANDLER_HPP__

#include <map>

#include "../Camera.hpp"
#include "../Window.hpp"
#include "../Mouse.hpp"
#include "./KeyboardAndMouse.hpp"

namespace oglt {
  class Handler {
  public:
    virtual ~Handler() = 0;
    virtual void Handle(float deltatime) = 0;

    static Camera *GetCamera();
    static Mouse  *GetMouse();
    static Window *GetWindow();

    static void SetCamera(Camera *camera);
    static void SetWindow(Window *window);
    static void SetMouse(Mouse *mouse);

  private:
    static Camera *m_Camera;
    static Mouse  *m_Mouse;
    static Window *m_Window;
  };
}

#endif // __HANDLER_HPP__
