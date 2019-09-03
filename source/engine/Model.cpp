#include "Model.hpp"

Model::Model() {
    // init transform matricies
    reSetTransform();
}

Model::~Model() {
    meshGroupsFlush();
};

void Model::addVertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal, glm::vec3 color) {
    // create new Vertex object
    Vertex v(position, uv, normal, color);

    // add vertex to model vertices
    m_vertices.push_back(v);
}

void Model::loadVertices(unsigned int _indecies[], unsigned int _numberIndecies, Material _material) {
    MeshGroup meshGroup;

    // gen VAO & bind it for use
    glGenVertexArrays(1, &meshGroup.VAO);
    glBindVertexArray(meshGroup.VAO);

    // create Vertex Buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // load vbo with data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);

    // get model size Bytes for monitoring
    m_modelSize += sizeof(Vertex) * m_vertices.size();

    // handle data Vertex attribs
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0); // set position vertex attrib
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*3)); // set uv vertex attrib
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*5)); // set normal vertex attrib
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*8)); // set color vertex attrib
    glEnableVertexAttribArray(3);

    // create Eelement Buffer object
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    // load ebo with data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _numberIndecies, &_indecies[0], GL_STATIC_DRAW);

    // mseh group set number of indecies
    meshGroup.numberIndecies = _numberIndecies;

    // mseh group set material
    meshGroup.material = _material;

    // add mesh goup to list
    meshGroups.push_back(meshGroup);

    // unbind used buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // pop all vertecies
    m_vertices.clear();
}

void Model::meshGroupsFlush() {
    // FIXME: need to delete vaos data & vbos
    // for (int i = 0; i < meshGroups.size(); i++) {
    //     GLint nAttr = 0;
    //     glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nAttr);
    //     glBindVertexArray(meshGroups[i].VAO);
    //     for (int iAttr = 0; iAttr < nAttr; ++iAttr) {
    //         GLint vboId = 0;
    //         glGetVertexAttribiv(iAttr, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, &vboId);
    //         if (vboId > 0) {
    //             std::cout << "deleating: vbo " << vboId << std::endl;
    //             glDeleteBuffers(1, &vboId);
    //         }
    //     }
    // }
    //
    meshGroups.clear();
}

/*--------------------------------------------------------------------*/
void Model::setShaderProgram(std::string _shaderProgramName) {
    m_shaderProgram = ShaderLoader::getShader(_shaderProgramName);
}

void Model::setPolygoneMode(unsigned int _polygoneMode) {
    m_polygoneMode = _polygoneMode;
}

std::string Model::getSize() {
    return std::to_string(m_modelSize) + " Bytes";
};

void Model::render() {
    // set model shader
    glUseProgram(m_shaderProgram);

    // set openGL polygone mode
    glPolygonMode(GL_FRONT_AND_BACK, m_polygoneMode);

    // set transforms uniform
    setUniformTransform();

    // draw mesh groups
    for (int i = 0; i < meshGroups.size(); i++) {
        // set mesh group material uniform
        setUniformMaterial(meshGroups[i].material);

        // bind albedo texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, meshGroups[i].material.map_defuse);

        // bind model vao
        glBindVertexArray(meshGroups[i].VAO);

        // draw model
        glDrawElements(GL_TRIANGLES, meshGroups[i].numberIndecies, GL_UNSIGNED_INT, nullptr);
    }
}
/*--------------------------------------------------------------------*/
void Model::setUniformMaterial(Material _material) {
    // get unifoem location
    unsigned int defuseLoc = glGetUniformLocation(m_shaderProgram, "defuse");

    // set uniform
    glUniform4f(defuseLoc, _material.defuse.r, _material.defuse.g, _material.defuse.b, _material.defuse.a);
};

void Model::setDefuse(glm::vec4 _defuse) {
    // set all mesh groups defuse color
    for (int i = 0; i < meshGroups.size(); i++) {
        meshGroups[i].material.defuse = _defuse;
    }
};

void Model::setAlbedoTexture(std::string _textureName) {
    // set all mesh groups map defuse
    for (int i = 0; i < meshGroups.size(); i++) {
        meshGroups[i].material.map_defuse = TextureLoader::getTexture(_textureName);
    }
};

/*----------------------------------------------------------------------*/
void Model::setUniformTransform() {
    // get unifoem location
    unsigned int modelMatLoc = glGetUniformLocation(m_shaderProgram, "model");

    // set uniform
    glUniformMatrix4fv(modelMatLoc, 1, GL_FALSE, glm::value_ptr(m_model));
}

void Model::reSetTransform() {
    // reset transform matrices to 1.0f
    m_rotationMat = glm::mat4(1.0f);
    m_scaleMat = glm::mat4(1.0f);
    m_positionMat = glm::mat4(1.0f);

    // set transform
    m_rotationMat = glm::rotate(m_rotationMat, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    m_scaleMat = glm::scale(m_scaleMat, glm::vec3(1.0f, 1.0f, 1.0f));
    m_positionMat = glm::translate(m_positionMat, glm::vec3(0.0f, 0.0f, 0.0f));

    // calculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;

    // set transform uniform for shader
    setUniformTransform();
}

void Model::setRotation(float rotationDeg, glm::vec3 axes) {
    // reset rotation mat
    m_rotationMat = glm::mat4(1.0f);

    // set rotaion
    m_rotationMat = glm::rotate(m_rotationMat, glm::radians(rotationDeg), glm::normalize(axes));

    // recalculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;
};

void Model::setRotation(glm::quat quaternion) {
    // set rotaion
    m_rotationMat = glm::toMat4(quaternion);

    // recalculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;
};

void Model::setLookAt(glm::vec3 pos, glm::vec3 target, glm::vec3 up) {
    // set rotaion
    m_rotationMat = glm::lookAt(pos, target, up); // position, target and up vector

    // recalculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;
};

void Model::setScale(glm::vec3 _size) {
    // reset scale mat
    m_scaleMat = glm::mat4(1.0f);

    // set size
    m_scaleMat = glm::scale(m_scaleMat, _size);

    // recalculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;
};

void Model::setPosition(glm::vec3 _position) {
    // reset scale mat
    m_positionMat = glm::mat4(1.0f);

    // set position
    m_positionMat = glm::translate(m_positionMat, _position);

    // recalculate model matrix
    m_model = m_positionMat * m_rotationMat * m_scaleMat;
};

void Model::setPosition(float _x, float _y, float _z) {
    setPosition(glm::vec3(_x, _y, _z));
};
