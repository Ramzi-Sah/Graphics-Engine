#include "TerrainChunk.hpp"

const int TerrainChunk::nbrChunks = 10;
const int TerrainChunk::nbrTiles = 5;
const float TerrainChunk::tileSize = 1.0f;

TerrainChunk::TerrainChunk(float gridX, float gridZ) {
    m_position = glm::vec2(gridX * nbrTiles * tileSize, gridZ * nbrTiles * tileSize);
    generateMesh();
};

// FIXME: use only 1 vertex
void TerrainChunk::generateMesh() {
    float tileSize_2 = tileSize/2;
    for (int x = 0; x < nbrTiles; x++) {
        for (int z = 0; z < nbrTiles; z++) {

            // set vertecies
            model.addVertex(
                glm::vec3(x * tileSize_2 + tileSize_2, 0.0f, z * tileSize_2),
                glm::vec2(1.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
            );
            model.addVertex(
                glm::vec3(x * tileSize_2 + tileSize_2, 0.0f, z * tileSize_2 + tileSize_2),
                glm::vec2(1.0f, 1.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
            );
            model.addVertex(
                glm::vec3(x * tileSize_2, 0.0f, z * tileSize_2 + tileSize_2),
                glm::vec2(0.0f, 1.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
            );
            model.addVertex(
                glm::vec3(x * tileSize_2, 0.0f, z * tileSize_2),
                glm::vec2(0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
            );
        }
    }

    // set Element Buffer Object
    int squareNbrOfVertices = 4;
    int squareNbrOfIndecies = 6;
    unsigned int nbrOfIndecies = squareNbrOfIndecies * pow(nbrTiles, 2);
    unsigned int indeces[nbrOfIndecies];
    unsigned int squareIndeces[squareNbrOfIndecies] = {
        0, 1, 2,
        2, 3, 0
    };

    for (unsigned int i = 0; i < pow(nbrTiles, 2); i++) {
        for (int j = 0; j < squareNbrOfIndecies; j++) {
            indeces[j+i*squareNbrOfIndecies] = squareIndeces[j] + i*squareNbrOfVertices;
        }
    }

    // load Vertex Buffer Object
    model.loadVertices(indeces, nbrOfIndecies, Material());

    // set pos
    model.setTransform(glm::vec3(m_position.x/2, 0.0f, m_position.y/2), glm::vec3(1.0f, 1.0f, 1.0f));

    // set material
    // random colors
    glm::vec4 randomColor(static_cast<float>(rand()) / static_cast<float>(RAND_MAX), static_cast<float>(rand()) / static_cast<float>(RAND_MAX), static_cast<float>(rand()) / static_cast<float>(RAND_MAX), 1.0f);
    model.setDefuse(randomColor);
    model.setAlbedoTexture("wall");

};
