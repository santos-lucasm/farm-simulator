#include "world.h"
//------------------------------------------------------------------------------------
void draw_grid()
{
    Vector2 startPos = {0.0f, 0.0f};
    Vector2 endPos = {1024.0f, 0.0f};
    while(768.0f > endPos.y)
    {
        DrawLineV(startPos, endPos, PINK);
        startPos.y += 16.0f;
        endPos.y += 16.0f;
    }
}
//------------------------------------------------------------------------------------
