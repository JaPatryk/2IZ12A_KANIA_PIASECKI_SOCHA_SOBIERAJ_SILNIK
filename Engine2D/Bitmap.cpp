#include "Bitmap.hpp"


sf::Texture Bitmap::createApple(int x, int y) {

    sf::Image apple;
    apple.create(x, y, sf::Color::Transparent);
    for (int i = 25; i < 125; ++i) {
        for (int j = 25; j < 125; ++j) {
            float dx = i - 75;
            float dy = j - 75;
            float dist = std::sqrt(dx * dx + dy * dy);
            if (dist < 50) {
                apple.setPixel(i, j, sf::Color::Red);
            }
        }
    }

    for (int i = 70; i < 80; ++i) {

        for (int j = 0; j < 26; j++) {
            apple.setPixel(i, j, sf::Color(139, 69, 19)); 
        }

    }

    int n = 1;
    for (int i = 0; i < 20; i++) {

        for (int j = 49; j < n; j++) {
            apple.setPixel(j, i, sf::Color::Green); 
        }
        n++;
    }

    sf::Texture texture;
    texture.loadFromImage(apple);

    return texture;
    
}

sf::Texture Bitmap::loadImage(std::string filePath) {
    sf::Image image;
    if (!image.loadFromFile(filePath)) {
        return sf::Texture(); 
    }
    sf::Texture texture;
    texture.loadFromImage(image);

    return texture;
}

sf::Texture Bitmap::animateBitmap(sf::Texture& texture,sf::Clock& clock) {
    sf::Time deltaTime = sf::seconds(0.20f);
    if(clock.getElapsedTime() > deltaTime)
    return Bitmap::createApple(150,150);

    return Bitmap::createApple(140, 140);
}

