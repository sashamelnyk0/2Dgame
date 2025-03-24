#include "Player.h"
//private functions
void Player::initVariables() {
    this->movementSpeed = 2.f;
    this->playerHp = 100;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this -> attackCooldownMax;
    float directionX = 0.f;
    float directionY = -1.f;
    this->isFastRun = false;
}
void Player::initShape() {
    this->texture1.loadFromFile("D:\\goku11.png");
    this->texture2.loadFromFile("D:\\goku22.png");
    this->texture3.loadFromFile("D:\\goku33.png");

    this->textureD1.loadFromFile("D:\\gokud11.png");
    this->textureD2.loadFromFile("D:\\gokud22.png");
    this->textureD3.loadFromFile("D:\\gokud33.png");

    this->textureA1.loadFromFile("D:\\gokua111.png");
    this->textureA2.loadFromFile("D:\\gokua2.png");
    this->textureA3.loadFromFile("D:\\gokua4.png");

    this->textureS1.loadFromFile("D:\\gokus11.png");
    this->textureS2.loadFromFile("D:\\gokus2.png");
    this->textureS3.loadFromFile("D:\\gokus3.png");

    this->framesW.push_back(texture1);
    this->framesW.push_back(texture2);
    this->framesW.push_back(texture3);

    this->framesD.push_back(textureD1);
    this->framesD.push_back(textureD2);
    this->framesD.push_back(textureD3);

    this->framesA.push_back(textureA1);
    this->framesA.push_back(textureA2);
    this->framesA.push_back(textureA3);

    this->framesS.push_back(textureS1);
    this->framesS.push_back(textureS2);
    this->framesS.push_back(textureS3);


    shape.setTexture(texture1);
    shape.setScale(3, 3);



}
//Constructors
Player::Player(float x, float y) {

    this->shape.setPosition(x,y);


    this->initVariables();
    this->initShape();
}
Player::~Player() {

}
void Player::updateInput() {
    //Keyboard input
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed, 0.f);
        isAnimatingA = true;
        this->directionX = -1.f;
        this->directionY = 0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&canRun()){
            this->shape.setPosition(shape.getPosition().x-5, shape.getPosition().y);
            runClock.restart();
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
       isAnimatingA = false;
       currentFrameA = 0;
    }
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.f);
        isAnimatingD = true;
        this->directionX = 1.f;
        this->directionY = 0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&canRun()){
            this->shape.setPosition(shape.getPosition().x+5, shape.getPosition().y);
            runClock.restart();
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        isAnimatingD = false;
        currentFrameD = 0;
    }
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->movementSpeed);
        isAnimatingW = true;
        this->directionX = 0.f;
        this->directionY = -1.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&canRun()){
            this->shape.setPosition(shape.getPosition().x, shape.getPosition().y-5);
            runClock.restart();
        }
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        isAnimatingW = false;
        currentFrameW = 0;
    }
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movementSpeed);
        isAnimatingS = true;
        this->directionX = 0.f;
        this->directionY = 1.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&canRun()){
            this->shape.setPosition(shape.getPosition().x, shape.getPosition().y+5);
            runClock.restart();
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        isAnimatingS = false;
        currentFrameS = 0;
    }


    //Bullet direction
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->directionX = 1.f;
        this->directionY = -1.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->directionX = -1.f;
        this->directionY = -1.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->directionX = 1.f;
        this->directionY = 1.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->directionX = -1.f;
        this->directionY = 1.f;
    }

    //Animations
    if (isAnimatingW) {
        if (clock.getElapsedTime().asSeconds() >= 0.3f) { // Змінювати кадр кожну секунду
            currentFrameW = (currentFrameW + 1) % framesW.size();
            shape.setTexture(framesW[currentFrameW]);
            clock.restart();
        }
    }
    if (isAnimatingD) {
        if (clock.getElapsedTime().asSeconds() >= 0.3f) { // Змінювати кадр кожну секунду
            currentFrameD = (currentFrameD + 1) % framesD.size();
            shape.setTexture(framesD[currentFrameD]);
            clock.restart();
        }
    }
    if (isAnimatingA) {
        if (clock.getElapsedTime().asSeconds() >= 0.3f) { // Змінювати кадр кожну секунду
            currentFrameA = (currentFrameA + 1) % framesA.size();
            shape.setTexture(framesA[currentFrameA]);
            clock.restart();
        }
    }

    if (isAnimatingS) {
        if (clock.getElapsedTime().asSeconds() >= 0.3f) { // Змінювати кадр кожну секунду
            currentFrameS = (currentFrameS + 1) % framesS.size();
            shape.setTexture(framesS[currentFrameS]);
            clock.restart();
        }
    }
}
void Player::update() {
    this->updateAttack();
    this->updateInput();
    this->borders();
    this->canRun();
}

void Player::render(sf::RenderTarget * target) {
    target->draw(this->shape);
}

const sf::Vector2f &Player::getPos() const {
    return this->shape.getPosition();
}

const float Player::getDirectionX() const {
    return this->directionX;
}
const float Player::getDirectionY() const {
    return this->directionY;
}


void Player::updateAttack() {
    if(this->attackCooldown < this -> attackCooldownMax){
        this->attackCooldown += 0.25f;
    }

}

const bool Player::canAttack() {
    if(this->attackCooldown >= this->attackCooldownMax){
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
const bool Player::canRun() {
    if (this->runClock.getElapsedTime().asSeconds() >= 10.f) {
        return true;
    }
    return false;
}

const sf::FloatRect Player::getBounds() const {
    return this->shape.getGlobalBounds();
}

void Player::borders() {
    if(getBounds().top + getBounds().height < 300.f){
        shape.setPosition(shape.getPosition().x, shape.getPosition().y+20);
    }
    else if(getBounds().top + getBounds().height>800.f){
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - 20);
    }
    else if(getBounds().left + getBounds().width<50.f){
        shape.setPosition(shape.getPosition().x+20, shape.getPosition().y);
    }
    else if(getBounds().left + getBounds().width>800.f){
        shape.setPosition(shape.getPosition().x-20, shape.getPosition().y);
    }

}
