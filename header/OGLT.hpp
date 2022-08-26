#ifndef __OPENGL_TEMPLATE_HPP__
#define __OPENGL_TEMPLATE_HPP__

#include "./Shader.hpp"
#include "./Window.hpp"
#include "./Camera.hpp"
#include "./Mouse.hpp"
#include "./Texture/Texture.hpp"
#include "./Texture/Texture2D.hpp"
#include "./Texture/Texture3D.hpp"
#include "./BufferObject/VBO.hpp"
#include "./BufferObject/EBO.hpp"
#include "./BufferObject/VAO.hpp"

#define DELETE_IF_NOT_NULL(x) if ((x) != NULL) delete (x);

namespace oglt {
  class OpenGL {
  public:
    static OpenGL &CreateInstance() {
      static OpenGL opengl;
      return opengl;
    }
    virtual ~OpenGL();
  
    Window   *GetWindow();
    Shader   *GetShader();
    Texture  *GetTexture();

    VAO      *GetVAO();
    VBO      *GetVBO();
    EBO      *GetEBO();

    Camera *GetCamera();
    Mouse  *GetMouse();

    float GetDeltaTime();

    void CalculateDeltaTime();

    void CreateWindow(const char *title, WindowType type = WindowType::WindowedCentered, int width = 0, int height = 0);
    void CreateShaders(const char *vertexPath, const char *fragmentPath);
    void CreateCamera();
    void CreateMouse();
    void CreateTexture(TextureType type, GLint wrapping = GL_REPEAT, GLint filter = GL_LINEAR);

    void CreateVAO();
    void CreateVBO();
    void CreateEBO();

  public:
    Camera *m_Camera;
    Mouse  *m_Mouse;
  
  protected:
    OpenGL();
    OpenGL(const OpenGL&) = delete;

  private:
    void CleanUp();

  private:
    static float m_DeltaTime;
    static float m_LastFrame;

    Window   *m_Window;
    Shader   *m_Shader;
    Texture  *m_Texture;

    VAO      *m_VAO;
    VBO      *m_VBO;
    EBO      *m_EBO;
  };
}

#endif // __OPENGL_TEMPLATE_HPP__
