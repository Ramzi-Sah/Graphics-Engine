#ifndef SAH_TERRAINCONFIG
#define SAH_TERRAINCONFIG

// terrain params
static const int nbrTerrainChunks = 15; /* needs to be n * 2 + 1 */ // number of terrain chunks
static const int nbrTiles = 14; /* needs to be n * 2 */ // number of tiles in a terrain chunk
static const float tileSize = 1.0f; // square tile size

// height map
static const float heightMapSizeMultiplayer = 5.0f; // height map resize
static const float GridSize = 1.0f; // for raycast clipping
static const float AMPLITUDE = 100.0f;

// perlin noise
static const unsigned int SEED = 12345;
static const float FREQUANCY = 0.02f;
static const float ELEVATION = 1.0f;

#endif
