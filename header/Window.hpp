#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define OPENGL_VERSION_MAJOR 3
#define OPENGL_VERSION_MINOR 3

namespace oglt {
  enum class WindowType {
    BorderlessFullscreen,
    Fullscreen,
    Normal,
    WindowedCentered,
  };

  class Window {
  public:
    Window();
    virtual ~Window();

    // If both `width` and `height` is set to 0
    // This will create a window of the size
    // width  = (primary monior width) / 1.75f
    // height = width / 16 * 9
    void CreateWindow(const char *title, WindowType type = WindowType::WindowedCentered, int width = 0, int height = 0);
    // hex_color will be in RGBA order
    void ClearScreen(uint32_t hex_color, GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    void SwapBuffers();
    bool IsOpen();

    uint32_t    GetWidth();
    uint32_t    GetHeight();
    GLFWwindow *GetOpenGLWindow();

    void SetWidth(uint32_t value);
    void SetHeight(uint32_t value);
  private:
    bool InitGLFW();
    bool InitGLAD();

    bool CreateNormalWindow(const char *title, uint32_t width = 0, uint32_t height = 0);
    bool CreateFullScreenWindow(const char *title);
    bool CreateBorderlessFullscreenWindow(const char *title);
    bool CreateCenteredWindow(const char *title, uint32_t width = 0, uint32_t height = 0);

    void SetUpAttributes();
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

  private:
    GLFWwindow         *m_Window;
    GLFWmonitor       **m_Monitors;
    const GLFWvidmode  *m_VideoMode;

    int         a_MonitorCount;
    uint32_t    a_Width;
    uint32_t    a_Height;
    const char *a_Title;
  };
}

#endif // __WINDOW_HPP__
