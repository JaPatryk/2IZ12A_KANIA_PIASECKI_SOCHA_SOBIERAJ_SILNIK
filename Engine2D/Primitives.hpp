#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Klasa abstrakcyjna reprezentujaca podstawowe ksztalty.
 *
 * Klasa Primitives jest klasa abstrakcyjna, ktora reprezentuje podstawowe ksztalty graficzne.
 * Jest to klasa bazowa dla konkretnych ksztaltow, takich jak prostokat, kolo, trojkat.
 */
class Primitives {
public:
    float x, y, angle, borderWidth; /**< Wspolrzedne, kat obrotu, szerokosc obramowania */
    sf::Color color; /**< Kolor ksztaltu */
    bool background; /**< Czy ksztalt ma tlo */
    sf::Texture texture; /**< Tekstura ksztaltu */

    /**
     * @brief Konstruktor domyslny klasy Primitives.
     */
    Primitives();

    /**
     * @brief Ustawia kolor ksztaltu.
     *
     * @param color Nowy kolor ksztaltu.
     */
    void setColor(sf::Color color);

    /**
     * @brief Ustawia teksture ksztaltu.
     *
     * @param texture Nowa tekstura ksztaltu.
     */
    void setTexture(sf::Texture texture);

    /**
     * @brief Ustawia szerokosc obramowania ksztaltu.
     *
     * @param borderWidth Nowa szerokosc obramowania ksztaltu.
     */
    void setBorderWidth(float borderWidth);

    /**
     * @brief Ustawia pozycje X ksztaltu.
     *
     * @param x Nowa pozycja X ksztaltu.
     */
    void setX(float x);

    /**
     * @brief Ustawia pozycje Y ksztaltu.
     *
     * @param y Nowa pozycja Y ksztaltu.
     */
    void setY(float y);

    /**
     * @brief Zwraca pozycje X ksztaltu.
     *
     * @return Pozycja X ksztaltu.
     */
    float getX() const;

    /**
     * @brief Zwraca pozycje Y ksztaltu.
     *
     * @return Pozycja Y ksztaltu.
     */
    float getY() const;

    /**
     * @brief Ustawia tlo dla ksztaltu.
     */
    void setBackground();

    /**
     * @brief Usuwa tlo dla ksztaltu.
     */
    void clearBackground();

    /**
     * @brief Obraca ksztalt o zadany kat.
     *
     * @param angle Kat obrotu w stopniach.
     */
    void rotateShape(float angle);

    /**
     * @brief Wylacza mozliwosc obrotu ksztaltu.
     */
    void disableRotate();

    /**
     * @brief Ukrywa ksztalt.
     */
    void hide();
};
#endif // PRIMITIVES_HPP
