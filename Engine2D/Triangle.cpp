#include "Triangle.hpp"

Triangle::Triangle(float a,float x,float y) {
	this->a = a;
	this->x = x;
	this->y = y;
}
void Triangle::setA(float a) {
	this->a = a;
};
void Triangle::display(sf::RenderWindow& window) {
	float height = this->a * std::sqrt(3) / 2.0f;
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(this->x, this->y - height / 2.0f));
	triangle.setPoint(1, sf::Vector2f(this->x - this->a / 2.0f, this->y + height / 2.0f));
	triangle.setPoint(2, sf::Vector2f(this->x + this->a / 2.0f, this->y + height / 2.0f));
	if (this->background) {
		triangle.setFillColor(this->color);
	}
	triangle.setOutlineThickness(1);
	triangle.setOutlineColor(this->color);


	sf::Transform transform;
	sf::FloatRect bounds = triangle.getGlobalBounds();
	float centerX = bounds.left + bounds.width / 2;
	float centerY = bounds.top + bounds.height / 2;
	transform.rotate(this->angle, sf::Vector2f(centerX, centerY));
	triangle.setPosition(transform.transformPoint(triangle.getPosition()));
	triangle.setRotation(triangle.getRotation() + this->angle);
	window.draw(triangle);
}
