#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_uv;

out vec4 v_color;
out vec2 v_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    v_color = in_color;
    v_uv = in_uv;

    gl_Position = projection * view * model * vec4(in_position, 1.0f);
}
