#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Circle.hpp"
#include <vector>

/**
 * @brief Klasa reprezentujaca weza w grze Snake.
 *
 * Klasa Snake reprezentuje weza skladajacego sie z okregow (segmentow ciala).
 */
class Snake {
public:
    std::vector<Circle> body; /**< Wektor segmentow ciala weza */

    /**
     * @brief Konstruktor klasy Snake.
     *
     * @param r Promieñ okregu reprezentujacego segment ciala weza.
     * @param x Pozycja X poczatkowego segmentu ciala weza.
     * @param y Pozycja Y poczatkowego segmentu ciala weza.
     */
    Snake(float r, float x, float y);

    /**
     * @brief Wyswietla weza na oknie renderowania.
     *
     * @param window Okno renderowania, na ktorym ma byc wyswietlony waz.
     */
    void display(sf::RenderWindow& window);

    /**
     * @brief Powieksza weza.
     *
     * Dodaje nowy segment ciala weza o podanym kierunku.
     *
     * @param directory Kierunek, w ktorym ma byc dodany nowy segment ciala.
     */
    void grow(int directory);
};

#endif // SNAKE_HPP
