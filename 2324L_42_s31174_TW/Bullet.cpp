#include "Bullet.h"

Bullet::Bullet(){

}
Bullet::~Bullet(){

}

void Bullet::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Bullet::update() {
    //Movement
    this->shape.move(this->movementSpeed * this -> direction);

}

const sf::FloatRect Bullet::getBounds() const {
    return this->shape.getGlobalBounds();
}

Bullet::Bullet(sf::Texture * texture, float posX, float posY,float dirX, float dirY) {

    this->shape.setTexture(*texture);
    this->shape.setScale(2.5f, 2.5f);
    this->shape.setPosition(posX, posY);
    movementSpeed = 5.f;
    this->direction.x = dirX;
    this->direction.y = dirY;
    this->movementSpeed = movementSpeed;
}
