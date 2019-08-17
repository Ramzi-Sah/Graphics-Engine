#ifndef SAH_MODEL
#define SAH_MODEL

#include <iostream>
#include <vector>

#include "../include/glad.h"
#include <GLFW/glfw3.h>

#include "../common/Vectors.hpp"
#include "../common/Vertex.hpp"
#include "../common/Material.hpp"
#include "assets/ShaderLoader.hpp"
#include "assets/TextureLoader.hpp"

struct MeshGroup {
    Material material;
    unsigned int VAO;
    unsigned int numberIndecies;

    MeshGroup() {};
};

class Model {
private:
    // mesh groups for multy material capability
    std::vector<MeshGroup> meshGroups;

    // transforms
    glm::mat4 m_model = glm::mat4(1.0f);
    void setUniformTransform();

    // mesh
    std::vector<Vertex> m_vertices;
    unsigned int m_modelSize;

    // material
    void setUniformMaterial(Material _material);

    // for render
    unsigned int m_shaderProgram = ShaderLoader::getShader("Default");
    unsigned int m_polygoneMode = GL_FILL; // GL_POINT, GL_LINE, GL_FILL

public:
    Model();
    ~Model() {};

    // for model matrix transformation
    void setTransform(glm::vec3 position, glm::vec3 size);
    void setPos(glm::vec3 position); // FIXME: resets m_model matrix
    void setRot(float rotation, glm::vec3 axes); // FIXME: resets m_model matrix
    void setScale(glm::vec3 size); // FIXME: resets m_model matrix

    // for mesh
    void addVertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal);
    void loadVertices(unsigned int _indecies[], unsigned int _numberIndecies, Material _material);
    std::string getSize();

    // for material
    void setDefuse(glm::vec4 _defuse);
    void setAlbedoTexture(std::string _textureName);

    // for render
    void setShaderProgram(std::string _shaderProgramName);
    void setPolygoneMode(unsigned int _polygoneMode);
    void render();

};

#endif
