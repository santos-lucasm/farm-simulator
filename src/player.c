#include <stdlib.h>
#include "player.h"
//------------------------------------------------------------------------------------
player_t * create_player(const Vector2 startPos)
{
    player_t * p = malloc(sizeof(player_t));

    if(NULL != p)
    {
        p->pos = startPos;
        p->width = 16.0f;
        p->height = 16.0f;
        p->speed = 50.0f;
        p->color = RED;

        Image im = LoadImage("../assets/gameboy/gb_player.png");
        p->texture = LoadTextureFromImage(im);
    }
    return p;
}
//------------------------------------------------------------------------------------
void destroy_player(player_t * self)
{
    free(self);
}
//------------------------------------------------------------------------------------
void update_player(player_t * self)
{
    // Verify running state
    if(IsKeyPressed(KEY_LEFT_SHIFT))
        self->speed *= 2.0f;
    if(IsKeyReleased(KEY_LEFT_SHIFT))
        self->speed /= 2.0f;

    // Verify direction
    if(IsKeyDown(KEY_RIGHT))
        self->pos.x += self->speed * GetFrameTime();
    if(IsKeyDown(KEY_LEFT))
        self->pos.x -= self->speed * GetFrameTime();
    if(IsKeyDown(KEY_UP))
        self->pos.y -= self->speed * GetFrameTime();
    if(IsKeyDown(KEY_DOWN))
        self->pos.y += self->speed * GetFrameTime();
}
//------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------
