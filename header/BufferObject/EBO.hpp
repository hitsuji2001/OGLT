#ifndef __EBO_HPP__
#define __EBO_HPP__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./BufferObject.hpp"

namespace oglt {
  class EBO final : BufferObject {
  public:
    EBO();
    EBO(GLuint *vertices, GLsizeiptr size);

    void FlushData(void *data, GLsizeiptr size) override;
    void Bind() override;
    void Unbind() override;
    void Delete();
  };
}

#endif // __EBO_HPP__
