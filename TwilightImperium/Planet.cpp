#include "Planet.h"

const TupleInt Planet::_imageSize = TupleInt(40, 40);
const std::string Planet::_imagePath = "Map/Planet.png";

Planet::Planet()
{}

Planet::Planet(std::string name, int resourceValue, int influenceValue, std::string techSpec) :
	GameBoardObject(TupleInt(0, 0),  _imageSize, _imagePath)
{
	_name = name;
	_resourceValue = resourceValue;
	_influenceValue = influenceValue;

	if (techSpec.compare("Blue") == 0)
	{
		_technologySpeciality = Planet::Blue;
	}
	else if (techSpec.compare("Green") == 0)
	{
		_technologySpeciality = Planet::Green;
	}
	else if (techSpec.compare("Red") == 0)
	{
		_technologySpeciality = Planet::Red;
	}
	else if (techSpec.compare("Yellow") == 0)
	{
		_technologySpeciality = Planet::Yellow;
	}
	else if (techSpec.compare("None") == 0)
	{
		_technologySpeciality = Planet::None;
	}
	else
	{
		//TODO s�tt in en try catch runt den h�r
		int temp = 1;
	}
}

Planet& Planet::operator=(const Planet& planet)
{
	CopyPlanet(planet);
	return *this;
}

Planet::Planet(const Planet &planet) :
	GameBoardObject(planet._graphicalPos, planet._image)
{
	CopyPlanet(planet);
}

void Planet::CopyPlanet(const Planet& planet)
{
	_name = planet._name;
	_resourceValue = planet._resourceValue;
	_influenceValue = planet._influenceValue;
	_technologySpeciality = planet._technologySpeciality;
	_graphicalPos = planet._graphicalPos;
	_image = planet._image;
	_scale = planet._scale;
}

Planet::~Planet()
{}