#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Primitives.hpp"
#include "InputHandler.hpp"
#include "Circle.hpp"

/**
 * @brief Klasa obslugujaca glowna logike gry.
 *
 * Klasa Engine zarzadza glowna logika gry, taka jak inicjalizacja, obsluga kolizji i petla glowna.
 */
class Engine
{
public:
    /**
     * @brief Konstruktor klasy Engine.
     */
    Engine();

    /**
     * @brief Destruktor klasy Engine.
     */
    ~Engine();

    /**
     * @brief Inicjalizuje silnik gry.
     *
     * @param title Tytul okna gry.
     * @param width Szerokosc okna gry.
     * @param height Wysokosc okna gry.
     */
    void init(const std::string title, int width, int height);

    /**
     * @brief Uruchamia glowna petle gry.
     */
    void run();

    /**
     * @brief Sprawdza kolizje z punktem (jablkiem).
     *
     * @param apple Okr¹g reprezentujacy jablko.
     * @param snake Obiekt reprezentujacy weza.
     * @param handle Obiekt obslugujacy wejscie od uzytkownika.
     */
    static void checkCollisionWithPoint(Circle& apple, Snake& snake, InputHandler handle);

    /**
     * @brief Sprawdza kolizje z granicami okna.
     *
     * @param snake Obiekt reprezentujacy weza.
     */
    void checkCollisionWithBorder(Snake& snake);

    /**
     * @brief Sprawdza kolizje z wlasnym cialem (samokolizje).
     *
     * @param snake Obiekt reprezentujacy weza.
     */
    void checkCollisionWithYourself(Snake& snake);
private:
    sf::RenderWindow window; /**< Okno renderowania */

    int width, height; /**< Szerokosc i wysokosc okna */
};

#endif // ENGINE_HPP
