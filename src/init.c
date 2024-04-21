#include "init.h"
#include "window.h"

#include <raylib.h>

void init(ball *ball, player *player)
{
    ball->posx = WINDOW_WIDTH / 2;
    ball->posy = WINDOW_HEIGHT / 2;
    ball->speedx = 10;
    ball->speedy = 10;
    ball->radius = 5;
    ball->color = WHITE;

    player->posx = 0;
    player->posy = 0;
    player->width = 10;
    player->height = 100;
    player->color = WHITE;
}
