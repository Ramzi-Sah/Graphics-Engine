#version 330 core

out vec4 color;

in vec4 v_color;
in vec2 v_uv;

uniform sampler2D texture0;

void main() {
    color = texture(texture0, v_uv) + v_color;
}
