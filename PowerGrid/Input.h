#ifndef INPUT_H
#define INPUT_H

#include <Windows.h>

#include "Player.h"
#include "Game.h"
#include "Draw.h"

class Input
{
	static Game* _game;

	static Draw::Pos _mousePos;

public:
	Input();
	~Input() {};

	void SetGame(Game*);
	static void MouseClick();
	static int CheckPowerPlantPos();

	static LRESULT CALLBACK MsgProc(HWND, UINT, WPARAM, LPARAM);
};

void InitWinMain(HINSTANCE*, char*, Input*);

HWND InitWindow(HINSTANCE*, char*, Input*);

#endif // !CONTROL_H