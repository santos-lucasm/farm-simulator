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
/*! @brief init player_t
    @return Pointer to created obj, NULL if failed
*/
player_t * create_player();
//------------------------------------------------------------------------------------
/*! @brief deallocates obj memory
    @param self pointer to itself
*/
void destroy_player(player_t * self);
//------------------------------------------------------------------------------------
void update_player(player_t * self);
//------------------------------------------------------------------------------------
void draw_player(player_t * self);
//------------------------------------------------------------------------------------
