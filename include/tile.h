#pragma once
//------------------------------------------------------------------------------------
#include <raylib.h>
//------------------------------------------------------------------------------------
typedef struct
{
    Texture2D texture;
    Vector2 texturePos;
    Vector2 size;
    bool collision;
} tile_t;
//------------------------------------------------------------------------------------
/**
 * @brief Create a tile object
 * 
 * @param image_path    Tile texture will use this image base
 * @param texPos        Position in relation to texture 
 * @param size          Tile size in pixels
 * @param collision     FALSE if player can go through the tile
 * @return const tile_t Initialized tile
 */
const tile_t create_tile(const char * image_path, const Vector2 texPos,
    const Vector2 size, const bool collision);
//------------------------------------------------------------------------------------
