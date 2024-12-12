#include "Display.h"
#include "GameData.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "Vaisseau.h"

/*TODO: écrire le corps de la fonction Display, qui dessine le background, 
* les vaisseaux, le joueur, les obstacles, puis les éléménts d'UI
*/


void DrawObstacles(GameData* _gameData)
{
	for (int i = 0; i < _gameData->VectorObstacles.size(); i++)
	{
		BlitSprite(_gameData->Mine, _gameData->VectorObstacles[i]->pos.x, _gameData->VectorObstacles[i]->pos.y, _gameData->VectorObstacles[i]->rotate, &_gameData->m_window);
	}
}

void DrawVaisseau(GameData* _gameData)
{
		BlitSprite(_gameData->Ship, _gameData->vaisseau[0]->pos.x, _gameData->vaisseau[0]->pos.y, 0, &_gameData->m_window);
		if (getSatteliteState(*_gameData) == true)
		{
			_gameData->Satellite = _gameData->SattelliteSprite[0];
		}
		 if (getSatteliteState(*_gameData) == false)
		{
			_gameData->Satellite = _gameData->SattelliteSprite[1];
		}
		BlitSprite(_gameData->Satellite, _gameData->vaisseau[1]->pos.x, _gameData->vaisseau[1]->pos.y, 0, &_gameData->m_window);
}

void DrawPlayer(GameData* _gameData)
{
	BlitSprite(_gameData->Player, _gameData->joueur->pos.x, _gameData->joueur->pos.y, 0, &_gameData->m_window);
}
void DrawHud(GameData* _gameData)
{
	BlitSprite(_gameData->Hud, 0, 0, 0, &_gameData->m_window);
	BlitSprite(_gameData->O2Bar, _gameData->Hud.getGlobalBounds().width, (_gameData->Hud.getGlobalBounds().height /8), 0, &_gameData->m_window);
	BlitSprite(_gameData->BoostBar, _gameData->Hud.getGlobalBounds().width, (_gameData->Hud.getGlobalBounds().height / 8) * 5, 0, &_gameData->m_window);
}
void Display(GameData* _gameData)
{
	BlitSprite(_gameData->Bg, 0, 0, 0, &_gameData->m_window);
	if (_gameData->GameState == 0)
	{
		DrawVaisseau(_gameData);
		DrawPlayer(_gameData);
		DrawObstacles(_gameData);
		DrawHud(_gameData);
		if (getPlayerState(*_gameData) == true)
		{
			BlitSprite(_gameData->RepairText, SWIDTH / 2, SHEIGHT / 2, 0, &_gameData->m_window);
		}
	}
	if (_gameData->GameState == 1)
	{
		BlitSprite(_gameData->VictoryText, SWIDTH / 2, SHEIGHT / 2, 0, &_gameData->m_window);
	}
	if (_gameData->GameState == 2)
	{
		BlitSprite(_gameData->GameOverText, SWIDTH / 2, SHEIGHT / 2, 0, &_gameData->m_window);
	}

}