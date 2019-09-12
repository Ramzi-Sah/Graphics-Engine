#version 330 core

out vec4 out_color;

in vec2 v_uv;
in vec4 v_defuse; // from material
in vec3 v_color; // from vertex attrib
in vec3 v_diffuseLight;
in vec3 v_ambientLight;

// material
uniform sampler2D texture0; // defuseMap

void main() {
    // calculate light
    vec4 light = vec4(v_ambientLight + v_diffuseLight, 1.0f);

    // calculate color
    vec4 color = texture(texture0, v_uv) * v_defuse * vec4(v_color, 1.0f);

    // final color
    out_color = light * color;
}
