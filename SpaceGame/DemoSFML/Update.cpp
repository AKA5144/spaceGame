#include "Update.h"
#include "GameData.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "Vaisseau.h"
#include "Init.h"
/*TODO : écrire une fonction CollisionVaisseauJoueur qui testera les collisions entre le joueur, et un vaisseau passé en paramètre.
*/

/*TODO: écrire la fonction Update qui lancera l'Update du joueur, des obstacles, et les appels à la fonction
CollisionVaisseauJoueur. Si le joueur est assez lent, touche le satellite et que le satellite est en panne, le satellite sera réparé.
Si le joueur est assez lent et touche le soyouz il sera rechargé en carburant et oxygène. 
Si le satellite est réparé et que le vaisseau touche le soyouz, la partie redémarre en ajoutant deux obstacles, en positionnant le satellite et le soyouz
a une hauteur aléatoire, et le joueur à hauteur du vaisseau grâce à sa fonction Reinit. */


void UpdateBarScale(GameData* _gameData)
{
	_gameData->O2Bar.setScale(_gameData->joueur->oxygene * 10, 1);
	_gameData->BoostBar.setScale(_gameData->joueur->fuel * 10, 1);
	if (_gameData->joueur->fuel <= 0)
	{
		_gameData->joueur->fuel = 0;
	}
	if (_gameData->joueur->oxygene <= 0)
	{
		_gameData->joueur->oxygene = 0;
		
	}
}


void PlacePlayerOnSattelite(GameData* _gameData)
{
	if (getPlayerState(*_gameData) == true)
	{
			setSatteliteState(*_gameData, true);
			setPlayerState(*_gameData, false);

	}
}

void playHurtSound(GameData* _gameData)
{
	int random = rand() % 8;
	
	if (_gameData->Hurt.getStatus() == 0)
	{
		_gameData->Hurt.setBuffer(_gameData->HurtSoundsBuffer[random]);
		_gameData->Hurt.play();
	}
	
}
void PlayerObstacleColliding(GameData* _gameData)
{
	for (int i = 0; i < _gameData->VectorObstacles.size(); i++)
	{
		if ((_gameData->joueur->pos.x   > _gameData->VectorObstacles[i]->pos.x - _gameData->Mine.getGlobalBounds().width/2)
			&& (_gameData->joueur->pos.x  < _gameData->VectorObstacles[i]->pos.x + _gameData->Mine.getGlobalBounds().width - _gameData->Mine.getGlobalBounds().width / 2)
			&& (_gameData->joueur->pos.y  > _gameData->VectorObstacles[i]->pos.y - _gameData->Mine.getGlobalBounds().height / 2)
			&& (_gameData->joueur->pos.y  < _gameData->VectorObstacles[i]->pos.y + _gameData->Mine.getGlobalBounds().height - _gameData->Mine.getGlobalBounds().height / 2))
		{
			playHurtSound(_gameData);
			_gameData->joueur->oxygene -= _gameData->dt * 5;
		}
	}

}
void Update(GameData* _gameData)
{
	if (_gameData->GameState == 0)
	{
		UpdateObstacle(*_gameData);
		UpdateBarScale(_gameData);
		UpdateJoueur(*_gameData, _gameData->dt);
		PlayerObstacleColliding(_gameData);
		if (getSatteliteState(*_gameData) == false)
		{
			JoueurVaisseauColliding(*_gameData, getSattelitePos(*_gameData), _gameData->Satellite.getGlobalBounds().width, _gameData->Satellite.getGlobalBounds().height);
		}
		if (ReturnShip(*_gameData, getShipPos(*_gameData), _gameData->Ship.getGlobalBounds().width, _gameData->Ship.getGlobalBounds().height, getSatteliteState(*_gameData)))
		{

				NextLevel(_gameData);
			
		}
		if (_gameData->joueur->oxygene <= 0)
		{
			_gameData->GameOver.play();
			_gameData->GameState = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			_gameData->VectorObstacles.erase(_gameData->VectorObstacles.begin(), _gameData->VectorObstacles.end());
			NextLevel(_gameData);
			_gameData->Level = 1;
		}
		MoveVaisseau(*_gameData, _gameData->Level, _gameData->dt, _gameData->joueur->repair);
		PlacePlayerOnSattelite(_gameData);
	}
	if (_gameData->GameState == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			_gameData->GameState = 0;
		}
	}
	if (_gameData->GameState == 2)
	{
		_gameData->BgSound.stop();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			_gameData->BgSound.play();
			_gameData->VectorObstacles.erase(_gameData->VectorObstacles.begin(), _gameData->VectorObstacles.end());
			NextLevel(_gameData);
			_gameData->GameState = 0;
			_gameData->Level = 1 ;
		}
	}
}