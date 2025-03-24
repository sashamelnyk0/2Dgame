#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
class Perks{
private:
    sf::Sprite shape;

    void initShape();
    void initVariables();
    void initTextures();

    sf::Clock clock;

public:
    Perks();
    Perks(sf::Texture* texture);
    virtual ~Perks();

    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;

    void update();
    void render(sf::RenderTarget* target);

};


