#include "../../header/Camera/OrthographicCamera.hpp"

namespace oglt {
  OrthographicCamera::OrthographicCamera(float left, float right, float up, float bottom, float near, float far) {
    (void) left;
    (void) right;
    (void) up;
    (void) bottom;
    (void) near;
    (void) far;
  }

  OrthographicCamera::~OrthographicCamera() {
  }

  void OrthographicCamera::MoveUp(float dt) {
    (void) dt;
  }

  void OrthographicCamera::MoveDown(float dt) {
    (void) dt;
  }

  void OrthographicCamera::MoveLeft(float dt) {
    (void) dt;
  }

  void OrthographicCamera::MoveRight(float dt) {
    (void) dt;
  }
}
