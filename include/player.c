#include <stdlib.h>
#include "player.h"

player_t* create_player()
{
   player_t * p = malloc(sizeof(player_t));
   p->pos = (Vector2) {0.0f, 0.0f};
   p->width = 20.f;
   p->height = 30.f;
   p->speed = 50.0f;
   p->color = RED;
   return p;
}

void update_player(player_t * self)
{
   if(IsKeyDown(KEY_RIGHT))
      self->pos.x += self->speed * GetFrameTime();
   if(IsKeyDown(KEY_LEFT))
      self->pos.x -= self->speed * GetFrameTime();
   if(IsKeyDown(KEY_UP))
      self->pos.y -= self->speed * GetFrameTime();
   if(IsKeyDown(KEY_DOWN))
      self->pos.y += self->speed * GetFrameTime();
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
