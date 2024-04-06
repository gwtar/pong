#include <stdio.h>
#include </usr/local/include/raylib.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "pong"
#define WINDOW_MAX_FPS 60

typedef struct
{
    int posx;
    int posy;
    int speedx;
    int speedy;
    int radius;
    Color color;
} ball;

typedef struct
{
    int posx;
    int posy;
    int sizex;
    int sizey;
    Color color;
} player;

void init(ball *ball, player *player)
{

    ball->posx = WINDOW_WIDTH / 2;
    ball->posy = WINDOW_HEIGHT / 2;
    ball->speedx = 11;
    ball->speedy = 10;
    ball->radius = 5;
    ball->color = WHITE;

    player->posx = 0;
    player->posy = 0;
    player->sizex = 10;
    player->sizey = 100;
    player->color = WHITE;
}

void logic(ball *ball, player *player)
{
    if(ball->posx > WINDOW_WIDTH)
    {
        ball->posx = WINDOW_WIDTH;
        ball->speedx *= -1;
    }
    if(ball->posx <= 0 + ball->center)
    {
        ball->posx = 0 + ball->center;
        ball->speedx *= -1;
    }

    if(ball->posy >= WINDOW_HEIGHT - ball->center)
    {
        ball->posy = WINDOW_HEIGHT - ball->center;
        ball->speedy *= -1;
    }
    if(ball->posy <= 0 + ball->center)
    {
        ball->posy = 0 + ball->center;
        ball->speedy *= -1;
    }

    ball->posx += ball->speedx;
    ball->posy += ball->speedy;

    player->posy = GetMouseY() - player->centery;

    if(player->posy > WINDOW_HEIGHT - player->sizey)
    {
        player->posy = WINDOW_HEIGHT - player->sizey;
    }

    if(player->posy < 0)
    {
        player->posy = 0;
    }
}

void draw(ball ball, player player)
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawCircle(ball.posx, ball.posy, ball.radius, ball.color);
    DrawRectangle(player.posx, player.posy, player.sizex, player.sizey, player.color);

    EndDrawing();
}

int main()
{
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
