#ifndef GAMEDATA__H
#define GAMEDATA__H

#include <iostream>
#include <vector>

#include "common.h"


/*TODO: créer la classe GameData contenant :
* - le temps de frame (clock ou valeur float)
* */

class Joueur;
class Obstacle;
class Vaisseau;

class GameData
{
public:
	GameData() {};
	~GameData() {};
	sf::RenderWindow m_window;
	Joueur* joueur;
	float dt;
	float O2BarScale;
	float BoostBarScale;
	int GameState;
	int Level = 1;
	std::vector<Obstacle*> VectorObstacles;
	Vaisseau* vaisseau[2];

	sf::Sprite Player;
	sf::Sprite GameOverText;
	sf::Sprite Bg;
	sf::Sprite Hud;
	sf::Sprite Mine;
	sf::Sprite O2Bar;
	sf::Sprite BoostBar;
	sf::Sprite RepairText;
	sf::Sprite SattelliteSprite[2];
	sf::Sprite Satellite;
	sf::Sprite Ship;
	sf::Sprite VictoryText;
	/// //////////////
	sf::Sound GameOver;
	sf::Sound Hurt;
	sf::Sound Repair;
	sf::Music BgSound;

	sf::SoundBuffer GameOverBuffer;
	sf::SoundBuffer RepairBuffer;
	sf::SoundBuffer HurtSoundsBuffer[8];

	
private:

};

#endif