#include "Ball.h"
#include "config.h"

Ball::Ball(int x, int y, int r)
    : posX(x), posY(y), radius(r)
{
    directionX = 3;
    directionY = 3;
}

void Ball::Draw()
{
    DrawCircle(posX, posY, radius, WHITE);
}

