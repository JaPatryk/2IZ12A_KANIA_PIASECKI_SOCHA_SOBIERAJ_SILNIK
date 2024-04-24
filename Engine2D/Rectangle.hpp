#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Primitives.hpp"

/**
 * @brief Klasa reprezentujaca prostokat.
 *
 * Klasa Rectangle dziedziczy po klasie Primitives i reprezentuje prostokat o okreslonych wymiarach.
 */
class Rectangle : public Primitives {
public:
    float a; /**< Dlugosc boku a prostokata */
    float b; /**< Dlugosc boku b prostokata */

    /**
     * @brief Konstruktor klasy Rectangle.
     *
     * @param a Dlugosc boku a prostokata.
     * @param b Dlugosc boku b prostokata.
     * @param x Pozycja X lewego gornego rogu prostokata.
     * @param y Pozycja Y lewego gornego rogu prostokata.
     */
    Rectangle(float a, float b, float x, float y);

    /**
     * @brief Ustawia dlugosc boku a prostokata.
     *
     * @param a Nowa dlugosc boku a prostokata.
     */
    void setA(float a);

    /**
     * @brief Ustawia dlugosc boku b prostokata.
     *
     * @param b Nowa dlugosc boku b prostokata.
     */
    void setB(float b);

    /**
     * @brief Wyswietla prostokat na oknie renderowania.
     *
     * @param window Okno renderowania, na ktorym ma byc wyswietlony prostokat.
     */
    void display(sf::RenderWindow& window);
};

#endif // RECTANGLE_HPP
