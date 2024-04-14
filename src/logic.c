#include "logic.h"

#include "window.h"

void logic(ball *ball, player *player)
{
    if(ball->posx + ball->radius > WINDOW_WIDTH)
    {
        ball->posx = WINDOW_WIDTH - ball->radius;
        ball->speedx *= -1;
    }
    if(ball->posx - ball->radius < 0)
    {
        ball->posx = 0 + ball->radius;
        ball->speedx *= -1;
    }

    if(ball->posy + ball->radius > WINDOW_HEIGHT)
    {
        ball->posy = WINDOW_HEIGHT - ball->radius;
        ball->speedy *= -1;
    }
    if(ball->posy - ball->radius < 0)
    {
        ball->posy = 0 + ball->radius;
        ball->speedy *= -1;
    }

    if(player->posy + player->height > WINDOW_HEIGHT)
    {
        player->posy = WINDOW_WIDTH - player->height;
    }
    if(player->posy < 0)
    {
        player->posy = 0;
    }

    ball->posx += ball->speedx;
    ball->posy += ball->speedy;

    player->posy = GetMouseY() - player->height / 2;
}
