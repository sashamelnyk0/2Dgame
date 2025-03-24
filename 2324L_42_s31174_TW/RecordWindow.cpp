#include "RecordWindow.h"
#include <SFML/Graphics.hpp>

RecordWindow::RecordWindow(int bestScore) : window(sf::VideoMode(400, 300), "Best Scores"), score(bestScore), returnToMenu(false) {
    init();
}

void RecordWindow::init() {
    font.loadFromFile("D:\\font.ttf");

    this->map.loadFromFile("D:\\SHOP.jpg");
    this->backgroundSprite.setTexture(map);

    scoreText.setFont(font);
    scoreText.setString("Best Score: " + std::to_string(score));
    scoreText.setCharacterSize(30);
    scoreText.setPosition(50, 100);

    backText.setFont(font);
    backText.setString("Back to Menu");
    backText.setCharacterSize(20);
    backText.setPosition(120, 220);

    backButton.setSize(sf::Vector2f(160, 40));
    backButton.setPosition(110, 215);
    backButton.setFillColor(sf::Color::Blue);
}

bool RecordWindow::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
    return returnToMenu;
}

void RecordWindow::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                returnToMenu = true;
                window.close();
            }
        }
    }
}

void RecordWindow::render() {
    this->window.clear(sf::Color::Green);
    this->window.draw(this->backgroundSprite);
    window.draw(scoreText);
    window.draw(backButton);
    window.draw(backText);
    window.display();
}
