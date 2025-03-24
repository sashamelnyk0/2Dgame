#include "Perks.h"
Perks::Perks() {

}

Perks::~Perks() {

}


Perks::Perks(sf::Texture *texture) {
    this->shape.setTexture(*texture);
    float posX = rand() % 700 + 50;
    float posY = rand() % 500 + 300;
    this->shape.setPosition(posX, posY);
}
void Perks::update() {
    this->shape.move(100,100);
}

void Perks::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    shape.setScale(3,3);
}

const sf::Vector2f &Perks::getPos() const {
    return this->shape.getPosition();
}

const sf::FloatRect Perks::getBounds() const {
    return this->shape.getGlobalBounds();
}