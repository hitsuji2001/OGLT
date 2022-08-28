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

    this->m_KeyHandler   = NULL;
    this->m_MouseHandler = NULL;

    this->m_VAO     = NULL;
    this->m_VBO     = NULL;
    this->m_EBO     = NULL;
  }

  void OpenGL::CreateWindow(const char *title, WindowType type, int width, int height) {
    if (this->m_Window == NULL) {
      this->m_Window = new Window();
      this->m_Window->CreateWindow(title, type, width, height);
    } else {
      std::cerr << "[TODO]: Handle this case bro" << std::endl;
      exit(1);
    }
  }

  void OpenGL::CreateShaders(const char *vertexPath, const char *fragmentPath) {
    // [TODO]: Maybe we could have multiple shaders,
    // so find a way to handle that.
    // Right now we just support 1 of each type of shader.
    if (this->m_Shader == NULL) {
      this->m_Shader = new Shader(vertexPath, fragmentPath);
    } else {
      this->m_Shader->LoadShaders(vertexPath, fragmentPath);
    }
  }

  void OpenGL::CreateCamera() {
    // TODO: Can we have multiple camera?
    if (this->m_Camera == NULL) this->m_Camera = new Camera();
  }

  void OpenGL::CreateMouse() {
    if (this->m_Mouse == NULL) this->m_Mouse = new Mouse();
  }

  void OpenGL::CreateTexture(TextureType type, GLint wrapping, GLint filter) {
    // [TODO]: We certainly need multiple textures,
    // so find a way to deal with that.

    if (this->m_Texture == NULL) {
      if (type == TextureType::TextureType2D) this->m_Texture = new Texture2D();
      else if (type == TextureType::TextureType3D) this->m_Texture = new Texture3D();
    } else {
      std::cerr << "[TODO]: Handle this case bro" << std::endl;
      exit(1);
    }

    this->m_Texture->CreateTexture(wrapping, filter);
  }

  void OpenGL::CreateKeyHandler() {
    if (this->m_KeyHandler == NULL) this->m_KeyHandler = new KeyHandler(this->m_Window, this->m_Camera);
  }

  void OpenGL::CreateMouseHandler() {
    if (this->m_MouseHandler == NULL) {
      this->m_MouseHandler = new MouseHandler(this->m_Window, this->m_Mouse, this->m_Camera);
      this->m_MouseHandler->SetCamera(this->m_Camera);
      this->m_MouseHandler->SetMouse(this->m_Mouse);
    }
  }

  void OpenGL::CreateVAO() {
    // [TODO]: Multiple VAOs?
    if (this->m_VAO == NULL) this->m_VAO = new VAO();
  }

  void OpenGL::CreateVBO() {
    // [TODO]: Multiple VBOs?
    if (this->m_VBO == NULL) this->m_VBO = new VBO();
  }

  void OpenGL::CreateEBO() {
    // [TODO]: Multiple EBOs?
    if (this->m_EBO == NULL) this->m_EBO = new EBO();
  }

  void OpenGL::CleanUp() {
    DELETE_IF_NOT_NULL(this->m_Texture);
    DELETE_IF_NOT_NULL(this->m_Shader);
    DELETE_IF_NOT_NULL(this->m_Window);
    DELETE_IF_NOT_NULL(this->m_Camera);
    DELETE_IF_NOT_NULL(this->m_Mouse);

    DELETE_IF_NOT_NULL(this->m_KeyHandler);
    DELETE_IF_NOT_NULL(this->m_MouseHandler);

    DELETE_IF_NOT_NULL(this->m_EBO);
    DELETE_IF_NOT_NULL(this->m_VAO);
    DELETE_IF_NOT_NULL(this->m_VBO);
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
    return this->m_Camera;
  }

  Mouse *OpenGL::GetMouse() {
    return this->m_Mouse;
  }

  Window *OpenGL::GetWindow() {
    return this->m_Window;
  }

  Texture *OpenGL::GetTexture() {
    return this->m_Texture;
  }

  Handler *OpenGL::GetKeyHandler() {
    return this->m_KeyHandler;
  }

  Handler *OpenGL::GetMouseHandler() {
    return this->m_MouseHandler;
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
