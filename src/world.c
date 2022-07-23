#include <stdlib.h>
#include "world.h"
//------------------------------------------------------------------------------------
world_t * create_world(const Vector2 size)
{
    world_t * world = malloc(sizeof(world_t));
    if(NULL != world)
    {
        world->size = size;

        world->grass = create_tile("../assets/gameboy/gb_tilesheet.png",
            (Vector2){352.0f, 192.f}, (Vector2){16.0f,  16.0f}, false);

        world->path = create_tile("../assets/gameboy/gb_tilesheet.png", 
            (Vector2){368.0f, 160.f}, (Vector2){16.0f,  16.0f}, false);
    }
    return world;
}
//------------------------------------------------------------------------------------
void destroy_world(world_t * self)
{
    UnloadTexture(self->grass.texture);
    UnloadTexture(self->path.texture); 
    free(self);
}
//------------------------------------------------------------------------------------
void draw_world(world_t * self)
{
    draw_grid(self, 16.0f);
    draw_grass(self, (Vector2) {0.0f, 0.0f});
}
//------------------------------------------------------------------------------------
void draw_grid(world_t * self, const float step)
{
    // Draw horizontal lines
    Vector2 startPos = (Vector2) {0.0f, 0.0f};
    Vector2 endPos = (Vector2) {self->size.x, 0.0f};
    while(self->size.y >= endPos.y)
    {
        DrawLineV(startPos, endPos, PINK);
        startPos.y += step;
        endPos.y += step;
    }

    // Draw vertical lines
    startPos = (Vector2) {0.0f, 0.0f};
    endPos = (Vector2) {0.0f, self->size.y};
    while(self->size.x >= endPos.x)
    {
        DrawLineV(startPos, endPos, PINK);
        startPos.x += step;
        endPos.x += step;
    }
}
//------------------------------------------------------------------------------------
void draw_grass(world_t * self, const Vector2 pos)
{
    if(NULL != self)
    {
        // Create rectangle that contains texture coordinates
        Rectangle source = {0};
        source.x = self->grass.texturePos.x;
        source.y = self->grass.texturePos.y;
        source.width = self->grass.size.x;
        source.height = self->grass.size.y;

        DrawTextureRec(self->grass.texture, source, pos, WHITE);
    }
}
//------------------------------------------------------------------------------------

