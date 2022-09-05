#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./Window.hpp"

namespace oglt {
  class Window;

  class Mouse {
  public:
    void SetMouseInputMode(const std::shared_ptr<Window>& window, int mode, int value);
    void DisableCursor(const std::shared_ptr<Window>& window);

    void SetMouseCursorCallback(void (*callback)(GLFWwindow *window, double xPosIn, double yPosIn), std::shared_ptr<Window> window);
    void SetMouseScrollCallback(void (*callback)(GLFWwindow *window, double xOffset, double yOffset), std::shared_ptr<Window> window);

    float GetLastXPos() const;
    float GetLastYPos() const;
    float GetSensitivity() const;
    bool  IsFirstMouse() const;

    void SetFirstMouse(bool value);
    void SetLastXPos(float value);
    void SetLastYPos(float value);

    Mouse();
    virtual ~Mouse();

  private:
    float a_Sensitivty;
    bool  a_FirstMouse;
    float a_XPos;
    float a_YPos;
    float a_LastXPos;
    float a_LastYPos;
  };
}

#endif // __MOUSE_HPP__
