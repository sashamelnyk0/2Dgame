
#pragma once
#include <SFML/Graphics.hpp>

class StartMenu {
public:
    StartMenu(sf::RenderWindow& win);
    void handleEvent(sf::Event& event);
    void render();
    bool shouldClose() const;

private:
    sf::Texture map;
    sf::Sprite backgroundSprite;
    void init();
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text startText, recordText, shopText, exitText;
    sf::RectangleShape startButton, recordButton, shopButton, exitButton;
    bool closeMenu;
};

