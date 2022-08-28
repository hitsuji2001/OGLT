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
    void SetCamera(Camera *camera);
    void SetWindow(Window *window);
    void SetMouse(Mouse *mouse);

    Window *GetWindow();
    Camera *GetCamera();
    Mouse  *GetMouse();

    virtual void Handle(float deltatime) = 0;
    virtual ~Handler() = 0;
  private:
    Camera *m_Camera;
    Mouse  *m_Mouse;
    Window *m_Window;
  };
}

#endif // __HANDLER_HPP__
