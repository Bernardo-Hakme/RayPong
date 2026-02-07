#include "config.h"
#include "Ball.h"
#include "Paddle.h"

int main()
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "RayPong");
	SetTargetFPS(60);

	Ball ball(WIN_WIDTH/2, WIN_HEIGHT/2, ballRadius);
	Paddle paddleLeft(15, WIN_HEIGHT/2 - paddleHeight/2, paddleWidth, paddleHeight);
	Paddle paddleRight(WIN_WIDTH-2*paddleWidth, WIN_HEIGHT/2 - paddleHeight/2, paddleWidth, paddleHeight);

	while(!WindowShouldClose())
	{
		// Event Handling
		
		// Draw to screen
		BeginDrawing();
		ClearBackground(BLACK);
	
		ball.Draw();
		paddleLeft.Draw();
		paddleRight.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}