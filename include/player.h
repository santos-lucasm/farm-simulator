#include <raylib.h>

typedef struct
{
   Vector2 pos;
   float width;
   float height;
   Color color;
} player_t;

player_t* create_player();

Vector2 player_pos(player_t * self);

float player_width(player_t * self);

float player_height(player_t * self);

Color player_color(player_t * self);

void draw_player(player_t * self);
