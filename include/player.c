#include <stdlib.h>
#include "player.h"

player_t* create_player()
{
   player_t * p = malloc(sizeof(player_t));
   p->pos = (Vector2) {0.0f, 0.0f};
   p->width = 20.f;
   p->height = 30.f;
   p->color = RED;
   return p;
}

Vector2 player_pos(player_t * self)
{
   return self->pos;
}

float player_width(player_t * self)
{
   return self->width;
}

float player_height(player_t * self)
{
   return self->height;
}

Color player_color(player_t * self)
{
   return self->color;
}

void draw_player(player_t * self) 
{
   if(NULL != self)
   {
      DrawRectangle(
         0,
         0,
         player_width (self),
         player_height(self),
         player_color (self)
      );
   }   
}
