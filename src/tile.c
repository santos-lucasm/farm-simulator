#include "tile.h"
//------------------------------------------------------------------------------------
const tile_t create_tile(const char * image_path, const Vector2 texPos,
    const Vector2 size, const bool collision)
{
    Image im = LoadImage(image_path);
    return (tile_t) {LoadTextureFromImage(im), texPos, size, collision};
}
//------------------------------------------------------------------------------------
