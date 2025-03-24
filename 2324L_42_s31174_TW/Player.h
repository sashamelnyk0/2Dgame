#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;

    sf::Texture textureD1;
    sf::Texture textureD2;
    sf::Texture textureD3;

    sf::Texture textureA1;
    sf::Texture textureA2;
    sf::Texture textureA3;

    sf::Texture textureS1;
    sf::Texture textureS2;
    sf::Texture textureS3;

    std::vector<sf::Texture> framesW;
    std::vector<sf::Texture> framesD;
    std::vector<sf::Texture> framesA;
    std::vector<sf::Texture> framesS;

    sf::Sprite shape;

    sf::Clock clock;
    sf::Clock runClock;

    int currentFrameW;
    int currentFrameS;
    int currentFrameD;
    int currentFrameA;

    bool isAnimatingW;
    bool isAnimatingS;
    bool isAnimatingA;
    bool isAnimatingD;


    bool run;



    float directionX;
    float directionY;

    void initVariables();
    void initShape();


public:
    int playerHp;
    Player(float x = 200, float y = 150);

    virtual ~Player();

    float movementSpeed;
    float attackCooldown;
    float attackCooldownMax;
    bool isFastRun;
    bool isFastShoot;

    //Accessor
    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;
    const float getDirectionX() const;
    const float getDirectionY() const;

    //Functions

    const bool canAttack();
    const bool canRun();
    void borders();
    void updateAttack();
    void updateInput();
    void update();

    void render(sf::RenderTarget* target);

};



