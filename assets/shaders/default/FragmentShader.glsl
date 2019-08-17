#version 330 core

out vec4 out_color;

in vec4 v_defuse;
in vec2 v_uv;
in vec3 diffuseLight;

// material
uniform sampler2D texture0; // defuseMap

// light
uniform vec3 ambientLight;

void main() {
    // calculate light
    vec4 light = vec4(ambientLight + diffuseLight, 1.0f);

    // calculate color
    vec4 color = (texture(texture0, v_uv) * v_defuse);

    // final color
    out_color = light * color;
}
