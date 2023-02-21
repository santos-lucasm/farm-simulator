#include <stdlib.h>
#include "player.h"
//------------------------------------------------------------------------------------
player_t * create_player(const Vector2 startPos)
{
    //TODO: Verify startPos boundaries
    //TODO: Log error on malloc
    player_t * p = (player_t *) malloc( sizeof(player_t) );

    if(NULL != p)
    {
        p->pos = startPos;
        p->speed = 50.0f;
        p->color = RED;
        p->tile = create_tile("../assets/gameboy/gb_player.png",
                                (Vector2) {0.0f, 0.0f},
                                (Vector2) {16.0f, 16.0f},
                                true
                            );
    }
    return p;
}
//------------------------------------------------------------------------------------
void destroy_player(player_t * self)
{
    //TODO: Verify self ref
    //TODO: Rename this function or change it's context
    UnloadTexture(self->tile.texture);
    free(self);
}
//------------------------------------------------------------------------------------
void update_player(player_t * self)
{
    //TODO: Verify self ref

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
    //TODO: Verify self ref
    //TODO: Log drawing error
    if(NULL != self)
    {
        // Create rectangle that contains texture coordinates
        Rectangle source = {0};
        source.x = self->tile.texturePos.x;
        source.y = self->tile.texturePos.y;
        source.width = self->tile.size.x;
        source.height = self->tile.size.y;

        DrawTextureRec(self->tile.texture, source, self->pos, WHITE);
    }
}
//------------------------------------------------------------------------------------
