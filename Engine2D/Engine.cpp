#include <cstdlib>
#include <ctime>
#include "Engine.hpp"
#include "Primitives.hpp"
#include "InputHandler.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Snake.hpp"
#include "Bitmap.hpp"


Engine::Engine()
{
   
    width = 800;
    height = 600;
    
}

Engine::~Engine()
{
    
    window.close();
}

void Engine::init(const std::string title, int width, int height)
{
  
    this->width = width;
    this->height = height;

    sf::VideoMode mode(width, height);
    window.create(mode, title, sf::Style::Default);

}

void Engine::checkCollisionWithPoint(Circle& point, Snake& snake, InputHandler handle) {
    const Circle& head = snake.body.front();
    if (point.x == head.x && point.y == head.y) {
        snake.grow(handle.directory);
        int bodyPart = 0;
        float randX, randY;
        bool collision = false;
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        do {
            randX = (rand() % 10) * 100.0;
            randY = (rand() % 10) * 100.0;

            collision = false;
            for (const auto& segment : snake.body) {
                if (segment.getX() == randX && segment.getY() == randY) {
                    collision = true;
                    break;
                }
            }

        } while (collision);

        point.setX(randX);
        point.setY(randY);
    }
};
void Engine::checkCollisionWithBorder(Snake& snake) {
    const Circle& head = snake.body.front();
    if (head.x<0 || head.y <0 || head.x>=this->width || head.y>=this->height) {
        window.close();
    }
};

void Engine::checkCollisionWithYourself(Snake& snake) {
    const Circle& head = snake.body.front();
    for (int i = 1; i < snake.body.size(); ++i) {
        if (snake.body[i].x == head.x && snake.body[i].y == head.y) {
            window.close();
        }
       
    }
   
};
void Engine::run()
{
    bool isGameStarted = false;

    InputHandler handle;
    Rectangle rectangle(window.getSize().x, window.getSize().y,0,0);
    rectangle.setColor(sf::Color::Red);
    rectangle.background = true;

    Triangle triangle(window.getSize().x/3,window.getSize().x/2, window.getSize().y/6);
    triangle.setColor(sf::Color::Yellow);
    triangle.background = true;
    while (!isGameStarted) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (handle.mouseClick(window, event)==true)
                isGameStarted = true;
            window.clear();
 
            sf::Font font;
            if (!font.loadFromFile("..\\font\\Arial.ttf")) {
               
            }
            rectangle.display(window);
            sf::Text text("Nacisnij myszka, aby rozpoczac gre", font, 30);
            text.setPosition(window.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
                window.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f);

            window.draw(text);
            window.display();
        }
    }

    Circle point(50, 0, 0);
    point.setColor(sf::Color::Red);
    point.setBorderWidth(0);
    
    int directory = 1;
    //sf::Texture apple = Bitmap::loadImage(fileName);
    sf::Texture apple = Bitmap::createApple(250, 250);


    point.setTexture(apple);
    sf::Clock clock;
    int test = 1;
    Snake snake(50, width / 2, width / 2);

    

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    window.close();
            }

            window.clear();
            apple = Bitmap::animateBitmap(apple, clock);
            point.setTexture(apple);

            Engine::checkCollisionWithBorder(snake);
            Engine::checkCollisionWithYourself(snake);
            Engine::checkCollisionWithPoint(point, snake, handle);
            handle.setDirectory();
            handle.moveSnake(snake, snake.body.front().r * 2.0, clock);
            point.display(window);

            snake.display(window);

            window.display();
            if (snake.body.size() == 100) {
                window.clear();
                sf::Font font;
               
                sf::Text text("Wygrana!", font, 100);
                text.setPosition(window.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
                    window.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f);
                window.draw(text);
                window.display();
                while (true) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            window.close();


                        window.clear();

                        sf::Font font;
                        if (!font.loadFromFile("..\\font\\Arial.ttf")) {

                        }
                        triangle.display(window);
                        sf::Text text("Wygrana!! Aby zamknac nacisnij ESC", font, 30);
                        text.setPosition(window.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
                        window.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f);
                        window.draw(text);
                        window.display();
                    }
                }
            }
        }
    }

