#ifndef SAH_TERRAINCHUNKMODEL
#define SAH_TERRAINCHUNKMODEL

#include "../../../../engine/Model.hpp"

struct Vertex_terrain {
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;
    glm::vec3 color;

    float grass_val;

    Vertex_terrain(glm::vec3 _position, glm::vec2 _uv, glm::vec3 _normal, glm::vec3 _color, float _grass_val) {
        position = _position;
        uv = _uv;
        normal = _normal;
        color = _color;
        grass_val = _grass_val;
    }
};

class TerrainChunkModel : public Model{

    // terrain verticies
    std::vector<Vertex_terrain> m_vertices;

public:
    void addVertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal, glm::vec3 color, float grass_val) {
        // create new Vertex object
        Vertex_terrain v(position, uv, normal, color, grass_val);

        // add vertex to model vertices
        m_vertices.push_back(v);
    }

    void loadVertices(unsigned int _indecies[], unsigned int _numberIndecies, Material _material) {
        // instinitiate a mesh group
        MeshGroup meshGroup;

        // gen VAO & bind it for use
        glGenVertexArrays(1, &meshGroup.VAO);
        glBindVertexArray(meshGroup.VAO);

        // create Vertex Buffer object
        unsigned int VBO;
        glGenBuffers(1, &VBO);

        // load vbo with data
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_terrain) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);

        // get model size Bytes for monitoring
        m_modelSize += sizeof(Vertex_terrain) * m_vertices.size();

        // handle data Vertex attribs
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_terrain), (const void*)0); // set position vertex attrib
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_terrain), (const void*)(sizeof(float)*3)); // set uv vertex attrib
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_terrain), (const void*)(sizeof(float)*5)); // set normal vertex attrib
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_terrain), (const void*)(sizeof(float)*8)); // set color vertex attrib
        glEnableVertexAttribArray(3);

        // set textures value vertex attrib
        glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex_terrain), (const void*)(sizeof(float)*11));
        glEnableVertexAttribArray(4);

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
    };
};

#endif
