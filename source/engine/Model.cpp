#include "Model.hpp"

Model::Model() {
    // gen VAO & assign to vao object member
    glGenVertexArrays(1, &VAO);
}

void Model::addVertex(glm::vec3 position, glm::vec4 color, glm::vec2 uv) {
    // create new Vertex object
    Vertex v(position, color, uv);

    // add vertex to model vertices
    m_vertices.push_back(v);
}

void Model::loadVertices() {
    // bind VAO for use
    glBindVertexArray(VAO);

    // create Vertex Buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // load vbo with data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);

    // handle data Vertex attribs
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0); // set position vertex attrib
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*3)); // set color vertex attrib
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*7)); // set color vertex attrib
    glEnableVertexAttribArray(2);

    // unbind used buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // pop all vertecies
    for (int i = 0; i < m_vertices.size(); i++) {
        m_vertices.pop_back();
    }
}

void Model::setIndecies(unsigned int _indecies[], unsigned int _numberIndecies) {
    m_numberIndecies = _numberIndecies;

    // bind VAO for use
    glBindVertexArray(VAO);

    // create Eelement Buffer object
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    // load ebo with data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _numberIndecies, &_indecies[0], GL_STATIC_DRAW);

    // unbind used buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Model::setAlbedoTexture(std::string filePath) {
    // bind model VAO for use
    glBindVertexArray(VAO);

    // create gl texture object
    glGenTextures(1, &albedo);
    glBindTexture(GL_TEXTURE_2D, albedo);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load texture data
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Warning: Failed to load texture \"" << filePath << "\"." << std::endl;
    }
    stbi_image_free(data);

    // activate shader attribute texture 0 for albedo
    glActiveTexture(GL_TEXTURE0);
};


void Model::setShaderProgram(unsigned int _shaderProgram) {
    m_shaderProgram = _shaderProgram;
}

void Model::setPolygoneMode(unsigned int _polygoneMode) {
    m_polygoneMode = _polygoneMode;
}

void Model::render() {
    // set model shader
    glUseProgram(m_shaderProgram);

    // set transforms uniform
    setUniformTransform();

    // set openGL polygone mode
    glPolygonMode(GL_FRONT_AND_BACK, m_polygoneMode);

    // bind albedo texture
    glBindTexture(GL_TEXTURE_2D, albedo);

    // bind model vao
    glBindVertexArray(VAO);

    // draw model
    glDrawElements(GL_TRIANGLES, m_numberIndecies, GL_UNSIGNED_INT, nullptr);
}

/*----------------------------------------------------------------------*/
void Model::setUniformTransform() {
    // set model shader
    // glUseProgram(m_shaderProgram); // FIXME: alredy seten on render() methode

    unsigned int modelMatLoc = glGetUniformLocation(m_shaderProgram, "model");
    glUniformMatrix4fv(modelMatLoc, 1, GL_FALSE, glm::value_ptr(m_model));
}

void Model::setTransform(glm::vec3 _position, glm::vec3 _size) {
    // reset transform matrices to 1.0f
    m_model = glm::mat4(1.0f);

    // set transform
    m_model = glm::rotate(m_model, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    m_model = glm::scale(m_model, _size);
    m_model = glm::translate(m_model, _position);

    // set transform uniform for shader
    setUniformTransform();
}

 // FIXME: resets m_model matrix
void Model::setPos(glm::vec3 _position) {
    m_model = glm::mat4(1.0f);

    // set position
    m_model = glm::translate(m_model, _position);

    // set transform uniform for shader
    setUniformTransform();
};

 // FIXME: resets m_model matrix
void Model::setRot(float rotation, glm::vec3 axes) {
    m_model = glm::mat4(1.0f);

    // set rotaion
    m_model = glm::rotate(m_model, glm::radians(rotation), axes);

    // set transform uniform for shader
    setUniformTransform();
};

 // FIXME: resets m_model matrix
void Model::setScale(glm::vec3 _size) {
    m_model = glm::mat4(1.0f);

    // set size
    m_model = glm::scale(m_model, _size);

    // set transform uniform for shader
    setUniformTransform();
};
