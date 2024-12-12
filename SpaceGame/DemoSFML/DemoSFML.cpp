// DemoSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

#include "common.h"
#include "GameData.h"
#include "Joueur.h"

#include "Init.h"
#include "Display.h"
#include "Update.h"
#include "time.h""

int main()
{
	srand(time(0));
	rand(); rand(); rand(); rand();
	GameData* gameData = new GameData;
	gameData->m_window.create(sf::VideoMode(SWIDTH, SHEIGHT), "Projet Space");
	sf::Clock dtClock;
	Init(gameData);

	while (gameData->m_window.isOpen())
	{
		//TODO: extraire le frametime d'une horloge et le stocker dans GameData
		dtClock.getElapsedTime().asSeconds();
		gameData->dt = dtClock.restart().asSeconds();
		sf::Event event;
		while (gameData->m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameData->m_window.close();
			}
			//TODO: input évenementiels au clavier pour pousser le joueur dans certaines directions
			//grâce à sa fonction Move
			if (event.type == event.KeyPressed)
			{
				if (gameData->joueur->fuel > 0)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						gameData->joueur->Thurst = { 0, -1 };
						gameData->joueur->speed += gameData->joueur->Thurst;
						gameData->joueur->fuel -= gameData->dt * 200.0f;
						break;
					case sf::Keyboard::Down:
						gameData->joueur->Thurst = { 0, 1 };
						gameData->joueur->speed += gameData->joueur->Thurst;
						gameData->joueur->fuel -= gameData->dt * 200.0f;
						break;
					case sf::Keyboard::Left:
						gameData->joueur->Thurst = { -1, 0 };
						gameData->joueur->speed += gameData->joueur->Thurst;
						gameData->joueur->fuel -= gameData->dt * 200.0f;
						break;
					case sf::Keyboard::Right:
						gameData->joueur->Thurst = { 1, 0 };
						gameData->joueur->speed += gameData->joueur->Thurst;
						gameData->joueur->fuel -= gameData->dt * 200.0f;
						break;
					}
				}
			}

		}
		Update(gameData);
		//Affichage
		gameData->m_window.clear(sf::Color::Black);

		Display(gameData);

		gameData->m_window.display();
	}


}
