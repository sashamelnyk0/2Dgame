#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Perks.h"
#include "Icons.h"

class Game {
private:
    sf::VideoMode videoMode;
    sf::Event ev;

    sf::Texture map;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text scoreText;
    sf::Text hpText;
    sf::Text gameOver;

    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;
    std::vector<Bullet*> enemBullets;
    std::vector<Enemy*> enemies;
    std::vector<Enemy2*> enemies2;
    std::vector<Perks*> perks;
    std::vector<Icons*> icons;


    Player player;

    int score;
    int hp;

    bool enemyFar;

    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock atackClock;
    sf::Clock spawnElements;
    sf::Clock fastRunTimer;
    sf::Clock fastShootTimer;
    sf::Clock iconDelete;

    // Initialization
    void initVariables();
    void initWindow();
    void initTextures();

    int bestscore;
    const std::string scoreFile = "D:\\BestScore.txt";
    void loadBestScore();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;




    // Functions
    void pollEvents();
    void update();
    void render();

    void updateInput();
    void updateBullet();
    void updateEnemy();
    void updatePerks();
    void updateCombat();
    void updateEnemyAtack();

    int getBestScore() const;
    void setBestScore(int score);
    void saveBestScore() const;

    void endGame();
    void elementsSpawn();


    int getBestScore();
// Variables
sf::RenderWindow* window;

};

