#include "world.h"
//------------------------------------------------------------------------------------
void draw_grid()
{
    float step = 16.0f;

    // Draw horizontal lines
    Vector2 startPos = (Vector2) {0.0f, 0.0f};
    Vector2 endPos = (Vector2) {WORLD_WIDTH, 0.0f};
    while(WORLD_HEIGHT >= endPos.y)
    {
        DrawLineV(startPos, endPos, PINK);
        startPos.y += step;
        endPos.y += step;
    }

    // Draw vertical lines
    startPos = (Vector2) {0.0f, 0.0f};
    endPos = (Vector2) {0.0f, WORLD_HEIGHT};
    while(WORLD_WIDTH >= endPos.x)
    {
        DrawLineV(startPos, endPos, PINK);
        startPos.x += step;
        endPos.x += step;
    }
}
//------------------------------------------------------------------------------------
