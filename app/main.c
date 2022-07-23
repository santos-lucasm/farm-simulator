#include <stdio.h>
#include "player.h"
#include "camera.h"
#include "world.h"

int main(void)
{ 
    InitWindow(SCREEN_W, SCREEN_H, "farm-simulator");
    SetTargetFPS(75);

    const Vector2 playerStartPos = (Vector2) {SCREEN_W/2, SCREEN_H/2};
    player_t * player = create_player(playerStartPos);
    world_camera_t * world_cam = create_world_camera(playerStartPos);

    while(!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawFPS(0, 0);
            BeginMode2D(*world_cam->camera);
                draw_grid();
                update_player(player);
                draw_player(player);
                update_camera(world_cam, player->pos);
            EndMode2D();

        EndDrawing();
    }

    destroy_world_camera(world_cam);
    destroy_player(player);

    CloseWindow();
    return 0;
}
