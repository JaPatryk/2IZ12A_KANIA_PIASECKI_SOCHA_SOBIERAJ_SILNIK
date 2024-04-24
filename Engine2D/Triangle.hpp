#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Primitives.hpp"

/**
 * @brief Klasa reprezentujaca trojkat.
 *
 * Klasa Triangle dziedziczy po klasie Primitives i reprezentuje trojkat o okreslonych wymiarach.
 */
class Triangle : public Primitives {
public:
    float a; /**< Dlugosc boku trojkata */

    /**
     * @brief Konstruktor klasy Triangle.
     *
     * @param a Dlugosc boku trojkata.
     * @param x Pozycja X srodka trojkata.
     * @param y Pozycja Y srodka trojkata.
     */
    Triangle(float a, float x, float y);

    /**
     * @brief Ustawia dlugo boku trojkata.
     *
     * @param a Nowa dlugosc boku trojkata.
     */
    void setA(float a);

    /**
     * @brief Wyswietla trojkat na oknie renderowania.
     *
     * @param window Okno renderowania, na ktorym ma byc wyswietlony trojkat.
     */
    void display(sf::RenderWindow& window);
};

#endif // TRIANGLE_HPP
