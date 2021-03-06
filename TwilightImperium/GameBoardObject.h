#ifndef GAME_BOARD_OBJECT_H
#define GAME_BOARD_OBJECT_H

#include "Graphics.h"
#include "Image.h"
#include "UtilityClasses.h"

#include <string>
#include <map>

class GameBoardObject
{
protected:
	TupleInt _graphicalPos;
	float _scale = 1.0;
	GraphicsNS::Image* _image;
	const int _objectId;
	static GraphicsNS::Graphics* _g;

	//Objects graphical position
	static const TupleInt _gameMapPos;
	static const TupleInt _unitPosInTile;
	static const TupleInt _passButtonPos;
	
	static const TupleInt _playerSheetPos;
	static const TupleInt _playerSheetSize;

private:
	static int _latestObjectId;
	static std::map<int, GameBoardObject*> _gameBoardObjects;

public:
	static void DrawAllObjects();

	static void SetGraphics(HWND* hWnd);

	// Beskriver var kartan �r p� sk�rmen
	static TupleInt GetGameMapPos();

	TupleInt GetGraphicalPos() const;
	int GetObjectID() const;

	void SetGraphicalPos(TupleInt);
	void SetImageScale(float);

	virtual void Action(GameBoardObject*);

protected:
	GameBoardObject();
	GameBoardObject(TupleInt, GraphicsNS::Image*);
	GameBoardObject(TupleInt, TupleInt, std::string);
	~GameBoardObject();

	void SetImage(std::string, TupleInt);
	virtual void DrawObject();

private:
	bool PosInObject(TupleInt);

	friend class GameBoard;
};

#endif // ! GAME_BOARD_OBJECT_H

