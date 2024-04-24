#include "Primitives.hpp"

Primitives::Primitives() {
    this->x = 0;
    this->y = 0;
    this->angle = 0;
    this->borderWidth = 1.f;
}


void Primitives::setColor(sf::Color color) {
    this->color = color;
}
void Primitives::setTexture(sf::Texture texture) {
    this->texture = texture;
};
void Primitives::setBorderWidth(float borderWidth) {
    this->borderWidth = borderWidth;
};
void Primitives::setX(float x) {
    this->x = x;
};
void Primitives::setY(float y) {
    this->y = y;
};

float Primitives::getX() const { 
    return x;
}

float Primitives::getY() const {
    return y;
}
void Primitives::setBackground() {
    this->background = true;
};
void  Primitives::clearBackground() {
    this->background = false;
};
void Primitives::rotateShape(float angle) {
    this->angle = angle;
};
void Primitives::disableRotate() {
    this->angle = 0;
};

void Primitives::hide() {
    this->color = sf::Color::Transparent;
};

