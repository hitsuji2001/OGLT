#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../OGLT/header/OGLT.hpp"

int main() {
  oglt::OpenGL &opengl = oglt::OpenGL::CreateInstance();
  opengl.CreateWindow("Demo", oglt::WindowType::WindowedCentered);
  opengl.CreateShaders("./shader/vertex.glsl", "./shader/fragment.glsl");

  float vertices[] = {
     // Coords,         // Color
     1.0f,  1.0f, 1.0f, 0.5f, 0.0f , 0.0f,  // top right
     1.0f, -1.0f, 0.0f, 0.0f, 0.75f, 0.0f,  // bottom right
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f , 0.25f, // bottom left
    -1.0f,  1.0f, 0.0f, 0.5f, 0.75f, 0.25f, // top left 
  };

  uint32_t indices[] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  };

  opengl.CreateVAO();
  opengl.GetVAO()->Bind();

  opengl.CreateEBO();
  opengl.GetEBO()->FlushData(indices, sizeof(indices));
  opengl.CreateVBO();
  opengl.GetVBO()->FlushData(vertices, sizeof(vertices));
  
  opengl.GetVAO()->LinkVBO(opengl.GetVBO(), 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  opengl.GetVAO()->LinkVBO(opengl.GetVBO(), 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

  opengl.GetVAO()->Unbind();

  while (!glfwWindowShouldClose(opengl.GetWindow()->GetOpenGLWindow())) {
    double time = glfwGetTime();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    opengl.GetShader()->SetFloat("time", time);

    opengl.GetShader()->Use();
    opengl.GetVAO()->Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(opengl.GetWindow()->GetOpenGLWindow());
    glfwPollEvents();
  }

  return 0 ;
}
