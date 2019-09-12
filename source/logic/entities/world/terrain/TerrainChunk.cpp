#include "TerrainChunk.hpp"

TerrainChunk::TerrainChunk(int x, int z) {
    // set grid pos
    m_gridPos = glm::vec2(x * nbrTiles * tileSize, z * nbrTiles * tileSize);

    // m_model.setPolygoneMode(GL_LINE);

    // generate mesh
    generateMesh();
};

/*-----------------------------------------------*/
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
    for (unsigned int i = 0, j = 0; i < numberIndecies; i += 6) {
        indecies[i + 0] = j + 0;
        indecies[i + 1] = j + 1;
        indecies[i + 2] = j + 2;

        indecies[i + 3] = j + 1;
        indecies[i + 4] = j + 3;
        indecies[i + 5] = j + 2;

        j += 4;
    }

    // load model vertecies
    m_model.loadVertices(indecies, numberIndecies, Material());

    // set position of the chunk
    m_model.setPosition(m_gridPos.x, 0.0f, m_gridPos.y);
};

/*-----------------------------------------------*/
void TerrainChunk::generateTile(int x, int z) {
    // set face color vertex attrib
    glm::vec3 color = Bioms::getColor(x * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y);
    // color = glm::vec3(
    //     static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
    //     static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
    //     static_cast<float>(rand()) / static_cast<float>(RAND_MAX)
    // );

    // add vertecies to model
    m_model.addVertex(
        getVertexPos(x, z),
        glm::vec2(0.0f, 0.0f),
        getVertexNormal(x, z),
        color
    );
    m_model.addVertex(
        getVertexPos(x + 1, z),
        glm::vec2(1.0f, 0.0f),
        getVertexNormal(x + 1, z),
        color
    );
    m_model.addVertex(
        getVertexPos(x, z + 1),
        glm::vec2(0.0f, 1.0f),
        getVertexNormal(x, z + 1),
        color
    );
    m_model.addVertex(
        getVertexPos(x + 1, z + 1),
        glm::vec2(1.0f, 1.0f),
        getVertexNormal(x + 1, z + 1),
        color
    );

    // create a terrain decoration
    addProps(x * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y);
}

glm::vec3 TerrainChunk::getVertexPos(int x, int z) {
    return glm::vec3(
        x * tileSize,
        Bioms::getHight(x * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y),
        z * tileSize
    );
};

glm::vec3 TerrainChunk::getVertexNormal(int x, int z) {
    // get nearby verticies height
    float H_Up, H_Down, H_Right, H_Left;

    H_Up = Bioms::getHight((x + 1) * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y);
    H_Down = Bioms::getHight((x - 1) * tileSize + m_gridPos.x, z * tileSize + m_gridPos.y);
    H_Right = Bioms::getHight(x * tileSize + m_gridPos.x, (z + 1) * tileSize + m_gridPos.y);
    H_Left = Bioms::getHight(x * tileSize + m_gridPos.x, (z - 1) * tileSize + m_gridPos.y);

    // calculate & return vertex normal
    return glm::normalize(glm::vec3(
        H_Left - H_Right,
        H_Down - H_Up,
        2.0f
    ));
};

/*-----------------------------------------------*/
void TerrainChunk::render() {
    m_model.render();

    for (int i = 0; i < m_trees.size(); i++)
        m_trees[i].render();

    for (int i = 0; i < m_grass.size(); i++)
        m_grass[i].render();
};

/*-----------------------------------------------*/
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
