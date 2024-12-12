#ifndef JOUEUR__H
#define JOUEUR__H


/*TODO : créer une classe Joueur contenant:
* - Position
* - Vitesse
* - Oxygène
* - Carburant
* 
* - Fonction Update permettant de bouger le personnage le long de sa vitesse 
	et diminuer l'oxygène selon le temps
  - Fonction Thrust recevant une valeur X et Y, permettant de pousser 
    (ajouter une valeur à la vitesse) le joueur	dans une direction voulue
  - Fonction Reinit permettant de recharger l'oxygène et le carburant du joueur,
	en prenant en paramètre une hauteur pour le faire poper (qui sera probablement tirée de la hauteur du soyouz)
* */

#include "GameData.h"

class Joueur
{
public:
	Joueur();
	~Joueur();
	sf::Vector2f pos;
	sf::Vector2f speed;
	sf::Vector2f Thurst;
	float oxygene;
	float fuel;
	sf::Vector2i Dir;
	bool repair;
	sf::Clock repairTimer;
	float timer;
private:

};

void InitPlayer(GameData& _gameData, sf::Vector2f _posToSet);
void UpdateJoueur(GameData& _gameData, float _dt);
void JoueurVaisseauColliding(GameData& _gameData, sf::Vector2f _ShipPos, int _shipW, int _shipH);
bool getPlayerState(GameData& _gameData);
void setPosPlayer(GameData& _gameData, sf::Vector2f _pos);
void setPlayerState(GameData& _gameData, bool _state);
#endif