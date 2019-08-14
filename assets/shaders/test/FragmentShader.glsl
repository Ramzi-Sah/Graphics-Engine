#version 330 core

out vec4 color;

in vec4 v_color;

void main() {
    color = -v_color + 1.0f;
}
