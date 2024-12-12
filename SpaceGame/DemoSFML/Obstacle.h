#ifndef OBSTACLE__H
#define OBSTACLE__H

//TODO: écrire une classe Obstacle possédant une position, une vitesse, 
//et une fonction Update permettant de faire se déplacer l'obstacle le long de sa vitesse
//Si l'obstacle sort de l'écran, il faut qu'il rebondisse pour revenir à l'écran.

//TODO : ajouter une fonction AjouteObstacle (hors de la classe) qui prend en paramètre gameData, 
//et ajoute deux nouveaux obstacles à une position aléatoires dans le jeu.

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