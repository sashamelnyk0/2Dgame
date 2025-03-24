#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Enemy{
private:
    sf::Sprite shape;

    sf::Vector2f direction;


    int points;
    float movementSpeed;
    void initShape();
    void initVariables();




public:
    Enemy();
    Enemy(sf::Texture* texture, float movementSpeed, float posY,  int hpMax, int damage);
    virtual ~Enemy();

    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;

    void update();
    void render(sf::RenderTarget* target);

};
