#include "InputHandler.hpp"
#include <iostream>



void InputHandler::moveShapeToMousePosition(Primitives& shape, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f worldMousePosition = window.mapPixelToCoords(mousePosition);
    shape.setX(worldMousePosition.x);
    shape.setY(worldMousePosition.y);
};


void InputHandler::move(Primitives& shape, float step) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape.setX(shape.getX() - step);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape.setX(shape.getX() + step); 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        shape.setY(shape.getY() - step); 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        shape.setY(shape.getY() + step); 
    }
    
}
void InputHandler::setDirectory() 
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->directory = 4;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->directory = 2;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->directory = 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->directory = 3;
        }
    
}

bool InputHandler::mouseClick(sf::RenderWindow& window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (mousePos.x >= 0 && mousePos.x <= window.getSize().x &&
                mousePos.y >= 0 && mousePos.y <= window.getSize().y) {
                return true; 
            }
        }

        return false;
    }
}

void InputHandler::moveSnake(Snake& snake, float step, sf::Clock &clock) {
    

    sf::Time deltaTime = sf::seconds(0.35f);
    if (clock.getElapsedTime() >= deltaTime)
    {
        if (this->directory == 4) {
            std::vector<Circle> temp = snake.body;
            for (int i = 1; i < snake.body.size(); ++i) {
        
                Circle& currentSegment = snake.body[i];
                Circle& previousSegment = temp[i - 1];

                currentSegment.setY(previousSegment.getY());
                currentSegment.setX(previousSegment.getX());
            }
            snake.body.front().setX(snake.body.front().getX() - step);
        }
        else if (this->directory == 2) {
            std::vector<Circle> temp = snake.body;
            for (int i = 1; i < snake.body.size(); ++i) {
                Circle& currentSegment = snake.body[i];
                Circle& previousSegment = temp[i - 1];

                currentSegment.setY(previousSegment.getY());
                currentSegment.setX(previousSegment.getX());
            }
            snake.body.front().setX(snake.body.front().getX() + step);
        }
        else if (this->directory == 1) {
            std::vector<Circle> temp = snake.body;
            for (int i = 1; i < snake.body.size(); ++i) {
                Circle& currentSegment = snake.body[i];
                Circle& previousSegment = temp[i - 1];
                currentSegment.setY(previousSegment.getY());
                currentSegment.setX(previousSegment.getX());
            }
            snake.body.front().setY(snake.body.front().getY() - step);
        }
        else if (this->directory == 3) {
            std::vector<Circle> temp = snake.body;
            for (int i = 1; i < snake.body.size(); ++i) {
                Circle& currentSegment = snake.body[i];
                Circle& previousSegment = temp[i - 1];

                currentSegment.setY(previousSegment.getY());
                currentSegment.setX(previousSegment.getX());
            }
            snake.body.front().setY(snake.body.front().getY() + step);
        }
        clock.restart();
    }
}

void InputHandler::hideAfterClick(Primitives& shape) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
       shape.hide();
    }
   
}
