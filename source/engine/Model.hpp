#ifndef SAH_MODEL
#define SAH_MODEL

#include <iostream>
#include <vector>

#include <glad.h>
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
    // transforms
    glm::mat4 m_model = glm::mat4(1.0f);
    glm::mat4 m_rotationMat = glm::mat4(1.0f);
    glm::mat4 m_scaleMat = glm::mat4(1.0f);
    glm::mat4 m_positionMat = glm::mat4(1.0f);

    // mesh
    std::vector<Vertex> m_vertices;

public:
    Model();
    ~Model();

    // mesh groups for multy material capability
    std::vector<MeshGroup> meshGroups;

    // for render
    unsigned int m_shaderProgram = ShaderLoader::getShader("Default");
    unsigned int m_polygoneMode = GL_FILL; // GL_POINT, GL_LINE, GL_FILL
    unsigned int m_modelSize = 0;

    // for model matrix transformation
    void setUniformTransform();
    void reSetTransform();
    void setPosition(glm::vec3 position);
    void setPosition(float _x, float _y, float _z);
    void setRotation(float rotationDeg, glm::vec3 axes);
    void addRotation(float rotationDeg, glm::vec3 axes);
    void setLookAt(glm::vec3 pos, glm::vec3 target, glm::vec3 up);
    void setScale(glm::vec3 size);

    // for mesh
    void addVertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal, glm::vec3 color);
    void loadVertices(unsigned int _indecies[], unsigned int _numberIndecies, Material _material);
    void meshGroupsFlush();
    std::string getSize();

    // for material
    void setDefuse(glm::vec4 _defuse);
    void setAlbedoTexture(std::string _textureName);
    void setUniformMaterial(Material _material);

    // for render
    void setShaderProgram(std::string _shaderProgramName);
    void setPolygoneMode(unsigned int _polygoneMode);
    void render();

};

#endif
