
#include "Enemy.h"


Enemy::Enemy() {

}

Enemy::~Enemy() {

}


Enemy::Enemy(sf::Texture *texture, float movementSpeed, float posY, int hpMx, int dmg) {
    this->shape.setTexture(*texture);
    this->shape.setPosition(800, posY-300);

    this->direction.x = -posY;
    this->direction.y = 0;

    this->movementSpeed = movementSpeed;
}

void Enemy::update() {
    //Movement
    this->shape.move(this->direction*movementSpeed);
}

void Enemy::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

const sf::Vector2f &Enemy::getPos() const {
    return this->shape.getPosition();
}

const sf::FloatRect Enemy::getBounds() const {
    return this->shape.getGlobalBounds();
}


