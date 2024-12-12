#ifndef VAISSEAU__H
#define VAISSEAU__H

#include "common.h"

/*TODO: �crire une classe Vaisseau poss�dant: 
	- Position X et Y
	- indicateur de d�placement haut/rien/bas, ou vitesse verticale. 
	  Si l'indicateur vaut 1, le vaisseau monte, si il vaut -1, le vaisseau descend,
	  si il vaut 0, le vaisseau reste immobile. 
	  Le vaisseau rebondit contre les bordures de l'�cran.
	- bool�en "isRepaired", inutile pour le Soyouz mais sera utile pour le satellite

	- Un constructeur recevant en param�tre une position X pour placer le vaisseau
	  appropri� � gauche ou droite de l'�cran
	- Une fonction Update faisant se d�placer le vaisseau de haut en bas selon la valeur
	  de l'indicateur de d�placement

*/

#include "GameData.h"

class Vaisseau
{
public:
	Vaisseau(float _posX);
	~Vaisseau();
	sf::Vector2f pos;
	int dirY = 1;
	bool isRepaired;	
	sf::Clock SatelliteTimer;
	sf::Vector2f size;
 private:

};

void initVaisseau(GameData& _gameData);
sf::Vector2f getShipPos(GameData& _gameData);
sf::Vector2f getSattelitePos(GameData& _gameData);
bool getSatteliteState(GameData& _gameData);
void setSatteliteState(GameData& _gameData, bool _state);
bool ReturnShip(GameData& _gameData, sf::Vector2f _ShipPos, int _shipW, int _shipH, bool _state);
void MoveVaisseau(GameData& _gameData, int _level, float _dt, bool _state);
#endif