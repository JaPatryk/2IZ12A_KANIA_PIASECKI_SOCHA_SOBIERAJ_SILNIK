#include "PrimitiveRenderer.hpp"

void PrimitiveRenderer::drawPoint(const sf::Vector2f& position, const sf::Color& color)
{
    sf::Vertex vertex(position, color);
    m_vertices.push_back(vertex);
}

void PrimitiveRenderer::drawLine(const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color)
{
    sf::Vertex vertices[2] = {
      sf::Vertex(start, color),
      sf::Vertex(end, color)
    };
    m_vertices.insert(m_vertices.end(), vertices, vertices + 2);
}


void PrimitiveRenderer::draw(sf::RenderWindow& window)
{
    if (m_vertices.empty()) return;

    sf::RenderStates states;
    states.blendMode = sf::BlendMode::Alpha;

    window.draw(m_vertices.data(), m_vertices.size(), sf::PrimitiveType::Points, states);
    m_vertices.clear();
}
