#include "Vaisseau.h"
#include "GameData.h"
/*TODO: écrire une classe Vaisseau possédant:
	- Position XY
	- indicateur de déplacement haut/rien/bas, ou vitesse verticale.
	  Si l'indicateur vaut 1, le vaisseau monte, si il vaut -1, le vaisseau descend,
	  si il vaut 0, le vaisseau reste immobile.
	- booléen "isRepaired", inutile pour le Soyouz mais sera utile pour le satellite

	- Un constructeur recevant en paramètre une position X pour placer le vaisseau
	  approprié à gauche ou droite de l'écran
	- Une fonction Update faisant se déplacer le vaisseau de haut en bas selon la valeur
	  de l'indicateur de déplacement

*/



	


Vaisseau::Vaisseau(float _posX)
{
	pos.x = _posX;
	
}

Vaisseau::~Vaisseau()
{
}

sf::Vector2f getShipPos(GameData& _gameData)
{

	return _gameData.vaisseau[0]->pos;
}

sf::Vector2f getSattelitePos(GameData& _gameData)
{

	return _gameData.vaisseau[1]->pos;
}

bool getSatteliteState(GameData& _gameData)
{
	return _gameData.vaisseau[1]->isRepaired;
}

void setSatteliteState(GameData& _gameData, bool _state)
{
	_gameData.vaisseau[1]->isRepaired = _state;
}
void initVaisseau(GameData& _gameData)
{
	_gameData.vaisseau[1]->isRepaired = false;
	for (int i = 0; i < 2; i++)
	{
		int posy = rand() % SHEIGHT - _gameData.vaisseau[i]->size.y;
		_gameData.vaisseau[i]->pos.y = posy;
	}
}


void MoveVaisseau(GameData& _gameData, int _level, float _dt, bool _state)
{
	if (_level > 1)
	{
		if (_state == false)
		{
			_gameData.vaisseau[1]->pos.y += _dt * 50.0f * _gameData.vaisseau[1]->dirY;
			if (_gameData.vaisseau[1]->pos.y > SHEIGHT)
			{
				_gameData.vaisseau[1]->dirY = -1;
			}
			if (_gameData.vaisseau[1]->pos.y < 0)
			{
				_gameData.vaisseau[1]->dirY = 1;
			}
		}
		}
	if (_level > 2)
	{
		_gameData.vaisseau[0]->pos.y += _dt * 50.0f * _gameData.vaisseau[0]->dirY;
		if (_gameData.vaisseau[0]->pos.y > SHEIGHT)
		{
			_gameData.vaisseau[0]->dirY = -1;
		}
		if (_gameData.vaisseau[0]->pos.y < 0)
		{
			_gameData.vaisseau[0]->dirY = 1;
		}
	}
}