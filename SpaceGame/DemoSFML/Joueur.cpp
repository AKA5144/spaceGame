#include "Joueur.h"
#include "GameData.h"

/*TODO : écrire les fonctions de la classe Joueur:
* - Fonction Update permettant de bouger le personnage le long de sa vitesse
	et diminuer l'oxygène selon le temps.
  - Fonction Thrust recevant une valeur X et Y, permettant de pousser
	(ajouter une valeur à la vitesse) le joueur	dans une direction voulue
  - Fonction Reinit permettant de recharger l'oxygène et le carburant du joueur, et
  positionner le joueur à hauteur du vaisseau
* */

void InitPlayer(GameData& _gameData, sf::Vector2f _posToSet)
{
	_gameData.joueur->pos = _posToSet;
	_gameData.joueur->repair = false;
	float x = (rand() % 3) - 1;
	float y = (rand() % 3) - 1;
	_gameData.joueur->speed = { x, y };
	_gameData.joueur->Thurst = { 0, 0 };
	_gameData.joueur->oxygene = 30;
	_gameData.joueur->fuel = 30;
}
Joueur::Joueur()
{

}

Joueur::~Joueur()
{
}




void JoueurVaisseauColliding(GameData& _gameData, sf::Vector2f _ShipPos, int _shipW, int _shipH)
{
	if (_gameData.joueur->speed.x + _gameData.joueur->speed.y < 10)
	{
		if ((_gameData.joueur->pos.x > _ShipPos.x - _shipW / 2) && (_gameData.joueur->pos.x < _ShipPos.x + _shipW - _shipW / 2) && (_gameData.joueur->pos.y > _ShipPos.y - _shipH / 2) && (_gameData.joueur->pos.y < _ShipPos.y + _shipH - _shipH / 2))
		{
			_gameData.Repair.play();
			_gameData.joueur->repair = true;
		}

	}
}
void UpdateJoueur(GameData& _gameData, float _dt)
{
	if (_gameData.joueur->repair == false)
	{
		_gameData.joueur->pos += _gameData.dt * _gameData.joueur->speed * 25.0f;
	}
	_gameData.joueur->oxygene -= _dt ;

}

bool ReturnShip(GameData& _gameData, sf::Vector2f _ShipPos, int _shipW, int _shipH, bool _state)
{
		if ((_gameData.joueur->pos.x > _ShipPos.x - _shipW / 2) && (_gameData.joueur->pos.x < _ShipPos.x + _shipW - _shipW / 2) && (_gameData.joueur->pos.y > _ShipPos.y - _shipH / 2) && (_gameData.joueur->pos.y < _ShipPos.y + _shipH - _shipH / 2))
		{
			if (_state)
			{
				if((_gameData.joueur->speed.x + _gameData.joueur->speed.y < 10) && (_gameData.joueur->speed.x + _gameData.joueur->speed.y > -10))
				{
					_gameData.GameState = 1;
					return true;
				}



			}
			else
			{
				_gameData.joueur->fuel = 30;
				_gameData.joueur->oxygene = 30;
				return false;
			}
		}
		else
		{
			return false;
		}
}

bool getPlayerState(GameData& _gameData)
{
	return _gameData.joueur->repair;
}

void setPlayerState(GameData& _gameData, bool _state)
{
	_gameData.joueur->repair = _state;
}

void setPosPlayer(GameData& _gameData, sf::Vector2f _pos)
{
	_gameData.joueur->pos = _pos;
}