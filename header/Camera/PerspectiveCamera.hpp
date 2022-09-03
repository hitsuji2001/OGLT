#ifndef __PERSPECTIVE_CAMERA_HPP__
#define __PERSPECTIVE_CAMERA_HPP__

#include "./Camera.hpp"

namespace oglt {
  class PerspectiveCamera final : public Camera {
  public:
    PerspectiveCamera();
    virtual ~PerspectiveCamera();

    void MoveUp(float dt) override;
    void MoveDown(float dt) override;
    void MoveLeft(float dt) override;
    void MoveRight(float dt) override;
  };
}

#endif // __PERSPECTIVE_CAMERA_HPP__
