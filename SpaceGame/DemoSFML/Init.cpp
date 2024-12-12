#include "Init.h"
#include "GameData.h"
#include "Joueur.h"
#include "Vaisseau.h"
#include "Obstacle.h"

#define SHIPSIZE 224
#define SATTELITESIZE 100
/*TODO: écrire le corps de la fonction Init qui chargera les sprites, 
instanciera dynamiquement le joueur et les vaisseaux, et appellera la fonction
AjouteObstacle de obstacle.h pour ajouter les premiers obstacles du jeu.*/


void LoadSprite(GameData* _gameData)
{
	_gameData->Player = LoadSprite("Sprite/buzz.png", true);
	_gameData->GameOverText = LoadSprite("Sprite/defaite.png", true);
	_gameData->Bg = LoadSprite("Sprite/earth-wallpapers.jpeg", false);
	_gameData->Hud = LoadSprite("Sprite/interface.png", false);
	_gameData->Mine = LoadSprite("Sprite/mine.png", true);
	_gameData->O2Bar = LoadSprite("Sprite/O2.png", false);
	_gameData->BoostBar = LoadSprite("Sprite/Prop.png", false);
	_gameData->RepairText = LoadSprite("Sprite/reparation.png", true);
	_gameData->SattelliteSprite[0] = LoadSprite("Sprite/satellite.png", true);
	_gameData->SattelliteSprite[1] = LoadSprite("Sprite/satellitevrac.png", true);
	_gameData->Satellite = _gameData->SattelliteSprite[1];
	_gameData->Ship = LoadSprite("Sprite/vaisseau.png", true);
	_gameData->vaisseau[0]->size = (sf::Vector2f)_gameData->Ship.getTexture()->getSize();
	_gameData->vaisseau[1]->size = (sf::Vector2f)_gameData->Satellite.getTexture()->getSize();
	_gameData->VictoryText = LoadSprite("Sprite/victoire.png", true);
	_gameData->O2BarScale = _gameData->joueur->oxygene;
	_gameData->BoostBarScale = _gameData->joueur->fuel;
	_gameData->O2Bar.setScale(_gameData->O2BarScale, 1);
	_gameData->BoostBar.setScale(_gameData->BoostBarScale, 1);
}

void LoadSound(GameData* _gameData)
{

	_gameData->GameOverBuffer.loadFromFile("sound/Gameover/dude_choke.wav");
	_gameData->RepairBuffer.loadFromFile("sound/Reparation/dude_ohlooktheyleft.wav");
	_gameData->HurtSoundsBuffer[0].loadFromFile("sound/Jurons/dude_ak.wav");
	_gameData->HurtSoundsBuffer[1].loadFromFile("sound/Jurons/dude_augh.wav");
	_gameData->HurtSoundsBuffer[2].loadFromFile("sound/Jurons/dude_augh2.wav");
	_gameData->HurtSoundsBuffer[3].loadFromFile("sound/Jurons/dude_fuck.wav");
	_gameData->HurtSoundsBuffer[4].loadFromFile("sound/Jurons/dude_huh.wav");
	_gameData->HurtSoundsBuffer[5].loadFromFile("sound/Jurons/dude_oof.wav");
	_gameData->HurtSoundsBuffer[6].loadFromFile("sound/Jurons/dude_ow.wav");
	_gameData->HurtSoundsBuffer[7].loadFromFile("sound/Jurons/dude_shit.wav");
	_gameData->BgSound.openFromFile("sound/05-AudioTrack 05.ogg");

	_gameData->GameOver.setBuffer(_gameData->GameOverBuffer);
	_gameData->Repair.setBuffer(_gameData->RepairBuffer);
	

		
	
}

void SecondLoad(GameData* _gameData)
{
	initObstacle(*_gameData);
}

void ResetBarScale(GameData* _gameData)
{
	_gameData->BoostBarScale = 200;
	_gameData->O2BarScale = 200;
}
void NextLevel(GameData* _gameData)
{
	for (int i = 0; i < 2; i++)
	{
		AjouteObstacle(*_gameData);
	}
	SecondLoad(_gameData);
	initVaisseau(*_gameData);
	InitPlayer(*_gameData, getShipPos(*_gameData));
	ResetBarScale( _gameData);
	_gameData->Level++;
}
void Init(GameData* _gameData)
{
	
	_gameData->joueur = new Joueur;
	_gameData->vaisseau[0] = new Vaisseau(SHIPSIZE - SHIPSIZE/2);
	_gameData->vaisseau[1] = new Vaisseau(SWIDTH - SATTELITESIZE);
	_gameData->GameState = 0;//0 play , 1 win, 2 lose
	for (int i = 0; i < 2; i++)
	{
		AjouteObstacle(* _gameData);
	}
	initVaisseau(*_gameData);
	InitPlayer(*_gameData, getShipPos(*_gameData));
	LoadSprite(_gameData);
	LoadSound(_gameData);
	SecondLoad(_gameData);
	_gameData->BgSound.play();

}