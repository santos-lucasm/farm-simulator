#include "camera.h"
//------------------------------------------------------------------------------------
world_camera_t * create_world_camera()
{
    world_camera_t * wc = malloc(sizeof(world_camera_t));
    wc->camera = create2D_camera();
    wc->entryZoomIn = true;
}
//------------------------------------------------------------------------------------
void destroy_world_camera(world_camera_t * self)
{
    free(self->camera);
    free(self);
}
//------------------------------------------------------------------------------------
Camera2D * create2D_camera()
{
    Camera2D * c = malloc(sizeof(Camera2D));
    if(NULL != c)
    {
        c->target = (Vector2){0.0f, 0.0f};
        c->offset = (Vector2){SCREEN_W/2.0f, SCREEN_H/2.0f}; // centralizes target pixel
        c->rotation = 0.0f;
        c->zoom = 1.0f;
    }
    return c;
}
//------------------------------------------------------------------------------------
void update_camera(world_camera_t * self)
{
    if(NULL != self)
    {
        if(self->entryZoomIn)
            event_entry_zoomIn(self);
        
        //TODO: damped camera follow
    }
}
//------------------------------------------------------------------------------------
void event_entry_zoomIn(world_camera_t * self)
{
    if(3.0f < self->camera->zoom)
    {
        self->camera->zoom = 3.0f;
        self->entryZoomIn = false;
    }
    else if(3.0f == self->camera->zoom)
    {
        self->entryZoomIn = false;
    }
    else
    {
        self->camera->zoom += GetFrameTime();
    }
}
//------------------------------------------------------------------------------------
