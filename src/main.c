#include <stdio.h>
#include "player.h"
#include "camera.h"

int main(void) {
 
   InitWindow(SCREEN_W, SCREEN_H, "Testing");
   SetTargetFPS(75);
   Image im = LoadImage("assets/vacaroxa/rpg-pack/chars/sensei/sensei.png");
   Texture2D texture = LoadTextureFromImage(im);
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

            DrawTextureEx(texture, (Vector2){0.0f, 0.0f}, 0.0f, 1.0f, WHITE);

         EndMode2D();
      EndDrawing();
   }

   CloseWindow();
   return 0;
}
