#include <stdio.h>
#include "player.h"
#include "camera.h"

int main(void) {
 
   InitWindow(SCREEN_W, SCREEN_H, "farm-simulator");
   SetTargetFPS(75);

   player_t * player = create_player();
   world_camera_t * world_cam = create_world_camera();

   while(!WindowShouldClose())
   {
      BeginDrawing();
         ClearBackground(RAYWHITE);
         DrawFPS(0, 0);
         BeginMode2D(*world_cam->camera);
            update_player(player);
            draw_player(player);
            update_camera(world_cam);
         EndMode2D();
      EndDrawing();
   }

   destroy_world_camera(world_cam);
   free(player);

   CloseWindow();
   return 0;
}
