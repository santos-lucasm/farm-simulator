#include <stdio.h>
#include "player.h"

#define SCREEN_W 800
#define SCREEN_H 800

int main(void) {
   
   printf("Starting...\n");
 
   InitWindow(SCREEN_W, SCREEN_H, "Testing");
   SetTargetFPS(75);
   
   player_t * player = create_player();

   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawFPS(0, 0);
      draw_player(player);
      EndDrawing();
   }

   CloseWindow();
   return 0;
}
