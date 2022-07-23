#pragma once
//------------------------------------------------------------------------------------
#include <raylib.h>
//------------------------------------------------------------------------------------
typedef struct
{
    Vector2 pos;
    float width;
    float height;
    float speed;
    Color color;
    Texture2D texture;
} player_t;
//------------------------------------------------------------------------------------
/**
 * @brief Create a player object and inits it
 * 
 * @param startPos initial position of player
 * @return player_t* ref to the created instance, NULL if failed
 */
player_t * create_player(const Vector2 startPos);
//------------------------------------------------------------------------------------
/**
 * @brief Handle player dynamic memory allocation
 * 
 * @param self player to be destroyed
 */
void destroy_player(player_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Update player position and states each frame
 * 
 * @param self player to be updated
 */
void update_player(player_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Called each frame to redraw player object
 * 
 * @param self player to be draw
 */
void draw_player(player_t * self);
//------------------------------------------------------------------------------------
