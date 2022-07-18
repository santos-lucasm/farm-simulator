#include <stdlib.h>
#include "player.h"

player_t* create_player()
{
   player_t * p = malloc(sizeof(player_t));
   p->pos = (Vector2) {0.0f, 0.0f};
   p->width = 20.f;
   p->height = 30.f;
   p->speed = 10.0f;
   p->color = RED;
   return p;
}

void update_player(player_t * self)
{
  self->pos.x = self->pos.x + self->speed  * GetFrameTime();
}

void draw_player(player_t * self) 
{
   if(NULL != self)
   {
      DrawRectangle(
         self->pos.x,
         self->pos.y,
         self->width,
         self->height,
         self->color
      );
   }   
}
