#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Primitives.hpp"

/**
 * @brief Klasa reprezentujaca kolo.
 *
 * Klasa Circle dziedziczy po klasie Primitives i reprezentuje kolo o okreslonym promieniu.
 */
class Circle : public Primitives {
public:
    float r; /**< Promien kola */

    /**
     * @brief Konstruktor klasy Circle.
     *
     * @param r Promien kola.
     * @param x Pozycja X lewego gornego rogu kola.
     * @param y Pozycja Y lewego gornego rogu kola.
     */
    Circle(float r, float x, float y);

    /**
     * @brief Ustawia promien kola.
     *
     * @param r Nowy promien kola.
     */
    void setR(float r);

    /**
     * @brief Wyswietla kolo na oknie renderowania.
     *
     * @param window Okno renderowania, na ktorym ma byc wyswietlone kolo.
     */
    void display(sf::RenderWindow& window);
};

#endif // CIRCLE_HPP
