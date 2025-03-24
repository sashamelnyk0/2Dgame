#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Bullet.h"
class Enemy2{
private:
    sf::Sprite shape;

    sf::Vector2f direction;


    int points;
    float movementSpeed;
    void initShape();
    void initVariables();
    void initTextures();

    sf::Clock clock;
    std::vector<Bullet*> bullets;
    sf::Texture bulletTexture;



public:
    Enemy2();
    Enemy2(sf::Texture* texture, float movementSpeed, float posY,  int hpMax, int damage);
    virtual ~Enemy2();

    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;

    void update();
    void render(sf::RenderTarget* target);

};
