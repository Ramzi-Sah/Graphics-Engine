#ifndef SAH_MODEL
#define SAH_MODEL

#include <vector>

#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include "../include/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../common/Vectors.hpp"
#include "../common/Vertex.hpp"
#include "assets/ShaderLoader.hpp"
#include "Camera.hpp"

class Model {
private:
    // transforms
    glm::mat4 m_model = glm::mat4(1.0f);

    // mesh
    std::vector<Vertex> m_vertices;
    unsigned int m_numberIndecies;

    // material
    unsigned int albedo = 0;

    // for render
    unsigned int VAO;
    unsigned int m_shaderProgram = ShaderLoader::getShader("Default");
    unsigned int m_polygoneMode = GL_FILL; // GL_POINT, GL_LINE, GL_FILL

public:
    Model();
    ~Model() {};

    // for model matrix transformation
    void setUniformTransform();
    void setTransform(glm::vec3 position, glm::vec3 size);
    void setPos(glm::vec3 position); // FIXME: resets m_model matrix
    void setRot(float rotation, glm::vec3 axes); // FIXME: resets m_model matrix
    void setScale(glm::vec3 size); // FIXME: resets m_model matrix

    // for mesh
    void addVertex(glm::vec3 position, glm::vec4 color, glm::vec2 uv);
    void loadVertices();
    void setIndecies(unsigned int _indecies[], unsigned int _numberIndecies);

    // for material
    void setAlbedoTexture(std::string filePath); // FIXME:

    // for render
    void setShaderProgram(unsigned int _shaderProgram);
    void setPolygoneMode(unsigned int _polygoneMode);
    void render();

};

#endif
