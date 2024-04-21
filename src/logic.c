#include "logic.h"

#include "window.h"

void logic(ball *ball, player *player)
{

    ball->posx += ball->speedx;
    ball->posy += ball->speedy;

    player->posy = GetMouseY() - player->height / 2;

    if(ball->posx + ball->radius > WINDOW_WIDTH)
    {
        ball->speedx *= -1;
        ball->posx = WINDOW_WIDTH - ball->radius - 1;
    }
    if(ball->posx - ball->radius < 0)
    {
        ball->speedx *= -1;
        ball->posx = 0 + ball->radius + 1;
    }

    if(ball->posy + ball->radius > WINDOW_HEIGHT)
    {
        ball->speedy *= -1;
        ball->posy = WINDOW_HEIGHT - ball->radius - 1;
    }
    if(ball->posy - ball->radius < 0)
    {
        ball->speedy *= -1;
        ball->posy = 0 + ball->radius + 1;
    }

    if(player->posy + player->height > WINDOW_HEIGHT)
    {
        player->posy = WINDOW_WIDTH - player->height;
    }
    if(player->posy < 0)
    {
        player->posy = 0;
    }
}
