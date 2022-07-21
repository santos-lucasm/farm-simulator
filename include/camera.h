#pragma once

#include <stdlib.h>
#include <raylib.h>

#define SCREEN_W 1024
#define SCREEN_H 768

Camera2D * create_camera();


/*!
    @brief  Called at scene start to zoom in player direction until the
internal zoom offset is achieved
    @param self pointer to itself
    @return TRUE if camera should zoom_in again in next frame
*/
const bool entry_zoom_in(Camera2D * self);
