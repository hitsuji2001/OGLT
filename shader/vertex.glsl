#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 color;
uniform float time;

void main() {
  color = vec4(aColor.x * cos(time), aColor.y * sin(time), aColor.z * cos(sin(time)), 1.0f);
  gl_Position = vec4(aPos, 1.0f);
}
