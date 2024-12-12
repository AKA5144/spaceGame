#ifndef OBSTACLE__H
#define OBSTACLE__H

//TODO: �crire une classe Obstacle poss�dant une position, une vitesse, 
//et une fonction Update permettant de faire se d�placer l'obstacle le long de sa vitesse
//Si l'obstacle sort de l'�cran, il faut qu'il rebondisse pour revenir � l'�cran.

//TODO : ajouter une fonction AjouteObstacle (hors de la classe) qui prend en param�tre gameData, 
//et ajoute deux nouveaux obstacles � une position al�atoires dans le jeu.

#include "GameData.h"

class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	
	sf::Vector2f pos;
	int speed;
	float rotate;
	int rotateSpeed;
	sf::Vector2i Dir;

private:

};

void initObstacle(GameData& _gameData);
void AjouteObstacle(GameData& _gameData);
void UpdateObstacle(GameData& _gameData);

#endif