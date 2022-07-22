#include <stdlib.h>
#include "player.h"

player_t * create_player()
{
   player_t * p = malloc(sizeof(player_t));

   if(NULL != p)
   {
      p->pos = (Vector2) {0.0f, 0.0f};
      p->width = 20.f;
      p->height = 30.f;
      p->speed = 50.0f;
      p->color = RED;

      Image im = LoadImage("assets/gameboy/gb_player.png");
      p->texture = LoadTextureFromImage(im);
   }
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
      Rectangle source = {0};
      source.width = 16;
      source.height = 16;
      DrawTextureRec(self->texture, source,
         (Vector2){self->pos.x, self->pos.y}, WHITE);
   }   
}
