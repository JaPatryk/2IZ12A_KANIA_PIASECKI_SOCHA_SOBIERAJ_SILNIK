#include "Rectangle.hpp"

Rectangle::Rectangle(float a,float b, float x, float y) {
	this->a = a;
	this->b = b;
	this->x = x;
	this->y = y;
}
void Rectangle::setA(float a) {
	this->a = a;
};
void Rectangle::setB(float b) {
	this->b = b;
};
void Rectangle::display(sf::RenderWindow& window) {
	sf::RectangleShape rectangle(sf::Vector2f(this->a, this->b));
	if (this->background) {
		rectangle.setFillColor(this->color);
	}
	else {
		rectangle.setFillColor(sf::Color::Transparent);
	}
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(color);
	rectangle.setPosition(x, y);


	sf::Transform transform;
	sf::FloatRect bounds = rectangle.getGlobalBounds();
	float centerX = bounds.left + bounds.width / 2;
	float centerY = bounds.top + bounds.height / 2;
	transform.rotate(this->angle, sf::Vector2f(centerX, centerY));
	rectangle.setPosition(transform.transformPoint(rectangle.getPosition()));
	rectangle.setRotation(rectangle.getRotation() + this->angle);
	window.draw(rectangle);
}
