#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../OGLT/header/OGLT.hpp"

int main() {
  OpenGL &opengl = OpenGL::CreateInstance();
  opengl.GetWindow()->CreateWindow("Demo");
  opengl.GetShader()->LoadShaders("./shader/vertex.glsl", "./shader/fragment.glsl");

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

  opengl.SetVAO(new VAO());
  opengl.GetVAO()->Bind();

  opengl.SetEBO(new EBO(indices, sizeof(indices)));
  opengl.SetVBO(new VBO(vertices, sizeof(vertices)));
  
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
