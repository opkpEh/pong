#include "raylib.h"

int main()
{
	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	float ballX, ballY, ballRadius, ballSpeedX, ballSpeedY;

	ballX = GetScreenWidth() / 2.0f;
	ballY = GetScreenHeight() / 2.0f;
	ballRadius = 5.0;
	ballSpeedX = 300;
	ballSpeedY = 300;



	while (!WindowShouldClose())
	{
		ballX += ballSpeedX* GetFrameTime();
		ballY += ballSpeedY* GetFrameTime();
		
		if (ballY < 0)
		{
			ballY = 0;
			ballSpeedY *= -1;
		}

		if (ballY > GetScreenHeight())
		{
			ballY = GetScreenHeight();
			ballSpeedY *= -1;
		}

		BeginDrawing();
			ClearBackground(BLACK);

			DrawCircle(int(ballX), int(ballY), ballRadius, WHITE);
			DrawRectangle(30, GetScreenHeight() / 2-50,10, 100, WHITE);
			DrawRectangle(GetScreenWidth()-40 , GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawFPS(10, 0);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}