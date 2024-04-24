#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SFML/Graphics.hpp>
#include "Primitives.hpp"
#include "Snake.hpp"

/**
 * @brief Obsluguje interakcje z uzytkownikiem.
 *
 * Klasa InputHandler zawiera metody do obslugi interakcji z uzytkownikiem, takie jak przesuwanie obiektow do pozycji myszy
 * lub obsluga ruchu weza w grze Snake.
 */
class InputHandler
{
public:
    int directory = 1; /**< Kierunek ruchu */

    /**
     * @brief Przesuwa ksztalt do pozycji myszy.
     *
     * @param shape Ksztalt, ktory ma byc przesuniety.
     * @param window Okno renderowania, na ktorym znajduje sie ksztalt.
     */
    void moveShapeToMousePosition(Primitives& shape, sf::RenderWindow& window);

    /**
     * @brief Ukrywa ksztalt po kliknieciu.
     *
     * @param shape Ksztalt, ktory ma zostac ukryty.
     */
    void hideAfterClick(Primitives& shape);

    /**
     * @brief Przesuwa ksztalt.
     *
     * @param shape Ksztalt, ktory ma byc przesuniety.
     * @param step Krok przesuniecia.
     */
    void move(Primitives& shape, float step);

    /**
     * @brief Przesuwa weza w grze Snake.
     *
     * @param shape Waz, ktory ma byc przesuniety.
     * @param step Krok przesuniecia.
     * @param clock Zegar uzywany do synchronizacji ruchu.
     */
    void moveSnake(Snake& shape, float step, sf::Clock& clock);

    /**
     * @brief Ustawia kierunek ruchu.
     */
    void setDirectory();

    /**
     * @brief Sprawdza, czy nastapilo klikniecie myszy.
     *
     * @param window Okno renderowania.
     * @param event Zdarzenie myszy.
     * @return true, jesli nastapilo klikniecie myszy, w przeciwnym razie false.
     */
    bool mouseClick(sf::RenderWindow& window, sf::Event event);
};

#endif // INPUTHANDLER_HPP
