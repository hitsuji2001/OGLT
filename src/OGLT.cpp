#define STB_IMAGE_IMPLEMENTATION
#include "../header/OGLT.hpp"

namespace oglt {
  float    OpenGL::a_DeltaTime		= 0.0f;
  float    OpenGL::a_LastFrame		= 0.0f;
  Camera  *OpenGL::m_ViewCamera		= NULL;
  Window  *OpenGL::m_Window		= NULL;
  Mouse   *OpenGL::m_Mouse		= NULL;
  Handler *OpenGL::m_MouseHandler	= NULL;
  Handler *OpenGL::m_KeyHandler		= NULL;

  OpenGL::OpenGL() {
    this->m_Shader		= NULL;
    this->m_Texture		= NULL;

    this->m_KeyHandler		= NULL;
    this->m_MouseHandler	= NULL;

    this->m_VAO			= NULL;
    this->m_VBO			= NULL;
    this->m_EBO			= NULL;
  }

  void OpenGL::CreateWindow(const char *title, WindowType type, int width, int height) {
    if (OpenGL::GetWindow() == NULL) {
      OpenGL::m_Window = new Window();
      OpenGL::GetWindow()->CreateWindow(title, type, width, height);
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
    if (OpenGL::m_ViewCamera == NULL) OpenGL::m_ViewCamera = new Camera();
  }

  void OpenGL::CreateMouse() {
    if (OpenGL::m_Mouse == NULL) OpenGL::m_Mouse = new Mouse();
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
    if (OpenGL::m_KeyHandler == NULL) OpenGL::m_KeyHandler = new KeyHandler(OpenGL::GetWindow(), OpenGL::m_ViewCamera);
  }

  void OpenGL::CreateMouseHandler() {
    if (OpenGL::m_MouseHandler == NULL) {
      OpenGL::m_MouseHandler = new MouseHandler(OpenGL::GetWindow(), OpenGL::m_Mouse, OpenGL::m_ViewCamera);
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

    DELETE_IF_NOT_NULL(this->m_KeyHandler);
    DELETE_IF_NOT_NULL(this->m_MouseHandler);

    DELETE_IF_NOT_NULL(this->m_EBO);
    DELETE_IF_NOT_NULL(this->m_VAO);
    DELETE_IF_NOT_NULL(this->m_VBO);

    DELETE_IF_NOT_NULL(OpenGL::m_Window);
    DELETE_IF_NOT_NULL(OpenGL::m_ViewCamera);
    DELETE_IF_NOT_NULL(OpenGL::m_Mouse);
  }

  OpenGL::~OpenGL() {
    this->CleanUp();
    glfwTerminate();
  }

  void OpenGL::PollEvents() {
    glfwPollEvents();
  }

  float OpenGL::GetDeltaTime() {
    return OpenGL::a_DeltaTime;
  }

  void OpenGL::CalculateDeltaTime() {
    float currentFrame = glfwGetTime();
    OpenGL::a_DeltaTime = currentFrame - OpenGL::a_LastFrame;
    OpenGL::a_LastFrame = currentFrame;
  }

  Shader *OpenGL::GetShader() {
    return this->m_Shader;
  }

  Camera *OpenGL::GetCamera() {
    return OpenGL::m_ViewCamera;
  }

  Mouse *OpenGL::GetMouse() {
    return OpenGL::m_Mouse;
  }

  Window *OpenGL::GetWindow() {
    return OpenGL::m_Window;
  }

  Texture *OpenGL::GetTexture() {
    return this->m_Texture;
  }

  Handler *OpenGL::GetKeyHandler() {
    return OpenGL::m_KeyHandler;
  }

  Handler *OpenGL::GetMouseHandler() {
    return OpenGL::m_MouseHandler;
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
