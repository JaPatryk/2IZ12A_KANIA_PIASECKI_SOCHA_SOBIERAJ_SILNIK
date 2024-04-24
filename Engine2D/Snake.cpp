#include "Circle.hpp"
#include "Snake.hpp"

Snake::Snake(float r, float x, float y) {
		body.push_back(Circle(r, x, y));
	
	}
void Snake::display(sf::RenderWindow& window) {
	
	if (!body.empty()) {
		body[0].setColor(sf::Color(34, 139, 34));
		body[0].display(window);
	}

	for (size_t i = 1; i < body.size(); ++i) {
		body[i].setColor(sf::Color(34, 139, 34));
		body[i].display(window);
	}
}

void Snake::grow(int directory) {
	if (directory == 1){
		Circle newCircle(this->body.front().r, this->body.back().x, this->body.back().y + (this->body.back().r*2));
		body.push_back(newCircle);
	}
	else if (directory == 2) {
		Circle newCircle(this->body.front().r, this->body.back().x - (this->body.back().r * 2), this->body.back().y);
		body.push_back(newCircle);
	}
	else if (directory == 3) {
		Circle newCircle(this->body.front().r, this->body.back().x, this->body.back().y - (this->body.back().r * 2));
		body.push_back(newCircle);
	}
	else{
		Circle newCircle(this->body.front().r, this->body.back().x + (this->body.back().r * 2), this->body.back().y);
		body.push_back(newCircle);
	}
	
	

	
}