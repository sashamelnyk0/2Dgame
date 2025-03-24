#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Icons{
private:
    sf::Sprite shape;

    sf::Vector2f direction;


    int points;
    float movementSpeed;
    void initShape();
    void initVariables();
    void initTextures();

    sf::Clock clock;

    sf::Texture bulletTexture;



public:
    Icons();
    Icons(sf::Texture* texture);
    virtual ~Icons();

    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;

    void update();
    void render(sf::RenderTarget* target);

};



