#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace oglt {
  class Camera {
  public:
    Camera();
    virtual ~Camera();

    void MoveUp(float dt);
    void MoveDown(float dt);
    void MoveLeft(float dt);
    void MoveRight(float dt);

    glm::vec3 GetPosition();
    glm::vec3 GetFrontVector();
    glm::vec3 GetUpVector();

    float GetSpeed();
    float GetFOV();
    float GetYaw();
    float GetPitch();

    void SetFrontVector(glm::vec3 value);
    void SetPosition(glm::vec3 value);

    void SetSpeed(float value);
    void SetFOV(float value);
    void SetYaw(float value);
    void SetPitch(float value);

  private:
    float     a_Yaw;
    float     a_Pitch;
    float     a_FOV;
    float     a_Speed;

    glm::vec3 a_Position;
    glm::vec3 a_Front;
    glm::vec3 a_UpVector;
  };
}

#endif // __CAMERA_HPP__
