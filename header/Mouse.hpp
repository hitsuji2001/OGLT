#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./Window.hpp"

namespace oglt {
  class Window;

  class Mouse {
  public:
    void SetMouseInputMode(Window *window, int mode, int value);

    void SetCursorCallback(void (*callback)(GLFWwindow *window, double xPosIn, double yPosIn),
			   GLFWwindow *window, double xPosIn, double yPosIn);
    void SetScrollCallback(void (*callback)(GLFWwindow *window, double xPosIn, double yPosIn),
			   GLFWwindow *window, double xPosIn, double yPosIn);

    Mouse();
    virtual ~Mouse();

  public:
    float a_Sensitivty;

  private:
    float GetLastXPos();
    float GetLastYPos();
    float GetSensitivity();
    bool IsFirstMouse();

    void SetFirstMouse(bool value);
    void SetLastXPos(float value);
    void SetLastYPos(float value);

  private:
    bool a_FirstMouse;

    float a_XPos;
    float a_YPos;

    float a_LastXPos;
    float a_LastYPos;
  };
}

#endif // __MOUSE_HPP__
