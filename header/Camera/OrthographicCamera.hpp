#ifndef __ORTHOGRAPHIC_CAMERA_HPP__
#define __ORTHOGRAPHIC_CAMERA_HPP__

#include "./Camera.hpp"

namespace oglt {
  class OrthographicCamera final : public Camera {
  public:
    OrthographicCamera(float left, float right, float up, float bottom, float near, float far);
    virtual ~OrthographicCamera();

    void MoveUp(float dt) override;
    void MoveDown(float dt) override;
    void MoveLeft(float dt) override;
    void MoveRight(float dt) override;
  };
}

#endif // __ORTHOGRAPHIC_CAMERA_HPP__
