#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;
layout(location = 3) in vec3 in_color;

layout(location = 4) in float in_grass_val;

out vec4 v_defuse;
out vec2 v_uv;
out vec3 v_color;
out vec3 v_normal;
out vec3 v_diffuseLight;
out vec3 v_ambientLight;

out float v_grass_val;

// material
uniform vec4 defuse;
uniform vec3 ambientLight;

// transforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// light
uniform vec3 lightDir;
uniform vec3 lightColor;

void main() {
    // calculate position
    v_defuse = defuse;
    v_uv = in_uv;
    v_color = in_color;
    v_normal = vec3(model * vec4(in_normal, 0.0));

    // textures val
    v_grass_val = in_grass_val;

    // calculate ambient light
    v_ambientLight = ambientLight;

    // calculate deffuse light
    float diffuse_diff = max(dot(normalize(v_normal), normalize(lightDir)), 0.0f) + max(dot(normalize(v_normal), -normalize(lightDir)), 0.0f) / 4;
    v_diffuseLight = vec3(diffuse_diff * lightColor);

    gl_Position = projection * view * model * vec4(in_position, 1.0f);
}
