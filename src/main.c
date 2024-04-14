#include <stdio.h>
#include <raylib.h>

#include "window.h"
#include "ball.h"
#include "player.h"

#include "init.h"
#include "logic.h"
#include "draw.h"

int main()
{
    printf("simple pong ohio kai cenat gyatt\n");
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(WINDOW_MAX_FPS);

    ball ball;
    player player;

    init(&ball, &player);

    while(!WindowShouldClose())
    {
        logic(&ball, &player);
        draw(ball, player);
    }

    CloseWindow();
    return 0;
}
