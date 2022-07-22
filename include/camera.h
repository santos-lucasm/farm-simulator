#pragma once
//------------------------------------------------------------------------------------
#include <stdlib.h>
#include <raylib.h>
//------------------------------------------------------------------------------------
// TODO: Move this to a game/screen object
#define SCREEN_W 1024
#define SCREEN_H 768
//------------------------------------------------------------------------------------
typedef struct
{
    Camera2D * camera;
    bool entryZoomIn;
} world_camera_t;
//------------------------------------------------------------------------------------
/*! @brief init world_camera_t
    @return Pointer to created obj, NULL if failed
*/
world_camera_t * create_world_camera();
//------------------------------------------------------------------------------------
/*! @brief deallocates obj memory
    @param self pointer to itself
*/
void destroy_world_camera(world_camera_t * self);
//------------------------------------------------------------------------------------
/*! @brief Create raylib std Camera2D
    @return Pointer to created obj, NULL if failed
*/
Camera2D * create2D_camera();
//------------------------------------------------------------------------------------
/*! @brief Called each frame to move camera
    @param self pointer to itself
    TODO: Receive target position to be followed
*/
void update_camera(world_camera_t * self);
//------------------------------------------------------------------------------------
/*! @brief ZoomIn animation when wordl_camera is created
    @param self pointer to itself
    TODO: Add max zoom as world_camera_t parameter
*/
void event_entry_zoomIn(world_camera_t * self);
//------------------------------------------------------------------------------------
