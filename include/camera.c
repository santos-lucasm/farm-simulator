#include "camera.h"

Camera2D * create_camera()
{
   Camera2D * c = malloc(sizeof(Camera2D));
   c->target = (Vector2){0.0f, 0.0f};
   c->offset = (Vector2){SCREEN_W/2.0f, SCREEN_H/2.0f}; // centralizes target pixel
   c->rotation = 0.0f;
   c->zoom = 1.0f;
}

const bool entry_zoom_in(Camera2D * self)
{
   bool ret = false;

   if(NULL != self)
   {
      if(3.0f < self->zoom)
      {
         self->zoom = 3.0f;
         ret = false;
      }
      else if(3.0f == self->zoom)
      {
         ret = false;
      }
      else
      {
         self->zoom += GetFrameTime();
         ret = true;
      }
   }
   return ret;
}
