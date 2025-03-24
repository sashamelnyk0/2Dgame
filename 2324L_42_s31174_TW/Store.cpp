#include "Store.h"
#include "Player.h"
#include "Bullet.h"

Store::Store(int mon) : window(sf::VideoMode(1200, 800), "Shop"), money(mon), returnToMenu(false) {
    init();
}
void Store::init() {
    font.loadFromFile("D:\\font.ttf");
    this->map.loadFromFile("D:\\SHOP.jpg");
    this->backgroundSprite.setTexture(map);
    moneyText.setFont(font);
    moneyText.setString("Money: " + std::to_string(this->money) + "$");
    moneyText.setCharacterSize(30);
    moneyText.setPosition(100, 50);
//------------------------------------------------------
    backText.setFont(font);
    backText.setString("Back to Menu");
    backText.setCharacterSize(20);
    backText.setPosition(1000, 50);

    backButton.setSize(sf::Vector2f(160, 40));
    backButton.setPosition(1000, 50);
    backButton.setFillColor(sf::Color::Blue);

//-------------------------------------
    armorText.setFont(font);
    armorText.setString("Armor-2000$");
    armorText.setCharacterSize(20);
    armorText.setPosition(110, 600);

    armorButton.setSize(sf::Vector2f(160, 40));
    armorButton.setPosition(100, 600);
    armorButton.setFillColor(sf::Color::Blue);


    armorTexture.loadFromFile("D:\\armor1.png");

    armorSprite.setTexture(armorTexture);
    armorSprite.setPosition(80, 450); //
//-------------------------------------
    speedText.setFont(font);
    speedText.setString("Speed - 1500$");
    speedText.setCharacterSize(20);
    speedText.setPosition(510, 600);

    speedButton.setSize(sf::Vector2f(160, 40));
    speedButton.setPosition(500, 600);
    speedButton.setFillColor(sf::Color::Blue);

    speedTexture.loadFromFile("D:\\shoes.png");
    speedSprite.setTexture(speedTexture);
    speedSprite.setPosition(470, 380); // Позиція над кнопкою Speed
    speedSprite.setScale(0.6, 0.6);
//------------------

    bulletSpeed.setFont(font);
    bulletSpeed.setString("Bul.Speed-$1000");
    bulletSpeed.setCharacterSize(20);
    bulletSpeed.setPosition(810, 600);

    bulletButton.setSize(sf::Vector2f(160, 40));
    bulletButton.setPosition(800, 600);
    bulletButton.setFillColor(sf::Color::Blue);


    bulletTexture.loadFromFile("D:\\bull.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setPosition(810, 430);
    bulletSprite.setScale(0.3, 0.3);

    this->armorSprite = armorSprite;
    this->speedSprite = speedSprite;
    this->bulletSprite = bulletSprite;
}

bool Store::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
    return returnToMenu;
}

void Store::handleEvents() {
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
            else if (armorButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if(money>2000){
                    money -= 2000;
                    moneyText.setString("Money: " + std::to_string(this->money) + "$");
                    Player player;
                    player.playerHp+=20;
                }
            }
            else if (speedButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if(money>1500){
                    money -= 1500;
                    moneyText.setString("Money: " + std::to_string(this->money) + "$");
                    Player player;
                    player.movementSpeed+=2.f;
                }
            }
            else if(bulletSpeed.getGlobalBounds().contains(mousePos.x, mousePos.y)){
                if(money>1000){
                    money -= 1000;
                    moneyText.setString("Money: " + std::to_string(this->money) + "$");
                    Bullet bullet;
                    bullet.movementSpeed +=2.f;
                }
            }

        }
    }
}

void Store::render() {
    window.clear();
    this->window.clear(sf::Color::Green);
    this->window.draw(this->backgroundSprite);
    window.draw(moneyText);
    window.draw(backButton);
    window.draw(backText);
    window.draw(armorButton);
    window.draw(armorText);
    window.draw(speedButton);
    window.draw(speedText);
    window.draw(bulletButton);
    window.draw(bulletSpeed);
    window.draw(armorSprite);
    window.draw(speedSprite);
    window.draw(bulletSprite);
    window.display();
}
