
#include "CreateBackground.hpp"

int createBackground(VertexArray& r_VA, IntRect arena) {
    // Anything we do to r_VA we are really doing to background (in the main function)

    // How big is each tile/texture?
    const int TILE_SIZE = 50;
    const int TILE_TYPES = 3;
    const int VERTS_IN_QUAD = 4;
    int worldWidth = arena.width / TILE_SIZE;
    int worldHeight = arena.height / TILE_SIZE;

    // What types of primitive are we using?
    r_VA.setPrimitiveType(Quads);

    // Set the size of the vertex array
    r_VA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

    // Start at the beginning of the vertex array
    int currentVertex = 0;

    for (int w = 0; w < worldWidth; w++) {
        for (int h = 0; h < worldHeight; h++) {
            // Position each vertes in the current quad
            r_VA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);

            r_VA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

            r_VA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

            r_VA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

            // Define the position in the texture for current quad, Either grass, stone, bush or wall
            if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1) {
                // Use the wall texture
                r_VA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

                r_VA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

                r_VA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);

                r_VA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
            }
            else {
                // Use a random floor texture
                srand((int)time(0) + h * w - h);
                // mOrG = Mud or grass
                int mOrG = (rand() % TILE_TYPES);
                int verticalOffset = mOrG * TILE_SIZE;
                r_VA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);

                r_VA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);

                r_VA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

                r_VA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
            }

            // Position ready for the next four verticies
            currentVertex = currentVertex + VERTS_IN_QUAD;
        }
    }

    return TILE_SIZE;
}