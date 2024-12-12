#ifndef JOUEUR__H
#define JOUEUR__H


/*TODO : cr�er une classe Joueur contenant:
* - Position
* - Vitesse
* - Oxyg�ne
* - Carburant
* 
* - Fonction Update permettant de bouger le personnage le long de sa vitesse 
	et diminuer l'oxyg�ne selon le temps
  - Fonction Thrust recevant une valeur X et Y, permettant de pousser 
    (ajouter une valeur � la vitesse) le joueur	dans une direction voulue
  - Fonction Reinit permettant de recharger l'oxyg�ne et le carburant du joueur,
	en prenant en param�tre une hauteur pour le faire poper (qui sera probablement tir�e de la hauteur du soyouz)
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