#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

class PrimitiveRenderer
{
public:
	void drawPoint(const sf::Vector2f& position, const sf::Color& color);
	void drawLine(const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color);

	void draw(sf::RenderWindow& window);

private:
	std::vector<sf::Vertex> m_vertices;
};

#endif // PRIMITIVERENDERER_HPP
