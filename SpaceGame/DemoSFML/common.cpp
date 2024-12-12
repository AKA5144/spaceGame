#include "common.h"

sf::Sprite LoadSprite(std::string _sNom, bool _isCentered)
{
    sf::Sprite tempSprite;
    sf::Texture* tempTexture = new sf::Texture();
    tempTexture->loadFromFile(_sNom);
    tempSprite.setTexture(*tempTexture);

    if (_isCentered) //Centrage
    {
        sf::Vector2u tempTaille = tempTexture->getSize();
        sf::Vector2f nouvelleTaille(tempTaille.x / 2.0f, tempTaille.y / 2.0f);
        tempSprite.setOrigin(nouvelleTaille);
    }
    return tempSprite;
}

void BlitSprite(sf::Sprite _sprite, int _x, int _y, float _angle, sf::RenderWindow* _window)
{
    _sprite.setPosition(sf::Vector2f(_x, _y));
    _sprite.setRotation(_angle);
    _window->draw(_sprite);
}