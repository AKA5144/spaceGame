#ifndef COMMON__H
#define COMMON__H

#define SWIDTH 1280
#define SHEIGHT 800

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/freeglut.h>
#include "SFML/OpenGL.hpp"

sf::Sprite LoadSprite(std::string _sNom, bool _isCentered);
void BlitSprite(sf::Sprite _sprite, int _x, int _y, float _angle, sf::RenderWindow* _window);

#endif