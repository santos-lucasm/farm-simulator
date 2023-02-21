#include "camera.h"
//------------------------------------------------------------------------------------
world_camera_t * create_world_camera(const Vector2 targetPos)
{
    world_camera_t * wc = (world_camera_t *) malloc( sizeof(world_camera_t) );
    if(NULL != wc)
    {
        wc->camera = create2D_camera(targetPos);
        wc->entryZoomIn = true;
    }
    return wc;
}
//------------------------------------------------------------------------------------
void destroy_world_camera(world_camera_t * self)
{
    free(self->camera);
    free(self);
}
//------------------------------------------------------------------------------------
Camera2D * create2D_camera(const Vector2 targetPos)
{
    Camera2D * c = (Camera2D *) malloc( sizeof(Camera2D) );
    if(NULL != c)
    {
        c->target = targetPos;
        c->offset = (Vector2){SCREEN_W/2.0f, SCREEN_H/2.0f}; // centralizes target pixel
        c->rotation = 0.0f;
        c->zoom = 1.0f;
    }
    return c;
}
//------------------------------------------------------------------------------------
void update_camera(world_camera_t * self, const Vector2 targetPos)
{
    if(NULL != self)
    {
        if(self->entryZoomIn)
        {
            event_entry_zoomIn(self);
        }
        self->camera->target = targetPos;
    }
}
//------------------------------------------------------------------------------------
void event_entry_zoomIn(world_camera_t * self)
{
    if(3.0f <= self->camera->zoom)
    {
        self->camera->zoom = 3.0f;
        self->entryZoomIn = false;
    }
    else
    {
        self->camera->zoom += GetFrameTime();
    }
}
//------------------------------------------------------------------------------------
