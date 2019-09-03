#include "TerrainChunk.hpp"

TerrainChunk::TerrainChunk(int x, int z) {
    // set grid pos
    m_gridPos = glm::vec2(x * nbrTiles * tileSize, z * nbrTiles * tileSize);

    // generate mesh
    generateMesh();
};

void TerrainChunk::generateMesh() {
    // generate vertecies
    for (int x = 0; x < nbrTiles; x++) {
        for (int z = 0; z < nbrTiles; z++) {
            // generate faces
            generateTile(x, z);
        }
    }

    // calculate faces indecies
    unsigned int numberIndecies = pow(nbrTiles, 2) * 3 * 2; // nbr of tiles each tile have 2 triangles each triangle have 3 vertecies
    unsigned int indecies[numberIndecies];
    for (int i = 0; i < numberIndecies; i++) {
        indecies[i] = i;
    }

    // load model vertecies
    m_model.loadVertices(indecies, numberIndecies, Material());

    // set position of the chunk
    m_model.setPosition(m_gridPos.x, 0.0f, m_gridPos.y);
};

void TerrainChunk::generateTile(int x, int z) {
    // vertex attribs
    glm::vec3 v1, v2, v3, normal, color;

    // triangel 1
    // calculate vertecies attribs & color
    v1 = glm::vec3(x * tileSize, Bioms::getHight(x * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y), z * tileSize);
    v2 = glm::vec3((x + 1) * tileSize, Bioms::getHight((x + 1) * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y), z * tileSize);
    v3 = glm::vec3(x * tileSize, Bioms::getHight(x * tileSize + m_gridPos.x, (z + 1) * tileSize + m_gridPos.y), (z + 1) * tileSize);

    // calculate face normal
    normal = glm::normalize(glm::cross(v3 - v1, v2 - v1));
    color = Bioms::getColor(v1.x + m_gridPos.x, v1.z + m_gridPos.y);

    // add vertecies to model
    m_model.addVertex(
        v1,
        glm::vec2(0.0f, 0.0f),
        normal,
        color
    );
    m_model.addVertex(
        v2,
        glm::vec2(1.0f, 0.0f),
        normal,
        color
    );
    m_model.addVertex(
        v3,
        glm::vec2(0.0f, 1.0f),
        normal,
        color
    );

    // triangel 2
    // calculate face normal
    v1 = glm::vec3((x + 1) * tileSize, Bioms::getHight((x + 1) * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y), z * tileSize);
    v2 = glm::vec3((x + 1) * tileSize, Bioms::getHight((x + 1) * tileSize + m_gridPos.x, (z + 1) * tileSize + m_gridPos.y), (z + 1) * tileSize);
    v3 = glm::vec3(x * tileSize, Bioms::getHight(x * tileSize + m_gridPos.x, (z + 1) * tileSize + m_gridPos.y), (z + 1) * tileSize);

    // calculate face normal & color
    normal = glm::normalize(glm::cross(v3 - v1, v2 - v1));
    color = Bioms::getColor(v1.x + m_gridPos.x, v1.z + m_gridPos.y);

    m_model.addVertex(
        v1,
        glm::vec2(1.0f, 0.0f),
        normal,
        color
    );
    m_model.addVertex(
        v2,
        glm::vec2(1.0f, 1.0f),
        normal,
        color
    );
    m_model.addVertex(
        v3,
        glm::vec2(0.0f, 1.0f),
        normal,
        color
    );

    addProps(v1.x + m_gridPos.x, v1.z + m_gridPos.y);
}

void TerrainChunk::render() {
    m_model.render();

    for (int i = 0; i < m_trees.size(); i++)
        m_trees[i].render();

    for (int i = 0; i < m_grass.size(); i++)
        m_grass[i].render();
};

void TerrainChunk::addProps(float x, float z) {
    // populate tile
    if (Bioms::getTree(x, z)) {
        // instinitiate a tree object
        Tree tree;

        // set it's pos
        tree.setPosition(x, Bioms::getHight(x, z), z);

        // set it's rotation
        tree.setRotation(rand() % 360, glm::vec3(0.0f, 1.0f, 0.0f));

        // push it to trees list
        m_trees.push_back(tree);

    } else if (Bioms::getGrass(x, z)) {
        // instinitiate a grass object
        Grass grass;

        // set it's pos
        grass.setPosition(x, Bioms::getHight(x, z), z);

        // set it's rotation
        grass.setRotation(rand() % 360, glm::vec3(0.0f, 1.0f, 0.0f));

        // push it to trees list
        m_grass.push_back(grass);
    }
};
