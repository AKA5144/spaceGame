#include "Obstacle.h"
#include "GameData.h"

//TODO: écrire les fonctions de la classe Obstacle: 
//Fonction Update permettant de faire se déplacer l'obstacle le long de sa vitesse
//Si l'obstacle sort de l'écran, il faut qu'il rebondisse pour revenir à l'écran.


//TODO : ajouter une fonction AjouteObstacle qui prend en paramètre gameData, 
//et ajoute deux nouveaux obstacles à une position aléatoires dans le jeu.



void initObstacle(GameData& _gameData)
{
	for (int i = 0; i < _gameData.VectorObstacles.size(); i++)
	{
		int posx = rand() % SWIDTH;
		int posy = rand() % SHEIGHT;
		_gameData.VectorObstacles[i]->pos = {(float)posx ,(float)posy};
		_gameData.VectorObstacles[i]->rotate = 0;
		_gameData.VectorObstacles[i]->rotateSpeed = rand()% 250;
		_gameData.VectorObstacles[i]->Dir.x = (rand() % 3) - 1;
		_gameData.VectorObstacles[i]->Dir.y = (rand() % 3) - 1;
		_gameData.VectorObstacles[i]->speed = (rand() % 100)  + 50;
	}
}
void AjouteObstacle(GameData& _gameData)
{
	_gameData.VectorObstacles.push_back(new Obstacle);
}

void UpdateObstacle(GameData& _gameData)
{
	for (int i = 0; i < _gameData.VectorObstacles.size(); i++)
	{
		_gameData.VectorObstacles[i]->rotate += _gameData.dt * _gameData.VectorObstacles[i]->rotateSpeed;
		_gameData.VectorObstacles[i]->pos.x += _gameData.dt * _gameData.VectorObstacles[i]->speed * _gameData.VectorObstacles[i]->Dir.x;
		_gameData.VectorObstacles[i]->pos.y += _gameData.dt * _gameData.VectorObstacles[i]->speed * _gameData.VectorObstacles[i]->Dir.y;
		
		if (_gameData.VectorObstacles[i]->pos.x > SWIDTH)
		{
			_gameData.VectorObstacles[i]->Dir.x = -_gameData.VectorObstacles[i]->Dir.x;
		}
		if (_gameData.VectorObstacles[i]->pos.x < 0 )
		{
			_gameData.VectorObstacles[i]->Dir.x = abs(_gameData.VectorObstacles[i]->Dir.x);
		}
		if (_gameData.VectorObstacles[i]->pos.y > SHEIGHT)
		{
			_gameData.VectorObstacles[i]->Dir.y = -_gameData.VectorObstacles[i]->Dir.y;
		}
		if (_gameData.VectorObstacles[i]->pos.y < 0)
		{
			_gameData.VectorObstacles[i]->Dir.y = abs(_gameData.VectorObstacles[i]->Dir.y);
		}
	}
}
Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}