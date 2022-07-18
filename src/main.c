#include <stdio.h>
#include "player.h"
#include "camera.h"

int main(void) {
 
   InitWindow(SCREEN_W, SCREEN_H, "Testing");
   SetTargetFPS(75);
   
   player_t * player = create_player();
   Camera2D * camera = create_camera();

   while(!WindowShouldClose())
   {
      BeginDrawing();
         ClearBackground(RAYWHITE);
         DrawFPS(0, 0);
         BeginMode2D(*camera);
            update_player(player);
            draw_player(player);
         EndMode2D();
      EndDrawing();
   }

   CloseWindow();
   return 0;
}
