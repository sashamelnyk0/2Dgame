#include "Enemy2.h"


Enemy2::Enemy2() {

}

Enemy2::~Enemy2() {

}


Enemy2::Enemy2(sf::Texture *texture, float movementSpeed, float posY, int hpMx, int dmg) {
    this->shape.setTexture(*texture);
    this->shape.setPosition(800, posY-300);
    this->shape.setScale(3, 3);

    this->direction.x = -posY;
    this->direction.y = 0;

    this->movementSpeed = movementSpeed;


}
void Enemy2::update() {
    //Movement
    this->shape.move(this->direction*movementSpeed);

}

void Enemy2::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

const sf::Vector2f &Enemy2::getPos() const {
    return this->shape.getPosition();
}

const sf::FloatRect Enemy2::getBounds() const {
    return this->shape.getGlobalBounds();
}

