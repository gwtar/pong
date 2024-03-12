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
}

void logic(ball *ball)
{
    ball->posx += ball->speedx;
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
