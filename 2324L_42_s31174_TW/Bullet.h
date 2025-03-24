#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Bullet
{
private:
    sf::Sprite shape;


    sf::Vector2f direction;


public:
    Bullet();
    Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY);
    virtual ~Bullet();

    float movementSpeed;
    //Accesor
    const sf::FloatRect getBounds() const;

    void update();
    void render(sf::RenderTarget* target);
};



