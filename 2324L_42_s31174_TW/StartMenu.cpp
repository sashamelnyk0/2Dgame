
#include "StartMenu.h"
#include "RecordWindow.h"
#include "Game.h"
#include "Store.h"
StartMenu::StartMenu(sf::RenderWindow& win) : window(win), closeMenu(false) {
    init();
}

void StartMenu::init() {
    font.loadFromFile("D:\\font.ttf");
    this->map.loadFromFile("D:\\back4.png");
    this->backgroundSprite.setTexture(map);


    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(30);
    startText.setPosition(350, 150);

    recordText.setFont(font);
    recordText.setString("Best score");
    recordText.setCharacterSize(30);
    recordText.setPosition(350, 250);

    shopText.setFont(font);
    shopText.setString("Shop");
    shopText.setCharacterSize(30);
    shopText.setPosition(350, 350);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(30);
    exitText.setPosition(350, 450);


    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setPosition(300, 150);
    startButton.setFillColor(sf::Color::Green);

    recordButton.setSize(sf::Vector2f(200, 50));
    recordButton.setPosition(300, 250);
    recordButton.setFillColor(sf::Color::Green);

    shopButton.setSize(sf::Vector2f(200, 50));
    shopButton.setPosition(300, 350);
    shopButton.setFillColor(sf::Color::Green);

    exitButton.setSize(sf::Vector2f(200, 50));
    exitButton.setPosition(300, 450);
    exitButton.setFillColor(sf::Color::Green);
}

void StartMenu::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            Game game;

            while(game.running()){
                game.update();
                game.render();
            }
        } else if (recordButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            std::ifstream inputFile("D:\\BestScore.txt");
            int bestScore = 0;
            if (inputFile.is_open()) {
                inputFile >> bestScore;
                inputFile.close();
            } else {
                std::cerr << "Error!" << std::endl;
            }
            RecordWindow recordWindow(bestScore);
            recordWindow.run();
        } else if (shopButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            std::ifstream inputFile("D:\\BestScore.txt");
            int money = 0;
            if (inputFile.is_open()) {
                inputFile >> money;
                inputFile.close();
            } else {
                std::cerr << "Error!" << std::endl;
            }
            Store store(money);
            store.run();

        } else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            window.close();
        }
    }
}

void StartMenu::render() {
    this->window.clear(sf::Color::Green);

    this->window.draw(this->backgroundSprite);
    window.draw(startButton);
    window.draw(recordButton);
    window.draw(shopButton);
    window.draw(exitButton);
    window.draw(startText);
    window.draw(recordText);
    window.draw(shopText);
    window.draw(exitText);

    window.display();
}

bool StartMenu::shouldClose() const {
    return closeMenu;
}
