#pragma once

#include <raylib.h>

typedef struct
{
   Vector2 pos;
   float width;
   float height;
   float speed;
   Color color;
   Texture2D texture;
} player_t;

player_t * create_player();

void update_player(player_t * self);

void draw_player(player_t * self);
