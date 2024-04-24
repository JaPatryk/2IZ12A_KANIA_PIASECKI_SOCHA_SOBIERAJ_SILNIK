#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string> 

/**
 * @brief Klasa Bitmap
 *
 * Klasa Bitmap zawiera metody do operacji na obrazkach.
 */
class Bitmap {
public:
    /**
     * @brief Tworzenie tekstury jablka
     *
     * @param x Szerokosc tekstury jablka
     * @param y Wysokosc tekstury jablka
     * @return Tekstura jablka
     */
    static sf::Texture createApple(int x, int y);

    /**
     * @brief Wczytywanie obrazu z pliku
     *
     * @param filePath sciezka do pliku obrazu
     * @return Tekstura obrazu
     */
    static sf::Texture loadImage(std::string filePath);

    /**
     * @brief Animacja bitmapy
     *
     * @param texture Tekstura do animacji
     * @param clock Zegar do obliczenia czasu
     * @return Tekstura animacji
     */
    static sf::Texture animateBitmap(sf::Texture& texture, sf::Clock& clock);
};

#endif // BITMAP_HPP
