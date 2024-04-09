#include "draw.h"

void draw(ball ball, player player)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(0, 0);

    DrawCircle(ball.posx, ball.posy, ball.radius, ball.color);
    DrawRectangle(player.posx, player.posy, player.width, player.height, player.color);

    EndDrawing();
}
