#include "../../header/Camera/PerspectiveCamera.hpp"

namespace oglt {
  PerspectiveCamera::PerspectiveCamera() {
    this->SetViewMatrix(glm::mat4(1.0f));
    this->SetProjectionMatrix(glm::mat4(1.0f));
    this->SetTransformationMatrix(glm::mat4(1.0f));

    this->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
    this->SetFrontVector(glm::vec3(0.0f, 0.0f, -1.0f));
    this->SetUpVector(glm::vec3(0.0f, 1.0f, 0.0f));

    this->SetYaw(-90.0f);
    this->SetPitch(0.0f);
    this->SetFOV(45.0f);
    
    this->SetSpeed(10.0f);
  }

  PerspectiveCamera::~PerspectiveCamera() {
  }

  void PerspectiveCamera::MoveUp(float dt) {
    this->SetPosition(this->GetPosition() + this->GetFrontVector() * this->GetSpeed() * dt);
  }

  void PerspectiveCamera::MoveDown(float dt) {
    this->SetPosition(this->GetPosition() - this->GetFrontVector() * this->GetSpeed() * dt);
  }

  void PerspectiveCamera::MoveLeft(float dt) {
    this->SetPosition(this->GetPosition() - glm::normalize(glm::cross(this->GetFrontVector(), this->GetUpVector())) * this->GetSpeed() * dt);
  }

  void PerspectiveCamera::MoveRight(float dt) {
    this->SetPosition(this->GetPosition() + glm::normalize(glm::cross(this->GetFrontVector(), this->GetUpVector())) * this->GetSpeed() * dt);
  }
}
