#include <stdio.h>
#include </usr/local/include/raylib.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "pong"
#define WINDOW_MAX_FPS 60

typedef struct ball
{
    int posx;
    int posy;
    int speedx;
    int speedy;
    int radius;
    Color color;
} ball;

typedef struct player
{
    int posx;
    int posy;
    int width;
    int height;
    Color color;
} player;

void init(ball *ball, player *player)
{

    ball->posx = WINDOW_WIDTH / 2;
    ball->posy = WINDOW_HEIGHT / 2;
    ball->speedx = 5;
    ball->speedy = 1;
    ball->radius = 5;
    ball->color = WHITE;

    player->posx = 0;
    player->posy = 0;
    player->width = 10;
    player->height = 100;
    player->color = WHITE;
}

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

    ball->posx += ball->speedx;
    ball->posy += ball->speedy;

    player->posy = GetMouseY() - player->height / 2;

    if(player->posy + player->height > WINDOW_HEIGHT)
    {
        player->posy = WINDOW_WIDTH - player->height;
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
    DrawRectangle(player.posx, player.posy, player.width, player.height, player.color);

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
