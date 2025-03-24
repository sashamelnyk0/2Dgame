#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#include <SFML/Graphics.hpp>

class RecordWindow {
public:
    RecordWindow(int bestScore);
    bool run();

private:
    sf::Texture map;
    sf::Sprite backgroundSprite;
    void init();
    void handleEvents();
    void render();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    sf::Text backText;
    sf::RectangleShape backButton;
    int score;
    bool returnToMenu;
};

#endif // RECORDWINDOW_H