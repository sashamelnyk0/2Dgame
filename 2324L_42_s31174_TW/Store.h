#pragma once
#include <SFML/Graphics.hpp>

class Store {
public:
    Store(int money);
    bool run();

private:
    sf::Texture armorTexture;
    sf::Sprite armorSprite;
    sf::Texture speedTexture;
    sf::Sprite speedSprite;
    sf::Texture bulletTexture;
    sf::Sprite bulletSprite;
    sf::Texture map;
    sf::Sprite backgroundSprite;
    void init();
    void render();
    void handleEvents();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text armorText, speedText, bulletSpeed, moneyText, backText;


    sf::RectangleShape backButton;
    sf::RectangleShape armorButton, speedButton, bulletButton;
    bool returnToMenu;
    int money;
};
