#define STB_IMAGE_IMPLEMENTATION
#include "../header/OGLT.hpp"

namespace oglt {
  float OpenGL::m_DeltaTime = 0.0f;
  float OpenGL::m_LastFrame = 0.0f;

  OpenGL::OpenGL() {
    this->m_Window  = NULL;
    this->m_Shader  = NULL;
    this->m_Camera  = NULL;
    this->m_Mouse   = NULL;

    this->m_Texture = NULL;
    this->m_VAO     = NULL;
    this->m_VBO     = NULL;
    this->m_EBO     = NULL;
  }

  void OpenGL::CreateWindow(const char *title, WindowType type, int width, int height) {
    this->m_Window = new Window();
    this->m_Window->CreateWindow(title, type, width, height);
  }

  void OpenGL::CreateShaders(const char *vertexPath, const char *fragmentPath) {
    this->m_Shader = new Shader(vertexPath, fragmentPath);
  }

  void OpenGL::CreateCamera() {
    this->m_Camera = new Camera();
  }

  void OpenGL::CreateMouse() {
    this->m_Mouse = new Mouse();
  }

  void OpenGL::CreateTexture(TextureType type, GLint wrapping, GLint filter) {
    if (type == TextureType::TextureType2D) this->m_Texture = new Texture2D();
    if (type == TextureType::TextureType3D) this->m_Texture = new Texture3D();

    this->m_Texture->CreateTexture(wrapping, filter);
  }

  void OpenGL::CreateVAO() {
    this->m_VAO = new VAO();
  }

  void OpenGL::CreateVBO() {
    this->m_VBO = new VBO();
  }

  void OpenGL::CreateEBO() {
    this->m_EBO = new EBO();
  }

  void OpenGL::CleanUp() {
    DELETE_IF_NOT_NULL(this->m_Texture);
    DELETE_IF_NOT_NULL(this->m_Shader);
    DELETE_IF_NOT_NULL(this->m_Window);
    DELETE_IF_NOT_NULL(this->m_EBO);
    DELETE_IF_NOT_NULL(this->m_VAO);
    DELETE_IF_NOT_NULL(this->m_VBO);
    DELETE_IF_NOT_NULL(this->m_Camera);
    DELETE_IF_NOT_NULL(this->m_Mouse);
  }

  OpenGL::~OpenGL() {
    this->CleanUp();
    glfwTerminate();
  }

  float OpenGL::GetDeltaTime() {
    return this->m_DeltaTime;
  }

  void OpenGL::CalculateDeltaTime() {
    float currentFrame = glfwGetTime();
    this->m_DeltaTime = currentFrame - this->m_LastFrame;
    this->m_LastFrame = currentFrame;
  }

  Shader *OpenGL::GetShader() {
    return this->m_Shader;
  }

  Camera *OpenGL::GetCamera() {
    return OpenGL::m_Camera;
  }

  Mouse *OpenGL::GetMouse() {
    return OpenGL::m_Mouse;
  }

  Window *OpenGL::GetWindow() {
    return this->m_Window;
  }

  Texture *OpenGL::GetTexture() {
    return this->m_Texture;
  }

  VAO *OpenGL::GetVAO() {
    return this->m_VAO;
  }

  VBO *OpenGL::GetVBO() {
    return this->m_VBO;
  }

  EBO *OpenGL::GetEBO() {
    return this->m_EBO;
  }
}
