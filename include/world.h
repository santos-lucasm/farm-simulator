#pragma once
//------------------------------------------------------------------------------------
#include <raylib.h>
#include "tile.h"
//------------------------------------------------------------------------------------
typedef struct
{
    Vector2 size;
    tile_t grass;
    tile_t path;
    int n_columns;
    int n_rows;
    int ** grid;
} world_t;
//------------------------------------------------------------------------------------
/**
 * @brief Create a world object
 * 
 * @param size      World size
 * @return world_t* Ref to created object, NULL if failed
 * 
 * TODO: Pass configuration path argument, to somehow generate different worlds
 * based on the configuration
 */
world_t * create_world(const Vector2 size);
//------------------------------------------------------------------------------------
/**
 * @brief Handles memory allocation and unload textures
 * 
 * @param self World to be destroyed
 */
void destroy_world(world_t * self);
//------------------------------------------------------------------------------------
void init_world(world_t * self);
//------------------------------------------------------------------------------------
int generate_tile();
//------------------------------------------------------------------------------------
/**
 * @brief Draw world in screen
 * 
 * @param self World to be draw
 */
void draw_world(world_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Draw grid of world size
 * 
 * @param self  Use world size
 * @param step  Space size in x and y between grid lines
 */
void draw_grid(world_t * self, const float step);
//------------------------------------------------------------------------------------
/**
 * @brief Draw grass tile stored in world
 * 
 * @param self  Use world stored grass tile
 * @param pos   Tile draw position
 */
void draw_tile(tile_t tile, const Vector2 pos);
//------------------------------------------------------------------------------------
