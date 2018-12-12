#pragma once
#include "../SFML-2.4.2/SFML-2.4.2/include/SFML/Graphics.hpp"
class Collider
{
public:
	Collider(float w=0.0f, float h=0.0f,sf::Vector2f pos=sf::Vector2f(0.0f,0.0f));
	bool IsInabled();
	void Enabled(bool);
	float GetWidth();
	float GetHeight();
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f p);
	void SetWidth(float w);
	void SetHeight(float h);


private:
	sf::Vector2f _pos;
	bool _enabled=true;
	float _width;
	float _height;
};

