#include "Circle.hpp"

Circle::Circle(float r, float x, float y) {
	this->r = r;
	this->x = x;
	this->y = y;
}
void Circle::setR(float r) {
	this->r = r;
};
void Circle::display(sf::RenderWindow& window) {
	sf::CircleShape circle(this->r);
	if (this->background) {
		circle.setFillColor(this->color);
	}
	circle.setOutlineThickness(borderWidth);
	circle.setOutlineColor(color);
	circle.setPosition(x, y);
	circle.setTexture(&texture);
	sf::Transform transform;
	sf::FloatRect bounds = circle.getGlobalBounds();
	float centerX = bounds.left + bounds.width / 2;
	float centerY = bounds.top + bounds.height / 2;
	transform.rotate(this->angle, sf::Vector2f(centerX, centerY));
	circle.setPosition(transform.transformPoint(circle.getPosition()));
	circle.setRotation(circle.getRotation() + this->angle);
	window.draw(circle);
}


