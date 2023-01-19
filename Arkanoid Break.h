#pragma once
#include <SFML/Graphics.hpp> 
#include "settings.h" 
struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};
void brickInit(Brick& brick, sf::Color color, sf::Vector2f position) {
	brick.color = color;
	brick.position = position;
	brick.shape.setSize(sf::Vector2f{ BRICK_WIDTH,BRICK_HEIGHT });
	brick.shape.setFillColor(brick.color);
	brick.shape.setPosition(brick.position);
}
void brickUpdate(Brick& brick) {

}
void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}
