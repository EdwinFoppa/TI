#include "Graphics.h"
#include <Windows.h>
#include "IO.h"
#include <sys\timeb.h>

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	const int sleepTime = 20;
	IO* io = new IO();
	std::string windowName = "Game";

	HWND hWnd = InitWindow(&hInstance, windowName, io);

	Game *game = new Game(hWnd);
	io->InitIO(game);

	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	while (true)
	{
		game->Run();
		game->DrawScreen();
		if (game->GetGameOver())
		{
			io->EndGame();
		}
		MSG msg = { 0 };
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
		}
		Sleep(sleepTime);
	}
	return 0;
}