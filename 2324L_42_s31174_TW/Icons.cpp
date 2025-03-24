#include "Icons.h"


Icons::Icons() {

}

Icons::~Icons() {

}


Icons::Icons(sf::Texture *texture) {
    this->shape.setTexture(*texture);
    this->shape.setPosition(1100, 250);
    this->shape.setScale(3, 3);

}
void Icons::update() {

}

void Icons::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

const sf::Vector2f &Icons::getPos() const {
    return this->shape.getPosition();
}

const sf::FloatRect Icons::getBounds() const {
    return this->shape.getGlobalBounds();
}
