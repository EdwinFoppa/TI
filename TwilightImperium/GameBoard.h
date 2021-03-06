#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GameBoardObject.h"
#include "GameMap.h"
#include "PassButton.h"

#pragma once
class GameBoard
{
private:
	GameMap _gameMap;
	PassButton _passButton;

public:
	GameBoard();
	~GameBoard();

	void Draw();
	void Run(Player*);

	const std::map<TupleInt, MapTile>* GetMapMap() const;
	static std::vector<GameBoardObject*> GetGameBoardObjectByPosition(TupleInt);
};

#endif // !GAME_BOARD_H