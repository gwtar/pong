#ifndef BALL_H
#define BALL_H

#include <raylib.h>

typedef struct ball
{
    int posx;
    int posy;
    int speedx;
    int speedy;
    int radius;
    Color color;
} ball;

#endif /* BALL_H */
