#ifndef __KEY_HANDLER_HPP__
#define __KEY_HANDLER_HPP__

#include "./Handler.hpp"

namespace oglt {
  class KeyHandler final : public Handler {
  public:
    KeyHandler();
    KeyHandler(Window *window, Camera *camera);
    virtual ~KeyHandler();

    void Handle(float deltatime) override;
  };
}

#endif // __KEY_HANDLER_HPP__
