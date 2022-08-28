#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../OGLT/header/OGLT.hpp"

int main() {
  oglt::OpenGL &opengl = oglt::OpenGL::CreateInstance();
  opengl.CreateWindow("Demo", oglt::WindowType::Fullscreen);
  opengl.CreateShaders("./shader/vertex.glsl", "./shader/fragment.glsl");

  float vertices[] = {
    // Position,       // Color            // Text Coord
     1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f,  // top right
     1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // bottom right
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom left
    -1.0f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // top left 
  };

  uint32_t indices[] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  };

  opengl.CreateCamera();
  opengl.CreateMouse();
  opengl.GetMouse()->DisableCursor(opengl.GetWindow());

  opengl.CreateKeyHandler();
  opengl.CreateMouseHandler();

  opengl.CreateVAO();
  opengl.CreateVBO();
  opengl.CreateEBO();

  opengl.GetVAO()->Bind();

  opengl.GetEBO()->FlushData(indices, sizeof(indices));
  opengl.GetVBO()->FlushData(vertices, sizeof(vertices));
  
  opengl.GetVAO()->LinkVBO(opengl.GetVBO(), 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  opengl.GetVAO()->LinkVBO(opengl.GetVBO(), 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  opengl.GetVAO()->LinkVBO(opengl.GetVBO(), 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

  opengl.GetVAO()->Unbind();

  opengl.CreateTexture(oglt::TextureType::TextureType2D);
  opengl.GetTexture()->LoadTexture("image.png", GL_RGBA);
  while (!glfwWindowShouldClose(opengl.GetWindow()->GetOpenGLWindow())) {
    double time = glfwGetTime();

    opengl.CalculateDeltaTime();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    opengl.GetKeyHandler()->Handle(opengl.GetDeltaTime());
    opengl.GetMouseHandler()->Handle(opengl.GetDeltaTime());

    glm::mat4 view       = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 model      = glm::mat4(1.0f);

    view = glm::lookAt(opengl.GetCamera()->GetPosition(), opengl.GetCamera()->GetPosition() + opengl.GetCamera()->GetFrontVector(), opengl.GetCamera()->GetUpVector());
    projection = glm::perspective(glm::radians(opengl.GetCamera()->a_FOV), (float)opengl.GetWindow()->GetWidth() / (float)opengl.GetWindow()->GetHeight(), 0.1f, 100.0f);
    // model = glm::rotate(model, (float)glm::radians(45.0f), glm::vec3(-0.25f, 0.0f, 0.0f));
    opengl.GetShader()->SetMat4("projection", projection);
    opengl.GetShader()->SetMat4("view", view);
    opengl.GetShader()->SetMat4("model", model);

    opengl.GetShader()->SetFloat("time", time);

    opengl.GetShader()->Use();
    opengl.GetVAO()->Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(opengl.GetWindow()->GetOpenGLWindow());
    glfwPollEvents();
  }

  return 0 ;
}
