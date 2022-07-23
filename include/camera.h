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
/**
 * @brief Create a world camera object
 * 
 * @param targetPos Target position that camera will point to
 * @return world_camera_t* Ref to created object, or NULL if failed
 */
world_camera_t * create_world_camera(const Vector2 targetPos);
//------------------------------------------------------------------------------------
/**
 * @brief Handles dynamic memory allocation for world camera
 * 
 * @param self world camera to be destroyed
 */
void destroy_world_camera(world_camera_t * self);
//------------------------------------------------------------------------------------
/**
 * @brief Create a 2D camera object
 * 
 * @param targetPos Target position that camera will point to
 * @return Camera2D* Ref to created object, or NULL if failed
 */
Camera2D * create2D_camera(const Vector2 targetPos);
//------------------------------------------------------------------------------------
/**
 * @brief Called each frame to update camera target and offset
 * 
 * @param self Camera to be updated
 * @param targetPos Target position that camera should follow
 */
void update_camera(world_camera_t * self, const Vector2 targetPos);
//------------------------------------------------------------------------------------
/**
 * @brief Zoomin animation at world camera creation in a new scene
 * 
 * @param self Camera to run event
 */
void event_entry_zoomIn(world_camera_t * self);
//------------------------------------------------------------------------------------
