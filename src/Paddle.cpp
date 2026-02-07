#include "Paddle.h"
#include "config.h"

Paddle::Paddle(int x, int y, int w, int h)
    : posX(x), posY(y), width(w), height(h)
{}

void Paddle::Draw()
{
    DrawRectangle(posX, posY, width, height, WHITE);
}