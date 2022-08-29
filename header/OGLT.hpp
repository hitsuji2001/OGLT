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

#include "./Handler/Handler.hpp"
#include "./Handler/KeyHandler.hpp"
#include "./Handler/MouseHandler.hpp"

#define DELETE_IF_NOT_NULL(x) if ((x) != NULL) delete (x);

namespace oglt {
  class OpenGL {
  public:
    static OpenGL &CreateInstance() {
      static OpenGL opengl;
      return opengl;
    }
    virtual ~OpenGL();

    Shader   *GetShader();
    Texture  *GetTexture();

    VAO      *GetVAO();
    VBO      *GetVBO();
    EBO      *GetEBO();

    static Window   *GetWindow();
    static Camera   *GetCamera();
    static Mouse    *GetMouse();
    static Handler  *GetKeyHandler();
    static Handler  *GetMouseHandler();
    static float     GetDeltaTime();

    void CreateShaders(const char *vertexPath, const char *fragmentPath);
    void CreateTexture(TextureType type, GLint wrapping = GL_REPEAT, GLint filter = GL_LINEAR);

    static void PollEvents();
    static void CalculateDeltaTime();
    static void CreateWindow(const char *title, WindowType type = WindowType::WindowedCentered, int width = 0, int height = 0);
    static void CreateCamera();
    static void CreateMouse();
    // You can call this after you called `CreateCamera()`
    static void CreateKeyHandler();
    // You can call this after you called `CreateCamera()` and `CreateMouse()`
    static void CreateMouseHandler();

    void CreateVAO();
    void CreateVBO();
    void CreateEBO();
  
  protected:
    OpenGL();
    OpenGL(const OpenGL&) = delete;

  private:
    void CleanUp();

  private:
    static float a_DeltaTime;
    static float a_LastFrame;

    static Camera  *m_ViewCamera;
    static Mouse   *m_Mouse;
    static Handler *m_KeyHandler;
    static Handler *m_MouseHandler;
    static Window  *m_Window;

    Shader   *m_Shader;
    Texture  *m_Texture;

    VAO      *m_VAO;
    VBO      *m_VBO;
    EBO      *m_EBO;
  };
}

#endif // __OPENGL_TEMPLATE_HPP__
