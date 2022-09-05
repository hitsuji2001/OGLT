#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace oglt {
  enum class CameraType {
    OrthoCamera,
    PerspecCamera,
    Undefined,
  };

  class Camera {
  public:
    Camera();
    virtual ~Camera();

    virtual void MoveUp(float dt) = 0;
    virtual void MoveDown(float dt) = 0;
    virtual void MoveLeft(float dt) = 0;
    virtual void MoveRight(float dt) = 0;

    const glm::vec3& GetPosition() const;
    const glm::vec3& GetFrontVector() const;
    const glm::vec3& GetUpVector() const;

    const glm::mat4& GetViewMatrix() const;
    const glm::mat4& GetProjectionMatrix() const;
    const glm::mat4& GetTransformationMatrix() const;

    float GetSpeed() const;
    float GetFOV() const;
    float GetYaw() const;
    float GetPitch() const;

    void SetUpVector(const glm::vec3& value);
    void SetFrontVector(const glm::vec3& value);
    void SetPosition(const glm::vec3& value);
    void SetViewMatrix(const glm::mat4& value);
    void SetProjectionMatrix(const glm::mat4& value);
    void SetTransformationMatrix(const glm::mat4& value);

    void SetSpeed(float value);
    void SetFOV(float value);
    void SetYaw(float value);
    void SetPitch(float value);

  private:
    void RecalculateViewMatrix();

  private:
    float     a_Yaw;
    float     a_Pitch;
    float     a_FOV;
    float     a_Speed;
    float     a_Rotation;

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;
    glm::mat4 m_TransformationMatrix;

    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_UpVector;
  };
}

#endif // __CAMERA_HPP__
