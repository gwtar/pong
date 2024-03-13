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
    int center;
} ball;

typedef struct
{
    int sizex;
    int sizey;
    int speed;
    Color color;
} player;

void init(ball *ball)
{

    ball->posx = WINDOW_WIDTH / 2;
    ball->posy = WINDOW_HEIGHT / 2;
    ball->speedx = 10;
    ball->speedy = 10;
    ball->radius = 5;
    ball->color = WHITE;
    ball->center = ball->radius / 2;
}

void logic(ball *ball)
{
    /*
    if(ball->posx >= WINDOW_WIDTH - ball->center)
    {
        ball->posx = WINDOW_WIDTH - ball->center;
        ball->speedx *= -1;
    }
    if(ball->posx <= 0 + ball->center)
    {
        ball->posx = 0 + ball->center;
        ball->speedx *= -1;
    }
    */

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
}

void draw(ball ball)
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawCircle(ball.posx, ball.posy, ball.radius, ball.color);

    EndDrawing();
}

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(WINDOW_MAX_FPS);

    ball ball;

    init(&ball);

    while(!WindowShouldClose())
    {
        logic(&ball);
        draw(ball);
    }

    CloseWindow();
    return 0;
}
