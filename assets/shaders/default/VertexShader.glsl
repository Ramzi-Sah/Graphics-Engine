#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

out vec4 v_defuse;
out vec2 v_uv;
out vec3 diffuseLight;

// material
uniform vec4 defuse;

// transforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// light
uniform vec3 lightDir;
uniform vec3 lightColor;

void main() {
    v_defuse = defuse;
    v_uv = in_uv;

    // calculate deffuse color
    // vec3 vertexPos = vec3(model * vec4(in_position, 1.0));
    // vec3 lightDir = normalize(lightPos - vertexPos); // for light point
    float diff = max(dot(normalize(in_normal), normalize(lightDir)), 0.0f);
    diffuseLight = vec3(diff * lightColor);

    gl_Position = projection * view * model * vec4(in_position, 1.0f);
}
