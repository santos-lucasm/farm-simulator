#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "world.h"
//------------------------------------------------------------------------------------
world_t * create_world(const Vector2 size)
{
    world_t * world = malloc(sizeof(world_t));
    if(NULL != world)
    {
        world->size = size;
        world->n_rows = size.x/16;
        world->n_columns = size.y/16;

        world->grid = (int **)malloc(world->n_rows * sizeof(int*));
        for(int i = 0; i < world->n_rows; i++)
        {
            world->grid[i] = (int *)malloc(world->n_columns * sizeof(int));
        }
        
        if(NULL != world->grid)
        {
            world->grass = create_tile("../assets/gameboy/gb_tilesheet.png",
                (Vector2){352.0f, 192.f}, (Vector2){16.0f,  16.0f}, false);

            world->path = create_tile("../assets/gameboy/gb_tilesheet.png", 
                (Vector2){336.0f, 160.f}, (Vector2){16.0f,  16.0f}, false);

            init_world(world);
        }
        else
        {
            free(world);
        }
    }
    return world;
}
//------------------------------------------------------------------------------------
void destroy_world(world_t * self)
{
    UnloadTexture(self->grass.texture);
    UnloadTexture(self->path.texture);

    // Deallocated grid
    for(int i = 0; i < self->n_rows; i++)
    {
        free(self->grid[i]);
    }
    free(self->grid);

    free(self);
}
//------------------------------------------------------------------------------------
void init_world(world_t * self)
{
    srand(time(NULL));
    for(int i = 0; i < self->n_rows; i++)
    {
        for(int j = 0; j < self->n_columns; j++)
        {
            self->grid[i][j] = generate_tile();
        }
    }
}
//------------------------------------------------------------------------------------
int generate_tile()
{
    return rand() % 2;
}
//------------------------------------------------------------------------------------
void draw_world(world_t * self)
{
    for(int i = 0; i < self->n_rows; ++i)
    {
        for(int j = 0; j < self->n_columns; ++j)
        {
            if(1 == self->grid[i][j])
            {
                draw_tile(self->grass, (Vector2) {i * self->grass.size.x, j * self->grass.size.y});
            }
            else if(0 == self->grid[i][j])
            {
                draw_tile(self->path, (Vector2) {i * self->path.size.x, j * self->path.size.y});
            }
        }
    }
    draw_grid(self, 16.0f);
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
void draw_tile(tile_t tile, const Vector2 pos)
{
    //TODO: Verify pos boundaries

    // Create rectangle that contains texture coordinates
    Rectangle source = {0};
    source.x = tile.texturePos.x;
    source.y = tile.texturePos.y;
    source.width = tile.size.x;
    source.height = tile.size.y;

    DrawTextureRec(tile.texture, source, pos, WHITE);
}
//------------------------------------------------------------------------------------

