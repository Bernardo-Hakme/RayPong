#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
private:
    int posX;
    int posY;
    int width;
    int height;

public:
    Paddle(int x, int y, int w, int h);
    void Draw();
};




#endif