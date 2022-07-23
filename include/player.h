#pragma once
//------------------------------------------------------------------------------------
#include <raylib.h>
#include "tile.h"
//------------------------------------------------------------------------------------
typedef struct
{
    Vector2 pos;
    float speed;
    Color color;
    tile_t tile;
} player_t;
//------------------------------------------------------------------------------------
/**
 * @brief Create a player object and inits it
 * 
 * @param startPos      Initial position of player
 * @return player_t*    Ref to the created object, NULL if failed
 */
player_t * create_player(const Vector2 startPos);
//------------------------------------------------------------------------------------
/**
 * @brief Handle player dynamic memory allocation
 * 
 * @param self Player to be destroyed
 */
void destroy_player(player_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Update player position and states each frame
 * 
 * @param self Player to be updated
 */
void update_player(player_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Called each frame to redraw player object
 * 
 * @param self Player to be draw
 */
void draw_player(player_t * self);
//------------------------------------------------------------------------------------
