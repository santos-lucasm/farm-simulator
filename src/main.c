#include <stdio.h>
#include "player.h"
#include "camera.h"

int main(void) {
 
   InitWindow(SCREEN_W, SCREEN_H, "Testing");
   SetTargetFPS(75);

   player_t * player = create_player();
   Camera2D * camera = create_camera();

   bool zoom_in_anim = true;
   while(!WindowShouldClose())
   {
      if(zoom_in_anim)
         zoom_in_anim = entry_zoom_in(camera);

      BeginDrawing();
         ClearBackground(RAYWHITE);
         DrawFPS(0, 0);
         BeginMode2D(*camera);
            update_player(player);
            draw_player(player);
         EndMode2D();
      EndDrawing();
   }

   free(camera);
   free(player);

   CloseWindow();
   return 0;
}
