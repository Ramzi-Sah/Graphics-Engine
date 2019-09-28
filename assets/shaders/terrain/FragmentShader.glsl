#version 330 core

out vec4 out_color;

in vec2 v_uv;
in vec4 v_defuse; // from material
in vec3 v_color; // from vertex attrib
in vec3 v_diffuseLight;
in vec3 v_ambientLight;

in float v_grass_val;  // grass texture value

// material
uniform sampler2D texture0; // defuseMap

// terrain textures
uniform sampler2D grass_texture; // grass texture
uniform sampler2D rock_texture; // rock texture

void main() {
    // calculate light
    vec4 light = vec4(v_ambientLight + v_diffuseLight, 1.0f);

    // calculate color
    vec4 color = mix(texture(texture0, v_uv), texture(grass_texture, v_uv), v_grass_val) * vec4(v_color, 1.0f);

    // final color
    out_color = light * color;
}
