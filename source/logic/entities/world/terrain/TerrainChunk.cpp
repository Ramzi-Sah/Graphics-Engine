#include "TerrainChunk.hpp"

TerrainChunk::TerrainChunk(int x, int z, float lod) {
    // set pos
    m_pos = glm::vec2(x * nbrTiles * tileSize, z * nbrTiles * tileSize);

    // set chunk's lod
    m_LOD = lod;

    // DEBUG: set polygone mod to GL_LINE
    // m_model.setPolygoneMode(GL_LINE);

    // use terrain shader
    m_model.setShaderProgram("terrain");

    // DEBUG: random color
    m_chunkColor = glm::vec3(
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX)
    );

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
        };
    };

    // // generate vertecies with lod
    // for (int x = 0; x < nbrTiles / m_LOD; x++) {
    //     for (int z = 0; z < nbrTiles / m_LOD; z++) {
    //         // generate faces
    //         // generateTile(x, z);
    //         if (m_LOD == 1)
    //             generateTile(x, z);
    //         if (m_LOD == 2)
    //             generateTile(x + m_LOD * x / 2, z + m_LOD * z / 2);
    //     };
    // };

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
    };

    // load model vertecies
    m_model.loadVertices(indecies, numberIndecies, Material());

    // set position of the chunk
    m_model.setPosition(m_pos.x, 0.0f, m_pos.y);
};

/*-----------------------------------------------*/
void TerrainChunk::generateTile(int x, int z) {
    // DEBUG: chunk color
    // glm::vec3 color = m_chunkColor;

    // DEBUG: random color
    glm::vec3 color(
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX)/2 + m_chunkColor.r/2,
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX)/2 + m_chunkColor.g/2,
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX)/2 + m_chunkColor.b/2
    );

    // DEBUG: white color
    // glm::vec3 color(1.0f, 1.0f, 1.0f);

    // add vertecies to model
    m_model.addVertex(
        getVertexPos(x, z),
        glm::vec2(0.0f, 0.0f),
        getVertexNormal(x, z),
        color,
        Bioms::getGrassValue(x * tileSize + m_pos.x, z * tileSize + m_pos.y)
    );
    m_model.addVertex(
        getVertexPos(x + m_LOD, z),
        glm::vec2(1.0f, 0.0f),
        getVertexNormal(x + m_LOD, z),
        color,
        Bioms::getGrassValue((x + m_LOD) * tileSize + m_pos.x, z * tileSize + m_pos.y)
    );
    m_model.addVertex(
        getVertexPos(x, z + m_LOD),
        glm::vec2(0.0f, 1.0f),
        getVertexNormal(x, z + m_LOD),
        color,
        Bioms::getGrassValue(x * tileSize + m_pos.x, (z + m_LOD) * tileSize + m_pos.y)
    );
    m_model.addVertex(
        getVertexPos(x + m_LOD, z + m_LOD),
        glm::vec2(1.0f, 1.0f),
        getVertexNormal(x + m_LOD, z + m_LOD),
        color,
        Bioms::getGrassValue((x + m_LOD) * tileSize + m_pos.x, (z + m_LOD) * tileSize + m_pos.y)
    );

    // create a terrain decoration
    addProps(x * tileSize + m_pos.x, z * tileSize + m_pos.y);
};

glm::vec3 TerrainChunk::getVertexPos(int x, int z) {
    // calculate vertex model pos
    float posX, posZ;
    posX = x * tileSize;
    posZ = z * tileSize;

    // return vertex pos attrib
    return glm::vec3(
        posX,
        Bioms::getHight(posX + m_pos.x, posZ + m_pos.y),
        posZ
    );
};

glm::vec3 TerrainChunk::getVertexNormal(int x, int z) {
    // get nearby verticies height
    float H_Up, H_Down, H_Right, H_Left;

    H_Up = Bioms::getHight((x + 1) * tileSize + m_pos.x, z * tileSize + m_pos.y);
    H_Down = Bioms::getHight((x - 1) * tileSize + m_pos.x, z * tileSize + m_pos.y);
    H_Right = Bioms::getHight(x * tileSize + m_pos.x, (z + 1) * tileSize + m_pos.y);
    H_Left = Bioms::getHight(x * tileSize + m_pos.x, (z - 1) * tileSize + m_pos.y);

    // calculate & return vertex normal
    return glm::normalize(glm::vec3(
        H_Down - H_Up,
        H_Left - H_Right,
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
    };
};
